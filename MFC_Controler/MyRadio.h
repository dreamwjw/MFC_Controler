#pragma once

#include "KbcBmp.h"

//自定义消息
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
	CKbcBmp m_ImgRadio;
	bool m_bChecked;

public:
	BOOL LoadBitmaps(UINT nIDBitmapResource);

//自定义消息
LRESULT MyUnChecked(WPARAM wParam, LPARAM lParam);
	
public:
	virtual void PreSubclassWindow();
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnBnClicked();
};


