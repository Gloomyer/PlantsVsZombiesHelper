
// PlantsVsZombiesHelper.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CPlantsVsZombiesHelperApp: 
// �йش����ʵ�֣������ PlantsVsZombiesHelper.cpp
//

class CPlantsVsZombiesHelperApp : public CWinApp
{
public:
	CPlantsVsZombiesHelperApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CPlantsVsZombiesHelperApp theApp;