
// MFC lab 3.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CMFClab3App:
// � ���������� ������� ������ ��. MFC lab 3.cpp
//

class CMFClab3App : public CWinApp
{
public:
	CMFClab3App();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CMFClab3App theApp;