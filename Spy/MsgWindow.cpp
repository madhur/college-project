// MsgWindow.cpp : implementation file
//

#include "stdafx.h"
#include "Spy.h"
#include "MsgWindow.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// MsgWindow

IMPLEMENT_DYNCREATE(MsgWindow, CView)

MsgWindow::MsgWindow()
{
}

MsgWindow::~MsgWindow()
{
}


BEGIN_MESSAGE_MAP(MsgWindow, CView)
	//{{AFX_MSG_MAP(MsgWindow)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// MsgWindow drawing

void MsgWindow::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// MsgWindow diagnostics

#ifdef _DEBUG
void MsgWindow::AssertValid() const
{
	CView::AssertValid();
}

void MsgWindow::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// MsgWindow message handlers

BOOL MsgWindow::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	
	return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}
