#pragma once
#include "afxwin.h"

#include "MyEdit.h"

// CDlgEdit �Ի���

class CDlgEdit : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgEdit)

public:
	CDlgEdit(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgEdit();

// �Ի�������
	enum { IDD = IDD_DLG_EDIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
