#pragma once

#include "ComboboxListboxDlg.h"

// CMyComboBox

class CMyComboBox : public CStatic
{
	DECLARE_DYNAMIC(CMyComboBox)

public:
	CMyComboBox();
	virtual ~CMyComboBox();

protected:
	DECLARE_MESSAGE_MAP()

private:
	unsigned char m_ucStatus;
	enum{NORMAL, MOUSEDOWN};
	CBitmap m_cbmpMouseDown, m_cbmpNormal;
	BITMAP m_bmpMouseDown, m_bmpNormal;
	CComboboxListboxDlg m_listboxdlg;
	CString m_cstrText;
	CFont m_font;
	int nRowCount;//下拉框显示多少行
	COLORREF m_rgbText;

private:
	//绘图
	void DrawBk(CDC& dc,int nIndex);

public:
	void MyAddString(LPCTSTR lpszItem);
	void Init();
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
	CString& MyGetString();
	void MySetItemHeight(int nItemHeight);
	void MySetString(LPCTSTR lpszItem);
	int SetFontColor(COLORREF rgbText);

public:
	//自定义消息
	LRESULT HandleMessage(WPARAM wParam, LPARAM lParam);

public:
	virtual void PreSubclassWindow();
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnStnClicked();
};

//使用须知
//1、继承CStatic，静态框控件必须激活点击事件，即将Notify属性设为True
//2、该组合框是Drop List而不是DropDown，DropDown的组合框重绘更复杂
//2、需要配合MyListBox和ComboboxListBoxDlg使用
//3、需要调用Init初始化
//4、获取文本调用MyGetString而不是GetItemText
