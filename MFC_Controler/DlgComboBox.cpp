// DlgComboBox.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_Controler.h"
#include "DlgComboBox.h"
#include "afxdialogex.h"

// CDlgComboBox �Ի���

IMPLEMENT_DYNAMIC(CDlgComboBox, CDialogEx)

CDlgComboBox::CDlgComboBox(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgComboBox::IDD, pParent)
{

}

CDlgComboBox::~CDlgComboBox()
{
}

void CDlgComboBox::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_COMBOBOX, m_Combobox);
}


BEGIN_MESSAGE_MAP(CDlgComboBox, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgComboBox ��Ϣ�������


BOOL CDlgComboBox::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	InitDlg();
	InitControler();

	SetDlgItemText(IDC_TEST, "testestsetsetestsetsetsetsetes");

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CDlgComboBox::InitDlg()
{
	int nScreenWidth = ::GetSystemMetrics(SM_CXSCREEN);
	int nScreenHeight = ::GetSystemMetrics(SM_CYSCREEN);

	int nDlgWidth = static_cast<int>(nScreenWidth * 0.3);
	int nDlgHeight = static_cast<int>(nScreenHeight * 0.3);
	int nDlgX = (nScreenWidth - nDlgWidth)/2;
	int nDlgY = (nScreenHeight - nDlgHeight)/2;
	MoveWindow(nDlgX, nDlgY, nDlgWidth, nDlgHeight, TRUE);
}

void CDlgComboBox::InitControler()
{
	CRect rect;
	GetClientRect(rect);
	int nDlgWidth = rect.Width();
	int nDlgHeight = rect.Height();

	int nStatic_Width = nDlgWidth/10*2;
	int nStatic_Height = nDlgHeight/10*2;
	int nStatic_X = (nDlgWidth - nStatic_Width)/2;
	int nStatic_Y = (nDlgHeight - nStatic_Height)/2;
	m_Combobox.MoveWindow(nStatic_X, nStatic_Y, nStatic_Width, nStatic_Height);
	m_Combobox.Init();
	m_Combobox.MySetItemHeight(nStatic_Height);
	CString cstrText;
	for(int i = 0; i < 5; i++)
	{
		cstrText.Format("testtesttest%d", i);
		m_Combobox.MyAddString(cstrText);
	}
}

void CDlgComboBox::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()

	CRect rect;
	GetClientRect(rect);
	//dc.FillSolidRect(rect, RGB(255,0,0));
}
