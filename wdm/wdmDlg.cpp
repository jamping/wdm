
// wdmDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "wdm.h"
#include "wdmDlg.h"
#include "afxdialogex.h"
#include "DownloadEngine.h"
#include "DownloadHttpFile.h"
#include "TextDlg.h"
#include <boost/regex/mfc.hpp>
#include "ChineseCodeLib.h"
#include "JHtmlDocument.h"
#include "TextExtractor.h"
#include "Extract.h"
#include "DOMTreeDlg.h"
#include "StopWatch.h"
#include "CharsetDetector.h"
#include "HtmlDlg.h"
#include "JUtility.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CwdmDlg 对话框




CwdmDlg::CwdmDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CwdmDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_strUrl = _T("http://news.sina.com.cn/c/2010-08-18/170720925417.shtml");
	m_nThreshold = 172;
	m_bTagWindow = TRUE;
	m_bBlock = FALSE;
}

void CwdmDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CONTENT, m_tab);
	DDX_Text(pDX, IDC_URL, m_strUrl);
	DDX_Text(pDX, IDC_THRESHOLD, m_nThreshold);
	DDX_Check(pDX, IDC_TAGWINDOW, m_bTagWindow);
	DDX_Check(pDX, IDC_BLOCK, m_bBlock);
}

BEGIN_MESSAGE_MAP(CwdmDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_CONTENT, &CwdmDlg::OnTcnSelchangeTab1)
	ON_BN_CLICKED(IDC_EXTRACT, &CwdmDlg::OnClickedExtract)
	ON_BN_CLICKED(IDC_BLOCK, &CwdmDlg::OnBnClickedBlock)
	ON_UPDATE_COMMAND_UI(IDC_EXTRACT,OnUpdateExtract)
	ON_BN_CLICKED(IDC_BUTTON1, &CwdmDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CwdmDlg 消息处理程序

BOOL CwdmDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码	
	m_tab.AddPage(_T("正文"), RUNTIME_CLASS(CTextDlg), IDD_CONTENT);
	m_tab.AddPage(_T("全文"), RUNTIME_CLASS(CTextDlg), IDD_CONTENT);
	m_tab.AddPage(_T("DOM树"), RUNTIME_CLASS(CDOMTreeDlg), IDD_DOMTREE);
	m_tab.AddPage(_T("网页原文"), RUNTIME_CLASS(CHtmlDlg), IDD_HTML);
	m_tab.AddPage(_T("精简DOM树"), RUNTIME_CLASS(CDOMTreeDlg), IDD_DOMTREE);

	m_tab.ActivePage(0);
		
	GetDlgItem(IDC_THRESHOLD)->ShowWindow((m_bBlock == FALSE)?SW_HIDE:SW_SHOW);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CwdmDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CwdmDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CwdmDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CwdmDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CwdmDlg::OnClickedExtract()
{
	// TODO: Add your control notification handler code here
	// 下载网页
	UpdateData();

	if(m_strUrl.IsEmpty())
		return;

	CWaitCursor wait;
	
	CStopWatch s;

	char* buf=NULL;
	int   nLen=-1;

	CDownloadHttpFile http;
	if( !http.Fetch(m_strUrl,&buf,nLen) || buf==NULL )
	{
		if(buf)
		{
			free(buf);
			buf=NULL;
		}
		return;
	}

	double t1 = s.Now();
	TRACE("下载网页花费时间%.6f秒\n",t1);
	// 处理数据
	// 编码转换	
	CString strBuf(buf);
	CCharsetDetector detecotr;
	charset_t ct = detecotr.GetCharset(buf,nLen);
	TRACE("The page code is %s\n",Charset::TypeToName(ct).c_str());

	switch ( ct )
	{
	case Charset::UTF_8:
		strBuf=CChineseCodeLib::Utf8ToGBK(strBuf);	
		break;
	case Charset::BIG5:
		strBuf = CChineseCodeLib::Big5ToGBK(strBuf);
		break;
	}
	
	// 清除内存
	free(buf);
	buf=NULL;	

	s.Start();
	// 提取正文
	CString strContent = strBuf;
	if( m_bTagWindow )
	{
		CJHTMLDocument html(strContent);
		html.Parse();		
		
		strContent = html.GetText();
	}
	if( m_bBlock )
	{
		std::string strIn(strContent),strOut;
		CTextExtractor te;
		te.ParseString(strIn,strOut,m_nThreshold);
		strContent = strOut.c_str();
	}
	CString str;
	str.Format("\n提取网页正文花费时间%.6f秒\n总花费时间%.6f秒",s.Now(),t1+s.Now());
	
	// 正文
	static_cast<CTextDlg*>(m_tab.GetPage(0))->m_edit.SetWindowText(strContent+str);	
	// 全文
	static_cast<CTextDlg*>(m_tab.GetPage(1))->m_edit.SetWindowText(strBuf);
	// DOM树
	static_cast<CDOMTreeDlg*>(m_tab.GetPage(2))->ShowDOMTree(/*CJUtility::FilterInvalidElements*/(strBuf));
	// 网页原文
	static_cast<CHtmlDlg*>(m_tab.GetPage(3))->Navigate(m_strUrl);	
	// 精简DOM树
	CJUtility::FilterInvalidElements(strBuf);
	static_cast<CDOMTreeDlg*>(m_tab.GetPage(4))->ShowDOMTree(strBuf);

}


void CwdmDlg::OnBnClickedBlock()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	GetDlgItem(IDC_THRESHOLD)->ShowWindow(( m_bBlock == FALSE )?SW_HIDE:SW_SHOW);
}


BOOL CwdmDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	UpdateDialogControls(this,FALSE);

	return CDialogEx::PreTranslateMessage(pMsg);
}
void CwdmDlg::OnUpdateExtract(CCmdUI* pCmdUI)
{
	UpdateData();
	pCmdUI->Enable(m_bBlock || m_bTagWindow);
}

void CwdmDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

}
