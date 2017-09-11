// MyRadio.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_Controler.h"
#include "MyRadio.h"


// CMyRadio

IMPLEMENT_DYNAMIC(CMyRadio, CButton)

CMyRadio::CMyRadio()
{
	m_font.CreateFont(20,10,0,0,400,0,0,0,134,3,2,1,2,TEXT("宋体"));
	m_rgbText = RGB(0,255,0);
	m_bChecked = false;
	m_rgbMask = RGB(0, 1, 0);
}

CMyRadio::~CMyRadio()
{
	m_font.DeleteObject();
}


BEGIN_MESSAGE_MAP(CMyRadio, CButton)
	ON_WM_CTLCOLOR_REFLECT()
	ON_CONTROL_REFLECT(BN_CLICKED, &CMyRadio::OnBnClicked)
	ON_MESSAGE(MYUNCHECKED,MyUnChecked)
END_MESSAGE_MAP()



// CMyRadio 消息处理程序
void CMyRadio::PreSubclassWindow()
{
	// TODO: 在此添加专用代码和/或调用基类
	ModifyStyle(0, BS_OWNERDRAW);

	CButton::PreSubclassWindow();
}


HBRUSH CMyRadio::CtlColor(CDC* pDC, UINT nCtlColor)
{
	// TODO:  在此更改 DC 的任何特性
	pDC->SetBkMode(TRANSPARENT);
	return (HBRUSH)GetStockObject(NULL_BRUSH);

	// TODO:  如果不应调用父级的处理程序，则返回非 null 画笔
	return NULL;
}


void CMyRadio::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
	CRect rcItem(lpDrawItemStruct->rcItem);

	m_ImgRadio.SetBTHeight(rcItem.Height());
	m_ImgRadio.SetBTWidth(rcItem.Width()/4);
	if(m_bChecked)
	{
		m_ImgRadio.Draw(pDC,0,0,0,m_rgbMask);
	}

	CString strText;
	GetWindowText(strText);
	
	pDC->SelectObject(&m_font);
	pDC->SetTextColor(m_rgbText);
	LOGFONT lg;
	m_font.GetLogFont(&lg);
	pDC->TextOut(rcItem.Width()/4, (rcItem.Height()-lg.lfHeight)/2, strText);
}

BOOL CMyRadio::LoadBitmaps(UINT nIDBitmapResource)
{
	if(nIDBitmapResource) m_ImgRadio.LoadBitmap(nIDBitmapResource);

	return TRUE;
}

void CMyRadio::OnBnClicked()
{
	if(m_bChecked == false)
	{
		m_bChecked = true;
		//TODO: 使同组的Radio置于UnChecked状态
		Invalidate(FALSE);
	}
}

LRESULT CMyRadio::MyUnChecked(WPARAM wParam, LPARAM lParam)
{
	if(m_bChecked == true)
	{
		m_bChecked = false;
		//TODO: 使同组的Radio置于UnChecked状态
		Invalidate(FALSE);
	}

	return 0;
}