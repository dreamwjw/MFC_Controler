// MyRadio.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_Controler.h"
#include "MyRadio.h"


// CMyRadio

IMPLEMENT_DYNAMIC(CMyRadio, CButton)

CMyRadio::CMyRadio()
{
	m_font.CreateFont(20,10,0,0,FW_NORMAL,FALSE,FALSE,FALSE,
		ANSI_CHARSET,OUT_CHARACTER_PRECIS,
		CLIP_CHARACTER_PRECIS,DEFAULT_QUALITY,
		FF_MODERN,"����");
	m_rgbText = RGB(255,255,255);
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
	int nHeight = rcItem.Height();

	m_ImgChecked.SetBTHeight(nHeight);
	m_ImgChecked.SetBTWidth(nHeight);
	m_ImgUnchecked.SetBTHeight(nHeight);
	m_ImgUnchecked.SetBTWidth(nHeight);
	if(m_bChecked)
	{
		m_ImgChecked.Draw(pDC,0,0,0,m_rgbMask);
	}
	else
	{
		m_ImgUnchecked.Draw(pDC,0,0,0,m_rgbMask);
	}

	CString cstrText;
	GetWindowText(cstrText);
	
	pDC->SelectObject(&m_font);
	pDC->SetTextColor(m_rgbText);
	LOGFONT lg;
	m_font.GetLogFont(&lg);
	pDC->TextOut(nHeight, (nHeight-lg.lfHeight)/2, cstrText);
}

BOOL CMyRadio::LoadBitmaps(UINT nIDBitmapChecked, UINT nIDBitmapUnchecked)
{
	if(nIDBitmapChecked) m_ImgChecked.LoadBitmap(nIDBitmapChecked);

	if(nIDBitmapUnchecked) m_ImgUnchecked.LoadBitmap(nIDBitmapUnchecked);

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

	//������¼����ݳ�ȥ
	GetParent()->PostMessage(WM_COMMAND, MAKEWPARAM(m_nIDRadio, BN_CLICKED), NULL);
}

LRESULT CMyRadio::MyUnChecked(WPARAM wParam, LPARAM lParam)
{
	if(m_bChecked == true)
	{
		m_bChecked = false;
		Invalidate(FALSE);
	}

	return 0;
}

int CMyRadio::MySetFont(CFont& font)
{
	m_font.Attach(font);

	return 0;
}

int CMyRadio::MySetFont(int nHeight, // logical height of font height
	int nWidth, // logical average character width
	int nEscapement, // angle of escapement
	int nOrientation, // base-line orientation angle
	int fnWeight, // font weight
	BYTE fdwItalic, // italic attribute flag
	BYTE fdwUnderline, // underline attribute flag
	BYTE fdwStrikeOut, // strikeout attribute flag
	BYTE fdwCharSet, // character set identifier
	BYTE fdwOutputPrecision, // output precision
	BYTE fdwClipPrecision, // clipping precision
	BYTE fdwQuality, // output quality
	BYTE fdwPitchAndFamily, // pitch and family
	LPCTSTR lpszFace // pointer to typeface name string
	)
{
	m_font.DeleteObject();

	m_font.CreateFont(nHeight,nWidth,nEscapement,nOrientation,fnWeight,fdwItalic,fdwUnderline,fdwStrikeOut,
		fdwCharSet,fdwOutputPrecision,fdwClipPrecision,fdwQuality,fdwPitchAndFamily,lpszFace);

	return 0;
}

void CMyRadio::MySetCheck(bool bChecked)
{
	if(m_bChecked != bChecked)
	{
		m_bChecked = bChecked;
		Invalidate(FALSE);
	}
}

int CMyRadio::SetFontColor(COLORREF rgbText)
{
	m_rgbText = rgbText;

	return 0;
}

void CMyRadio::SetRadioID(UINT nIDRadio)
{
	m_nIDRadio = nIDRadio;
}