// JTreeCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "wdm.h"
#include "JTreeCtrl.h"


// CJTreeCtrl

IMPLEMENT_DYNAMIC(CJTreeCtrl, CTreeCtrl)

CJTreeCtrl::CJTreeCtrl()
{

}

CJTreeCtrl::~CJTreeCtrl()
{
}


BEGIN_MESSAGE_MAP(CJTreeCtrl, CTreeCtrl)
END_MESSAGE_MAP()



// CJTreeCtrl message handlers




void CJTreeCtrl::PreSubclassWindow()
{
	// TODO: Add your specialized code here and/or call the base class
	ModifyStyle(0,/*TVS_EDITLABELS | */TVS_HASLINES |TVS_LINESATROOT | TVS_HASBUTTONS);

	CTreeCtrl::PreSubclassWindow();
}
