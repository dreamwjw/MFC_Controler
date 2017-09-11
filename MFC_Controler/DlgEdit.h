#pragma once
#include "afxwin.h"

#include "MyEdit.h"

// CDlgEdit 对话框

class CDlgEdit : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgEdit)

public:
	CDlgEdit(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgEdit();

// 对话框数据
	enum { IDD = IDD_DLG_EDIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

private:
	CMyEdit m_Edit;

private:
	void InitDlg();
	void InitControler();

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
};
