#pragma once
#include "afxwin.h"
#include "resource.h"
#include "MyListBox.h"

// CComboboxListboxDlg �Ի���

class CComboboxListboxDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CComboboxListboxDlg)

public:
	CComboboxListboxDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CComboboxListboxDlg();

// �Ի�������
	enum { IDD = IDD_DLG_CBLISTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

private:
	CStatic* m_pStatic;
	CMyListBox m_ListBox;
	CBrush m_brush;//�滭ListBox��Item�ı�����ɫ

private:
	void MoveControler();

public:
	void MyAddString(LPCTSTR lpszItem);
	void Init(CStatic* pStatic);
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
		LPCTSTR lpszFace = "����"// pointer to typeface name string
		);

public:
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
