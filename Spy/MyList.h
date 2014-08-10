#if !defined(AFX_MYLIST_H__1BE83B54_6F0E_4D46_9C26_620FDBDF9DEA__INCLUDED_)
#define AFX_MYLIST_H__1BE83B54_6F0E_4D46_9C26_620FDBDF9DEA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyList.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// MyList window

class MyList : public CListBox
{
// Construction
public:
	MyList();
	int count;
	CString machine;
	int anchors[10];
	CString anchorval[10];
	CMapStringToString map; 
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(MyList)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~MyList();
	void MyAdd(CString item,CString mac="");
	void MyCheck(CString item);
	CString MyGet(int pos);
	void MyMcGet(CString item);
	

	// Generated message map functions
protected:
	//{{AFX_MSG(MyList)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYLIST_H__1BE83B54_6F0E_4D46_9C26_620FDBDF9DEA__INCLUDED_)
