
// MFC lab 3.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMFClab3App:
// О реализации данного класса см. MFC lab 3.cpp
//

class CMFClab3App : public CWinApp
{
public:
	CMFClab3App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMFClab3App theApp;