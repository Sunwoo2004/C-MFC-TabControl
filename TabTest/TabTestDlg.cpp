
// TabTestDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"

#include "TabTest.h"
#include "TabTestDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTabTestDlg 대화 상자



CTabTestDlg::CTabTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TABTEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTabTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_MAIN, m_MainTab);
}

BEGIN_MESSAGE_MAP(CTabTestDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_MAIN, &CTabTestDlg::OnSelchangeTabMain)
END_MESSAGE_MAP()


// CTabTestDlg 메시지 처리기

BOOL CTabTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CRect rect;
	m_MainTab.GetWindowRect(rect);

	m_MainTab.InsertItem(0, "tab1");
	m_MainTab.InsertItem(0, "tab2");
	m_MainTab.InsertItem(0, "tab3");

	m_MainTab.SetCurSel(0);

	dlg1 = new CDlgTab1();
	dlg1->Create(IDD_TAB_DIALOG1, &m_MainTab);
	dlg1->MoveWindow(0, 20, rect.Width(), rect.Height());
	dlg1->ShowWindow(SW_SHOW);

	dlg2 = new CDlgTab2();
	dlg2->Create(IDD_TAB_DIALOG2, &m_MainTab);
	dlg2->MoveWindow(0, 20, rect.Width(), rect.Height());
	dlg2->ShowWindow(SW_HIDE);

	dlg3 = new CDlgTab3();
	dlg3->Create(IDD_TAB_DIALOG3, &m_MainTab);
	dlg3->MoveWindow(0, 20, rect.Width(), rect.Height());
	dlg3->ShowWindow(SW_HIDE);




	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

	return TRUE;
}


void CTabTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CTabTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTabTestDlg::OnSelchangeTabMain(NMHDR* pNMHDR, LRESULT* pResult)
{
	if (IDC_TAB_MAIN == pNMHDR->idFrom)
	{
		int iSelect = m_MainTab.GetCurSel();
		switch (iSelect)
		{
		case 0:
			dlg1->ShowWindow(SW_SHOW);
			dlg2->ShowWindow(SW_HIDE);
			dlg3->ShowWindow(SW_HIDE);
			break;
		case 1:
			dlg1->ShowWindow(SW_HIDE);
			dlg2->ShowWindow(SW_SHOW);
			dlg3->ShowWindow(SW_HIDE);
			break;
		case 2:
			dlg1->ShowWindow(SW_HIDE);
			dlg2->ShowWindow(SW_HIDE);
			dlg3->ShowWindow(SW_SHOW);
			break;
		default:
			break;
		}
	}
	*pResult = 0;
}
