#pragma once

#include "afxwin.h"

// CMyEdit

//MyEdit��Ҫ�༭�ؼ����ޱ߿�

class CMyEdit : public CEdit
{
	DECLARE_DYNAMIC(CMyEdit)

public:
	CMyEdit();
	virtual ~CMyEdit();

protected:
	DECLARE_MESSAGE_MAP()

private:
	CBrush m_brushBkg;//������ˢ���滭��������ı�����һ������屳��һ������ɫ
	COLORREF m_rgbTextBackground, m_rgbText;
	CFont m_font;

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
		LPCTSTR lpszFace = "����"// pointer to typeface name string
		);
	int SetBackGroundColor(COLORREF rgbTextBackground);
	int SetFontColor(COLORREF rgbText);

public:
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	afx_msg void OnNcPaint();
};


