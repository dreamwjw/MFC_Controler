// DlgDate.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_Controler.h"
#include "DlgDate.h"
#include "afxdialogex.h"


// CDlgDate 对话框

IMPLEMENT_DYNAMIC(CDlgDate, CDialogEx)

CDlgDate::CDlgDate(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgDate::IDD, pParent)
{

}

CDlgDate::~CDlgDate()
{
}

void CDlgDate::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_YEAR, m_myeditYear);
	DDX_Control(pDX, IDC_EDIT_MONTH, m_myeditMonth);
	DDX_Control(pDX, IDC_STATIC_SUN, m_mystaticSun);
	DDX_Control(pDX, IDC_STATIC_MON, m_mystaticMon);
	DDX_Control(pDX, IDC_STATIC_TUE, m_mystaticTue);
	DDX_Control(pDX, IDC_STATIC_WED, m_mystaticWed);
	DDX_Control(pDX, IDC_STATIC_THU, m_mystaticThu);
	DDX_Control(pDX, IDC_STATIC_FRI, m_mystaticFri);
	DDX_Control(pDX, IDC_STATIC_SAT, m_mystaticSat);
}


BEGIN_MESSAGE_MAP(CDlgDate, CDialogEx)
END_MESSAGE_MAP()


// CDlgDate 消息处理程序

void CDlgDate::MoveControler()
{
	CRect rect;
	GetClientRect(rect);


}