#pragma once

#ifdef _WIN32_WCE
#error "CDHtmlDialog is not supported for Windows CE."
#endif 

// CHtmlDlg dialog

class CHtmlDlg : public CDHtmlDialog
{
	DECLARE_DYNCREATE(CHtmlDlg)

public:
	CHtmlDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CHtmlDlg();
// Overrides
	//HRESULT OnButtonOK(IHTMLElement *pElement);
	//HRESULT OnButtonCancel(IHTMLElement *pElement);

// Dialog Data
	enum { IDD = IDD_HTML, IDH = IDR_HTML_HTMLDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
	DECLARE_DHTML_EVENT_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void PostNcDestroy();
};
