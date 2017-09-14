// DlgRadio.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_Controler.h"
#include "DlgRadio.h"
#include "afxdialogex.h"


// CDlgRadio 对话框

IMPLEMENT_DYNAMIC(CDlgRadio, CDialogEx)

CDlgRadio::CDlgRadio(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgRadio::IDD, pParent)
{

}

CDlgRadio::~CDlgRadio()
{
}

void CDlgRadio::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_Radio);
}


BEGIN_MESSAGE_MAP(CDlgRadio, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgRadio 消息处理程序


void CDlgRadio::InitDlg()
{
	int nScreenWidth = ::GetSystemMetrics(SM_CXSCREEN);
	int nScreenHeight = ::GetSystemMetrics(SM_CYSCREEN);

	int nDlgWidth = static_cast<int>(nScreenWidth * 0.3);
	int nDlgHeight = static_cast<int>(nScreenHeight * 0.3);
	int nDlgX = (nScreenWidth - nDlgWidth)/2;
	int nDlgY = (nScreenHeight - nDlgHeight)/2;
	MoveWindow(nDlgX, nDlgY, nDlgWidth, nDlgHeight, TRUE);
}

void CDlgRadio::InitControler()
{
	CRect rect;
	GetClientRect(rect);
	int nDlgWidth = rect.Width();
	int nDlgHeight = rect.Height();

	int nStatic_Width = nDlgWidth/10*2;
	int nStatic_Height = nDlgHeight/10;
	int nStatic_X = (nDlgWidth - nStatic_Width)/2;
	int nStatic_Y = (nDlgHeight - nStatic_Height)/2;
	m_Radio.MoveWindow(nStatic_X, nStatic_Y, nStatic_Width, nStatic_Height);
	m_Radio.SetWindowText("test");
	m_Radio.LoadBitmaps(IDR_RADIO_CHECKED, IDR_RADIO_UNCHECKED);
}

BOOL CDlgRadio::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	InitDlg();
	InitControler();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CDlgRadio::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()

	CRect rect;
	GetClientRect(rect);
	dc.FillSolidRect(rect, RGB(255,0,0));
}