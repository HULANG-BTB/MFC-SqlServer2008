// UpdateInfo.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication.h"
#include "UpdateInfo.h"
#include "afxdialogex.h"
#include "User.h"

extern User* UserInfo;

// UpdateInfo �Ի���

IMPLEMENT_DYNAMIC(UpdateInfo, CDialogEx)

UpdateInfo::UpdateInfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(UpdateInfo::IDD, pParent)
{

}

UpdateInfo::~UpdateInfo()
{
}

void UpdateInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(UpdateInfo, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &UpdateInfo::OnBnClickedButtonSave)
END_MESSAGE_MAP()


// UpdateInfo ��Ϣ�������


void UpdateInfo::OnBnClickedButtonSave()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	GetDlgItemText(IDC_EDIT1, UserInfo->name);
	GetDlgItemText(IDC_EDIT2, UserInfo->number);
	GetDlgItemText(IDC_EDIT3, UserInfo->username);
	GetDlgItemText(IDC_EDIT4, UserInfo->sex);
	GetDlgItemText(IDC_EDIT5, UserInfo->phone);
	GetDlgItemText(IDC_EDIT6, UserInfo->dept);
	GetDlgItemText(IDC_EDIT7, UserInfo->pos);
	CString SQL;
	SQL = "UPDATE Users SET UserName='";
	SQL += UserInfo->username;
	SQL += "', Sex='";
	SQL += UserInfo->sex;
	SQL += "', Phone='";
	SQL += UserInfo->phone;
	SQL += "', Dept='";
	SQL += UserInfo->dept;
	SQL += "', POST='";
	SQL += UserInfo->pos;
	SQL += "' WHERE WorkId='";
	SQL += UserInfo->number;
	SQL += "'";
	if (UserInfo->ExecSQL(SQL)) {
		MessageBox(L"�޸ĳɹ���", L"��ʾ��");
		this->OnCancel();
	} else {
		MessageBox(L"�޸�ʧ�ܣ�", L"��ʾ��");
	}
}


void UpdateInfo::OnOK()
{
	// TODO:  �ڴ����ר�ô����/����û���
	this->OnBnClickedButtonSave();
	
}


BOOL UpdateInfo::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	SetDlgItemText(IDC_EDIT1, UserInfo->name);
	SetDlgItemText(IDC_EDIT2, UserInfo->number);
	SetDlgItemText(IDC_EDIT3, UserInfo->username);
	SetDlgItemText(IDC_EDIT4, UserInfo->sex);
	SetDlgItemText(IDC_EDIT5, UserInfo->phone);
	SetDlgItemText(IDC_EDIT6, UserInfo->dept);
	SetDlgItemText(IDC_EDIT7, UserInfo->pos);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
