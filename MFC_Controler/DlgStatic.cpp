// DlgStatic.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_Controler.h"
#include "DlgStatic.h"
#include "afxdialogex.h"


// CDlgStatic 对话框

IMPLEMENT_DYNAMIC(CDlgStatic, CDialogEx)

CDlgStatic::CDlgStatic(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgStatic::IDD, pParent)
{

}

CDlgStatic::~CDlgStatic()
{
}

void CDlgStatic::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_1, m_MyStatic);
}


BEGIN_MESSAGE_MAP(CDlgStatic, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgStatic 消息处理程序


BOOL CDlgStatic::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	InitDlg();
	InitControler();

	//AfxBeginThread(ThreadGetVideoData, this);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CDlgStatic::InitDlg()
{
	int nScreenWidth = ::GetSystemMetrics(SM_CXSCREEN);
	int nScreenHeight = ::GetSystemMetrics(SM_CYSCREEN);

	int nDlgWidth = static_cast<int>(nScreenWidth * 0.3);
	int nDlgHeight = static_cast<int>(nScreenHeight * 0.3);
	int nDlgX = (nScreenWidth - nDlgWidth)/2;
	int nDlgY = (nScreenHeight - nDlgHeight)/2;
	MoveWindow(nDlgX, nDlgY, nDlgWidth, nDlgHeight, TRUE);
}

void CDlgStatic::InitControler()
{
	CRect rect;
	GetClientRect(rect);
	int nDlgWidth = rect.Width();
	int nDlgHeight = rect.Height();

	int nStatic_Width = nDlgWidth/10*2;
	int nStatic_Height = nDlgHeight/10*2;
	int nStatic_X = (nDlgWidth - nStatic_Width)/2;
	int nStatic_Y = (nDlgHeight - nStatic_Height)/2;
	m_MyStatic.MoveWindow(nStatic_X, nStatic_Y, nStatic_Width, nStatic_Height);
}

void CDlgStatic::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	CRect rect;
	GetClientRect(rect);
	dc.FillSolidRect(rect, RGB(255,0,0));
}

UINT CDlgStatic::ThreadGetVideoData(LPVOID lpVoid)
{
	CDlgStatic* pDlgStatic = (CDlgStatic*)lpVoid;
	int n = 0;
	CString cstrText;
	while(1)
	{
		cstrText.Format("%d", n);
		pDlgStatic->m_MyStatic.MySetWindowText(cstrText);
		n++;
		Sleep(1000);
	}
}