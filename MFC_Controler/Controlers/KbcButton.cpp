// KbcButton.cpp : implementation file
//

#include "stdafx.h"
#include "KbcButton.h"

#include "CMS Client.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKbcButton

CKbcButton::CKbcButton()
{	
	m_bChageColor		       = TRUE;
	m_bDisable			       = FALSE;
	m_bCursorOnButton	       = FALSE;
	m_bHover			       = FALSE;
	m_bSetCursor		       = FALSE;
	m_nMask				       = RGB(0, 1, 0);
	m_hCursor			       = NULL;
	m_bIsSelected              = FALSE;
	m_bIsFontAndBackGround     = FALSE;
	SetCursor(LoadCursor(NULL, IDC_HAND));
}

CKbcButton::~CKbcButton()
{
	if(m_hCursor)
	{
		DestroyCursor(m_hCursor);
		m_hCursor = NULL;
	}

	if(m_font.m_hObject != NULL) m_font.DeleteObject();
}


BEGIN_MESSAGE_MAP(CKbcButton, CButton)
	//{{AFX_MSG_MAP(CKbcButton)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_SETCURSOR()
	ON_MESSAGE(WM_MOUSEHOVER,OnMouseHover)
	ON_MESSAGE(WM_MOUSELEAVE,OnMouseLeave)
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKbcButton message handlers

void CKbcButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// get DC from LPDRAWITEMSTRUCT..
	CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
	
	//如果按钮不是图片，则绘画字体和背景颜色
	if(m_bIsFontAndBackGround)
	{
		COLORREF rgbFont, rgbBK;

		if( m_bDisable == TRUE)
		{
			rgbFont = m_rgbFontDisabled;
			rgbBK = m_rgbBKDisabled;
		}
		else
		{
			if( lpDrawItemStruct->itemAction & ODA_SELECT)
			{
				rgbFont = m_rgbFontFocus;
				rgbBK = m_rgbBKFocus;
			}
			else if ( m_bHover)
			{
				rgbFont = m_rgbFontSelect;
				rgbBK = m_rgbBKSelect;
			}
			else
			{
				if(m_bIsSelected)
				{
					rgbFont = m_rgbFontFocus;
					rgbBK = m_rgbBKFocus;
				}
				else
				{
					rgbFont = m_rgbFontNormal;
					rgbBK = m_rgbBKNormal;
				}
			}
		}

		DrawFontAndBackGround(pDC, rgbFont, rgbBK);

		return;
	}

	// disable state...
	if( m_bDisable == TRUE && m_bmpImageDisable.IsOK())
	{
		CRect rect;
		GetClientRect(rect);
		m_bmpImageDisable.SetBTHeight(rect.Height());
		m_bmpImageDisable.SetBTWidth(rect.Width());
		m_bmpImageDisable.Draw(pDC,BUTTON_ENABLE,0,0,m_nMask);
	}
	else
	{
		// click state
		if( lpDrawItemStruct->itemAction & ODA_SELECT && m_bmpImageFocus.IsOK())
		//if( lpDrawItemStruct->itemState & ODS_SELECTED && m_bmpImageFocus.IsOK())
		{
			CRect rect;
			GetClientRect(rect);
			m_bmpImageFocus.SetBTHeight(rect.Height());
			m_bmpImageFocus.SetBTWidth(rect.Width());
			m_bmpImageFocus.Draw(pDC,BUTTON_ENABLE,0,0,m_nMask);
		}
		
		// hover state
		else if ( m_bHover && m_bmpImageSel.IsOK())
		{
			CRect rect;
			GetClientRect(rect);
			m_bmpImageSel.SetBTHeight(rect.Height());
			m_bmpImageSel.SetBTWidth(rect.Width());
			m_bmpImageSel.Draw(pDC,BUTTON_ENABLE,0,0,m_nMask);
		}
		
		// enable state
		else
		{
			if(m_bIsSelected)
			{
				CRect rect;
				GetClientRect(rect);
				m_bmpImageFocus.SetBTHeight(rect.Height());
				m_bmpImageFocus.SetBTWidth(rect.Width());
				m_bmpImageFocus.Draw(pDC,BUTTON_ENABLE,0,0,m_nMask);
			}
			else
			{
				CRect rect;
				GetClientRect(rect);
				m_bmpImage.SetBTHeight(rect.Height());
				m_bmpImage.SetBTWidth(rect.Width());
				m_bmpImage.Draw(pDC,BUTTON_ENABLE,0,0,m_nMask);
			}
		}
	}
	/*
	// get DC from LPDRAWITEMSTRUCT..
	CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);

	// disable state...
	if( m_bDisable == TRUE && m_bmpImageDisable.IsOK())
		m_bmpImage.Draw(pDC,BUTTON_DISABLE,0,0,m_nMask);

	else
	{
		// click state
		if( lpDrawItemStruct->itemState & ODS_SELECTED )
			m_bmpImage.Draw(pDC,BUTTON_CLICK,0,0,m_nMask);

		// hover state
		else if ( m_bHover)
			m_bmpImage.Draw(pDC,BUTTON_HOVER,0,0,m_nMask);

		// enable state
		else
			m_bmpImage.Draw(pDC,BUTTON_ENABLE,0,0,m_nMask);
	}*/
	
}

