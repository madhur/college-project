// SpyView.cpp : implementation of the CSpyView class
//

#include "stdafx.h"
#include "Spy.h"
#include "pingthread.h"
#include "SpyDoc.h"
#include "SpyView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpyView

IMPLEMENT_DYNCREATE(CSpyView, CView)

BEGIN_MESSAGE_MAP(CSpyView, CView)
	//{{AFX_MSG_MAP(CSpyView)
	ON_WM_SETFOCUS()
	ON_WM_CREATE()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	ON_BN_CLICKED(12323,CSpyView::Mybmp)
	ON_EN_SETFOCUS(1124,CSpyView::MyIPClick)
	ON_BN_CLICKED(RTOP1,CSpyView::MyRT1Click)
	ON_BN_CLICKED(RTOP2,CSpyView::MyRT2Click)
	ON_BN_CLICKED(RTOP3,CSpyView::MyRT3Click)
	ON_BN_CLICKED(RTOP4,CSpyView::MyRT4Click)
	ON_BN_CLICKED(RTOP5,CSpyView::MyRT5Click)
	ON_BN_CLICKED(LSIDE1,CSpyView::MyLS1Click)
	ON_BN_CLICKED(LSIDE2,CSpyView::MyLS2Click)
	ON_BN_CLICKED(LSIDE3,CSpyView::MyLS3Click)
	ON_BN_CLICKED(LSIDE4,CSpyView::MyLS4Click)
	ON_NOTIFY(TVN_SELCHANGED,IDC_MYTREE,TNotify)
	ON_MESSAGE(WM_PING_END,OnPingEnd)
	ON_MESSAGE(WM_MSG_MYCPING,OnTreeGen)
	ON_MESSAGE(WM_MSG_STATUS,OnRequestTimedOut)
	ON_MESSAGE(STN_CLICKED,Mybmp)

END_MESSAGE_MAP()

void CSpyView::Mybmp()
{

	ShellExecute(0,"open","c:\\bitmap20.bmp",0,0,SW_MAXIMIZE);


}

// CSpyView construction/destruction
void CSpyView::MyIPClick () {
//	CIPAddressCtrl spy_sc,spy_dc;
	CString txt;
	spy_sc.GetWindowText(txt);
	txt.SetAt(txt.GetLength()-1,'0');
	spy_dc.SetWindowText(txt);
//y_sc.GetAddress(&ad1,&ad2,&ad3,&ad4);
//spy_dc.SetAddress(*ad1,*ad2,*ad3,0);

}
void CSpyView::OnRequestTimedOut(WPARAM wParam,LPARAM lParam) {
//Now display appr message if the host is not responding from the tree;
int n=(int)wParam;
char* pMsg = (char*) lParam;
if(n==20 || n==23) {
	//AfxMessageBox(pMsg);
	lval=pMsg;
	cnt++;
int mc=Mctree.GetIndex(pMsg);
cpingStatus[mc]="Machine Inactive";
//Mctree.DefSearchNDelete(pMsg);
}
//if ping is successful then display the message
if(n==42) {
int mc=Mctree.GetIndex(pMsg);
cpingStatus[mc]="Machine Active";
}
//listRefresh();
}


void CSpyView::OnPingEnd(WPARAM wParam,LPARAM lParam) {
//can be used to check a non existing host
char* pMsg = (char*) lParam;
int x=(int)wParam;
if(x==20 || x==23) {
	//AfxMessageBox(pMsg);
	lval=pMsg;
	cnt++;
int mc=Mctree.GetIndex(pMsg);
cpingStatus[mc]="Machine Inactive";
//Mctree.DefSearchNDelete(pMsg);
}
if(x==42) {
int mc=Mctree.GetIndex(pMsg);
cpingStatus[mc]="Machine Active";
}
listRefresh();
}


