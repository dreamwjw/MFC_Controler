// ScrollBarEx.cpp : implementation file
//

#include "stdafx.h"
#include "MyScrollBar.h"

#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

///USAGE:  /////////////////////////////////////////////////////////
//StdAfx.h
//#define WINVER  0x0500
//
//CMyScrollBar m_HScroll;
//CMyScrollBar m_VScroll;
//
// void CXxxWnd::PreSubclassWindow() 
// {
// 	CWnd::PreSubclassWindow();
// 	m_HScroll.InitScrollBar(this, SB_HORZ);
// 	m_VScroll.InitScrollBar(this, SB_VERT);
// }
// 
// void CXxxWnd::OnPaint() 
// {
// 	CWnd::OnPaint();
// 	m_HScroll.UpdateScrollBar();
// 	m_VScroll.UpdateScrollBar();
// }
//
/////////////////////////////////////////////////////////////////////////////

#define SCROLLBAR_NORMAL_MINIMUM 45  //经验值,当Scrollbar宽度/高度小于这一数值时需要特殊处理,保证与系统的处理方式一致
/////////////////////////////////////////////////////////////////////////////
// CMyScrollBar

CMyScrollBar::CMyScrollBar()
{
}

CMyScrollBar::~CMyScrollBar()
{
}


BEGIN_MESSAGE_MAP(CMyScrollBar, CStatic)
//{{AFX_MSG_MAP(CMyScrollBar)
	ON_WM_PAINT()
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyScrollBar message handlers

void CMyScrollBar::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	if (m_nScrollStyle == SB_VERT) 
    {
        DrawVScroll(&dc);
    }
    else if(m_nScrollStyle == SB_HORZ)
	{
		DrawHScroll(&dc);
	}
	
	// Do not call CStatic::OnPaint() for painting messages
}

BOOL CMyScrollBar::InitScrollBar(CWnd *pCtrl, UINT nStyle, int nType = 0)
{
	if(nType == 0)
	{
		m_nHLeft = IDB_HORIZONTAL_SCROLLBAR_LEFTARROW;
		m_nHRight = IDB_HORIZONTAL_SCROLLBAR_RIGHTARROW;
		m_nHSCenter = IDB_HORIZONTAL_SCROLLBAR_SLIDER_CENTER;
		m_nHSLeft = IDB_HORIZONTAL_SCROLLBAR_SLIDER_LEFT;
		m_nHSRight = IDB_HORIZONTAL_SCROLLBAR_SLIDER_RIGHT;
		m_nHSpan = IDB_HORIZONTAL_SCROLLBAR_SPAN; 
		m_nHThumb = IDB_HORIZONTAL_SCROLLBAR_THUMB;
		m_nVDown = IDB_VERTICLE_SCROLLBAR_DOWNARROW;
		m_nVUp = IDB_VERTICLE_SCROLLBAR_UPARROW;
		m_nVSCenter = IDB_VERTICLE_SCROLLBAR_SLIDER_CENTER;
		m_nVSBottom = IDB_VERTICLE_SCROLLBAR_SLIDER_BOTTOM;
		m_nVSTop = IDB_VERTICLE_SCROLLBAR_SLIDER_TOP;
		m_nVSpan = IDB_VERTICLE_SCROLLBAR_SPAN; 
		m_nVThumb = IDB_VERTICLE_SCROLLBAR_THUMB;
	}

    if (pCtrl == NULL) 
    {
        return FALSE;
    }
    m_pCtrl = pCtrl;
	
    int nx, ny;
    if (nStyle == SB_VERT) 
    {
        nx = ::GetSystemMetrics(SM_CXVSCROLL);
        ny = ::GetSystemMetrics(SM_CYVSCROLL);
    }
    else if(nStyle == SB_HORZ)
    {
        nx = GetSystemMetrics(SM_CXHSCROLL);
        ny = GetSystemMetrics(SM_CYHSCROLL);
    }
	else
	{
		return FALSE;
	}
    m_nScrollStyle = nStyle;


	CRect rect;
    pCtrl->GetWindowRect(rect);
	pCtrl->ModifyStyle(0, WS_CLIPSIBLINGS);
//	pCtrl->SetWindowPos(&wndBottom, 0,0,0,0,SWP_NOSIZE | SWP_NOMOVE);

	CWnd* pParent = pCtrl->GetParent();
    pParent->ScreenToClient(rect);
    
    if (nStyle == SB_VERT) 
    {
        rect.left = rect.right- nx;		
    }
    else if(nStyle == SB_HORZ)
    {
        rect.top = rect.bottom - ny;
    }
	
    BOOL bResult = Create(NULL, WS_CHILD|SS_LEFT|WS_VISIBLE|WS_EX_TOPMOST, rect, pParent);
    if (!bResult)
    {
        return FALSE;
    }
  
	UpdateScrollBar();
    return TRUE;
}

