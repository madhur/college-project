#if !defined(AFX_DEFTREE_H__DE2C07C4_9330_42B3_B880_E2FC0234BABE__INCLUDED_)
#define AFX_DEFTREE_H__DE2C07C4_9330_42B3_B880_E2FC0234BABE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DefTree.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DefTree window

class DefTree : public CTreeCtrl
{
// Construction
private:
	HTREEITEM root;
	int flag,count;
	char ccount[10];
	//CMap<CString,CString,int,int> myMap(100);
	CMapStringToString map;  
public:
	DefTree();
	
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DefTree)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~DefTree();
	HTREEITEM GetRoot();
	void DefInsert(CString item);
	int MyDelete(CString item);
	CString DefSearchNDelete(CString item);
	int GetIndex(CString item);
	int DefGetCount();
	int ResetCount();
	// Generated message map functions
protected:
	//{{AFX_MSG(DefTree)
		// NOTE - the ClassWizard will add and remove member functions here.
	
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEFTREE_H__DE2C07C4_9330_42B3_B880_E2FC0234BABE__INCLUDED_)
