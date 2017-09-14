// MyEdit.cpp : ʵ���ļ�
//

#include "MyEdit.h"


// CMyEdit

IMPLEMENT_DYNAMIC(CMyEdit, CEdit)

CMyEdit::CMyEdit()
{
	m_rgbTextBackground = RGB(0,0,0);
	m_rgbText = RGB(0,255,0);
	m_brushBkg.CreateSolidBrush(m_rgbTextBackground);			//����������ˢ
	m_font.CreateFont(20,10,0,0,FW_NORMAL,FALSE,FALSE,FALSE,
		ANSI_CHARSET,OUT_CHARACTER_PRECIS,
		CLIP_CHARACTER_PRECIS,DEFAULT_QUALITY,
		FF_MODERN,"����");
}

CMyEdit::~CMyEdit()
{
	m_brushBkg.DeleteObject();
	m_font.DeleteObject();
}


BEGIN_MESSAGE_MAP(CMyEdit, CEdit)
	ON_WM_CTLCOLOR_REFLECT()
	ON_WM_NCPAINT()
END_MESSAGE_MAP()



// CMyEdit ��Ϣ�������
HBRUSH CMyEdit::CtlColor(CDC* pDC, UINT nCtlColor)
{
	// TODO:  �ڴ˸��� DC ���κ�����
	m_brushBkg.DeleteObject();
	m_brushBkg.CreateSolidBrush(m_rgbTextBackground);
	pDC->SetTextColor(m_rgbText);		    //����������ɫ
	pDC->SetBkColor(m_rgbTextBackground);	//���ñ���ɫ

	return (HBRUSH)m_brushBkg.GetSafeHandle();

	// TODO:  �����Ӧ���ø����Ĵ�������򷵻ط� null ����
	return NULL;
}

void CMyEdit::OnNcPaint()
{
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CEdit::OnNcPaint()

	SetFont(&m_font);
}

int CMyEdit::MySetFont(CFont& font)
{
	m_font.Attach(font);

	return 0;
}

int CMyEdit::MySetFont(int nHeight, // logical height of font height
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

int CMyEdit::SetBackGroundColor(COLORREF rgbTextBackground)
{
	m_rgbTextBackground = rgbTextBackground;

	return 0;
}

int CMyEdit::SetFontColor(COLORREF rgbText)
{
	m_rgbText = rgbText;

	return 0;
}