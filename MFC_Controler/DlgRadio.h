#pragma once
#include "afxwin.h"

#include "MyRadio.h"

// CDlgRadio �Ի���

class CDlgRadio : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgRadio)

public:
	CDlgRadio(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgRadio();

// �Ի�������
	enum { IDD = IDD_DLG_RADIO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

private:
	CMyRadio m_Radio;

private:
	void InitDlg();
	void InitControler();

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
};
