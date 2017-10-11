#pragma once

#include "KbcBmp.h"

//�Զ�����Ϣ
#define       MYUNCHECKED      WM_USER + 1200

// CMyRadio

class CMyRadio : public CButton
{
	DECLARE_DYNAMIC(CMyRadio)

public:
	CMyRadio();
	virtual ~CMyRadio();

protected:
	DECLARE_MESSAGE_MAP()

private:
	CFont m_font;
	COLORREF m_rgbText, m_rgbMask;
	CKbcBmp m_ImgChecked, m_ImgUnchecked;
	bool m_bChecked;
	UINT m_nIDRadio;

public:
	BOOL LoadBitmaps(UINT nIDBitmapChecked, UINT nIDBitmapUnchecked);
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
	void MySetCheck(bool bChecked = true);
	int SetFontColor(COLORREF rgbText);
	void SetRadioID(UINT nIDRadio);

public:
	//�Զ�����Ϣ
	LRESULT MyUnChecked(WPARAM wParam, LPARAM lParam);
	
public:
	virtual void PreSubclassWindow();
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnBnClicked();
};

//ʹ����֪
//1���ػ�Ŀؼ��ǰ�ť�����ǵ�ѡ��ť
//2�����ʱ��Ҫ����MySetCheck(false)��ͬ���Radio����UnChecked״̬
