#pragma once

#include "afxwin.h"

// CMyEdit

class CMyEdit : public CEdit
{
	DECLARE_DYNAMIC(CMyEdit)

public:
	CMyEdit();
	virtual ~CMyEdit();

protected:
	DECLARE_MESSAGE_MAP()

private:
	CBrush m_brushBkg;//背景画刷，绘画除字体外的背景，一般跟字体背景一样的样色
	COLORREF m_rgbTextBackground, m_rgbText;
	CFont m_font;

public:
	int MySetFont(int nHeight, // logical height of font height
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
		);
	int SetBackGroundColor(COLORREF rgbTextBackground);
	int SetFontColor(COLORREF rgbText);

public:
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	afx_msg void OnNcPaint();
};


