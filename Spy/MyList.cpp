// MyList.cpp : implementation file
//

#include "stdafx.h"
#include "MyList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// MyList

MyList::MyList()
{
	count=0;
}
CString MyList::MyGet(int pos) {
	CString rt;
	this->GetText(pos,rt);
	return rt;
}
void MyList::MyCheck(CString item) {
	


}
void MyList::MyMcGet(CString item) {
	CString temp;
	this->map.Lookup(item,temp);
	AfxMessageBox(temp);
	
}

void MyList::MyAdd(CString item,CString mac) {
this->AddString(item);
map.SetAt(item+"!"+machine,machine);
if(!mac.IsEmpty()) {
	//anchorval[count++].Format(item);
	machine.Format(mac);
}
}

MyList::~MyList()
{


}



BEGIN_MESSAGE_MAP(MyList, CListBox)
	//{{AFX_MSG_MAP(MyList)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// MyList message handlers
