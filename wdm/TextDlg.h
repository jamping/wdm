#pragma once


// CTextDlg dialog

class CTextDlg : public CDialogEx
{
	DECLARE_DYNCREATE(CTextDlg)

public:
	CTextDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTextDlg();

// Dialog Data
	enum { IDD = IDD_CONTENT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CRichEditCtrl m_edit;

	virtual void PostNcDestroy();
};
