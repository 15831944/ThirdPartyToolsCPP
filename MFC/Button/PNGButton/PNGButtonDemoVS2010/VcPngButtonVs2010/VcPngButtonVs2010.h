
// VcPngButtonVs2010.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CVcPngButtonVs2010App:
// �йش����ʵ�֣������ VcPngButtonVs2010.cpp
//

class CVcPngButtonVs2010App : public CWinApp
{
public:
	CVcPngButtonVs2010App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CVcPngButtonVs2010App theApp;