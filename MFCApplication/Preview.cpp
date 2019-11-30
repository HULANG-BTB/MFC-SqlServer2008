// Preview.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication.h"
#include "Preview.h"
#include "afxdialogex.h"


// Preview 对话框

IMPLEMENT_DYNAMIC(Preview, CDialogEx)

Preview::Preview(CWnd* pParent /*=NULL*/)
	: CDialogEx(Preview::IDD, pParent)
{

}

Preview::~Preview()
{
}

void Preview::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Preview, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_OPEN_IMAGE, &Preview::OnBnClickedButtonOpenImage)
	ON_BN_CLICKED(IDC_BUTTON1, &Preview::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Preview::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Preview::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &Preview::OnBnClickedButton4)
END_MESSAGE_MAP()


// Preview 消息处理程序


void Preview::OnBnClickedButtonOpenImage()
{
	// TODO:  在此添加控件通知处理程序代码
	BOOL isOpen = TRUE;		//是否打开(否则为保存)
	CString fileName = L"原图.jpg";			//默认打开的文件名
	CString filter = L"图片 (*.jpeg; *.png; *.jpg; *.bmp)|*.jpeg;*.jpg;*.png;*.bmp||";	//文件过虑的类型
	CFileDialog openFileDlg(isOpen, L"", fileName, OFN_HIDEREADONLY | OFN_READONLY, filter, NULL);
	// openFileDlg.GetOFN().lpstrInitialDir = L"E:\\FileTest\\test.doc";
	INT_PTR result = openFileDlg.DoModal();
	if (result == IDOK) {
		CImage image1;
		CRect rect;
		int ModeOld;
		CWnd *pWnd = NULL;
		CDC *pDc = NULL;
		image1.Load(L"./image/原图.jpg");
		pWnd = GetDlgItem(IDC_PIC_DEFAULT);
		pWnd->GetClientRect(&rect);
		pDc = pWnd->GetDC();
		ModeOld = SetStretchBltMode(pDc->m_hDC, STRETCH_HALFTONE);
		image1.StretchBlt(pDc->m_hDC, rect, SRCCOPY);
		SetStretchBltMode(pDc->m_hDC, ModeOld);
		ReleaseDC(pDc);
	}


}


void Preview::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	CImage image1;
	CRect rect;
	int ModeOld;
	CWnd *pWnd = NULL;
	CDC *pDc = NULL;
	image1.Load(L"./image/灰度化.jpg");
	pWnd = GetDlgItem(IDC_PIC_HDH);
	pWnd->GetClientRect(&rect);
	pDc = pWnd->GetDC();
	ModeOld = SetStretchBltMode(pDc->m_hDC, STRETCH_HALFTONE);
	image1.StretchBlt(pDc->m_hDC, rect, SRCCOPY);
	SetStretchBltMode(pDc->m_hDC, ModeOld);
	ReleaseDC(pDc);
}


void Preview::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	CImage image1;
	CRect rect;
	int ModeOld;
	CWnd *pWnd = NULL;
	CDC *pDc = NULL;
	image1.Load(L"./image/直方图均衡化.jpg");
	pWnd = GetDlgItem(IDC_PIC_JHH);
	pWnd->GetClientRect(&rect);
	pDc = pWnd->GetDC();
	ModeOld = SetStretchBltMode(pDc->m_hDC, STRETCH_HALFTONE);
	image1.StretchBlt(pDc->m_hDC, rect, SRCCOPY);
	SetStretchBltMode(pDc->m_hDC, ModeOld);
	ReleaseDC(pDc);
}


void Preview::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码
	CImage image1;
	CRect rect;
	int ModeOld;
	CWnd *pWnd = NULL;
	CDC *pDc = NULL;
	image1.Load(L"./image/图像二值化.jpg");
	pWnd = GetDlgItem(IDC_PIC_EZH);
	pWnd->GetClientRect(&rect);
	pDc = pWnd->GetDC();
	ModeOld = SetStretchBltMode(pDc->m_hDC, STRETCH_HALFTONE);
	image1.StretchBlt(pDc->m_hDC, rect, SRCCOPY);
	SetStretchBltMode(pDc->m_hDC, ModeOld);
	ReleaseDC(pDc);
}


void Preview::OnBnClickedButton4()
{
	// TODO:  在此添加控件通知处理程序代码
	CImage image1;
	CRect rect;
	int ModeOld;
	CWnd *pWnd = NULL;
	CDC *pDc = NULL;
	image1.Load(L"./image/形态学.jpg");
	pWnd = GetDlgItem(IDC_PIC_XTX);
	pWnd->GetClientRect(&rect);
	pDc = pWnd->GetDC();
	ModeOld = SetStretchBltMode(pDc->m_hDC, STRETCH_HALFTONE);
	image1.StretchBlt(pDc->m_hDC, rect, SRCCOPY);
	SetStretchBltMode(pDc->m_hDC, ModeOld);
	ReleaseDC(pDc);
}
