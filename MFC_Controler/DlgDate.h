#pragma once

#include "KbcButton.h"
#include "MyEdit.h"
#include "MyStatic.h"

// CDlgDate 对话框

class CDlgDate : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgDate)

public:
	CDlgDate(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgDate();

// 对话框数据
	enum { IDD = IDD_DLG_DATE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

private:
	/*CKbcButton m_KbcYearLeft, m_KbcYearRight, m_KbcMonthLeft, m_KbcMonthRight;
	CKbcButton m_KbcDay1, m_KbcDay2, m_KbcDay3, m_KbcDay4, m_KbcDay5, m_KbcDay6, m_KbcDay7,
		m_KbcDay8, m_KbcDay9, m_KbcDay10, m_KbcDay11, m_KbcDay12, m_KbcDay13, m_KbcDay14, 
		m_KbcDay15, m_KbcDay16, m_KbcDay17, m_KbcDay18, m_KbcDay19, m_KbcDay20, m_KbcDay21,
		m_KbcDay22, m_KbcDay23, m_KbcDay24, m_KbcDay25, m_KbcDay26, m_KbcDay27, m_KbcDay28, 
		m_KbcDay29, m_KbcDay30, m_KbcDay31, m_KbcDay32, m_KbcDay33, m_KbcDay34, m_KbcDay35, 
		m_KbcDay36, m_KbcDay37, m_KbcDay38, m_KbcDay39, m_KbcDay40, m_KbcDay41, m_KbcDay42;*/
	CMyEdit m_myeditYear, m_myeditMonth;
	CMyStatic m_mystaticSun, m_mystaticMon, m_mystaticTue, m_mystaticWed, m_mystaticThu, m_mystaticFri,m_mystaticSat;

private:
	void MoveControler();
};
