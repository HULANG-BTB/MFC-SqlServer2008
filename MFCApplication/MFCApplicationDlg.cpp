
// MFCApplicationDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication.h"
#include "MFCApplicationDlg.h"
#include "afxdialogex.h"
#include "Preview.h"
#include "UpdateInfo.h"
#include "UpdatePass.h"
#include "StaticInfo.h"
#include "UserLogin.h"
#include "User.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

extern User* UserInfo;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplicationDlg 对话框



CMFCApplicationDlg::CMFCApplicationDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApplicationDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplicationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplicationDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_OPEN_IMAGE, &CMFCApplicationDlg::OnBnClickedButtonOpenImage)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CMFCApplicationDlg::OnBnClickedButtonExit)
	ON_BN_CLICKED(IDC_BUTTON_RUN, &CMFCApplicationDlg::OnBnClickedButtonRun)
	ON_BN_CLICKED(IDC_BUTTON_ABOUT, &CMFCApplicationDlg::OnBnClickedButtonAbout)
	ON_COMMAND(MENU_EXIT, &CMFCApplicationDlg::OnBnClickedButtonExit)
	ON_COMMAND(MENU_PREIVIEW, &CMFCApplicationDlg::OnMenuPreview)
	ON_COMMAND(MENU_UPDATE_PASS, &CMFCApplicationDlg::OnMenuUpdatePass)
	ON_COMMAND(MENU_UPDATE_INFO, &CMFCApplicationDlg::OnMenuUpdateInfo)
	ON_COMMAND(MENU_INFO, &CMFCApplicationDlg::OnMenuInfo)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY_INFO, &CMFCApplicationDlg::OnBnClickedButtonModifyInfo)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY_PASS, &CMFCApplicationDlg::OnBnClickedButtonModifyPass)
END_MESSAGE_MAP()

// CMFCApplicationDlg 消息处理程序

