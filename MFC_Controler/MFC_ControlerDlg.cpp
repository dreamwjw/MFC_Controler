
// MFC_ControlerDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_Controler.h"
#include "MFC_ControlerDlg.h"
#include "afxdialogex.h"

#include "DlgMutiEdit.h"
#include "DlgTimeAxisCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_ControlerDlg 对话框

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
	ON_BN_CLICKED(IDC_BUTTON_SCROLLBAR, &CMFC_ControlerDlg::OnBnClickedButtonScrollbar)
	ON_BN_CLICKED(IDC_BUTTON_META, &CMFC_ControlerDlg::OnBnClickedButtonMeta)
	ON_BN_CLICKED(IDC_BUTTON_CHECK, &CMFC_ControlerDlg::OnBnClickedButtonCheck)
	ON_BN_CLICKED(IDC_BTN_MUTI_EDIT, &CMFC_ControlerDlg::OnBnClickedBtnMutiEdit)
	ON_BN_CLICKED(IDC_BTN_TIME_AXIS_CTRL, &CMFC_ControlerDlg::OnBnClickedBtnTimeAxisCtrl)
END_MESSAGE_MAP()


// CMFC_ControlerDlg 消息处理程序


BOOL CMFC_ControlerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	InitChildDlg();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFC_ControlerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
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
	m_DlgScrollBar.Create(IDD_DLG_SCROLLBAR, this);
	m_DlgMeta.Create(IDD_DLG_META, this);
	m_DlgCheckBox.Create(IDD_DLG_CHECKBOX, this);
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


void CMFC_ControlerDlg::OnBnClickedButtonScrollbar()
{
	m_DlgScrollBar.ShowWindow(SW_SHOW);
}


void CMFC_ControlerDlg::OnBnClickedButtonMeta()
{
	//m_DlgMeta.ShowWindow(SW_SHOW);
	CDlgMeta dlg;
	dlg.DoModal();
}


void CMFC_ControlerDlg::OnBnClickedButtonCheck()
{
	m_DlgCheckBox.ShowWindow(SW_SHOW);
}


void CMFC_ControlerDlg::OnBnClickedBtnMutiEdit()
{
	CDlgMutiEdit dlg;
	dlg.DoModal();
}


void CMFC_ControlerDlg::OnBnClickedBtnTimeAxisCtrl()
{
	CDlgTimeAxisCtrl dlg;
	dlg.DoModal();
}
