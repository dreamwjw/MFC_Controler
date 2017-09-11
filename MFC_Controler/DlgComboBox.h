#pragma once
#include "afxwin.h"


// CDlgComboBox �Ի���

class CDlgComboBox : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgComboBox)

public:
	CDlgComboBox(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgComboBox();

// �Ի�������
	enum { IDD = IDD_DLG_COMBOBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
