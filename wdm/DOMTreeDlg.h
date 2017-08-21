#pragma once

#include "JTreeCtrl.h"
// CDOMTreeDlg dialog

class CDOMTreeDlg : public CDialogEx
{
	DECLARE_DYNCREATE(CDOMTreeDlg)

public:
	CDOMTreeDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDOMTreeDlg();

// Dialog Data
	enum { IDD = IDD_DOMTREE };
	
	void ShowDOMTree(const CString& strHtml);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	void InsertTree(TidyDoc doc,TidyNode node,CTreeCtrl& tree,HTREEITEM hParent = TVI_ROOT);
	DECLARE_MESSAGE_MAP()
public:
	CJTreeCtrl m_tree;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnInitDialog();
	virtual void PostNcDestroy();
};
