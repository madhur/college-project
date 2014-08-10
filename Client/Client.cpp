// client.cpp : Defines the entry point for the application.
// build a function for time

#include "stdafx.h"
#include "resource.h"
#include "Tlhelp32.h"
#include "stdio.h"
//#include "jpeglib.h"
//#include "BitmapFile.h"

#define WS_EX_LAYERED  80000// I guess you won't find these equates in your includes 
#define LMA_COLORKEY  1
#define LMA_ALPHA     2

#define IDI_EXIT 50
typedef DWORD  (WINAPI *MYPROC) (HWND,DWORD,DWORD,DWORD); 
#define MENUID 6000

HINSTANCE hinst;
HWND hwnd;
//DWORD tid,tid1,tbuzzid;
	static HMENU hmenu;
	HMENU hpop;
	HANDLE tpop;
BOOL disturb,vi;
HANDLE thwnd;
SOCKET newsocket;
int flag=1;
int cd=0;
static HANDLE closeevent;
//char buffer[255];

//////////////////////////////////////////////////////
void errhandler(char *msg, HWND hwnd);
DWORD WINAPI lstproc(void *);
DWORD WINAPI tproc(LPVOID s);
DWORD WINAPI tbuzz(void *s);
DWORD WINAPI sthread(void *s);
DWORD WINAPI dispinfo(void *);
DWORD playWAVEFile(HWND hWndNotify, LPSTR lpszWAVEFileName);
PBITMAPINFO CreateBitmapInfoStruct(HWND hwnd, HBITMAP hBmp);
void CreateBMPFile(HWND hwnd, LPTSTR pszFile, PBITMAPINFO pbi,
                  HBITMAP hBMP, HDC hDC);

LRESULT CALLBACK dlgproc(HWND hwnd,UINT msg,WPARAM wparam,LPARAM lparam);
BOOL WINAPI NetErrorHandler(HWND hwnd, 
                            DWORD dwErrorCode, 
                            LPSTR lpszFunction) ;

init();


struct processlist
{
	DWORD pid;
	TCHAR file[255];
};

BOOL CALLBACK addhostproc(HWND hwnd,UINT msg,WPARAM wparam,LPARAM lparam);


