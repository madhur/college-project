#if !defined(AFX_MYSPY_H__54D055F2_415F_41D4_965C_A66EC73A8B02__INCLUDED_)
#define AFX_MYSPY_H__54D055F2_415F_41D4_965C_A66EC73A8B02__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MySpy.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// MySpy view

class MySpy : public CView
{
public:
	MySpy();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(MySpy)
	CBitmap bct;
	int fg;
	
	

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(MySpy)
	protected:
	virtual void OnDraw(CDC* pDC);
	//}}AFX_VIRTUAL

// Implementation
	public:
	virtual ~MySpy();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(MySpy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYSPY_H__54D055F2_415F_41D4_965C_A66EC73A8B02__INCLUDED_)
