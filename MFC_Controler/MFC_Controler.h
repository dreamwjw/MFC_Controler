
// MFC_Controler.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFC_ControlerApp:
// �йش����ʵ�֣������ MFC_Controler.cpp
//

class CMFC_ControlerApp : public CWinApp
{
public:
	CMFC_ControlerApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFC_ControlerApp theApp;