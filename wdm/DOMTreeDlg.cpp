// DOMTreeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "wdm.h"
#include "DOMTreeDlg.h"
#include "afxdialogex.h"


// CDOMTreeDlg dialog

IMPLEMENT_DYNCREATE(CDOMTreeDlg, CDialogEx)

CDOMTreeDlg::CDOMTreeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDOMTreeDlg::IDD, pParent)
{

}

CDOMTreeDlg::~CDOMTreeDlg()
{
}

void CDOMTreeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DOMTREE, m_tree);
}


BEGIN_MESSAGE_MAP(CDOMTreeDlg, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CDOMTreeDlg message handlers


void CDOMTreeDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	if ( m_tree.GetSafeHwnd() )
	{
		CRect rect;
		GetWindowRect(&rect);

		rect.DeflateRect(2,2,2,4);
		ScreenToClient(&rect);
		m_tree.MoveWindow(rect);
	}
}


BOOL CDOMTreeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CDOMTreeDlg::PostNcDestroy()
{
	// TODO: Add your specialized code here and/or call the base class
	delete this;

	CDialogEx::PostNcDestroy();
}
void CDOMTreeDlg::ShowDOMTree(const CString& strHtml)
{
	TidyDoc doc = tidyCreate();
	tidySetCharEncoding(doc,"raw");
	tidyOptSetBool( doc, TidyXhtmlOut, yes );	

	tidyParseString( doc, strHtml);           // Parse the input
	tidyCleanAndRepair( doc );    

	m_tree.DeleteAllItems();
	InsertTree(doc,tidyGetHtml(doc),m_tree);

	tidyRelease(doc);
}
void CDOMTreeDlg::InsertTree(TidyDoc doc,TidyNode node,CTreeCtrl& tree,HTREEITEM hParent /* = TVI_ROOT */)
{
//	ctmbstr n = tidyNodeGetName(node);
    HTREEITEM nItem = tree.InsertItem(CJUtility::GetNodeText(doc,node,FALSE),hParent);	

	for(TidyNode child = tidyGetChild(node);child;child = tidyGetNext(child))
		InsertTree(doc,child,tree,nItem);

	if(hParent == TVI_ROOT)
		tree.Expand(nItem,TVE_EXPAND);	
}

