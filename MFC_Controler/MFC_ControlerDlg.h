
// MFC_ControlerDlg.h : ͷ�ļ�
//

#pragma once

#include "DlgStatic.h"
#include "DlgEdit.h"
#include "DlgRadio.h"
#include "DlgComboBox.h"
#include "DlgTree.h"

// CMFC_ControlerDlg �Ի���
class CMFC_ControlerDlg : public CDialogEx
{
// ����
public:
	CMFC_ControlerDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFC_CONTROLER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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

private:
	void InitChildDlg();

public:
	afx_msg void OnBnClickedButtonStatic();
	afx_msg void OnBnClickedButtonEdit();
	afx_msg void OnBnClickedButtonRadio();
	afx_msg void OnBnClickedButtonCombobox();
	afx_msg void OnBnClickedButtonTree();
};
