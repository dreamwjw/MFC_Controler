#if !defined(AFX_KBCBMP_H__3B18A7EA_F8CB_4410_8E1E_AA0B72F039BB__INCLUDED_)
#define AFX_KBCBMP_H__3B18A7EA_F8CB_4410_8E1E_AA0B72F039BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// KbcBmp.h : header file
//

#include "JPGPicture.h"

/////////////////////////////////////////////////////////////////////////////
// CKbcBmp view
//

class CKbcBmp : public CView
{
public:
	void				LoadBitmap(CString);
	void				LoadBitmap(UINT nID);
	
	void				Draw(CDC *pDC,int nSeq,int nX,int nY,UINT nMask);	

	int					GetWidth()		 { return m_nWidth; }
	int					GetHeight()		 { return m_nHeight; }
	int					GetSliceWidth()	 { return m_nSliceWidth; }
	BOOL				IsOK(){return m_picImg.IsOK();}
protected:
	CJPGPicture			m_picImg;

	int					m_nWidth;	
	int					m_nHeight;
	int					m_nSliceWidth;

	int                 m_nBTWidth;
	int                 m_nBTHeight;
public:
	void                SetBTWidth(int nBTWidth){m_nBTWidth = nBTWidth;};
	void                SetBTHeight(int nBTHeight){m_nBTHeight = nBTHeight;};

protected:
	
	DECLARE_DYNCREATE(CKbcBmp)
	
// Attributes
public:
	CKbcBmp();           // protected constructor used by dynamic creation
	virtual ~CKbcBmp();
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKbcBmp)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CKbcBmp)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KBCBMP_H__3B18A7EA_F8CB_4410_8E1E_AA0B72F039BB__INCLUDED_)
