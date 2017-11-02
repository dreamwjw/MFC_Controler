#pragma once
#include "afxcmn.h"


// CDlgTree 对话框

class CDlgTree : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTree)

public:
	CDlgTree(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgTree();

// 对话框数据
	enum { IDD = IDD_DLG_TREE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

private:
	void InitTree();

public:
	CTreeCtrl m_Tree;
	virtual BOOL OnInitDialog();
};
