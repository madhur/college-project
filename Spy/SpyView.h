// SpyView.h : interface of the CSpyView class
//
/////////////////////////////////////////////////////////////////////////////
#include "MySpy.h"
#include "SpyHelp.h"
#include "pingthread.h"
#include "DefTree.h"
#include "MsgWindow.h"
#include "MyList.h"
#if !defined(AFX_SPYVIEW_H__360AD053_D8CA_4C88_8E9A_CD940542C0EF__INCLUDED_)
#define AFX_SPYVIEW_H__360AD053_D8CA_4C88_8E9A_CD940542C0EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

const char anistr[]="192.168.0.";
class CSpyView : public CView
{
public:
	//CListBox list1,list2,list3;
	
protected:
	CBitmap bt,spy_snap;
	BITMAP bm;
	HBITMAP *phBitmap;
	CBitmapButton my1,my2,my3,my4,my5,my6,my7,my8,my9,my10;
	CBrush brx;HANDLE xx;
	int rt1fl,rt2fl,rt3fl,rt4fl,rt5fl,ls1fl,ls2fl,ls3fl,ls4fl;
	//CWnd* pWnd;
	//CDC* MyDC;
	MySpy mySt;int fl;
	CDatabase dbObj;
	DefTree Mctree;
	MsgWindow* myWnd;
	CString lval,cpingStatus[100];
	CStatic *c,*log,*bmp;
	CPingThread m_pingThread;

	CPingThread a_pingThread[255];
	CPing myPing[255];
	CString c_mac;
	CString machine;
	SpyHelp spy_help;
	CIPAddressCtrl spy_sc,spy_dc;
	CFileDialog* spy_list;
	CComboBox sc,dc;
	CListBox spyLog,pingStatus;
	CListBox procList[100];int procNum;
	MyList procs;

	CDC *gDC;
	FILE *spy;
	FILE *rdspy;
	FILE *spy_proc;
	char buf[2000];int killChk;
	char mfbuf[2000];
	char pingbuf[2000];int pingcn;
	SOCKET sock;
	sockaddr_in sockad,newsockad;
	int i,cnt;
	
		WSADATA wsadata;
	CString SpyGetIPText();
	void listRefresh();
	void DeleteALL();
	void refresh();
	void DeleteProc(CString);
	void SocketComm(CString,int,CString proc="Animesh");
	void SpyAppln();
	void GetProcList(CString mac="");
	void TreeSync();
	void ListSync();
	void MakeGUI(int);
protected: // create from serialization only
	CSpyView();
	DECLARE_DYNCREATE(CSpyView)

// Attributes
public:
	CSpyDoc* GetDocument();

	int flag;
	int flg;
// Operations
public:
	

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpyView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSpyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSpyView)
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void MyRT1Click();
	afx_msg void MyRT2Click();
	afx_msg void MyRT3Click();
	afx_msg void MyRT4Click();
	afx_msg void MyRT5Click();
	afx_msg void MyLS1Click();
	afx_msg void MyLS2Click();
	afx_msg void MyLS3Click();
	afx_msg void MyLS4Click();
	afx_msg void MyIPClick();
	afx_msg void Mybmp();
	afx_msg void TNotify(NMTREEVIEW* p,LRESULT *result);
	afx_msg void OnPingEnd(WPARAM wParam,LPARAM lParam);
	afx_msg void OnTreeGen();
	afx_msg void OnRequestTimedOut(WPARAM wParam,LPARAM lParam);
//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SpyView.cpp
inline CSpyDoc* CSpyView::GetDocument()
   { return (CSpyDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPYVIEW_H__360AD053_D8CA_4C88_8E9A_CD940542C0EF__INCLUDED_)
