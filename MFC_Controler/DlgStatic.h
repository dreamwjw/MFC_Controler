#pragma once

#include "MyStatic.h"

// CDlgStatic 对话框

class CDlgStatic : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgStatic)

public:
	CDlgStatic(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgStatic();

// 对话框数据
	enum { IDD = IDD_DLG_STATIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
