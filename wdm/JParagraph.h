/**
 * 用来描述文本中的一个段落，段落的概念是，一个独立语义的，可以单独划分的段落。
 * 在不同的文档中可能对不同的段落有不同的定义。但一个最基本的定义是：段落是介于篇章和
 * 句子之间的文字块， 每个文字块因为对文档的贡献不同而可以被赋予不同的值，称之为权重。
 * @author jjp
 */

#pragma once
class CJParagraph
{
public:
	CJParagraph(void);
	~CJParagraph(void);

	CJParagraph(CString strText, double dWeight, int nOffset);

	void SetText(CString strText);
	CString GetText() { return m_strText; }
	void SetWeight(double dWeight);
	double GetWeight() { return m_dWeight; }
	int GetOffset() { return m_nOffset; }
private:	
	CString     m_strText;  // 段落的文本
	double      m_dWeight;  // 段落的权重
	int         m_nOffset;  // 段落开始相对于整个文章的偏移
};