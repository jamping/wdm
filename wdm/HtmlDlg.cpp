// HtmlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "wdm.h"
#include "HtmlDlg.h"


// CHtmlDlg dialog

IMPLEMENT_DYNCREATE(CHtmlDlg, CDHtmlDialog)

CHtmlDlg::CHtmlDlg(CWnd* pParent /*=NULL*/)
	: CDHtmlDialog(CHtmlDlg::IDD, 0/*CHtmlDlg::IDH*/, pParent)
{

}

CHtmlDlg::~CHtmlDlg()
{
}

void CHtmlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDHtmlDialog::DoDataExchange(pDX);
}

BOOL CHtmlDlg::OnInitDialog()
{
	SetHostFlags(DOCHOSTUIFLAG_FLAT_SCROLLBAR);

	CDHtmlDialog::OnInitDialog();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

BEGIN_MESSAGE_MAP(CHtmlDlg, CDHtmlDialog)
	ON_WM_SIZE()
END_MESSAGE_MAP()

BEGIN_DHTML_EVENT_MAP(CHtmlDlg)
	//DHTML_EVENT_ONCLICK(_T("ButtonOK"), OnButtonOK)
	//DHTML_EVENT_ONCLICK(_T("ButtonCancel"), OnButtonCancel)
END_DHTML_EVENT_MAP()



// CHtmlDlg message handlers

//HRESULT CHtmlDlg::OnButtonOK(IHTMLElement* /*pElement*/)
//{
//	OnOK();
//	return S_OK;
//}
//
//HRESULT CHtmlDlg::OnButtonCancel(IHTMLElement* /*pElement*/)
//{
//	OnCancel();
//	return S_OK;
//}


void CHtmlDlg::OnSize(UINT nType, int cx, int cy)
{
	CDHtmlDialog::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


void CHtmlDlg::PostNcDestroy()
{
	// TODO: Add your specialized code here and/or call the base class
	delete this;

	CDHtmlDialog::PostNcDestroy();
}
