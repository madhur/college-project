// SpyHelp.cpp : implementation file
//

#include "stdafx.h"
#include "Spy.h"
#include "SpyHelp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// SpyHelp dialog


SpyHelp::SpyHelp(CWnd* pParent /*=NULL*/)
	: CDialog(SpyHelp::IDD, pParent)
{
	//{{AFX_DATA_INIT(SpyHelp)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void SpyHelp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(SpyHelp)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(SpyHelp, CDialog)
	//{{AFX_MSG_MAP(SpyHelp)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// SpyHelp message handlers
