#pragma once
#include "afxcmn.h"


// CDlgTree �Ի���

class CDlgTree : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTree)

public:
	CDlgTree(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgTree();

// �Ի�������
	enum { IDD = IDD_DLG_TREE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

private:
	void InitTree();

public:
	CTreeCtrl m_Tree;
	virtual BOOL OnInitDialog();
};
