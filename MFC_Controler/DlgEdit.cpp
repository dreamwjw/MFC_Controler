// DlgEdit.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_Controler.h"
#include "DlgEdit.h"
#include "afxdialogex.h"


// CDlgEdit �Ի���

IMPLEMENT_DYNAMIC(CDlgEdit, CDialogEx)

CDlgEdit::CDlgEdit(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgEdit::IDD, pParent)
{

}

CDlgEdit::~CDlgEdit()
{
}

void CDlgEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Edit);
}


BEGIN_MESSAGE_MAP(CDlgEdit, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgEdit ��Ϣ�������


BOOL CDlgEdit::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	InitDlg();
	InitControler();

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CDlgEdit::InitDlg()
{
	int nScreenWidth = ::GetSystemMetrics(SM_CXSCREEN);
	int nScreenHeight = ::GetSystemMetrics(SM_CYSCREEN);

	int nDlgWidth = static_cast<int>(nScreenWidth * 0.3);
	int nDlgHeight = static_cast<int>(nScreenHeight * 0.3);
	int nDlgX = (nScreenWidth - nDlgWidth)/2;
	int nDlgY = (nScreenHeight - nDlgHeight)/2;
	MoveWindow(nDlgX, nDlgY, nDlgWidth, nDlgHeight, TRUE);
}

void CDlgEdit::InitControler()
{
	CRect rect;
	GetClientRect(rect);
	int nDlgWidth = rect.Width();
	int nDlgHeight = rect.Height();

	int nStatic_Width = nDlgWidth/10*2;
	int nStatic_Height = nDlgHeight/10*2;
	int nStatic_X = (nDlgWidth - nStatic_Width)/2;
	int nStatic_Y = (nDlgHeight - nStatic_Height)/2;
	m_Edit.MoveWindow(nStatic_X, nStatic_Y, nStatic_Width, nStatic_Height);
	m_Edit.SetWindowText("test");
}


void CDlgEdit::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()

	CRect rect;
	GetClientRect(rect);
	dc.FillSolidRect(rect, RGB(255,0,0));
}