void CSpyView::TNotify(NMTREEVIEW* p,LRESULT *result) {
//Notify the occcurence of selection of a tree item	
	CString xx=Mctree.GetItemText(p->itemNew.hItem);
	c_mac="";
		//AfxMessageBox(machine);
	if(!machine.IsEmpty())
		if(xx.Find("Pr")>-1)
			c->SetWindowText(machine+xx);
		else
		  c->SetWindowText(machine);
	else
		c->SetWindowText(xx);
	c_mac.Format(xx);
//c->SetWindowText(c_mac);
}

//Initialize
CSpyView::CSpyView()
{
	spy_list=new CFileDialog(FALSE,"","*.spy",OFN_FILEMUSTEXIST| OFN_HIDEREADONLY,0,this);
	//pingbuf is used to hold ip addresses to ping
	killChk=0;
strcpy(pingbuf,"");
//load the background bitmap
bt.LoadBitmap(165);
spy_snap.LoadBitmap(IDB_BITMAP20);
procNum=0;
//flags for controlling access to functions
rt1fl=rt2fl=rt3fl=rt4fl=rt5fl=ls1fl=ls2fl=ls3fl=ls4fl=0;
//itmap spy_snap;
fl=0;
cnt=0;
}
//function to display a bitmap on the screen

void CSpyView::MyRT1Click() {

		
	char buff[1000];
	CDC MemDC;
	FILE *df;
	
	//machine="127.0.0.1";
	//used to take a snap of the client computer
	sock=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	memset((void*)&sockad,0,sizeof(sockad));
	AfxMessageBox(machine,0,0);
	sockad.sin_addr.S_un.S_addr=inet_addr(machine);
	sockad.sin_port=htons(4444);
	sockad.sin_family =AF_INET;
	i=connect(sock,(SOCKADDR*) &sockad,sizeof(sockad));
	if(i!=0)
	{
		AfxMessageBox("Cannot connect");
		return;
	}
	send(sock,"GETSNAP",8,0);
	df=fopen("C:\\bitmap20.bmp","wb");
	while(1)
	{
		i=recv(sock,buff,1000,0);
		if(i==0)
			break;
		fwrite(buff,1,i,df);
	}
	fclose(df);
//	recv(sock,buff,8,0);
	printf(buf);
	closesocket(sock);
	
	HANDLE phBitmap = (HBITMAP)LoadImage( NULL,"c:\\bitmap20.bmp" , IMAGE_BITMAP, 0, 0,LR_DEFAULTSIZE | LR_LOADFROMFILE );

  //  GetObject(phBitmap, sizeof(BITMAP), &bm );
	
//	MemDC.CreateCompatibleDC(NULL);
//	MemDC.SelectObject(&bm);


	
bmp->SetBitmap((HBITMAP)phBitmap);
	bmp->UpdateWindow ();
	
	
	
//goto skip;	
//x:
//spyLog.AddString("Please choose a machine first by using Machine Scan button");
//skip: ;

}
void CSpyView::OnTreeGen() {}
void CSpyView::MyRT2Click() {
	HTREEITEM ht;
	CString txt;
	if(ls2fl==0 && rt5fl==0) goto error;
	ht=Mctree.GetSelectedItem();
	 txt=Mctree.GetItemText(ht);
	if(txt.Find(anistr)==-1) {
	DeleteProc(txt);
	if(killChk!=1)
		Mctree.DeleteItem(ht);
		killChk=0;
	}
	//fl=1;
	//CListBox spyLog;
goto skip;
error:
spyLog.AddString("Please select a process first by generating the process list");
skip: ;
}
void CSpyView::MyRT3Click() {
//used for database access check......manually configured	
	SpyAppln();
}

