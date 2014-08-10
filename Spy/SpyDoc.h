// SpyDoc.h : interface of the CSpyDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPYDOC_H__5418DD84_A806_4677_A6EC_23B9A0F6E4B2__INCLUDED_)
#define AFX_SPYDOC_H__5418DD84_A806_4677_A6EC_23B9A0F6E4B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSpyDoc : public CDocument
{
protected:
	CButton my2;

protected: // create from serialization only
	CSpyDoc();
	DECLARE_DYNCREATE(CSpyDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpyDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSpyDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSpyDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPYDOC_H__5418DD84_A806_4677_A6EC_23B9A0F6E4B2__INCLUDED_)
