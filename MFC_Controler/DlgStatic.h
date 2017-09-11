#pragma once

#include "MyStatic.h"

// CDlgStatic �Ի���

class CDlgStatic : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgStatic)

public:
	CDlgStatic(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgStatic();

// �Ի�������
	enum { IDD = IDD_DLG_STATIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

private:
	CMyStatic m_MyStatic;

private:
	void InitDlg();
	void InitControler();

private:
	static UINT ThreadGetVideoData(LPVOID lpVoid);

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
};
