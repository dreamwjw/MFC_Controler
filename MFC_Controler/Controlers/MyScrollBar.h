#if !defined(AFX_VMCUBASESCROLLBAR_H__EB442742_EC74_4F6F_94FA_7833E431C59A__INCLUDED_)
#define AFX_VMCUBASESCROLLBAR_H__EB442742_EC74_4F6F_94FA_7833E431C59A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ScrollBarEx.h : header file
//
//Author: Nobita
//Date: 2010.01.29
//I love Doraemon!!!

/////////////////////////////////////////////////////////////////////////////
// CScrollBarEx window

class CMyScrollBar : public CStatic
{
	// Construction
public:
	CMyScrollBar();
	
	// Attributes
public:
	BOOL InitScrollBar(CWnd *pCtrl, UINT nStyle, int nType);
	void UpdateScrollBar();
	
	// Operations
public:
	
	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScrollBarEx)
	//}}AFX_VIRTUAL
	
	// Implementation
public:
	virtual ~CMyScrollBar();
	
	// Generated message map functions
protected:
	//{{AFX_MSG(CScrollBarEx)
	afx_msg void OnPaint();
	//}}AFX_MSG
	
	DECLARE_MESSAGE_MAP()
private:
	CWnd* m_pCtrl;
	UINT m_nScrollStyle;
	int m_nHLeft, m_nHRight, m_nHSCenter, m_nHSLeft, m_nHSRight, m_nHSpan, m_nHThumb,
		m_nVDown, m_nVUp, m_nVSCenter, m_nVSBottom, m_nVSTop, m_nVSpan, m_nVThumb;
private:
	void DrawVScroll(CDC* pDC);
	void DrawHScroll(CDC* pDC);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VMCUBASESCROLLBAR_H__EB442742_EC74_4F6F_94FA_7833E431C59A__INCLUDED_)

//使用须知
//1、在所属类的PreSubclassWindow调用InitScrollBar，例如InitScrollBar(this,SB_HORZ,0)
//2、在所属类的OnPaint或者DrawItem调用UpdateScrollBar
//3、貌似树控件的水平滚动条有问题，当文本超出一定范围才显示出来，长度估算有问题