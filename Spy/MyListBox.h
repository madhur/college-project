#if !defined(AFX_MYLISTBOX_H__F9B8C4FC_40E6_426B_BD79_E5ED179C74A7__INCLUDED_)
#define AFX_MYLISTBOX_H__F9B8C4FC_40E6_426B_BD79_E5ED179C74A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyListBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// MyListBox window

class MyListBox : public CListBox
{
// Construction
public:
	MyListBox();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(MyListBox)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~MyListBox();

	// Generated message map functions
protected:
	//{{AFX_MSG(MyListBox)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYLISTBOX_H__F9B8C4FC_40E6_426B_BD79_E5ED179C74A7__INCLUDED_)