void CSpyView::SpyAppln() {
	CDatabase xx;
	CString ab;
	xx.Open("ODBC;DSN=ProcInfo");
	CString z1;
	CRecordset dbSQL(&xx);
	dbSQL.Open(CRecordset::forwardOnly,"select NProcess from Info");
	while(!dbSQL.IsEOF()) {
	CString xy;
	dbSQL.GetFieldValue("NProcess",xy);
	dbSQL.MoveNext();
	if(!xy.IsEmpty()) {
	z1=Mctree.DefSearchNDelete(xy);
	}
	if(!z1.IsEmpty()) {
		AfxMessageBox(z1);
	DeleteProc(z1);
	}
	}
}
CString CSpyView::SpyGetIPText() {
BYTE ip1,ip2,ip3,ip4;
CString txt;
AfxMessageBox(txt);
return "";
}
//Machine Scan and Pinging

void CSpyView::MyLS1Click() {
ls1fl=1;
rt4fl=0;
rt5fl=0;
//Method for initalizaing basic controls to be used 
TreeSync();
CString txt;
spy_sc.GetWindowText(txt);
if(!strcmp(txt,"0.0.0.0")) 
{
	spyLog.AddString("Please enter the IP addresses");
	return;
}
char s=txt.GetAt(txt.GetLength()-1);
int lim1=s-48;
spy_dc.GetWindowText(txt);
if(!strcmp(txt,"0.0.0.0")) {
	spyLog.AddString("Please enter the IP addresses");
	return;
}
s=txt.GetAt(txt.GetLength()-1);
int lim2=s-48;
char str[125];
strcpy(str,anistr);
char tmp[10];
int k=0;

for(int i=lim1;i<=lim2;i++) {
_itoa(i,tmp,10);
strcat(str,tmp);
strcat(pingbuf,str);
strcat(pingbuf,"!");

myPing[k++].Ping(1,str,this->m_hWnd);
strcpy(str,anistr);
}
strcat(pingbuf,"#\0");


char lbuf[100];
int pi=0;
int jj=0;
while(pingbuf[pi]!='#') {
	while(pingbuf[pi]!='!' && pingbuf[pi]!='#') {
	    lbuf[jj++]=pingbuf[pi++];
	}
	lbuf[jj]='\0';
	Mctree.DefInsert(lbuf);
	strcpy(lbuf,"");
	jj=0;
	pi++;
	}
//Mctree.DefInsert("192.168.1.1");
//a_pingThread[k++].StartPing(1,"192.168.1.1",this->m_hWnd);
strcpy(pingbuf,"");
int mcn=Mctree.DefGetCount();
char tm[10];
_itoa(mcn,tm,10);
for(int pingi=0;pingi<mcn;pingi++) {
cpingStatus[pingi]="Analyzing Activity....";
pingStatus.AddString(cpingStatus[pingi]);
}
}
void CSpyView::SocketComm(CString name,int len,CString proc) {
sock=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	memset((void*)&sockad,0,sizeof(sockad));
	sockad.sin_addr.S_un.S_addr=inet_addr(machine);
	sockad.sin_port=htons(4444);
	sockad.sin_family =AF_INET;
	int c=0;
	CString procmsg;
	strcpy(mfbuf,"");strcpy(buf,"");
	i=connect(sock,(SOCKADDR*) &sockad,sizeof(sockad));
	if(i!=0)
	{
	
		spyLog.AddString("Cannot Connect....................Please Check the Client Program");
		goto SKIP;
	}
	send(sock,name,len,0);
	
	if(proc!="Animesh") {
		send(sock,proc,9,0);
		recv(sock,buf,100,0);
		while(buf[c++]!='!');
		buf[c-1]='\0';
		if(!strcmpi(buf,"failure: Unable to close application"))
			killChk=1;
		spyLog.AddString(buf);
		spy=fopen("C:\\log.txt","a");
		fprintf(spy,"%s!",buf);
		fclose(spy);
	}
	
	
	while(1)
	{
		i=recv(sock,buf,300,0);
		buf[i]=0;
		strcat(mfbuf,buf);
		if(i==0)
			break;
	}
	::closesocket(sock);
SKIP:
	strcat(mfbuf,"##");
}
void CSpyView::GetProcList(CString mac) {
	machine="";	
	machine.Format(c_mac);
	if(!mac.IsEmpty()) {
		machine.Format(mac);
	}
	Mctree.DeleteAllItems();
	SocketComm("GETPROCESS",11);
	MakeGUI(1);
}
//Prints process listing
void CSpyView::MyLS2Click() {
	CString temp;
	if(ls1fl==0) goto error;
	ls2fl=1;
pingStatus.DestroyWindow();
c->SetWindowText("");
c->SetWindowText("Starting Scan Please Wait.......");
::Sleep(1000);


c->SetWindowText(machine+"\n "+"Getting Process List....");
::Sleep(2000);
GetProcList();

goto skip;
error:spyLog.AddString("Please Choose a machine first");
skip: ;
ls1fl=0;
}
void CSpyView::MyLS3Click() {
	DeleteALL();
	rdspy=fopen("C:\\log.txt","r");
		char ss[1000];
		strcpy(ss,"");
		int x=0;
		char ch=fgetc(rdspy);
		int xx=spyLog.GetCount();
		while(ch!=EOF) {
			while(ch!='!' && ch!=EOF) {
				ss[x++]=ch;
				ch=fgetc(rdspy);
			}
			ss[x]='\0';
			spyLog.AddString(ss);
			
			strcpy(ss,"");
			x=0;
			ch=fgetc(rdspy);
		}
		
		fclose(rdspy);
}
void CSpyView::MyLS4Click() {
spy_help.DoModal();
}

