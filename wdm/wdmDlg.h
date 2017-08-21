
// wdmDlg.h : 头文件
//

#pragma once
#include "ConTabCtrl.h"

// CwdmDlg 对话框
class CwdmDlg : public CDialogEx
{
// 构造
public:
	CwdmDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_WDM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClickedExtract();
	afx_msg void OnUpdateExtract(CCmdUI* pCmdUI);
	CConTabCtrl m_tab;
	CString m_strUrl;
	int m_nThreshold;
	BOOL m_bTagWindow;
	BOOL m_bBlock;
	afx_msg void OnBnClickedBlock();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedButton1();
};
