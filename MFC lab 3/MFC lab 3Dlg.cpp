
// MFC lab 3Dlg.cpp : файл реализации
//

#include "stdafx.h"
#include "MFC lab 3.h"
#include "MFC lab 3Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// диалоговое окно CMFClab3Dlg



CMFClab3Dlg::CMFClab3Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCLAB3_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFClab3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFClab3Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()


// обработчики сообщений CMFClab3Dlg

BOOL CMFClab3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CMFClab3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CMFClab3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFClab3Dlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	flagR = true;
	m_StartPoint = point;
	CDialogEx::OnRButtonDown(nFlags, point);
}


void CMFClab3Dlg::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	flagR = false;
	m_EndPoint = point;
	CDialogEx::OnRButtonUp(nFlags, point);
}


void CMFClab3Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	if (flagR) {
		CPen pen(PS_SOLID,30,RGB(0,0,255));
		CBrush brush(RGB(0, 0, 255));
		dc.SelectObject(pen);
		dc.SelectObject(brush);
		dc.Ellipse(point.x + 10, point.y + 10, point.x-10, point.y-10);
	}
	if (flagL) {
		CPen pen(PS_SOLID, 1, RGB(0, 0, 0));
		CBrush brush(RGB(0, 0, 0));
		dc.SelectObject(pen);
		dc.SelectObject(brush);
		dc.MoveTo(m_StartPoint);
		m_StartPoint = point;
		dc.LineTo(point);
	}
	CDialogEx::OnMouseMove(nFlags, point);
}


void CMFClab3Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	flagL = true;
	m_StartPoint = point;
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMFClab3Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	flagL = false;
	m_EndPoint = point;
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CMFClab3Dlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	switch (nChar)
	{
		case(0x51): SetCursor(::LoadCursor(NULL, IDC_ARROW));
		case(0x57): SetCursor(::LoadCursor(NULL, IDC_SIZEALL));
		case(0x45): SetCursor(::LoadCursor(NULL, IDC_CROSS));
	}
	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}
