/**
 * ���������ı��е�һ�����䣬����ĸ����ǣ�һ����������ģ����Ե������ֵĶ��䡣
 * �ڲ�ͬ���ĵ��п��ܶԲ�ͬ�Ķ����в�ͬ�Ķ��塣��һ��������Ķ����ǣ������ǽ���ƪ�º�
 * ����֮������ֿ飬 ÿ�����ֿ���Ϊ���ĵ��Ĺ��ײ�ͬ�����Ա����費ͬ��ֵ����֮ΪȨ�ء�
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
	CString     m_strText;  // ������ı�
	double      m_dWeight;  // �����Ȩ��
	int         m_nOffset;  // ���俪ʼ������������µ�ƫ��
};