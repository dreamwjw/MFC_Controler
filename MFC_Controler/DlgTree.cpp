// DlgTree.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_Controler.h"
#include "DlgTree.h"
#include "afxdialogex.h"


// CDlgTree �Ի���

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


// CDlgTree ��Ϣ�������


BOOL CDlgTree::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	InitTree();

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CDlgTree::InitTree()
{
	HTREEITEM hRoot = m_Tree.InsertItem("123456789123456789123456789123456789");

	for(int i = 0; i < 20; i++)
		m_Tree.InsertItem("test", hRoot);
}
