
// wdmDlg.h : ͷ�ļ�
//

#pragma once
#include "ConTabCtrl.h"

// CwdmDlg �Ի���
class CwdmDlg : public CDialogEx
{
// ����
public:
	CwdmDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_WDM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
