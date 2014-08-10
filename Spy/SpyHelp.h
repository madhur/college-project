#if !defined(AFX_SPYHELP_H__27199828_447C_49CC_BF0D_AA5DA73DA5D7__INCLUDED_)
#define AFX_SPYHELP_H__27199828_447C_49CC_BF0D_AA5DA73DA5D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SpyHelp.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// SpyHelp dialog

class SpyHelp : public CDialog
{
// Construction
public:
	SpyHelp(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(SpyHelp)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SpyHelp)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(SpyHelp)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPYHELP_H__27199828_447C_49CC_BF0D_AA5DA73DA5D7__INCLUDED_)
