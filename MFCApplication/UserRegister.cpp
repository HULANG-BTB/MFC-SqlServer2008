// UserRegister.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication.h"
#include "UserRegister.h"
#include "afxdialogex.h"
#include "User.h"

extern User* UserInfo;

// UserRegister �Ի���

IMPLEMENT_DYNAMIC(UserRegister, CDialogEx)

UserRegister::UserRegister(CWnd* pParent /*=NULL*/)
	: CDialogEx(UserRegister::IDD, pParent)
{

}

UserRegister::~UserRegister()
{
}

void UserRegister::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(UserRegister, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, &UserRegister::OnBnClickedButtonCancel)
	ON_BN_CLICKED(IDC_BUTTON_REGISTER, &UserRegister::OnBnClickedButtonRegister)
END_MESSAGE_MAP()


// UserRegister ��Ϣ�������


void UserRegister::OnBnClickedButtonCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	this->OnCancel();
}


void UserRegister::OnBnClickedButtonRegister()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString rePassword;
	GetDlgItemText(IDC_EDIT1, UserInfo->name);
	GetDlgItemText(IDC_EDIT2, UserInfo->number);
	GetDlgItemText(IDC_EDIT3, UserInfo->username);
	GetDlgItemText(IDC_EDIT4, UserInfo->password);
	GetDlgItemText(IDC_EDIT5, rePassword);
	GetDlgItemText(IDC_EDIT6, UserInfo->sex);
	GetDlgItemText(IDC_EDIT7, UserInfo->phone);
	GetDlgItemText(IDC_EDIT8, UserInfo->dept);
	GetDlgItemText(IDC_EDIT9, UserInfo->pos);
	if (rePassword != UserInfo->password) {
		MessageBox(L"���벻һ�£�", L"��ʾ��");
		return;
	}
	CString SQL;
	SQL = "INSERT Users VALUES ('";
	SQL += UserInfo->number;
	SQL += "', '";
	SQL += UserInfo->name;
	SQL += "', '";
	SQL += UserInfo->username;
	SQL += "', '";
	SQL += UserInfo->password;
	SQL += "', '";
	SQL += UserInfo->sex;
	SQL += "', '";
	SQL += UserInfo->phone;
	SQL += "', '";
	SQL += UserInfo->dept;
	SQL += "', '";
	SQL += UserInfo->pos;
	SQL += "')";
	if (UserInfo->ExecSQL(SQL)) {
		MessageBox(L"ע��ɹ���", L"��ʾ��");
		this->OnCancel();
	}
	else {
		MessageBox(L"ע��ʧ�ܣ�Ա����Ż��û����Ѵ���", L"��ʾ��");
	}


}


void UserRegister::OnOK()
{
	// TODO:  �ڴ����ר�ô����/����û���

	this->OnBnClickedButtonRegister();
}