void CSpyView::DeleteProc(CString item) {
CString txt=item;
int len=txt.GetLength();
	char str[125];
	strcpy(str,"");
	strcat(str,"0000");
	int k=0;
	for(int i=0;i<len;i++) {
		if(txt.GetAt(i)>=48 && txt.GetAt(i)<=57)
			str[k++]=txt.GetAt(i);
	}
	str[k]='\0';
	SocketComm("KILLPROCESS",12,str);
}
//print status quo
int CSpyView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	c=new CStatic;
	log=new CStatic;
	bmp=new CStatic;
	c->Create("SpyMAC",WS_CHILD|WS_VISIBLE|WS_OVERLAPPED  ,CRect(178+450,320,988,400),this,12322);
	bmp->Create("SpyMAC",WS_CHILD|WS_VISIBLE|WS_OVERLAPPED |SS_BITMAP|SS_REALSIZEIMAGE |SS_NOTIFY   ,CRect(178+450,400,988,695),this,12323);

	log->Create("SpyMAC",WS_CHILD|WS_VISIBLE|WS_OVERLAPPED,CRect(175,205,988,310),this,4578);

	spy_sc.Create(WS_CHILD|WS_VISIBLE,CRect(180,153,580,177),this,1123);
	spy_dc.Create(WS_CHILD|WS_VISIBLE,CRect(590,153,990,177),this,1124);
	spyLog.Create(LBS_HASSTRINGS|LBS_STANDARD|WS_CHILD|WS_VISIBLE,CRect(175,205,988,310),this,34561);
	
	my2.Create(NULL,WS_CHILD|WS_VISIBLE|BS_OWNERDRAW, CRect(0,0,60,60),this,1);
	my3.Create(NULL,WS_CHILD|WS_VISIBLE|BS_OWNERDRAW, CRect(350+160,0,60,60),this,RTOP1);
	my4.Create(NULL,WS_CHILD|WS_VISIBLE|BS_OWNERDRAW, CRect(450+160,0,60,60),this,RTOP2);
	my5.Create(NULL,WS_CHILD|WS_VISIBLE|BS_OWNERDRAW, CRect(550+160,0,60,60),this,RTOP3);
	my9.Create(NULL,WS_CHILD|WS_VISIBLE|BS_OWNERDRAW, CRect(650+160,0,60,60),this,RTOP4);
	my10.Create(NULL,WS_CHILD|WS_VISIBLE|BS_OWNERDRAW, CRect(750+160,0,60,60),this,RTOP5);
	
	my1.Create(NULL,WS_CHILD|WS_VISIBLE|BS_OWNERDRAW, CRect(0,92,60,60),this,LSIDE1);
	my6.Create(NULL,WS_CHILD|WS_VISIBLE|BS_OWNERDRAW, CRect(0,125,60,60),this,LSIDE2);
	my7.Create(NULL,WS_CHILD|WS_VISIBLE|BS_OWNERDRAW, CRect(0,160,60,60),this,LSIDE3);
	my8.Create(NULL,WS_CHILD|WS_VISIBLE|BS_OWNERDRAW, CRect(0,190,60,60),this,LSIDE4);
	
	my1.LoadBitmaps(IDB_BITMAP3,156);
	my2.LoadBitmaps(173);
	my3.LoadBitmaps(IDB_BITMAP9,179);
	my4.LoadBitmaps(IDB_BITMAP11,179);
	my5.LoadBitmaps(IDB_BITMAP19,179);
	my9.LoadBitmaps(IDB_BITMAP9,179);
	my10.LoadBitmaps(IDB_BITMAP9,179);

	my6.LoadBitmaps(IDB_BITMAP14,IDB_BITMAP13);
	my7.LoadBitmaps(IDB_BITMAP16,IDB_BITMAP15);
	my8.LoadBitmaps(IDB_BITMAP17,IDB_BITMAP18);
	
	my1.SizeToContent();
	my2.SizeToContent();
	my3.SizeToContent();
	my4.SizeToContent();
	my5.SizeToContent();
	my6.SizeToContent();
	my7.SizeToContent();
	my8.SizeToContent();
	my9.SizeToContent();
	my10.SizeToContent();
	return 0;
}
void CSpyView::MyRT4Click() {
//	CFileDialog spy_list;
CString filName;
spy_list->DoModal();
filName=spy_list->GetPathName();

ListSync();
CString txt;
char tmp[10];
spy_sc.GetWindowText(txt);
if(!strcmp(txt,"")) return ;
char s=txt.GetAt(txt.GetLength()-1);
int lim1=s-48;
spy_dc.GetWindowText(txt);
if(!strcmp(txt,"")) return ;
s=txt.GetAt(txt.GetLength()-1);
int lim2=s-48;
char str[125];
strcpy(str,anistr);
int k=0;
for(int i=lim1;i<=lim2;i++) {
_itoa(i,tmp,10);
strcat(str,tmp);
strcat(pingbuf,str);
machine.Format(str);
	SocketComm("GETPROCESS",11);
	MakeGUI(2);
	//MyList procs;
	if(procs.GetCount()==1) rt4fl=0;
strcpy(str,anistr);

}
spy_proc=fopen(filName,"a");
				

for(int j=0;j<procs.GetCount();j++) {
	CString item;
	item=procs.MyGet(j);
	fprintf(spy_proc,"%s\n",item);
	}
AfxMessageBox("Information has been saved in the file");
fclose(spy_proc);
}