int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.

	init();

	::hinst =hinst;
	MSG msg;
	HWND hwnd;
	WNDCLASSEX wc;
	wc.cbClsExtra =0;
	wc.cbSize =sizeof(wc);
	wc.cbWndExtra =DLGWINDOWEXTRA;
	wc.hbrBackground =HBRUSH(COLOR_WINDOW+1);
	wc.hCursor =LoadCursor(0,IDC_ARROW);
	wc.hIcon =LoadIcon(0,IDI_APPLICATION);
	wc.hIconSm =LoadIcon(0,IDI_APPLICATION);
	wc.hInstance =hinst;
	wc.lpfnWndProc =WNDPROC(dlgproc);
	wc.lpszClassName ="Spy";
	wc.lpszMenuName =0;
	wc.style =CS_HREDRAW;

	RegisterClassEx(&wc);

	hwnd=CreateWindowEx(0,"Spy","Mac",WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,0,0,hinst,0);
	::hwnd=hwnd;
	ShowWindow(hwnd,SW_SHOW);
	while(GetMessage(&msg,0,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	return msg.wParam ;

	return 0;
}




LRESULT CALLBACK dlgproc(HWND hwnd,UINT msg,WPARAM wparam,LPARAM lparam)
{
	POINT pt;
	static HANDLE mainthwnd;
	DWORD butid;
	static char lhost[128];
	char event[]={"beller"};
	int i;
	
	static NOTIFYICONDATA note;
	OSVERSIONINFO vi;
	switch(msg)
	{
	
	


	
	case WM_CREATE:
				
			CreateEvent(0,0,0, event);
			i=GetLastError();
			if(i==0xb7)
			{
				MessageBox(hwnd,"Only one instance of program can be active","Beller",MB_ICONSTOP);
				ExitProcess(0);
			}
			
			vi.dwOSVersionInfoSize =sizeof(OSVERSIONINFO);
				
			GetVersionEx(&vi);
			if(vi.dwMajorVersion >4)
				::vi=1;
			
			
			hmenu=CreatePopupMenu();
			hpop=CreatePopupMenu();

			AppendMenu(hmenu,MF_STRING,40001,"E&xit");
			SetMenuDefaultItem(hmenu,40003,0);
			/////////////////////////////////////////
						
			note.cbSize =sizeof(NOTIFYICONDATA);
			note.hIcon =LoadIcon(hinst,MAKEINTRESOURCE(IDI_ICON3));
			note.hWnd =hwnd;
			note.uCallbackMessage =WM_USER+5;
			note.uID =25;
			note.uFlags =NIF_ICON | NIF_MESSAGE;
			Shell_NotifyIcon(NIM_ADD,&note);
			mainthwnd=CreateThread(0,0,lstproc,0,0,0);
		break;

		case WM_SIZE:
			//ShowWindow(hwnd,SW_HIDE);
			break;
	
		case WM_COMMAND:
			switch(LOWORD(wparam))
			{
			case IDEXIT:
				SendMessage(hwnd,WM_CLOSE,0,0);
				break;

			

			case IDDISTURB:
				MessageBox(0,"here",0,0);
				i=CheckMenuItem(hmenu,IDDISTURB,MF_BYCOMMAND);
				if(i==MF_CHECKED)
				{
					i=CheckMenuItem(hmenu,IDDISTURB,MF_BYCOMMAND|MF_UNCHECKED);
					note.hIcon =LoadIcon(hinst,MAKEINTRESOURCE(IDI_ICON3));
					Shell_NotifyIcon(NIM_MODIFY,&note);
					disturb=0;
				}
				else
				{
					i=CheckMenuItem(hmenu,IDDISTURB,MF_BYCOMMAND|MF_CHECKED);
					note.hIcon =LoadIcon(hinst,MAKEINTRESOURCE(IDI_ICON4));
					Shell_NotifyIcon(NIM_MODIFY,&note);
					disturb=1;
				}
				break;

		

			}
		break;

		case WM_USER+5:
		if(wparam==25)
		{
			if(lparam==WM_RBUTTONDOWN)
			{
				GetCursorPos(&pt);
				SetForegroundWindow(hwnd);
				TrackPopupMenu(hmenu,TPM_LEFTALIGN,pt.x,pt.y,0,hwnd,0);
				PostMessage(hwnd,WM_NULL,0,0);
			}
		}
		break;

		case WM_CLOSE:
			WSACleanup();
			TerminateThread(mainthwnd,0);
			PostQuitMessage(0);
			Shell_NotifyIcon(NIM_DELETE,&note);
			break;

		default:
			return(DefWindowProc(hwnd,msg,wparam,lparam));
	}
	return 0;

}



DWORD WINAPI lstproc(LPVOID h)
{
	SOCKET listensocket;
	sockaddr_in sockad,newsockad;
	int i;
	
	listensocket=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(listensocket==INVALID_SOCKET)
	{
		MessageBox(0,"Cannot Create Socket","Beller",MB_ICONSTOP);
		ExitProcess(0);
	}

	sockad.sin_addr.S_un.S_addr  =INADDR_ANY;
	sockad.sin_port =htons(4444);		//listening on port 4444
	sockad.sin_family =AF_INET  ;

	i=bind(listensocket,reinterpret_cast<sockaddr*>(&sockad),sizeof(sockad));

	if(i==INVALID_SOCKET)
	{
		MessageBox(0,"Socket Binding Error","Beller",MB_ICONSTOP);
		ExitProcess(0);
	}

	i=listen(listensocket,SOMAXCONN);
	if(i==INVALID_SOCKET)
	{
		MessageBox(0,"Cannot Listen Socket","Beller",MB_ICONSTOP);
		ExitProcess(0);
	}

	i=sizeof(newsockad);

	while(1)
	{
		newsocket=accept(listensocket,reinterpret_cast<sockaddr*>(&newsockad),&i);
		if(newsocket==INVALID_SOCKET)
		{
			MessageBox(0,"Error in accepting incoming connection","Beller",MB_ICONSTOP);
			ExitProcess(0);
		}
	
	    tpop=CreateThread(0,0,dispinfo,(void *)&newsocket,0,0);
		
		WaitForSingleObject(thwnd,INFINITE);
	}

	closesocket(listensocket);

	return 1;


}

char * gettime()
{
	SYSTEMTIME sm;
	GetLocalTime(&sm);
	char buff[10],buff1[10];

	
	itoa(sm.wYear,buff,10);
	itoa(sm.wMonth,buff1,10);
	
//	sprintf(buff1,"%2d",buff1);
	strcat(buff,buff1);

	itoa(sm.wDay,buff1,10);

	strcat(buff,buff1);

	itoa(sm.wHour,buff1,10);

	strcat(buff,buff1);

	itoa(sm.wMinute,buff1,10);

	strcat(buff,buff1);

	return buff;

}

DWORD WINAPI	dispinfo(void *newsocket1)
{
	
	int retval;
	static char buffer[5];
	int i;
	//processlist p[100];
	char buff[1000];
	int cnt=0;

	//SOCKET sock=(SOCKET)*newsocket;
	retval=recv(newsocket,buffer,12,0);

	if(retval==SOCKET_ERROR)
	{
		MessageBox(0,"Error Receiving Data","Beller",0);
		return 1 ;
	}

	
	i=strcmp(buffer,"GETPROCESS");	//check the code, at this time only play is supported
	if(i==0)
	{
		
		HANDLE hSnapshot=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	

		PROCESSENTRY32 pe;

		// fill up its size
		pe.dwSize=sizeof(PROCESSENTRY32);

		BOOL retval=Process32First(hSnapshot,&pe);
		FILE *df=fopen("c:\\process.txt","w");
		while(retval)
		{
			char str[100];
			printf("Process ID : %08X %s\n",pe.th32ProcessID,pe.szExeFile);
			sprintf(str,"Process ID : %ld %s!\n",pe.th32ProcessID,pe.szExeFile);
			fprintf(df,"Process ID : %08X %s\n",pe.th32ProcessID,pe.szExeFile);
			
			str[strlen(str)]=0;
			int k=strlen(str);
			send(newsocket,str,strlen(str),0);
		
			pe.dwSize=sizeof(PROCESSENTRY32);
			retval=Process32Next(hSnapshot,&pe);
		}
		fclose(df);
		//send(newsocket,buff,sizeof(p),0);
		// close snapshot handle
		CloseHandle(hSnapshot);

		closesocket((int)newsocket);

		return 1;
	}

	i=strcmp(buffer,"KILLPROCESS");
	
	if(i==0)
	{
		FILE *df=fopen("c:\\kill.log","w");

		retval=recv(newsocket,buffer,9,0);

		HANDLE hSnapshot=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
		//thwnd=CreateThread(0,0,tproc,(void *)newsocket,0,0);
	/*	if (hSnapshot==-1)
		{
		// error: unable to create snapshot
		}*/
		char ppid[10];
		DWORD pid;

		//sprintf(ppid,"%d",buffer);
		
		pid=atoi(buffer);
		
		PROCESSENTRY32 pe;

		// fill up its size
		pe.dwSize=sizeof(PROCESSENTRY32);

		BOOL retval=Process32First(hSnapshot,&pe);
		
		while(retval)
		{
			
			char str[100];
			int flag=0;
			
			
			if(pe.th32ProcessID==pid)
			{
				//MessageBox(0,"proc found","Df",0);
				HANDLE pr=OpenProcess(PROCESS_TERMINATE,1,pid);
				i=TerminateProcess(pr,0);
				if(i!=0)
				{
					char str[200];
					sprintf(str,"SUCESS:Process ID : %08X %s : Application not permitted by administrator\n",pe.th32ProcessID,pe.szExeFile);
					strcat(str,"!");
					
					//MessageBox(0,str,"df",0);
					fwrite(str,1,strlen(str),df);
					send(newsocket,str,strlen(str),0);
					flag=1;
					break;
				}
				if(flag==0) {
				sprintf(str,"FAILURE: Unable to close Application\n!");
				send(newsocket,str,strlen(str),0);
				}
			}

			
			
				//sprintf(str,"Process ID : %08X %s\n",pe.th32ProcessID,pe.szExeFile);
		
			pe.dwSize=sizeof(PROCESSENTRY32);
			retval=Process32Next(hSnapshot,&pe);
		}
		CloseHandle(hSnapshot);
		closesocket((int)newsocket);
		fclose(df);


		return 1;

	}
	i=strcmp(buffer,"GETSNAP");
	if(i==0)
	{

		 HDC hdcBmp, hdcAux;
		 HBITMAP hBmp, hBmpPrev;
		 int iBmpWidth, iBmpHeight;
		 BOOL bStatus ;
		 PBITMAPINFO pInfo;
		
		
		hdcAux = CreateDC("DISPLAY",NULL,NULL,NULL);
		 hdcBmp = CreateCompatibleDC(hdcAux);

		 iBmpWidth = 1024;
		 iBmpHeight = 768;
		 hBmp  = CreateCompatibleBitmap(hdcAux, iBmpWidth, iBmpHeight);
		 hBmpPrev = (HBITMAP)SelectObject(hdcBmp, hBmp);
		 bStatus = ::BitBlt( hdcBmp, 0, 0, 1024, 768, hdcAux, 0, 0, SRCCOPY     
		);

		 pInfo = CreateBitmapInfoStruct(hwnd, hBmp);
			char *msg=gettime();
		 CreateBMPFile(hwnd, "desktop.bmp", pInfo, hBmp, hdcBmp);

		 SelectObject(hdcBmp, hBmpPrev);
		 
		 
		 FILE *df=fopen("desktop.bmp","rb");
		 if(df==NULL)
		 {
			 MessageBox(0,"file error","d",0);
			 return 1;
		 }
		 char buff[1000];
		 while(1)
		 {
			 i=fread(buff,1,1000,df);
			 if(feof(df))
				 break;
			 send(newsocket,buff,i,0);
		 }
		 send(newsocket,buff,i,0);
		 	closesocket((int)newsocket);
		 fclose(df);


	//	 send(newsocket,"SUCCESS",8,0);
		 
		 DeleteObject(hBmp);
		 DeleteDC(hdcBmp);
		 DeleteDC(hdcAux);

		 	return 1;

	}
	i=strcmp(buffer,"ROUTINE");
	if(i==0)
	{

		HANDLE hSnapshot=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
		PROCESSENTRY32 pe;

		// fill up its size
		pe.dwSize=sizeof(PROCESSENTRY32);

		BOOL retval=Process32First(hSnapshot,&pe);
		//FILE *df=fopen("c:\\process.txt","w");
		FILE *df=fopen("c:\\terminated.log","w");
		while(retval)
		{
			
			char str[100],buff[100];
			

			printf("Process ID : %08X %s\n",pe.th32ProcessID,pe.szExeFile);
			sprintf(str,"Process ID : %ld %s\n",pe.th32ProcessID,pe.szExeFile);
		//	fprintf(df,"Process ID : %08X %s\n",pe.th32ProcessID,pe.szExeFile);
			
			str[strlen(str)]=0;
			int k=strlen(str);
			send(newsocket,str,strlen(str),0);

			i=recv(newsocket,buff,8,0);
			i=strcmp(buff,"LEGAL");
			if(i==0)
			{
				//no action

			}
			i=strcmp(buff,"ILLEGAL");
			if(i==0)
			{
				//log and queue for termination
				HANDLE pr=OpenProcess(PROCESS_TERMINATE,1,pe.th32ProcessID);
				i=TerminateProcess(pr,0);
				if(i!=0)
				{
					MessageBox(0,"terminated","df",0);
					
					send(newsocket,"SUCCESS",8,0);
					fwrite(str,1,strlen(str),df);

				//	flag=1;
				
				}
				else
					send(newsocket,"FAILURE: Unable to Close Application!",strlen(str),0);
			}
			
		
			pe.dwSize=sizeof(PROCESSENTRY32);
			retval=Process32Next(hSnapshot,&pe);
		}
		// close snapshot handle
		CloseHandle(hSnapshot);

		fclose(df);

		closesocket((int)newsocket);

		return 1;
	}

	
	else
	{
		MessageBox(0,"Received Data not identified: probably corrupted","Beller",0);
	}

	closesocket((int)newsocket);

	return 1;
}

//The following example code defines a function that allocates memory for and
//initializes members within a BITMAPINFOHEADER structure.
PBITMAPINFO CreateBitmapInfoStruct(HWND hwnd, HBITMAP hBmp)
{
    BITMAP bmp;
    PBITMAPINFO pbmi;
    WORD    cClrBits;

    // Retrieve the bitmap's color format, width, and height.
    if (!GetObject(hBmp, sizeof(BITMAP), (LPSTR)&bmp))
        return NULL;

    // Convert the color format to a count of bits.
    cClrBits = (WORD)(bmp.bmPlanes * bmp.bmBitsPixel);
    if (cClrBits == 1)
        cClrBits = 1;
    else if (cClrBits <= 4)
        cClrBits = 4;
    else if (cClrBits <= 8)
        cClrBits = 8;
    else if (cClrBits <= 16)
        cClrBits = 16;
    else if (cClrBits <= 24)
        cClrBits = 24;
    else cClrBits = 32;

    // Allocate memory for the BITMAPINFO structure. (This structure
    // contains a BITMAPINFOHEADER structure and an array of RGBQUAD
    // data structures.)

     if (cClrBits != 24)
         pbmi = (PBITMAPINFO) LocalAlloc(LPTR,
                    sizeof(BITMAPINFOHEADER) +
                    sizeof(RGBQUAD) * (1<< cClrBits));

     // There is no RGBQUAD array for the 24-bit-per-pixel format.

     else
         pbmi = (PBITMAPINFO) LocalAlloc(LPTR,
                    sizeof(BITMAPINFOHEADER));

    // Initialize the fields in the BITMAPINFO structure.

    pbmi->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    pbmi->bmiHeader.biWidth = bmp.bmWidth;
    pbmi->bmiHeader.biHeight = bmp.bmHeight;
    pbmi->bmiHeader.biPlanes = bmp.bmPlanes;
    pbmi->bmiHeader.biBitCount = bmp.bmBitsPixel;
    if (cClrBits < 24)
        pbmi->bmiHeader.biClrUsed = (1<<cClrBits);

    // If the bitmap is not compressed, set the BI_RGB flag.
    pbmi->bmiHeader.biCompression = BI_RGB;

    // Compute the number of bytes in the array of color
    // indices and store the result in biSizeImage.
    // For Windows NT/2000, the width must be DWORD aligned unless
    // the bitmap is RLE compressed. This example shows this.
    // For Windows 95/98, the width must be WORD aligned unless the
    // bitmap is RLE compressed.
    pbmi->bmiHeader.biSizeImage = ((pbmi->bmiHeader.biWidth * cClrBits +31)
& ~31) /8
                                  * pbmi->bmiHeader.biHeight;
    // Set biClrImportant to 0, indicating that all of the
    // device colors are important.
     pbmi->bmiHeader.biClrImportant = 0;
     return pbmi;
}

void CreateBMPFile(HWND hwnd, LPTSTR pszFile, PBITMAPINFO pbi, HBITMAP hBMP,
HDC hDC)
{
 HANDLE hf;                 // file handle
 BITMAPFILEHEADER hdr;       // bitmap file-header
 PBITMAPINFOHEADER pbih;     // bitmap info-header
 LPBYTE lpBits;              // memory pointer
 DWORD dwTotal;              // total count of bytes
 DWORD cb;                   // incremental count of bytes
 BYTE *hp;                   // byte pointer
 DWORD dwTmp;

    pbih = (PBITMAPINFOHEADER) pbi;
    lpBits = (LPBYTE) GlobalAlloc(GMEM_FIXED, pbih->biSizeImage);

    if (!lpBits)
  return;

    // Retrieve the color table (RGBQUAD array) and the bits
    // (array of palette indices) from the DIB.
    if (!GetDIBits(hDC, hBMP, 0, (WORD) pbih->biHeight, lpBits, pbi,
DIB_RGB_COLORS))
  return;

    // Create the .BMP file.
    hf = CreateFile(pszFile, GENERIC_READ | GENERIC_WRITE, (DWORD) 0, NULL,
CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, (HANDLE) NULL);
    if (hf == INVALID_HANDLE_VALUE)
        return;

    hdr.bfType = 0x4d42;        // 0x42 = "B" 0x4d = "M"
    // Compute the size of the entire file.
    hdr.bfSize = (DWORD) (sizeof(BITMAPFILEHEADER) + pbih->biSize +
pbih->biClrUsed * sizeof(RGBQUAD) + pbih->biSizeImage);
    hdr.bfReserved1 = 0;
    hdr.bfReserved2 = 0;

    // Compute the offset to the array of color indices.
    hdr.bfOffBits = (DWORD) sizeof(BITMAPFILEHEADER) + pbih->biSize +
pbih->biClrUsed * sizeof (RGBQUAD);

    // Copy the BITMAPFILEHEADER into the .BMP file.
    if (WriteFile(hf, (LPVOID) &hdr, sizeof(BITMAPFILEHEADER), (LPDWORD)
&dwTmp,  NULL))
    {
       // Copy the BITMAPINFOHEADER and RGBQUAD array into the file.
  if (WriteFile(hf, (LPVOID) pbih, sizeof(BITMAPINFOHEADER)  +
pbih->biClrUsed * sizeof (RGBQUAD), (LPDWORD) &dwTmp, ( NULL)))
        {
   // Copy the array of color indices into the .BMP file.
   dwTotal = cb = pbih->biSizeImage;
   hp = lpBits;
   if (!WriteFile(hf, (LPSTR) hp, (int) cb, (LPDWORD) &dwTmp,NULL))
   {
   }
  }
 }
    // Close the .BMP file.
    if (CloseHandle(hf))

    // Free memory.
    GlobalFree((HGLOBAL)lpBits);
}

void errhandler(char *msg, HWND hwnd)
{

	MessageBox(0,msg,msg,0);
}
DWORD playWAVEFile(HWND hWndNotify, LPSTR lpszWAVEFileName)
{
    UINT wDeviceID;
    DWORD dwReturn;
	char buffer[100];
    MCI_OPEN_PARMS mciOpenParms;
    MCI_PLAY_PARMS mciPlayParms;

    // Open the device by specifying the device and filename.
    // MCI will choose a device capable of playing the specified file.

	

    mciOpenParms.lpstrDeviceType = "waveaudio";
    mciOpenParms.lpstrElementName = lpszWAVEFileName;
	//mciOpenParms.lpstrAlias ="fdsfd";
    if (dwReturn = mciSendCommand(0, MCI_OPEN,
       MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, 
       (DWORD)(LPVOID) &mciOpenParms))
    {
        
		mciGetErrorString(dwReturn,buffer,sizeof buffer);
		MessageBox(0,buffer,0,0);
		// Failed to open device. Don't close it; just return error.
        return (dwReturn);
    }

    // The device opened successfully; get the device ID.
    wDeviceID = mciOpenParms.wDeviceID;

    // Begin playback. The window procedure function for the parent 
    // window will be notified with an MM_MCINOTIFY message when 
    // playback is complete. At this time, the window procedure closes 
    // the device.

    mciPlayParms.dwCallback = (DWORD) hWndNotify;
    if (dwReturn = mciSendCommand(wDeviceID, MCI_PLAY, MCI_NOTIFY, 
        (DWORD)(LPVOID) &mciPlayParms))
    {
        mciSendCommand(wDeviceID, MCI_CLOSE, 0, NULL);
        return (dwReturn);
    }

    return (0L);
}


init()
{
	char buffer[255];		
	WSADATA wsadata;
	int	i=WSAStartup(2,&wsadata);
	if(i!=0)
	{
		MessageBox(hwnd,"Winsock Error","Beller",MB_ICONSTOP);
		return 0;
	}
	if(wsadata.wVersion !=2)
	{
		MessageBox(HWND(hwnd),"Older Winsock version","Beller",MB_ICONSTOP);
		return 0;
	}
		
/*	i=GetPrivateProfileSection(sec1,buffer,sizeof(buffer),inifile);
	if(i==0)	//if the inifile doesnot exist
	{
		WritePrivateProfileSection(sec1,indata,inifile); //write initial section
		gethostname(inidata.hosts[0],255);
		WritePrivateProfileString(sec1,"0",inidata.hosts[0],inifile);	//write actual hostname
		inidata.hostindex ++;		//set initial hostindex
		//_itoa(inidata.hostindex ,buffer,10);
		//WritePrivateProfileString(sec1,"hostindex",buffer,inifile);
				
	}

	GetPrivateProfileString(sec1,"wavefile","ringin.wav",inidata.wavefile ,sizeof(inidata.wavefile) ,inifile);
	inidata.trans =GetPrivateProfileInt(sec1,"trans",1,inifile);
	inidata.hostindex =GetPrivateProfileInt(sec1,"hostindex",1,inifile);
	//get the hostindex first so that we can get nu\o of hosts
	for(i=0;i<inidata.hostindex ;++i)
	{
		_itoa(i,buffer,10);
		GetPrivateProfileString(sec1,buffer,"client",inidata.hosts [i],sizeof(inidata.hosts [i]),inifile);
	}*/
	return 1;
}