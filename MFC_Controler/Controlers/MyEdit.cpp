// MyEdit.cpp : 实现文件
//

#include "MyEdit.h"


// CMyEdit

IMPLEMENT_DYNAMIC(CMyEdit, CEdit)

CMyEdit::CMyEdit()
{
	m_rgbTextBackground = RGB(0,0,0);
	m_rgbText = RGB(0,255,0);
	m_brushBkg.CreateSolidBrush(m_rgbTextBackground);			//创建背景画刷
	m_font.CreateFont(20,10,0,0,FW_NORMAL,FALSE,FALSE,FALSE,
		ANSI_CHARSET,OUT_CHARACTER_PRECIS,
		CLIP_CHARACTER_PRECIS,DEFAULT_QUALITY,
		FF_MODERN,"宋体");
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



// CMyEdit 消息处理程序
HBRUSH CMyEdit::CtlColor(CDC* pDC, UINT nCtlColor)
{
	// TODO:  在此更改 DC 的任何特性
	m_brushBkg.DeleteObject();
	m_brushBkg.CreateSolidBrush(m_rgbTextBackground);
	pDC->SetTextColor(m_rgbText);		    //设置文字颜色
	pDC->SetBkColor(m_rgbTextBackground);	//设置背景色

	return (HBRUSH)m_brushBkg.GetSafeHandle();

	// TODO:  如果不应调用父级的处理程序，则返回非 null 画笔
	return NULL;
}

void CMyEdit::OnNcPaint()
{
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CEdit::OnNcPaint()

	SetFont(&m_font);
}

int CMyEdit::MySetFont(int nHeight = 20, // logical height of font height
	int nWidth = 10, // logical average character width
	int nEscapement = 0, // angle of escapement
	int nOrientation = 0, // base-line orientation angle
	int fnWeight = FW_NORMAL, // font weight
	BYTE fdwItalic = FALSE, // italic attribute flag
	BYTE fdwUnderline = FALSE, // underline attribute flag
	BYTE fdwStrikeOut = FALSE, // strikeout attribute flag
	BYTE fdwCharSet = ANSI_CHARSET, // character set identifier
	BYTE fdwOutputPrecision = OUT_CHARACTER_PRECIS, // output precision
	BYTE fdwClipPrecision = CLIP_CHARACTER_PRECIS, // clipping precision
	BYTE fdwQuality = DEFAULT_QUALITY, // output quality
	BYTE fdwPitchAndFamily = FF_MODERN, // pitch and family
	LPCTSTR lpszFace = "宋体"// pointer to typeface name string
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