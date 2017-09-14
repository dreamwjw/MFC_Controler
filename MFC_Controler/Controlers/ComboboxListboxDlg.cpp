// ComboboxListboxDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ComboboxListboxDlg.h"
#include "afxdialogex.h"

// CComboboxListboxDlg �Ի���

IMPLEMENT_DYNAMIC(CComboboxListboxDlg, CDialogEx)

	CComboboxListboxDlg::CComboboxListboxDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CComboboxListboxDlg::IDD, pParent)
{
	m_pStatic = NULL;
	m_brush.CreateSolidBrush(RGB(0,124,155));
}

CComboboxListboxDlg::~CComboboxListboxDlg()
{
	m_brush.DeleteObject();
}

void CComboboxListboxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ListBox);
}


BEGIN_MESSAGE_MAP(CComboboxListboxDlg, CDialogEx)
	ON_WM_ACTIVATE()
	ON_WM_SIZE()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CComboboxListboxDlg ��Ϣ�������


void CComboboxListboxDlg::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
	CDialogEx::OnActivate(nState, pWndOther, bMinimized);
	if (WA_INACTIVE == nState)
	{
		this->ShowWindow(SW_HIDE);
		m_pStatic->SendMessage(HANDLEMESSAGE, NOACTIVE, NULL);
	}
}


void CComboboxListboxDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	MoveControler();
}

void CComboboxListboxDlg::MoveControler()
{
	if(m_ListBox.m_hWnd == NULL) return;

	CRect rect;
	GetClientRect(rect);
	m_ListBox.MoveWindow(rect);
}

void CComboboxListboxDlg::MyAddString(LPCTSTR lpszItem)
{
	m_ListBox.MyAddString(lpszItem);
}

void CComboboxListboxDlg::Init(CStatic* pStatic)
{
	m_pStatic = pStatic;
	m_ListBox.Init(pStatic, this);
}

void CComboboxListboxDlg::MySetItemHeight(int nItemHeight)
{
	m_ListBox.MySetItemHeight(nItemHeight);
}

HBRUSH CComboboxListboxDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	switch (pWnd->GetDlgCtrlID())
	{
	case IDC_LIST1:
		return (HBRUSH)m_brush;
		break;
	default:
		break;
	}

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}

int CComboboxListboxDlg::MySetFont(int nHeight, // logical height of font height
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
	)
{
	return m_ListBox.MySetFont(nHeight,nWidth,nEscapement,nOrientation,fnWeight,fdwItalic,
		fdwUnderline,fdwStrikeOut,fdwCharSet,fdwOutputPrecision,fdwClipPrecision,fdwQuality,
		fdwPitchAndFamily,lpszFace);
}