void CKbcButton::SetButtonImage(CString strFileName,UINT nMask)
{
	m_bmpImage.LoadBitmap(strFileName);
	m_nMask = nMask;
	
	// get button info..
	m_rectButton.left	= 0;
	m_rectButton.top	= 0;
	m_rectButton.right	= m_bmpImage.GetSliceWidth();
	m_rectButton.bottom	= m_bmpImage.GetHeight();
	////////////////////////////////////////////////////////////////


	// resize button size.
	// if button size is smaller than button image then we enlarge button size..
	CWnd *pWnd = this->GetParent();
	GetWindowRect(&m_rectButtonPos);
	pWnd->ScreenToClient(m_rectButtonPos);
	m_rectButtonPos.right	= m_rectButtonPos.left + m_bmpImage.GetSliceWidth();
	m_rectButtonPos.bottom	= m_rectButtonPos.top  + m_bmpImage.GetHeight();
	MoveWindow(m_rectButtonPos);
	////////////////////////////////////////////////////////////////
}


void CKbcButton::OnMouseMove(UINT nFlags, CPoint point) 
{
	// we wanna get WM_MOUSEHOVER,WM_MOUSELEAVE message, so we call _TrackMouseEvent
	if( m_bCursorOnButton == FALSE )
	{
		TRACKMOUSEEVENT tme;
		ZeroMemory(&tme,sizeof(TRACKMOUSEEVENT));
		tme.cbSize = sizeof(tme);
		tme.hwndTrack = m_hWnd;
		tme.dwFlags = TME_LEAVE|TME_HOVER;
		tme.dwHoverTime = 1;
		m_bCursorOnButton = _TrackMouseEvent(&tme);
	}
	
	CButton::OnMouseMove(nFlags, point);
}


LRESULT CKbcButton::OnMouseHover(WPARAM wparam, LPARAM lparam)
{
	m_bHover = TRUE;
	
	Invalidate();
	return 0L;
}

LRESULT CKbcButton::OnMouseLeave(WPARAM wparam, LPARAM lparam)
{
	m_bCursorOnButton	= FALSE;
	m_bHover			= FALSE;
	
	Invalidate();
	return 0L;
}

void CKbcButton::SetButtonEnable()
{
	m_bDisable = FALSE;
	
	Invalidate();
}

void CKbcButton::SetButtonDisable()
{
	m_bDisable = TRUE;
	
	Invalidate();
}

void CKbcButton::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// if button state is disable we do not call CButton::OnLButtonDown funtion..
	if( !m_bDisable )
		CButton::OnLButtonDown(nFlags, point);
}

BOOL CKbcButton::PreTranslateMessage(MSG* pMsg) 
{
	// to showing a tooltip message, call RelayEvent if m_ToolTip has created.
	 if((pMsg->message== WM_LBUTTONDOWN ||
		  pMsg->message== WM_LBUTTONUP ||
		  pMsg->message== WM_MOUSEMOVE))  
		  {  
		  MSG tempMsg;  
		  tempMsg=*pMsg;  
		  tempMsg.message=WM_MOUSEMOVE;  
		  
			InitToolTip();
			m_ToolTip.RelayEvent(&tempMsg);
		  }
	//InitToolTip();
	//m_ToolTip.RelayEvent(pMsg);
	//m_ToolTip.Popup();
	
	return CButton::PreTranslateMessage(pMsg);
}

void CKbcButton::InitToolTip()
{
	if (m_ToolTip.GetSafeHwnd() == NULL)
	{
		// Create ToolTip control
		m_ToolTip.Create(this,TTS_ALWAYSTIP);
		// Create inactive
		m_ToolTip.Activate(FALSE);
		// Enable multiline
		m_ToolTip.SendMessage(TTM_SETMAXTIPWIDTH, 0, 400);
		//m_ToolTip.SendMessage(TTM_SETTITLE, TTI_INFO, (LPARAM)_T("Title"));
	} // if
} // End of InitToolTip

void CKbcButton::SetToolTipText(CString strText)
{
	// We cannot accept NULL pointer
	if (strText.GetLength() < 0) return;
	
	// Initialize ToolTip
	InitToolTip();

	// If there is no tooltip defined then add it
	if (m_ToolTip.GetToolCount() == 0)
	{
		CRect rectBtn; 
		GetClientRect(rectBtn);
		m_ToolTip.AddTool(this, (LPCTSTR)strText, rectBtn, 1);
	} // if

	// Set text for tooltip
	m_ToolTip.UpdateTipText((LPCTSTR)strText, this, 1);

	m_ToolTip.Activate(TRUE);
}

