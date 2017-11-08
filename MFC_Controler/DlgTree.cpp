// DlgTree.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_Controler.h"
#include "DlgTree.h"
#include "afxdialogex.h"


// CDlgTree 对话框

IMPLEMENT_DYNAMIC(CDlgTree, CDialogEx)

CDlgTree::CDlgTree(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgTree::IDD, pParent)
{

}

CDlgTree::~CDlgTree()
{
}

void CDlgTree::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, m_Tree);
}


BEGIN_MESSAGE_MAP(CDlgTree, CDialogEx)
END_MESSAGE_MAP()


// CDlgTree 消息处理程序


BOOL CDlgTree::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	InitTree();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CDlgTree::InitTree()
{
	HTREEITEM hRoot = m_Tree.InsertItem("123456789123456789123456789123456789");

	for(int i = 0; i < 20; i++)
		m_Tree.InsertItem("test", hRoot);
}
