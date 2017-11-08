#include "MyStatic.h"


CMyStatic::CMyStatic(void)
{
	m_font.CreateFont(20,10,0,0,FW_NORMAL,FALSE,FALSE,FALSE,
		ANSI_CHARSET,OUT_CHARACTER_PRECIS,
		CLIP_CHARACTER_PRECIS,DEFAULT_QUALITY,
		FF_MODERN,"宋体");
	 m_rgbBackground = RGB(0,255,0);
	 m_rgbText = RGB(0,0,0);
	 m_bSetBackgroundColor = true;
}

CMyStatic::~CMyStatic(void)
{
	m_font.DeleteObject();
}

BEGIN_MESSAGE_MAP(CMyStatic, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()

void CMyStatic::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	//获取文本
	CString cstrText;
	GetWindowText(cstrText);

	MyDrawText(&dc, cstrText);
}

void CMyStatic::MyDrawText(CDC* pDC, const CString& cstrText)
{
	if(m_bSetBackgroundColor)
	{
		//设置背景颜色
		pDC->SetBkColor(m_rgbBackground);
	}
	else
	{
		//设置透明背景
		pDC->SetBkMode(TRANSPARENT);
	}

	//设置字体样式
	pDC->SelectObject(m_font);

	//设置文本颜色
	pDC->SetTextColor(m_rgbText);

	//绘画文本 
	CRect rc;
	GetClientRect(rc);
	LOGFONT lg;
	m_font.GetLogFont(&lg);
	//pDC->TextOut(rc.left, (rc.Height()-lg.lfHeight)/2, cstrText);
	pDC->DrawText(cstrText, rc, DT_LEFT|DT_VCENTER|DT_SINGLELINE); 
}

int CMyStatic::MySetFont(CFont& font)
{
	m_font.Attach(font);

	return 0;
}

int CMyStatic::MySetFont(int nHeight, // logical height of font height
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

int CMyStatic::SetBackGroundColor(COLORREF rgbBackground)
{
	m_rgbBackground = rgbBackground;
	m_bSetBackgroundColor = true;

	return 0;
}

int CMyStatic::SetFontColor(COLORREF rgbText)
{
	m_rgbText = rgbText;
	
	return 0;
}

int CMyStatic::MySetWindowText(const CString& cstrText)
{
	CClientDC dc(this);

	SetWindowText(cstrText);
	MyDrawText(&dc, cstrText);

	return 0;
}