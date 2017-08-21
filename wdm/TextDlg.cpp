// TextDlg.cpp : implementation file
//

#include "stdafx.h"
#include "wdm.h"
#include "TextDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
// CTextDlg dialog

IMPLEMENT_DYNCREATE(CTextDlg, CDialogEx)

CTextDlg::CTextDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTextDlg::IDD, pParent)
{

}

CTextDlg::~CTextDlg()
{
}

void CTextDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TEXT, m_edit);
}


BEGIN_MESSAGE_MAP(CTextDlg, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CTextDlg message handlers


void CTextDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	if ( m_edit.GetSafeHwnd() )
	{
		CRect rect;
		GetWindowRect(&rect);

		rect.DeflateRect(2,2,2,4);
		ScreenToClient(&rect);
		m_edit.MoveWindow(rect);
	}
}


void CTextDlg::PostNcDestroy()
{
	// TODO: Add your specialized code here and/or call the base class
	delete this;

	CDialogEx::PostNcDestroy();
}

