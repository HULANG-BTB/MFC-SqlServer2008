// UserRegister.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication.h"
#include "UserRegister.h"
#include "afxdialogex.h"
#include "User.h"

extern User* UserInfo;

// UserRegister 对话框

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


// UserRegister 消息处理程序


void UserRegister::OnBnClickedButtonCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	this->OnCancel();
}


void UserRegister::OnBnClickedButtonRegister()
{
	// TODO:  在此添加控件通知处理程序代码
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
		MessageBox(L"密码不一致！", L"提示：");
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
		MessageBox(L"注册成功！", L"提示：");
		this->OnCancel();
	}
	else {
		MessageBox(L"注册失败！员工编号或用户名已存在", L"提示：");
	}


}


void UserRegister::OnOK()
{
	// TODO:  在此添加专用代码和/或调用基类

	this->OnBnClickedButtonRegister();
}
