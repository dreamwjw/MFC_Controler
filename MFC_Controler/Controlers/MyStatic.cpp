#include "MyStatic.h"


CMyStatic::CMyStatic(void)
{
	m_font.CreateFont(20,10,0,0,FW_NORMAL,FALSE,FALSE,FALSE,
		ANSI_CHARSET,OUT_CHARACTER_PRECIS,
		CLIP_CHARACTER_PRECIS,DEFAULT_QUALITY,
		FF_MODERN,"����");
	 m_rgbBackground = RGB(255,255,255);
	 m_rgbText = RGB(0,0,0);
	 m_bSetBackgroundColor = true;
}

CMyStatic::~CMyStatic(void)
{
	m_font.DeleteObject();
}

BEGIN_MESSAGE_MAP(CMyStatic, CStatic)
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
END_MESSAGE_MAP()

BOOL CMyStatic::OnEraseBkgnd(CDC* pDC)
{
	//ʹ��˫���壬���Բ���Ҫˢ�±���
	return TRUE;
}

void CMyStatic::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	//��ȡ�ı�
	CString cstrText;
	GetWindowText(cstrText);

	DrawText(&dc, cstrText);
}

void CMyStatic::DrawText(CDC* pDC, const CString& cstrText)
{
	if(1)
	{
		//˫����滭
		CRect rect;
		GetClientRect(rect);
		CDC memDC;
		CBitmap memBitmap;
		memDC.CreateCompatibleDC(pDC);
		memBitmap.CreateCompatibleBitmap(pDC,rect.Width(), rect.Height());
		memDC.SelectObject(&memBitmap);

		if(m_bSetBackgroundColor)
		{
			//���ñ�����ɫ
			memDC.SetBkColor(m_rgbBackground);
		}
		else
		{
			//����͸������
			memDC.SetBkMode(TRANSPARENT);
		}

		//����������ʽ
		memDC.SelectObject(m_font);

		//�����ı���ɫ
		memDC.SetTextColor(m_rgbText);

		//�滭�ı� 
		memDC.TextOut(rect.left, rect.top, cstrText);

		//���ڴ�dc��������ʾdc
		pDC->BitBlt(rect.left, rect.top, rect.Width(), rect.Height(),&memDC, 0, 0,SRCCOPY);

		//�ͷ���Դ
		memBitmap.DeleteObject();
		memDC.DeleteDC();
	}
	else
	{
		if(m_bSetBackgroundColor)
		{
			//���ñ�����ɫ
			pDC->SetBkColor(m_rgbBackground);
		}
		else
		{
			//����͸������
			pDC->SetBkMode(TRANSPARENT);
		}

		//����������ʽ
		pDC->SelectObject(m_font);

		//�����ı���ɫ
		pDC->SetTextColor(m_rgbText);

		//�滭�ı� 
		CRect rc;
		GetClientRect(&rc);
		pDC->TextOut(rc.left, rc.top, cstrText);
	}
}

int CMyStatic::SetFont(int nHeight = 20, // logical height of font height
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
	)
{
	m_font.DeleteObject();

	m_font.CreateFont(nHeight,nWidth,nEscapement,nOrientation,fnWeight,fdwItalic,fdwUnderline,fdwStrikeOut,
		fdwCharSet,fdwOutputPrecision,fdwClipPrecision,fdwQuality,fdwPitchAndFamily,lpszFace);

	return 0;
}

int CMyStatic::SetBackGroundColor(COLORREF rgbBackground)
{
	m_rgbBackground = rgbBackground;
	m_bSetBackgroundColor = true;

	return 0;
}

int CMyStatic::SetFontColor(COLORREF rgbText)
{
	m_rgbText = rgbText;
	
	return 0;
}

int CMyStatic::MySetWindowText(const CString& cstrText)
{
	CClientDC dc(this);

	DrawText(&dc, cstrText);

	return 0;
}