
// MFC_ControlerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_Controler.h"
#include "MFC_ControlerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_ControlerDlg �Ի���

CMFC_ControlerDlg::CMFC_ControlerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC_ControlerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_ControlerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFC_ControlerDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_STATIC, &CMFC_ControlerDlg::OnBnClickedButtonStatic)
	ON_BN_CLICKED(IDC_BUTTON_EDIT, &CMFC_ControlerDlg::OnBnClickedButtonEdit)
	ON_BN_CLICKED(IDC_BUTTON_RADIO, &CMFC_ControlerDlg::OnBnClickedButtonRadio)
	ON_BN_CLICKED(IDC_BUTTON_COMBOBOX, &CMFC_ControlerDlg::OnBnClickedButtonCombobox)
	ON_BN_CLICKED(IDC_BUTTON_TREE, &CMFC_ControlerDlg::OnBnClickedButtonTree)
END_MESSAGE_MAP()


// CMFC_ControlerDlg ��Ϣ�������


BOOL CMFC_ControlerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	InitChildDlg();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFC_ControlerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFC_ControlerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFC_ControlerDlg::OnBnClickedButtonStatic()
{
	m_DlgStatic.ShowWindow(SW_SHOW);
}

void CMFC_ControlerDlg::InitChildDlg()
{
	m_DlgStatic.Create(IDD_DLG_STATIC, this);
	m_DlgEdit.Create(IDD_DLG_EDIT, this);
	m_DlgRadio.Create(IDD_DLG_RADIO, this);
	m_DlgComboBox.Create(IDD_DLG_COMBOBOX, this);
	m_DlgTree.Create(IDD_DLG_TREE, this);
}

void CMFC_ControlerDlg::OnBnClickedButtonEdit()
{
	m_DlgEdit.ShowWindow(SW_SHOW);
}


void CMFC_ControlerDlg::OnBnClickedButtonRadio()
{
	m_DlgRadio.ShowWindow(SW_SHOW);
}


void CMFC_ControlerDlg::OnBnClickedButtonCombobox()
{
	m_DlgComboBox.ShowWindow(SW_SHOW);
}


void CMFC_ControlerDlg::OnBnClickedButtonTree()
{
	m_DlgTree.ShowWindow(SW_SHOW);
}
