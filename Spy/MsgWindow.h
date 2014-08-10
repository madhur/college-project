#if !defined(AFX_MSGWINDOW_H__2C02EA33_A667_4158_B9FA_D996A90241DB__INCLUDED_)
#define AFX_MSGWINDOW_H__2C02EA33_A667_4158_B9FA_D996A90241DB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MsgWindow.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// MsgWindow view

class MsgWindow : public CView
{
protected:
	
	DECLARE_DYNCREATE(MsgWindow)

// Attributes
public:
MsgWindow();           // protected constructor used by dynamic creation
virtual ~MsgWindow();
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(MsgWindow)
	public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation

	
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(MsgWindow)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MSGWINDOW_H__2C02EA33_A667_4158_B9FA_D996A90241DB__INCLUDED_)
