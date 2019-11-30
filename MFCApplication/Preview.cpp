// Preview.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication.h"
#include "Preview.h"
#include "afxdialogex.h"


// Preview �Ի���

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


// Preview ��Ϣ�������


void Preview::OnBnClickedButtonOpenImage()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	BOOL isOpen = TRUE;		//�Ƿ��(����Ϊ����)
	CString fileName = L"ԭͼ.jpg";			//Ĭ�ϴ򿪵��ļ���
	CString filter = L"ͼƬ (*.jpeg; *.png; *.jpg; *.bmp)|*.jpeg;*.jpg;*.png;*.bmp||";	//�ļ����ǵ�����
	CFileDialog openFileDlg(isOpen, L"", fileName, OFN_HIDEREADONLY | OFN_READONLY, filter, NULL);
	// openFileDlg.GetOFN().lpstrInitialDir = L"E:\\FileTest\\test.doc";
	INT_PTR result = openFileDlg.DoModal();
	if (result == IDOK) {
		CImage image1;
		CRect rect;
		int ModeOld;
		CWnd *pWnd = NULL;
		CDC *pDc = NULL;
		image1.Load(L"./image/ԭͼ.jpg");
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CImage image1;
	CRect rect;
	int ModeOld;
	CWnd *pWnd = NULL;
	CDC *pDc = NULL;
	image1.Load(L"./image/�ҶȻ�.jpg");
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CImage image1;
	CRect rect;
	int ModeOld;
	CWnd *pWnd = NULL;
	CDC *pDc = NULL;
	image1.Load(L"./image/ֱ��ͼ���⻯.jpg");
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CImage image1;
	CRect rect;
	int ModeOld;
	CWnd *pWnd = NULL;
	CDC *pDc = NULL;
	image1.Load(L"./image/ͼ���ֵ��.jpg");
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CImage image1;
	CRect rect;
	int ModeOld;
	CWnd *pWnd = NULL;
	CDC *pDc = NULL;
	image1.Load(L"./image/��̬ѧ.jpg");
	pWnd = GetDlgItem(IDC_PIC_XTX);
	pWnd->GetClientRect(&rect);
	pDc = pWnd->GetDC();
	ModeOld = SetStretchBltMode(pDc->m_hDC, STRETCH_HALFTONE);
	image1.StretchBlt(pDc->m_hDC, rect, SRCCOPY);
	SetStretchBltMode(pDc->m_hDC, ModeOld);
	ReleaseDC(pDc);
}
