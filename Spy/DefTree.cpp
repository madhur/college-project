// DefTree.cpp : implementation file
//

#include "stdafx.h"
#include "Spy.h"
#include "DefTree.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DefTree

DefTree::DefTree()
{
	//CMap<CString,CString,int,int> myMap;
	

flag=count=0;
flag++;
}
int DefTree::ResetCount() {
count=0;
return 0;
}
void DefTree::DefInsert(CString item) {
	if(flag==1) {
root=DefTree::InsertItem(item,0,0);
//index[cnt++]=count;
//myMap.SetAt(item,count++);
_itoa(count,ccount,10);
map.SetAt(item,ccount);
//AfxMessageBox(ccount);
	}
	else {
DefTree::InsertItem(item,0,0); 
	//index[cnt++]=count;
//myMap.SetAt(item,count++);
_itoa(count,ccount,10);
map.SetAt(item,ccount);
}
++flag;
++count;
}
int DefTree::GetIndex(CString item) {
	
	CString pa;
	map.Lookup(item,pa);
	return atoi(pa);
}

int DefTree::MyDelete(CString item) {
HTREEITEM proc_handler=root;
	CString comp_handler;
		CString ret_value;
	//AfxMessageBox(item);
	for(int i=0;i<count;i++) {
	proc_handler = DefTree::GetNextItem(proc_handler, TVGN_NEXT);
	comp_handler=DefTree::GetItemText(proc_handler);		
	//AfxMessageBox(item+"!"+comp_handler);
 	int y=comp_handler.Find(item);
	if(y!=-1) {
		DefTree::DeleteItem(proc_handler);
		return 1;

		//AfxMessageBox("here"+comp_handler);
	}
}
return 0;
}
int DefTree::DefGetCount() {
return count;
}

CString DefTree::DefSearchNDelete(CString item) {
	HTREEITEM proc_handler=root;
	CString comp_handler;
	CString ret_value;
	//AfxMessageBox(item);
	//BOOL xx=DefTree::ItemHasChildren(proc_handler);
	
	/*
	proc_handler=DefTree::GetNextItem(proc_handler,TVGN_NEXTVISIBLE);
	AfxMessageBox(DefTree::GetItemText(proc_handler));
	proc_handler=DefTree::GetNextItem(proc_handler,TVGN_NEXTVISIBLE);
	AfxMessageBox(DefTree::GetItemText(proc_handler));*/
	for(int i=0;i<count;i++) {
	proc_handler = DefTree::GetNextItem(proc_handler, TVGN_NEXT);
	comp_handler=DefTree::GetItemText(proc_handler);		
	//AfxMessageBox("AAA");
	int y=comp_handler.Find(item);
	if(y!=-1) {
		DefTree::DeleteItem(proc_handler);
		ret_value.Insert(0,comp_handler);
		//AfxMessageBox("here"+comp_handler);
	}
				
	}
	
	return ret_value;	


	/*while(DefTree::ItemHasChildren(proc_handler)) {
	proc_handler=DefTree::GetChildItem(proc_handler);
	comp_handler=DefTree::GetItemText(proc_handler);
	AfxMessageBox(comp_handler);
	}*/


}

HTREEITEM DefTree::GetRoot() {
return root;
}

DefTree::~DefTree()
{
	
}




BEGIN_MESSAGE_MAP(DefTree, CTreeCtrl)
	//{{AFX_MSG_MAP(DefTree)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
	
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DefTree message handlers
