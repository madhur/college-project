// server.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
int main(int argc, char* argv[])
{
	char buf[100];
	printf("Hello World!\n");
	
	
	SOCKET sock;
	sockaddr_in sockad,newsockad;
	int i;
	
		WSADATA wsadata;
	i=WSAStartup(2,&wsadata);
	if(i!=0)
	{
		MessageBox(0,"Winsock Error","Beller",MB_ICONSTOP);
		return 0;
	}
	if(wsadata.wVersion !=2)
	{
		MessageBox(0,"Older Winsock version","Beller",MB_ICONSTOP);
		return 0;
	}

	sock=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	memset((void*)&sockad,0,sizeof(sockad));
	sockad.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
	sockad.sin_port=htons(4444);
	sockad.sin_family =AF_INET;
	i=connect(sock,(SOCKADDR*) &sockad,sizeof(sockad));
	
	if(i!=0)
	{
		MessageBox(0,"Cannot connect","Beller",MB_ICONSTOP);
		ExitProcess(0);
	}
	
	
	send(sock,"GETPROCESS",11,0);
	while(1)
	{
		i=recv(sock,buf,39,0);
		buf[i]=0;
		if(i==0)
			break;
		printf(buf);
	}
	closesocket(sock);

	sock=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	i=connect(sock,(SOCKADDR*) &sockad,sizeof(sockad));
	if(i!=0)
	{
		MessageBox(0,"Cannot connect","Beller",MB_ICONSTOP);
		ExitProcess(0);
	}

//- ------------------------------------------
	//send(sock,"KILLPROCESS",12,0);
	//buf[21]=0;
	//send(sock,buf,9,0);
	//recv(sock,buf,8,0);
	//i=strcmp(buf,"SUCCESS");
	//if(i==0)
	//	printf("terminated\n");
	//else
	//	printf("failure\n");
//---------------------------------------------

	send(sock,"GETSNAP",8,0);
	
	char buff[1000];
	FILE *df=fopen("snap.jpg","wb");
	while(1)
	{
		i=recv(sock,buff,1000,0);
		if(i==0)
			break;

		fwrite(buff,1,i,df);
	}
	fclose(df);

	recv(sock,buff,8,0);
	printf(buf);



	closesocket(sock);
	
	//i=sizeof(newsockad);
	return 0;
}

