#pragma once
#include "afxwin.h"


// CDlgComboBox 对话框

class CDlgComboBox : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgComboBox)

public:
	CDlgComboBox(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgComboBox();

// 对话框数据
	enum { IDD = IDD_DLG_COMBOBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

private:
	CComboBox m_ComboBox;

private:
	void InitDlg();
	void InitControler();

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
};