void CMyScrollBar::UpdateScrollBar()
{
	if(!IsWindow(m_hWnd) || m_pCtrl == NULL)
	{
		return;
	}
	m_pCtrl->SetWindowPos(&wndBottom, 0,0,0,0,SWP_NOSIZE | SWP_NOMOVE);

	SCROLLINFO sf;
	memset(&sf, 0, sizeof(SCROLLINFO));
	sf.cbSize = sizeof(SCROLLINFO);
	m_pCtrl->GetScrollInfo(m_nScrollStyle, &sf, SIF_ALL);
    if (sf.nPage < 0) 
    {
		ShowWindow(SW_HIDE);
        return;
    }

	SCROLLBARINFO hscr;
	memset(&hscr, 0, sizeof(SCROLLBARINFO));
	hscr.cbSize = sizeof(SCROLLBARINFO);
	CRect rcScrollBar;

	if(m_nScrollStyle == SB_VERT)
	{
		::GetScrollBarInfo(m_pCtrl->m_hWnd, OBJID_VSCROLL, &hscr);
		rcScrollBar = CRect(hscr.rcScrollBar);
	}
	else if(m_nScrollStyle == SB_HORZ)
	{
		::GetScrollBarInfo(m_pCtrl->m_hWnd, OBJID_HSCROLL, &hscr);
		rcScrollBar = CRect(hscr.rcScrollBar);
	}

	GetParent()->ScreenToClient(&rcScrollBar);
//	TRACE("rcScrollBar.left = %d, rcScrollBar.top = %d\n", rcScrollBar.left, rcScrollBar.top);

	SetWindowPos(NULL, rcScrollBar.left, rcScrollBar.top, rcScrollBar.Width(), rcScrollBar.Height(), SWP_SHOWWINDOW|SWP_NOZORDER);
	Invalidate();
}

