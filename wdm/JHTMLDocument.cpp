#include "StdAfx.h"
#include "JHTMLDocument.h"
#include "JTextExtractor.h"
#include <boost/regex/mfc.hpp>

CJHTMLDocument::CJHTMLDocument(CString strData):m_strData(strData)
{
	CJUtility::FilterInvalidElements(m_strData);
}


CJHTMLDocument::~CJHTMLDocument(void)
{
}

void CJHTMLDocument::Parse()
{
	m_strTitle = ParseTitle();
	m_strTime = ParseTime();
	m_strText = ParseText();	
}
CString CJHTMLDocument::ParseText()
{	
	CJTextExtractor extractor;

	return extractor.Extract(m_strData);
}

CString CJHTMLDocument::ParseTitle()
{
	CString strTitle;

	boost::tregex rx(_T("<\\s*title\\s*>(.*?)(?:-|_|\\||</\\s*title\\s*>)"),boost::regex::normal | boost::regex::icase);	
	boost::tmatch what;	

	if(boost::regex_search(m_strData, what, rx))   
	{
		strTitle = CString(what[1].first,what.length(1));			
	}
	strTitle.Trim();

	return strTitle;
}

CString CJHTMLDocument::ParseTime()
{
	CString strTime;

	boost::tregex rx(_T("(\\d{4}(?:Äê|-|\\.|\\/)\\d{1,2}(?:ÔÂ|-|\\.|\\/)\\d{1,2}(ÈÕ)?(\\s*\\d{1,2}:\\d{1,2}(:\\d{1,2})?)?)"));	
	boost::tmatch what;	

	if(boost::regex_search(m_strData, what, rx))   
	{
		strTime = CString(what[1].first,what.length(1));			
	}
	strTime.Trim();

	return strTime;
}