void CSpyView::MyRT5Click() {
	//MyList procs;
	int mcsel;
	CString itm;
		int j=0,k=0;
	if(rt4fl==0) goto error;
	mcsel=procs.GetCurSel();
	if(mcsel==LB_ERR)
		goto error;
	procs.GetText(mcsel,itm);
	AfxMessageBox(itm);
	if(itm.IsEmpty())
		goto error;
	machine.Format(itm);
//	AfxMessageBox(machine);
	TreeSync();
	pingStatus.DestroyWindow();
	GetProcList(itm);
	rt4fl=0;
	rt5fl=1;
	
	goto skip;
error: spyLog.AddString("Please select a machine first");
skip: ;
}
void CSpyView::OnTimer(UINT nIDEvent) 
{
//refreshes the process list and terminates illegal process by looking up the database
	GetProcList();
	SpyAppln();
	CView::OnTimer(nIDEvent);
}
//Makes the Tree structure
void CSpyView::MakeGUI(int treeOrproc) {
	char buffer[2000];
	int j=0,k=0;
	if(treeOrproc==2)
		procs.MyAdd(machine,machine);
	strcpy(buffer,"");
		while(mfbuf[j]!='#') {
        		while(mfbuf[j]!='!' && mfbuf[j]!='#') {
				buffer[k++]=mfbuf[j++];
				}
					buffer[k]='\0';
					k=0;
					buffer[0]=' ';
					if(treeOrproc==1)
					Mctree.DefInsert(buffer);
					else {
						if(strcmpi(buffer,"")) {
						procs.MyAdd(buffer);
						}
					}
					
					strcpy(buffer,"");
				j++;
		}
}
//synchronizes access
void CSpyView::ListSync() {
	Mctree.DestroyWindow();
	pingStatus.DestroyWindow();
	procs.DestroyWindow();
	procs.Create(WS_CHILD|WS_VISIBLE|LBS_MULTICOLUMN,CRect(178,320,580,680),this,12222);		
	procs.SetColumnWidth(220);
	procs.ResetContent();
	
}
//synchronizes access
void CSpyView::TreeSync() {
procs.DestroyWindow();
pingStatus.DestroyWindow();
Mctree.DestroyWindow();
Mctree.Create(WS_VISIBLE | WS_TABSTOP | WS_CHILD
   | TVS_HASBUTTONS | TVS_LINESATROOT | TVS_HASLINES
   | TVS_DISABLEDRAGDROP,CRect(178,320,600,600),this,IDC_MYTREE);   
pingStatus.Create(WS_VISIBLE|WS_CHILD|LBS_HASSTRINGS|LBS_MULTIPLESEL,CRect(478,320,600,600),this,7245);
strcpy(pingbuf,"");
Mctree.ResetCount();
machine="";
}
void DisplayBitmap(CDC *PDC,CBitmap *PBitmap,int X,int Y,int Wid=0,int Hig=0) {
BITMAP BM;
CDC MemDC;
MemDC.CreateCompatibleDC(NULL);
MemDC.SelectObject(PBitmap);
PBitmap->GetObject(sizeof(BM),&BM);
if(Wid==0) {
Wid=BM.bmWidth;
Hig=BM.bmHeight;
}
PDC->BitBlt(X,Y,Wid,Hig,&MemDC,0,0,SRCCOPY);
}

