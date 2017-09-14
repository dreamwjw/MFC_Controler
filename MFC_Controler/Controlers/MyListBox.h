#pragma once

#include "afxwin.h"
#include "MyScrollBar.h"

#define HANDLEMESSAGE WM_USER+1000
enum{SETTEXT, NOACTIVE};

class CMyListBox : public CListBox
{
public:
	CMyListBox(void);
	virtual ~CMyListBox(void);

	DECLARE_MESSAGE_MAP()

private:
	CMyScrollBar    m_HScroll;
	CMyScrollBar    m_VScroll;
	int m_nItemHeight;
	CString m_szCheck;
	CDialog* m_plistboxdlg;
	COLORREF m_rgbLine;
	CStatic* m_pStatic;
	CFont m_font;

public:
	void Init(CStatic* pStatic, CDialog* pDialog);
	void MyAddString(LPCTSTR lpszItem);
	void MySetItemHeight(int nItemHeight);
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
		LPCTSTR lpszFace = "ËÎÌו"// pointer to typeface name string
		);

public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	virtual void PreSubclassWindow();
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
};