BOOL CKbcButton::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	if( m_bSetCursor )
	{
		::SetCursor(m_hCursor);
		return TRUE;
	}
	else
		return CButton::OnSetCursor(pWnd,nHitTest,message);
}

void CKbcButton::SetCursor(HCURSOR hCursor)
{
	m_bSetCursor	= TRUE;
	m_hCursor		= hCursor;
}

BOOL CKbcButton::OnEraseBkgnd(CDC* pDC) 
{
	// do not draw back ground. just return here, so we can see the background.
	// if you have curiosity about this, then remove ON_WM_ERASEBKGND() and test..
	return TRUE;
}

BOOL CKbcButton::LoadBitmaps(
					UINT nIDBitmapResource,
					UINT nIDBitmapResourceSel,
					UINT nIDBitmapResourceFocus,
					UINT nIDBitmapResourceDisabled)
{
	if(nIDBitmapResource)
		m_bmpImage.LoadBitmap(nIDBitmapResource);
	if(nIDBitmapResourceSel)
		m_bmpImageSel.LoadBitmap(nIDBitmapResourceSel);
	if(nIDBitmapResourceFocus)
		m_bmpImageFocus.LoadBitmap(nIDBitmapResourceFocus);
	if(nIDBitmapResourceDisabled)
		m_bmpImageDisable.LoadBitmap(nIDBitmapResourceDisabled);

	return TRUE;
}
void CKbcButton::SizeToContent()
{
	CWnd *pWnd = this->GetParent();
	GetWindowRect(&m_rectButtonPos);
	pWnd->ScreenToClient(m_rectButtonPos);
	m_rectButtonPos.right	= m_rectButtonPos.left + m_bmpImage.GetSliceWidth();
	m_rectButtonPos.bottom	= m_rectButtonPos.top  + m_bmpImage.GetHeight();
	MoveWindow(m_rectButtonPos);
}

BOOL CKbcButton::LoadFontAndBackGround(const char* szContent, 
	COLORREF rgbFontNormal, COLORREF rgbFontSelect, COLORREF rgbFontFocus, COLORREF rgbFontDisabled,
	COLORREF rgbBKNormal, COLORREF rgbBKSelect, COLORREF rgbBKFocus, COLORREF rgbBKDisabled)
{
	strcpy_s(m_szContent, 20, szContent);
	m_rgbFontNormal = rgbFontNormal;
	m_rgbFontSelect = rgbFontSelect;
	m_rgbFontFocus = rgbFontFocus;
	m_rgbFontDisabled = rgbFontDisabled;
	m_rgbBKNormal = rgbBKNormal;
	m_rgbBKSelect = rgbBKSelect;
	m_rgbBKFocus = rgbBKFocus;
	m_rgbBKDisabled = rgbBKDisabled;

	m_bIsFontAndBackGround = TRUE;

	return TRUE;
}

void CKbcButton::DrawFontAndBackGround(CDC *pDC, COLORREF rgbFont, COLORREF rgbBK)
{
	CRect rect;
	GetClientRect(rect);  
	CBitmap bitmap;  
	CDC MemeDc;  
	MemeDc.CreateCompatibleDC(pDC);  
	bitmap.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());  
	CBitmap *pOldBitmap = MemeDc.SelectObject(&bitmap);  
	int nOldMode = MemeDc.SetBkMode(TRANSPARENT);

	MemeDc.FillSolidRect(rect, rgbBK);
	MemeDc.SetTextColor(rgbFont);
	
	//设置字体
	//CFont* pFont= GetFont();//GetFont返回空
	/*CFont *pFont = Global::getFont();
	LOGFONT LogFont;
	pFont->GetLogFont(&LogFont);
	LogFont.lfHeight = rect.Height()/5*3;
	LogFont.lfWidth = LogFont.lfHeight/2;
	LogFont.lfWeight = FW_BOLD;
	if(m_font.m_hObject == NULL) m_font.CreateFontIndirect(&LogFont);
	CFont *pOldFont = MemeDc.SelectObject(&m_font);*/

	TEXTMETRIC tm;
	if(Global::getResolutionType() == 1)
	{
		CFont *pOldFont = MemeDc.SelectObject(Global::getFont());
		MemeDc.GetTextMetrics(&tm);
		MemeDc.SelectObject(pOldFont);
	}
	else
	{
		MemeDc.GetTextMetrics(&tm);
	}
	
	int nY = (rect.Height() - tm.tmHeight) / 2;
	CSize sizeType = MemeDc.GetTextExtent(m_szContent);
	int nX = (rect.Width()-sizeType.cx)/2;
	MemeDc.TextOut(nX, nY, m_szContent, strlen(m_szContent));

	pDC->BitBlt(rect.left, rect.top, rect.Width(), rect.Height(), &MemeDc, 0, 0,SRCCOPY);  
	MemeDc.SelectObject(pOldBitmap);
	MemeDc.SetBkMode(nOldMode);
	MemeDc.DeleteDC();
	m_font.DeleteObject();
}