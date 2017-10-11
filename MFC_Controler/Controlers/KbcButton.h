//-----------------------------------------------------------------------------
// CKbcButton (Transparant image button)
//
// Feature - 1.transparant button
//			 2.diverse image support(BMP,JPG,GIF..) 
//			 3.easy to use :)
//
// 
// 
// Author: kbckbc, EMail: kbckbc@postech.ac.kr, Web: kbckbc.com 
// Thanks to 'Dr. Yovav Gad(CPicture)'
//-----------------------------------------------------------------------------


#if !defined(AFX_KBCBUTTON_H__41D0AB53_20C4_4079_B3E2_3E8B6B337CD5__INCLUDED_)
#define AFX_KBCBUTTON_H__41D0AB53_20C4_4079_B3E2_3E8B6B337CD5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// KbcButton.h : header file
//

#include "KbcBmp.h"

class CKbcButton : public CButton
{
public:
	enum BUTTON_STATE
	{
		BUTTON_ENABLE = 0,
		BUTTON_HOVER,
		BUTTON_CLICK,
		BUTTON_DISABLE
	};
	BOOL LoadBitmaps(
					UINT nIDBitmapResource,
					UINT nIDBitmapResourceSel = 0,
					UINT nIDBitmapResourceFocus = 0,
					UINT nIDBitmapResourceDisabled = 0
					);
	BOOL LoadFontAndBackGround(const char* szContent, 
		COLORREF rgbFontNormal, COLORREF rgbFontSelect, COLORREF rgbFontFocus, COLORREF rgbFontDisabled,
		COLORREF rgbBKNormal, COLORREF rgbBKSelect, COLORREF rgbBKFocus, COLORREF rgbBKDisabled);
	void SizeToContent();

	void			SetButtonImage(CString strFileName,UINT nMakse); // set button image..	
	void			SetButtonEnable();// make button enable/disable
	void			SetButtonDisable();	
	void			InitToolTip();
	void			SetToolTipText(CString strText);// set tooltip message	
	void			SetCursor(HCURSOR hCursor);// set cursor
	void            DrawFontAndBackGround(CDC *pDC, COLORREF rgbFont, COLORREF rgbBK);

protected:
	CKbcBmp			m_bmpImage;			// save image.
	CKbcBmp			m_bmpImageSel;			// save image.
	CKbcBmp			m_bmpImageFocus;			// save image.
	CKbcBmp			m_bmpImageDisable;			// save image.

	char m_szContent[20];
	COLORREF m_rgbFontNormal, m_rgbFontSelect, m_rgbFontFocus, m_rgbFontDisabled,
	m_rgbBKNormal, m_rgbBKSelect, m_rgbBKFocus, m_rgbBKDisabled;

	UINT			m_nMask;			// save mask
	BOOL			m_bDisable;			// enable or disable	
	CRect			m_rectButton;		// about button's position
	CRect			m_rectButtonPos;	// about button's position
	BOOL			m_bCursorOnButton; 	// cursor is on button or not.
	BOOL			m_bHover;			// determine button state is hover or not.
	CToolTipCtrl	m_ToolTip;			// for tooltip message..	
	BOOL			m_bSetCursor;
	HCURSOR			m_hCursor;			// set cursor	
	
	BOOL			m_bChageColor;		//can change color

	BOOL            m_bIsFontAndBackGround;

	CFont           m_font;

public:
	BOOL            m_bIsSelected;      // change select state

// Construction
public:
	CKbcButton();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKbcButton)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CKbcButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CKbcButton)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	afx_msg LRESULT OnMouseLeave(WPARAM wparam, LPARAM lparam);
	afx_msg LRESULT OnMouseHover(WPARAM wparam, LPARAM lparam);
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KBCBUTTON_H__41D0AB53_20C4_4079_B3E2_3E8B6B337CD5__INCLUDED_)