BOOL CMFCApplicationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将菜单项添加到系统菜单中。
	m_Menu.LoadMenu(IDR_MENU);
	SetMenu(&m_Menu);

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(TRUE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码


	// 初始化数据库
	AfxOleInit();
	HRESULT hr;
	hr = UserInfo->m_pConnection.CreateInstance("ADODB.Connection");
	UserInfo->m_pConnection->ConnectionTimeout = 8;
	try
	{
		_bstr_t strConnect = "Provider=SQLOLEDB.1;Password=ainibiezou;Persist Security Info=True;User ID=sa;Initial Catalog=Test;Data Source=127.0.0.1";//初始化连接  
		hr = UserInfo->m_pConnection->Open(strConnect, "", "", adModeUnknown);//打开数据库
		if (FAILED(hr))
		{
			MessageBox(L"链接数据库失败！", L"错误：");
			return FALSE;
		}
	}
	catch (_com_error e)
	{
		MessageBox(e.Description(), L"错误：");
		return FALSE;
	}


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplicationDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplicationDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
	
	if (!UserInfo->isLogin){
		UserLogin* dlg = new UserLogin;
		this->ShowWindow(SW_HIDE);
		dlg->DoModal();
	}
	if (!UserInfo->isLogin) {
		this->OnCancel();
	} else {
		this->ShowWindow(SW_SHOW);
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplicationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplicationDlg::OnBnClickedButtonOpenImage()
{
	// 打开图片
	// TODO:  在此添加控件通知处理程序代码
	BOOL isOpen = TRUE;		//是否打开(否则为保存)
	CString fileName = L"原图.jpg";			//默认打开的文件名
	CString filter = L"图片 (*.jpeg; *.png; *.jpg; *.bmp)|*.jpeg;*.jpg;*.png;*.bmp||";	//文件过虑的类型
	CFileDialog openFileDlg(isOpen, L"", fileName, OFN_HIDEREADONLY | OFN_READONLY, filter, NULL);
	// openFileDlg.GetOFN().lpstrInitialDir = L"E:\\FileTest\\test.doc";
	INT_PTR result = openFileDlg.DoModal();
	if (result == IDOK) {
		CImage image1;
		CImage image2;
		CImage image3;
		CImage image4;
		CImage image5;
		CImage image6;
		CRect rect;
		int ModeOld;
		CWnd *pWnd = NULL;
		CDC *pDc = NULL;
		image1.Load(L"./image/原图.jpg");
		image2.Load(L"./image/Canny算子边缘检测.jpg");
		image3.Load(L"./image/外边缘轮廓筛选.jpg");
		image4.Load(L"./image/内边缘轮廓筛选.jpg");
		image5.Load(L"./image/原图像分割结果.bmp");
		image6.Load(L"./image/边缘图像分割结果.bmp");
		pWnd = GetDlgItem(IDC_PIC_DEFAULT);
		pWnd->GetClientRect(&rect);
		pDc = pWnd->GetDC();
		ModeOld = SetStretchBltMode(pDc->m_hDC, STRETCH_HALFTONE);
		image1.StretchBlt(pDc->m_hDC, rect, SRCCOPY);
		SetStretchBltMode(pDc->m_hDC, ModeOld);
		ReleaseDC(pDc);	
	}
}


void CMFCApplicationDlg::OnBnClickedButtonExit()
{
	// TODO:  在此添加控件通知处理程序代码
	this->OnCancel();
}


void CMFCApplicationDlg::OnBnClickedButtonRun()
{
	// TODO:  在此添加控件通知处理程序代码

	CImage image2;
	CImage image3;
	CImage image4;
	CImage image5;
	CImage image6;
	CRect rect;
	int ModeOld;
	CWnd *pWnd = NULL;
	CDC *pDc = NULL;
	image2.Load(L"./image/Canny算子边缘检测.jpg");
	image3.Load(L"./image/外边缘轮廓筛选.jpg");
	image4.Load(L"./image/内边缘轮廓筛选.jpg");
	image5.Load(L"./image/原图像分割结果.bmp");
	image6.Load(L"./image/边缘图像分割结果.bmp");

	pWnd = GetDlgItem(IDC_PIC_CANNY);
	pWnd->GetClientRect(&rect);
	pDc = pWnd->GetDC();
	ModeOld = SetStretchBltMode(pDc->m_hDC, STRETCH_HALFTONE);
	image2.StretchBlt(pDc->m_hDC, rect, SRCCOPY);
	SetStretchBltMode(pDc->m_hDC, ModeOld);
	ReleaseDC(pDc);

	pWnd = GetDlgItem(IDC_PIC_OUTER);
	pWnd->GetClientRect(&rect);
	pDc = pWnd->GetDC();
	ModeOld = SetStretchBltMode(pDc->m_hDC, STRETCH_HALFTONE);
	image3.StretchBlt(pDc->m_hDC, rect, SRCCOPY);
	SetStretchBltMode(pDc->m_hDC, ModeOld);
	ReleaseDC(pDc);

	pWnd = GetDlgItem(IDC_PIC_INNER);
	pWnd->GetClientRect(&rect);
	pDc = pWnd->GetDC();
	ModeOld = SetStretchBltMode(pDc->m_hDC, STRETCH_HALFTONE);
	image4.StretchBlt(pDc->m_hDC, rect, SRCCOPY);
	SetStretchBltMode(pDc->m_hDC, ModeOld);
	ReleaseDC(pDc);

	pWnd = GetDlgItem(IDC_PIC_ORIGIN_DIVISION);
	pWnd->GetClientRect(&rect);
	pDc = pWnd->GetDC();
	ModeOld = SetStretchBltMode(pDc->m_hDC, STRETCH_HALFTONE);
	image5.StretchBlt(pDc->m_hDC, rect, SRCCOPY);
	SetStretchBltMode(pDc->m_hDC, ModeOld);
	ReleaseDC(pDc);

	pWnd = GetDlgItem(IDC_PIC_EDGE_DIVISION);
	pWnd->GetClientRect(&rect);
	pDc = pWnd->GetDC();
	ModeOld = SetStretchBltMode(pDc->m_hDC, STRETCH_HALFTONE);
	image6.StretchBlt(pDc->m_hDC, rect, SRCCOPY);
	SetStretchBltMode(pDc->m_hDC, ModeOld);
	ReleaseDC(pDc);

	GetDlgItem(IDC_EDIT1)->SetWindowText(L"正");
	GetDlgItem(IDC_EDIT_X_POS)->SetWindowText(L"510.161");
	GetDlgItem(IDC_EDIT_Y_POS)->SetWindowText(L"457.299");
	GetDlgItem(IDC_EDIT_ROUTE)->SetWindowText(L"44.159");
	GetDlgItem(IDC_EDIT_TITL)->SetWindowText(L"20.0789");
	GetDlgItem(IDC_EDIT_X)->SetWindowText(L"+630.483mm");
	GetDlgItem(IDC_EDIT_Y)->SetWindowText(L"+471.897mm");
	GetDlgItem(IDC_EDIT_DEEP)->SetWindowText(L"1335.99mm");
}


void CMFCApplicationDlg::OnBnClickedButtonAbout()
{
	// TODO:  在此添加控件通知处理程序代码
	CAboutDlg *pDlg = new CAboutDlg;
	pDlg->Create(IDD_ABOUTBOX, this);
	pDlg->ShowWindow(SW_SHOW);
}

void CMFCApplicationDlg::OnMenuUpdateInfo()
{
	UpdateInfo* dlg = new UpdateInfo;
	this->EnableWindow(FALSE);
	dlg->DoModal();
	this->EnableWindow(TRUE);
}

void CMFCApplicationDlg::OnMenuUpdatePass()
{
	UpdatePass* dlg = new UpdatePass;
	this->EnableWindow(FALSE);
	dlg->DoModal();
	this->EnableWindow(TRUE);
}

void CMFCApplicationDlg::OnMenuPreview()
{
	Preview* dlg = new Preview;
	this->ShowWindow(SW_HIDE);
	dlg->DoModal();
	this->ShowWindow(SW_SHOW);
}

void CMFCApplicationDlg::OnMenuInfo()
{
	StaticInfo* dlg = new StaticInfo;
	this->ShowWindow(SW_HIDE);
	dlg->DoModal();
	this->ShowWindow(SW_SHOW);
}

void CMFCApplicationDlg::OnBnClickedButtonModifyInfo()
{
	// TODO:  在此添加控件通知处理程序代码
	this->OnMenuUpdateInfo();
}


void CMFCApplicationDlg::OnBnClickedButtonModifyPass()
{
	// TODO:  在此添加控件通知处理程序代码
	this->OnMenuUpdatePass();
}
