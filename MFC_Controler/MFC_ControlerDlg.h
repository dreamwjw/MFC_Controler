
// MFC_ControlerDlg.h : 头文件
//

#pragma once

#include "DlgStatic.h"

// CMFC_ControlerDlg 对话框
class CMFC_ControlerDlg : public CDialogEx
{
// 构造
public:
	CMFC_ControlerDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFC_CONTROLER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	CDlgStatic m_DlgStatic;

private:
	void InitChildDlg();

public:
	afx_msg void OnBnClickedButtonStatic();
};