//draw vertical scrollbar
void CMyScrollBar::DrawVScroll(CDC* pDC)
{
	if(m_pCtrl == NULL)
	{
		return;
	}

	int cxButton     = ::GetSystemMetrics(SM_CXVSCROLL);
    int cyButton     = ::GetSystemMetrics(SM_CYVSCROLL);
	
	if(IsWindow(m_hWnd))
	{		
		SCROLLBARINFO vscr;
		memset(&vscr, 0, sizeof(SCROLLBARINFO));
		vscr.cbSize = sizeof(SCROLLBARINFO);
		if( ::GetScrollBarInfo(m_pCtrl->m_hWnd, OBJID_VSCROLL, &vscr) )
		{ 
			CRect rcVScrollBar(vscr.rcScrollBar);	
			
			int iWidth = vscr.dxyLineButton;
			int iThumbTop = vscr.xyThumbTop;
			int iThumbBottom = vscr.xyThumbBottom;
			
			//	TRACE("vscr.dxyLineButton = %d\n", iWidth);
			//	TRACE("vscr.xyThumbTop = %d\n", iThumbTop);
			//	TRACE("vscr.xyThumbBottom = %d\n", iThumbBottom);
			//	TRACE("rcVScrollBar: %d, %d, %d, %d \n", rcVScrollBar.left, rcVScrollBar.top, rcVScrollBar.right, rcVScrollBar.bottom);
			
			if(rcVScrollBar.Height() < ::GetSystemMetrics(SM_CYVSCROLL)*2+1)
			{
				cyButton = (rcVScrollBar.Height() - 1)/2; 
			}
			
			CDC cMemDC;
			cMemDC.CreateCompatibleDC(pDC);
	
			CBitmap bmp;
			BITMAP bitmap;
			
			//The top arrow button
			//bmp.LoadBitmap(IDB_VERTICLE_SCROLLBAR_UPARROW);
			bmp.LoadBitmap(m_nVUp);
			bmp.GetBitmap(&bitmap);
			cMemDC.SelectObject(&bmp);
			pDC->StretchBlt(0, 0, cxButton, cyButton, &cMemDC, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
			
			//The bottom arrow button
			bmp.DeleteObject();
			//bmp.LoadBitmap(IDB_VERTICLE_SCROLLBAR_DOWNARROW);
			bmp.LoadBitmap(m_nVDown);
			bmp.GetBitmap(&bitmap);
			cMemDC.SelectObject(&bmp);
			pDC->StretchBlt(0, rcVScrollBar.Height() - cyButton, cxButton, cyButton, &cMemDC, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
			
			//The scroll bar itself
			bmp.DeleteObject();
			//bmp.LoadBitmap(IDB_VERTICLE_SCROLLBAR_SPAN);
			bmp.LoadBitmap(m_nVSpan);
			cMemDC.SelectObject(&bmp);
			bmp.GetBitmap(&bitmap);
			pDC->StretchBlt(0, cyButton, rcVScrollBar.Width(), rcVScrollBar.Height() - 2*cyButton, &cMemDC, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
			
			if(rcVScrollBar.Height() <= SCROLLBAR_NORMAL_MINIMUM)
			{
				return;
			}
			
			//The thumb
			bmp.DeleteObject();
			//bmp.LoadBitmap(IDB_VERTICLE_SCROLLBAR_SLIDER_TOP);
			bmp.LoadBitmap(m_nVSTop);
			bmp.GetBitmap(&bitmap);
			cMemDC.SelectObject(&bmp);
			pDC->StretchBlt(0, iThumbTop, iWidth, bitmap.bmHeight, &cMemDC, 0, 0, bitmap.bmWidth, bitmap.bmHeight,SRCCOPY);
			
			bmp.DeleteObject();
			//bmp.LoadBitmap(IDB_VERTICLE_SCROLLBAR_SLIDER_CENTER);
			bmp.LoadBitmap(m_nVSCenter);
			bmp.GetBitmap(&bitmap);
			cMemDC.SelectObject(&bmp);
			pDC->StretchBlt(0 , iThumbTop + bitmap.bmHeight, iWidth, iThumbBottom - iThumbTop - 2*bitmap.bmHeight, &cMemDC, 0, 0,bitmap.bmWidth, bitmap.bmHeight,SRCCOPY);
			
			bmp.DeleteObject();
			//bmp.LoadBitmap(IDB_VERTICLE_SCROLLBAR_SLIDER_BOTTOM);
			bmp.LoadBitmap(m_nVSBottom);
			bmp.GetBitmap(&bitmap);
			cMemDC.SelectObject(&bmp);
			pDC->StretchBlt(0 , iThumbBottom - bitmap.bmHeight, iWidth, bitmap.bmHeight, &cMemDC, 0, 0, bitmap.bmWidth, bitmap.bmHeight,SRCCOPY);
			
			
			bmp.DeleteObject();
			//bmp.LoadBitmap(IDB_VERTICLE_SCROLLBAR_THUMB);
			bmp.LoadBitmap(m_nVThumb);
			bmp.GetBitmap(&bitmap);
			cMemDC.SelectObject(&bmp);
			pDC->StretchBlt(0, (iThumbTop + iThumbBottom)/2 - bitmap.bmHeight /2 , iWidth, bitmap.bmHeight, &cMemDC, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
			
		}
	}


}

//draw horizontal scrollbar
void CMyScrollBar::DrawHScroll(CDC* pDC)
{
	if(m_pCtrl == NULL)
	{
		return;
	}

	int cxButton     = ::GetSystemMetrics(SM_CXHSCROLL);
    int cyButton     = ::GetSystemMetrics(SM_CYHSCROLL);

	if(IsWindow(m_hWnd))
	{		
		SCROLLBARINFO hscr;
		memset(&hscr, 0, sizeof(SCROLLBARINFO));
		hscr.cbSize = sizeof(SCROLLBARINFO);
		if( ::GetScrollBarInfo(m_pCtrl->m_hWnd, OBJID_HSCROLL, &hscr) )
		{ 
			CRect rcHScrollBar(hscr.rcScrollBar);			
			
			int iHeigth = hscr.dxyLineButton;
			int iThumbLeft = hscr.xyThumbTop;
			int iThumbRight = hscr.xyThumbBottom;

//			TRACE("hscr.dxyLineButton = %d\n", iHeigth);
//			TRACE("hscr.xyThumbTop = %d\n", iThumbLeft);
//			TRACE("hscr.xyThumbBottom = %d\n", iThumbRight);
//			TRACE("rcHScrollBar: %d, %d, %d, %d \n", rcHScrollBar.left, rcHScrollBar.top, rcHScrollBar.right, rcHScrollBar.bottom);

			if(rcHScrollBar.Width() < ::GetSystemMetrics(SM_CXHSCROLL)*2+1)
			{
				cxButton = (rcHScrollBar.Width() - 1)/2; 
			}
			
			CDC cMemDC;
			cMemDC.CreateCompatibleDC(pDC);
			
			CBitmap bmp;
			BITMAP bitmap;
			
			//The left arrow button
			//bmp.LoadBitmap(IDB_HORIZONTAL_SCROLLBAR_LEFTARROW);
			bmp.LoadBitmap(m_nHLeft);
			bmp.GetBitmap(&bitmap);
			cMemDC.SelectObject(&bmp);
			pDC->StretchBlt(0, 0, cxButton, cyButton, &cMemDC, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
			
			//The right arrow button
			bmp.DeleteObject();
			//bmp.LoadBitmap(IDB_HORIZONTAL_SCROLLBAR_RIGHTARROW);
			bmp.LoadBitmap(m_nHRight);
			bmp.GetBitmap(&bitmap);
			cMemDC.SelectObject(&bmp);
			pDC->StretchBlt(rcHScrollBar.Width() - cxButton, 0, cxButton, cyButton, &cMemDC, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
		
			//The scroll bar itself
			bmp.DeleteObject();
			//bmp.LoadBitmap(IDB_HORIZONTAL_SCROLLBAR_SPAN);
			bmp.LoadBitmap(m_nHSpan);
			cMemDC.SelectObject(&bmp);
			bmp.GetBitmap(&bitmap);
			pDC->StretchBlt(cxButton, 0, rcHScrollBar.Width() - 2*cxButton, rcHScrollBar.Height(), &cMemDC, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
			
			if(rcHScrollBar.Width() <= SCROLLBAR_NORMAL_MINIMUM)
			{
				return;
			}
			
			//The thumb
			bmp.DeleteObject();
			//bmp.LoadBitmap(IDB_HORIZONTAL_SCROLLBAR_SLIDER_LEFT);
			bmp.LoadBitmap(m_nHSLeft);
			bmp.GetBitmap(&bitmap);
			cMemDC.SelectObject(&bmp);
			pDC->StretchBlt(iThumbLeft, 0, bitmap.bmWidth, iHeigth, &cMemDC, 0, 0, bitmap.bmWidth, bitmap.bmHeight,SRCCOPY);
			
			bmp.DeleteObject();
			//bmp.LoadBitmap(IDB_HORIZONTAL_SCROLLBAR_SLIDER_CENTER);
			bmp.LoadBitmap(m_nHSCenter);
			bmp.GetBitmap(&bitmap);
			cMemDC.SelectObject(&bmp);
			pDC->StretchBlt(iThumbLeft + bitmap.bmWidth , 0, iThumbRight - iThumbLeft - 2*bitmap.bmWidth,iHeigth, &cMemDC, 0, 0,bitmap.bmWidth, bitmap.bmHeight,SRCCOPY);
			
			bmp.DeleteObject();
			//bmp.LoadBitmap(IDB_HORIZONTAL_SCROLLBAR_SLIDER_RIGHT);
			bmp.LoadBitmap(m_nHSRight);
			bmp.GetBitmap(&bitmap);
			cMemDC.SelectObject(&bmp);
			pDC->StretchBlt(iThumbRight - bitmap.bmWidth , 0, bitmap.bmWidth, iHeigth, &cMemDC, 0, 0, bitmap.bmWidth, bitmap.bmHeight,SRCCOPY);
			
			
			bmp.DeleteObject();
			//bmp.LoadBitmap(IDB_HORIZONTAL_SCROLLBAR_THUMB);
			bmp.LoadBitmap(m_nHThumb);
			bmp.GetBitmap(&bitmap);
			cMemDC.SelectObject(&bmp);
			pDC->StretchBlt((iThumbLeft + iThumbRight)/2 - bitmap.bmWidth/2, 0, bitmap.bmWidth, iHeigth, &cMemDC, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
	
		}
	}
}