#pragma once


// CJTreeCtrl

class CJTreeCtrl : public CTreeCtrl
{
	DECLARE_DYNAMIC(CJTreeCtrl)

public:
	CJTreeCtrl();
	virtual ~CJTreeCtrl();

protected:
	DECLARE_MESSAGE_MAP()
	virtual void PreSubclassWindow();
};


