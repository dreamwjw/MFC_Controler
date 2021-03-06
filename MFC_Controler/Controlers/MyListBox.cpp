#include "StdAfx.h"
#include "resource.h"
#include "MyListBox.h"

CMyListBox::CMyListBox(void)
{
	m_nItemHeight = 0;
	m_plistboxdlg = NULL;
	m_rgbLine = RGB(0,93,118);
	m_pStatic = NULL;
	m_font.CreateFont(20,10,0,0,FW_NORMAL,FALSE,FALSE,FALSE,
		ANSI_CHARSET,OUT_CHARACTER_PRECIS,
		CLIP_CHARACTER_PRECIS,DEFAULT_QUALITY,
		FF_MODERN,"宋体");
}

CMyListBox::~CMyListBox(void)
{
	m_font.DeleteObject();
}


BEGIN_MESSAGE_MAP(CMyListBox, CListBox)
	ON_WM_LBUTTONDOWN()
	ON_WM_DRAWITEM()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


void CMyListBox::OnLButtonDown(UINT nFlags, CPoint point)
{
	int nCount = GetCount();
	CString cstrText;
	if(nCount > 0)
	{
		GetText(GetCurSel(), cstrText);
		if(m_plistboxdlg != NULL)
			m_plistboxdlg->ShowWindow(SW_HIDE);
		if(m_pStatic != NULL)
			m_pStatic->SendMessage(HANDLEMESSAGE, SETTEXT, (WPARAM)&cstrText);
	}

	CListBox::OnLButtonDown(nFlags, point);
}


void CMyListBox::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	CListBox::OnDrawItem(nIDCtl, lpDrawItemStruct);
}


void CMyListBox::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	int nCount = GetCount();
	if (nCount == 0)
	{
		return;
	}

	CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
	COLORREF clrItemText;
	switch ( lpDrawItemStruct->itemAction ) 
	{ 
	case ODA_SELECT: 
	case ODA_DRAWENTIRE: 
	case ODA_FOCUS:
		if ( lpDrawItemStruct->itemState & ODS_SELECTED ) 
		{ 
			HBRUSH hbrush = CreateSolidBrush(RGB(0,108,135));//创建一个画刷
			clrItemText = GetSysColor(COLOR_WINDOWTEXT);
			FillRect( lpDrawItemStruct->hDC,&lpDrawItemStruct->rcItem,hbrush);
			SetTextColor(lpDrawItemStruct->hDC,RGB(100,199,214));
			DeleteObject(hbrush);
		} 
		else
		{ 
			clrItemText = GetSysColor( COLOR_WINDOWTEXT );
			pDC->FillSolidRect(&lpDrawItemStruct->rcItem,RGB(0,124,155));
			SetTextColor(lpDrawItemStruct->hDC,RGB(100,199,214));
		} 
	}  

	//DrawText
	CRect rectFull = lpDrawItemStruct->rcItem;
	CString cstrText;
	UINT nIndex = lpDrawItemStruct->itemID;
	GetText(nIndex,cstrText);
	pDC->SelectObject(&m_font);
	pDC->SetBkMode(TRANSPARENT);
	LOGFONT lg;
	m_font.GetLogFont(&lg);
	pDC->TextOut(rectFull.left+5, rectFull.top+(rectFull.Height()-lg.lfHeight)/2, cstrText);

	//DrawLine
	CRect rectLine;
	rectLine.left = rectFull.left;
	rectLine.top = rectFull.bottom -1;
	rectLine.right = rectFull.right;
	rectLine.bottom = rectFull.bottom;
	pDC->FillSolidRect(rectLine, m_rgbLine);

	m_HScroll.UpdateScrollBar();
	m_VScroll.UpdateScrollBar();
}


void CMyListBox::OnMouseMove(UINT nFlags, CPoint point)
{
	int nCount = GetCount();
	for (int i = 0; i <nCount; i++)
	{
		RECT rc;
		this->GetItemRect(i,&rc);
		if(rc.top<point.y&&rc.bottom>point.y&&rc.left<point.x&&rc.right>point.x)
		{
			SetCurSel(i);
			break;
		}
	}

	CListBox::OnMouseMove(nFlags, point);
}


void CMyListBox::PreSubclassWindow()
{
	m_HScroll.InitScrollBar(this, SB_HORZ, 0);
	m_VScroll.InitScrollBar(this, SB_VERT, 0);

	CListBox::PreSubclassWindow();
}


void CMyListBox::Init(CStatic* pStatic, CDialog* pDialog)
{
	m_pStatic = pStatic;
	m_plistboxdlg = pDialog;
}

void CMyListBox::MyAddString(LPCTSTR lpszItem)
{
	if(this->GetSafeHwnd() == NULL)
		return;

	int nItem = AddString(lpszItem);
	SetItemHeight(nItem, m_nItemHeight);

	//计算水平滚动条宽度
	RefushHorizontalScrollBar();
}

void CMyListBox::MySetItemHeight(int nItemHeight)
{
	if(m_nItemHeight == 0)
	{
		m_nItemHeight = nItemHeight;
		int nSize = GetCount();
		for(int i = 0; i < nSize; i++)
			SetItemHeight(i, m_nItemHeight);
	}
}

int CMyListBox::MySetFont(int nHeight, // logical height of font height
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

	return 0;
}

void CMyListBox::RefushHorizontalScrollBar()
{
	CDC *pDC = GetDC();
	if (NULL == pDC)
	{
		return;
	}
	int nCount = GetCount();
	if ( nCount < 1 )
	{
		SetHorizontalExtent(0);
		return;
	}
	int nMaxExtent = 0;
	CString szText;
	for (int i = 0; i < nCount; ++i)
	{
		GetText(i, szText);
		CSize &cs = pDC->GetTextExtent(szText);
		if ( cs.cx > nMaxExtent )
		{
			nMaxExtent = cs.cx;
		}
	}
	SetHorizontalExtent(nMaxExtent);
}