BOOL CSpyView::PreCreateWindow(CREATESTRUCT& cs)
{return CView::PreCreateWindow(cs);}
void CSpyView::OnDraw(CDC* pDC)
{
	DisplayBitmap(pDC,&bt,0,0);
	pDC->DrawText("SpyMac Display",CRect(180,320,290,350),0);	
}

// Useless functions just to satisfy the base class
BOOL CSpyView::OnPreparePrinting(CPrintInfo* pInfo)
{return DoPreparePrinting(pInfo);}

void CSpyView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{}

void CSpyView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{}

#ifdef _DEBUG
void CSpyView::AssertValid() const
{CView::AssertValid();}

void CSpyView::Dump(CDumpContext& dc) const
{CView::Dump(dc);}

CSpyDoc* CSpyView::GetDocument() 
{ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSpyDoc)));
	return (CSpyDoc*)m_pDocument;}
#endif //_DEBUG
//initialize the buttons and all gui controls when focus is there.....this occurs only once
//by using a flag variable
void CSpyView::OnSetFocus(CWnd* pOldWnd) 
{
	CView::OnSetFocus(pOldWnd);
			
}
void CSpyView::refresh() {}void CSpyView::listRefresh() {
//used for recording status of pinged machines
pingStatus.ResetContent();
for(int i=0;i<Mctree.DefGetCount();i++) {
pingStatus.AddString(cpingStatus[i]);
}
}
//Destructor not used
CSpyView::~CSpyView(){}
void CSpyView::DeleteALL() {
	spyLog.ResetContent();	
}
