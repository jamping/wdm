#include "StdAfx.h"
#include "JParagraph.h"


CJParagraph::CJParagraph(void)
{
}


CJParagraph::~CJParagraph(void)
{
}

CJParagraph::CJParagraph(CString strText, double dWeight, int nOffset)
{
	m_strText = strText;
	m_dWeight = dWeight;
	m_nOffset = nOffset;
}

void CJParagraph::SetText(CString strText)
{
	m_strText = strText;
}

void CJParagraph::SetWeight(double dWeight)
{
	m_dWeight = dWeight;
}