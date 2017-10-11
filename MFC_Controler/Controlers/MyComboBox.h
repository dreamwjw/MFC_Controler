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
	int nRowCount;//��������ʾ������
	COLORREF m_rgbText;

private:
	//��ͼ
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
		LPCTSTR lpszFace = "����"// pointer to typeface name string
		);
	CString& MyGetString();
	void MySetItemHeight(int nItemHeight);
	void MySetString(LPCTSTR lpszItem);
	int SetFontColor(COLORREF rgbText);

public:
	//�Զ�����Ϣ
	LRESULT HandleMessage(WPARAM wParam, LPARAM lParam);

public:
	virtual void PreSubclassWindow();
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnStnClicked();
};

//ʹ����֪
//1���̳�CStatic����̬��ؼ����뼤�����¼�������Notify������ΪTrue
//2������Ͽ���Drop List������DropDown��DropDown����Ͽ��ػ������
//2����Ҫ���MyListBox��ComboboxListBoxDlgʹ��
//3����Ҫ����Init��ʼ��
//4����ȡ�ı�����MyGetString������GetItemText
