#pragma once

#include "afxwin.h"

class CMyStatic : public CStatic
{
public:
	CMyStatic(void);
	virtual ~CMyStatic(void);

	DECLARE_MESSAGE_MAP()

private:
	COLORREF m_rgbBackground, m_rgbText;
	CFont m_font;
	bool m_bSetBackgroundColor;//true则设置有颜色的背景，false则设置透明背景
	
private:
	void MyDrawText(CDC* pDC, const CString& cstrText);

public:
	int MySetFont(CFont& font);
	int MySetFont(int nHeight = 20, // logical height of font height
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
		);
	int SetBackGroundColor(COLORREF rgbBackground);
	int SetFontColor(COLORREF rgbText);
	int MySetWindowText(const CString& cstrText);

public:
	afx_msg void OnPaint();
};

//使用须知
//1、修改静态框的文本时不用SetWindowText而用MySetWindowText，否则文本修改后没有绘画出来