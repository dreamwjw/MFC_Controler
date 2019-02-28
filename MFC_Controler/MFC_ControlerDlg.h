
// MFC_ControlerDlg.h : 头文件
//

#pragma once

#include "DlgStatic.h"
#include "DlgEdit.h"
#include "DlgRadio.h"
#include "DlgComboBox.h"
#include "DlgTree.h"
#include "DlgScrollBar.h"
#include "DlgMeta.h"
#include "DlgCheckBox.h"

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
	CDlgEdit m_DlgEdit;
	CDlgRadio m_DlgRadio;
	CDlgComboBox m_DlgComboBox;
	CDlgTree m_DlgTree;
	CDlgScrollBar m_DlgScrollBar;
	CDlgMeta m_DlgMeta;
	CDlgCheckBox m_DlgCheckBox;

private:
	void InitChildDlg();

public:
	afx_msg void OnBnClickedButtonStatic();
	afx_msg void OnBnClickedButtonEdit();
	afx_msg void OnBnClickedButtonRadio();
	afx_msg void OnBnClickedButtonCombobox();
	afx_msg void OnBnClickedButtonTree();
	afx_msg void OnBnClickedButtonScrollbar();
	afx_msg void OnBnClickedButtonMeta();
	afx_msg void OnBnClickedButtonCheck();
	afx_msg void OnBnClickedBtnMutiEdit();
	afx_msg void OnBnClickedBtnTimeAxisCtrl();
};
