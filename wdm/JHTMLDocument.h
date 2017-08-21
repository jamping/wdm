#pragma once
#include "jdocument.h"

class CJHTMLDocument :public CJDocument
{
public:
	CJHTMLDocument(CString strData);
	~CJHTMLDocument(void);

	CString GetTitle() { return m_strTitle; }
	CString GetTime() { return m_strTime; }
	CString GetText() { return m_strText; }

	void Parse();
private:	
	CString ParseTitle();
	CString ParseTime();
	CString ParseText();

	CString      m_strData;

	CString      m_strTitle;
	CString      m_strTime;
	CString      m_strText;	
};

