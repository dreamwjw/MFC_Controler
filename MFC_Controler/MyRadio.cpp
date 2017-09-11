// MyRadio.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_Controler.h"
#include "MyRadio.h"


// CMyRadio

IMPLEMENT_DYNAMIC(CMyRadio, CButton)

CMyRadio::CMyRadio()
{
	m_font.CreateFont(20,10,0,0,400,0,0,0,134,3,2,1,2,TEXT("����"));
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



// CMyRadio ��Ϣ�������
void CMyRadio::PreSubclassWindow()
{
	// TODO: �ڴ����ר�ô����/����û���
	ModifyStyle(0, BS_OWNERDRAW);

	CButton::PreSubclassWindow();
}


HBRUSH CMyRadio::CtlColor(CDC* pDC, UINT nCtlColor)
{
	// TODO:  �ڴ˸��� DC ���κ�����
	pDC->SetBkMode(TRANSPARENT);
	return (HBRUSH)GetStockObject(NULL_BRUSH);

	// TODO:  �����Ӧ���ø����Ĵ�������򷵻ط� null ����
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
		//TODO: ʹͬ���Radio����UnChecked״̬
		Invalidate(FALSE);
	}
}

LRESULT CMyRadio::MyUnChecked(WPARAM wParam, LPARAM lParam)
{
	if(m_bChecked == true)
	{
		m_bChecked = false;
		//TODO: ʹͬ���Radio����UnChecked״̬
		Invalidate(FALSE);
	}

	return 0;
}