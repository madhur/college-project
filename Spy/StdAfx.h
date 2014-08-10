

#if !defined(AFX_STDAFX_H__2F9FA3A9_3C15_436E_B976_A1C19DB5D5D5__INCLUDED_)
#define AFX_STDAFX_H__2F9FA3A9_3C15_436E_B976_A1C19DB5D5D5__INCLUDED_

// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//
//
/////////////////////////////////////////////////////////////////////////////
//
//
/////////////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#include <afxdb.h>	
#include <Afxtempl.h>

#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

//#define _ICMP_Ping
#define WM_MSG_ANITIMER	0x100+4
#ifndef _ICMP_Ping
#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#endif

///////////////////////////////////////////////////////////////////////////
// Macros

#define _countof(array) (sizeof(array)/sizeof(array[0]))

///////////////////////////////////////////////////////////////////////////
// ToBool

template<class T>
inline bool ToBool(T boolValue)
{
	return boolValue != 0;
}
#include <afxsock.h>		// MFC socket extensions

#define WM_MSG_STATUS	WM_USER + 0x0100
#define WM_PING_END		WM_USER + 0x0101
#define WM_MSG_STATS	WM_USER + 0x0102
#define WM_MSG_MYCPING	WM_USER + 0x0103





// string message allocator for posting messages between windows...
static char* AllocBuffer(CString strMsg)
{

	int nLen = strMsg.GetLength();
	char *pBuffer = new char[nLen+1]; 
	
	strcpy(pBuffer,(const char*)strMsg);

	ASSERT(pBuffer != NULL);
	return pBuffer;
}

///////////////////////////////////////////////////////////////////////////
// Application messages

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__2F9FA3A9_3C15_436E_B976_A1C19DB5D5D5__INCLUDED_)
