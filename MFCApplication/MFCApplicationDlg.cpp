
// MFCApplicationDlg.cpp : ʵ���ļ�
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

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMFCApplicationDlg �Ի���



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

// CMFCApplicationDlg ��Ϣ�������

BOOL CMFCApplicationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���˵�����ӵ�ϵͳ�˵��С�
	m_Menu.LoadMenu(IDR_MENU);
	SetMenu(&m_Menu);

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������


	// ��ʼ�����ݿ�
	AfxOleInit();
	HRESULT hr;
	hr = UserInfo->m_pConnection.CreateInstance("ADODB.Connection");
	UserInfo->m_pConnection->ConnectionTimeout = 8;
	try
	{
		_bstr_t strConnect = "Provider=SQLOLEDB.1;Password=ainibiezou;Persist Security Info=True;User ID=sa;Initial Catalog=Test;Data Source=127.0.0.1";//��ʼ������  
		hr = UserInfo->m_pConnection->Open(strConnect, "", "", adModeUnknown);//�����ݿ�
		if (FAILED(hr))
		{
			MessageBox(L"�������ݿ�ʧ�ܣ�", L"����");
			return FALSE;
		}
	}
	catch (_com_error e)
	{
		MessageBox(e.Description(), L"����");
		return FALSE;
	}


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCApplicationDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
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

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCApplicationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplicationDlg::OnBnClickedButtonOpenImage()
{
	// ��ͼƬ
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	BOOL isOpen = TRUE;		//�Ƿ��(����Ϊ����)
	CString fileName = L"ԭͼ.jpg";			//Ĭ�ϴ򿪵��ļ���
	CString filter = L"ͼƬ (*.jpeg; *.png; *.jpg; *.bmp)|*.jpeg;*.jpg;*.png;*.bmp||";	//�ļ����ǵ�����
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
		image1.Load(L"./image/ԭͼ.jpg");
		image2.Load(L"./image/Canny���ӱ�Ե���.jpg");
		image3.Load(L"./image/���Ե����ɸѡ.jpg");
		image4.Load(L"./image/�ڱ�Ե����ɸѡ.jpg");
		image5.Load(L"./image/ԭͼ��ָ���.bmp");
		image6.Load(L"./image/��Եͼ��ָ���.bmp");
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	this->OnCancel();
}


void CMFCApplicationDlg::OnBnClickedButtonRun()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	CImage image2;
	CImage image3;
	CImage image4;
	CImage image5;
	CImage image6;
	CRect rect;
	int ModeOld;
	CWnd *pWnd = NULL;
	CDC *pDc = NULL;
	image2.Load(L"./image/Canny���ӱ�Ե���.jpg");
	image3.Load(L"./image/���Ե����ɸѡ.jpg");
	image4.Load(L"./image/�ڱ�Ե����ɸѡ.jpg");
	image5.Load(L"./image/ԭͼ��ָ���.bmp");
	image6.Load(L"./image/��Եͼ��ָ���.bmp");

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

	GetDlgItem(IDC_EDIT1)->SetWindowText(L"��");
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	this->OnMenuUpdateInfo();
}


void CMFCApplicationDlg::OnBnClickedButtonModifyPass()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	this->OnMenuUpdatePass();
}
