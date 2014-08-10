// SpyDoc.cpp : implementation of the CSpyDoc class
//

#include "stdafx.h"
#include "Spy.h"

#include "SpyDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpyDoc

IMPLEMENT_DYNCREATE(CSpyDoc, CDocument)

BEGIN_MESSAGE_MAP(CSpyDoc, CDocument)
	//{{AFX_MSG_MAP(CSpyDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpyDoc construction/destruction

CSpyDoc::CSpyDoc()
{
	// TODO: add one-time construction code here
	
		
		

}

CSpyDoc::~CSpyDoc()
{
}

BOOL CSpyDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSpyDoc serialization

void CSpyDoc::Serialize(CArchive& ar)
{
	
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CSpyDoc diagnostics

#ifdef _DEBUG
void CSpyDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSpyDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSpyDoc commands
