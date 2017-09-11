#pragma once
#include "afxwin.h"

#include "MyRadio.h"

// CDlgRadio 对话框

class CDlgRadio : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgRadio)

public:
	CDlgRadio(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgRadio();

// 对话框数据
	enum { IDD = IDD_DLG_RADIO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

private:
	void InitDlg();
	void InitControler();

public:
	CMyRadio m_Radio;
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
};
