// MySpy.cpp : implementation file
//

#include "stdafx.h"
#include "Spy.h"
#include "MySpy.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// MySpy

IMPLEMENT_DYNCREATE(MySpy, CView)


MySpy::MySpy()
{
	bct.LoadBitmap(176);


}

MySpy::~MySpy()
{
}


BEGIN_MESSAGE_MAP(MySpy, CView)
	//{{AFX_MSG_MAP(MySpy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// MySpy drawing


/////////////////////////////////////////////////////////////////////////////
// MySpy diagnostics

#ifdef _DEBUG
void MySpy::AssertValid() const
{
	CView::AssertValid();
}

void MySpy::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// MySpy message handlers
void MyDisplayBitmap(CDC *PDC,CBitmap *PBitmap,int X,int Y) {
BITMAP BM;
CDC MemDC;
MemDC.CreateCompatibleDC(NULL);
MemDC.SelectObject(PBitmap);
PBitmap->GetObject(sizeof(BM),&BM);
PDC->BitBlt(X,Y,BM.bmWidth,BM.bmHeight,&MemDC,0,0,SRCCOPY);

}

void MySpy::OnDraw(CDC* pDC) 
{

// TODO: Add your specialized code here and/or call the base class
//pDC->Ellipse(CRect(0,0,100,100));
//pDC->FillRect(CRect(0,0,100,23),(WHITE_BRUSH));
//if(fg==1)
//return;

//MyDisplayBitmap(pDC,&bct,0,0);
//fg=1;


	
}
