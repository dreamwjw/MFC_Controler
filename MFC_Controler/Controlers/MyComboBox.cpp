// MyComboBox.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_Controler.h"
#include "MyComboBox.h"


// CMyComboBox

IMPLEMENT_DYNAMIC(CMyComboBox, CStatic)

CMyComboBox::CMyComboBox()
{
	m_ucStatus = NORMAL;
	m_font.CreateFont(20,10,0,0,FW_NORMAL,FALSE,FALSE,FALSE,
		ANSI_CHARSET,OUT_CHARACTER_PRECIS,
		CLIP_CHARACTER_PRECIS,DEFAULT_QUALITY,
		FF_MODERN,"宋体");
	nRowCount = 10;
	m_rgbText = RGB(0,0,0);
}

CMyComboBox::~CMyComboBox()
{
	m_font.DeleteObject();
}


BEGIN_MESSAGE_MAP(CMyComboBox, CStatic)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_CONTROL_REFLECT(STN_CLICKED, &CMyComboBox::OnStnClicked)
	ON_MESSAGE(HANDLEMESSAGE,HandleMessage)
END_MESSAGE_MAP()



// CMyComboBox 消息处理程序


void CMyComboBox::DrawBk(CDC& dc,int nIndex)
{
	CRect rect;
	GetWindowRect(rect); 
	GetParent()->ScreenToClient(rect);
	int nWidth = rect.Width();
	int nHeight = rect.Height();

	CDC dcMem;
	dcMem.CreateCompatibleDC(&dc);
	if(m_ucStatus==NORMAL)
	{
		dcMem.SelectObject(&m_cbmpNormal);
		dc.StretchBlt(0,0,nWidth,nHeight,&dcMem,0,0,m_bmpNormal.bmWidth,m_bmpNormal.bmHeight,SRCCOPY);
	}
	else if(m_ucStatus==MOUSEDOWN)
	{
		dcMem.SelectObject(&m_cbmpMouseDown);
		dc.StretchBlt(0,0,nWidth,nHeight,&dcMem,0,0,m_bmpMouseDown.bmWidth,m_bmpMouseDown.bmHeight,SRCCOPY);
	}
	dcMem.DeleteDC();

	dc.SelectObject(&m_font);
	dc.SetTextColor(m_rgbText);

	dc.SetBkMode(TRANSPARENT);
	LOGFONT lg;
	m_font.GetLogFont(&lg);
	//dc.TextOut(5, (nHeight-lg.lfHeight)/2, m_cstrText);
	CRect rc(0,0,nWidth,nHeight);
	dc.DrawText(m_cstrText, rc, DT_LEFT|DT_VCENTER|DT_SINGLELINE); 
}

void CMyComboBox::MyAddString(LPCTSTR lpszItem)
{
	m_listboxdlg.MyAddString(lpszItem);
}

void CMyComboBox::MySetString(LPCTSTR lpszItem)
{
	m_cstrText = lpszItem;
}

LRESULT CMyComboBox::HandleMessage(WPARAM wParam, LPARAM lParam)
{
	int nCode = wParam;
	switch(nCode)
	{
	case SETTEXT:
		{
			m_cstrText = *(CString*)lParam;
			m_ucStatus = NORMAL;
			InvalidateRect(NULL);
		}
		break;
	case NOACTIVE:
		{
			m_ucStatus = NORMAL;
			Invalidate();
		}
		break;
	}
	
	return 0;
}

void CMyComboBox::PreSubclassWindow()
{
	m_listboxdlg.Create(IDD_DLG_CBLISTBOX,this);

	m_cbmpNormal.LoadBitmap(IDB_COMBOBOX_NORMAL);
	m_cbmpNormal.GetBitmap(&m_bmpNormal);

	m_cbmpMouseDown.LoadBitmap(IDB_COMBOBOX_MOUSEDOWN);
	m_cbmpMouseDown.GetBitmap(&m_bmpMouseDown);
	
	CStatic::PreSubclassWindow();
}

//一定要重载OnPaint，否则会调用CStatic的OnPaint，导致重绘的东西被覆盖
void CMyComboBox::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CStatic::OnPaint()
}


BOOL CMyComboBox::OnEraseBkgnd(CDC* pDC)
{
	DrawBk(*pDC, m_ucStatus);

	return CStatic::OnEraseBkgnd(pDC);
}


void CMyComboBox::OnStnClicked()
{
	m_ucStatus = MOUSEDOWN;
	Invalidate();

	CRect rc;
	GetClientRect(rc);
	ClientToScreen(rc);
	m_listboxdlg.SetWindowPos(&wndTop,rc.left,rc.bottom,rc.Width(),rc.Height()*nRowCount,SWP_ASYNCWINDOWPOS|SWP_NOACTIVATE);

	if(m_listboxdlg.IsWindowVisible())
	{
		m_listboxdlg.ShowWindow(SW_HIDE);
	}
	else
	{
		m_listboxdlg.ShowWindow(SW_SHOW);
	}
}

void CMyComboBox::Init()
{
	m_listboxdlg.Init(this);
}

int CMyComboBox::MySetFont(int nHeight, // logical height of font height
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
	m_font.DeleteObject();

	m_font.CreateFont(nHeight,nWidth,nEscapement,nOrientation,fnWeight,fdwItalic,fdwUnderline,fdwStrikeOut,
		fdwCharSet,fdwOutputPrecision,fdwClipPrecision,fdwQuality,fdwPitchAndFamily,lpszFace);

	m_listboxdlg.MySetFont(nHeight,nWidth,nEscapement,nOrientation,fnWeight,fdwItalic,
		fdwUnderline,fdwStrikeOut,fdwCharSet,fdwOutputPrecision,fdwClipPrecision,fdwQuality,
		fdwPitchAndFamily,lpszFace);

	return 0;
}

CString& CMyComboBox::MyGetString()
{
	return m_cstrText;
}

void CMyComboBox::MySetItemHeight(int nItemHeight)
{
	m_listboxdlg.MySetItemHeight(nItemHeight);
}

int CMyComboBox::SetFontColor(COLORREF rgbText)
{
	m_rgbText = rgbText;

	return 0;
}