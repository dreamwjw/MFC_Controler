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
	bool m_bSetBackgroundColor;//true则设置透明背景，false则设置有颜色的背景
	CString m_cstrText;
	
private:
	void DrawText(CDC* pDC, const CString& cstrText);

public:
	int SetFont(int nHeight, // logical height of font height
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
	int SetBackGroundColor(COLORREF rgbBackground);
	int SetFontColor(COLORREF rgbText);
	int MySetWindowText(const CString& cstrText);

public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
};

