// DlgRadio.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_Controler.h"
#include "DlgRadio.h"
#include "afxdialogex.h"


// CDlgRadio �Ի���

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


// CDlgRadio ��Ϣ�������


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

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	InitDlg();
	InitControler();

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CDlgRadio::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()

	CRect rect;
	GetClientRect(rect);
	dc.FillSolidRect(rect, RGB(255,0,0));
}