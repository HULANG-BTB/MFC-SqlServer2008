// UserLogin.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication.h"
#include "UserLogin.h"
#include "afxdialogex.h"
#include "UserRegister.h"
#include "User.h"

extern User* UserInfo;

// UserLogin 对话框

IMPLEMENT_DYNAMIC(UserLogin, CDialogEx)

UserLogin::UserLogin(CWnd* pParent /*=NULL*/)
	: CDialogEx(UserLogin::IDD, pParent)
{

}

UserLogin::~UserLogin()
{
}

void UserLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(UserLogin, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &UserLogin::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &UserLogin::OnBnClickedButton1)
END_MESSAGE_MAP()


// UserLogin 消息处理程序


void UserLogin::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	UserRegister* dlg = new UserRegister;
	this->EnableWindow(FALSE);
	dlg->DoModal();
	this->EnableWindow(TRUE);
}


void UserLogin::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	CString username;
	CString password;
	CString SQL;
	GetDlgItemText(IDC_EDIT1, username);
	GetDlgItemText(IDC_EDIT2, password);
	SQL = "SELECT WorkId, Name, UserName, PassWord, Sex, Phone, Dept, POST FROM Users WHERE UserName='";
	SQL += username;
	SQL += "' AND PassWord='";
	SQL += password;
	SQL += "'";
	bool flag = UserInfo->ExecSQL(SQL);
	if (flag) {
		while (!UserInfo->m_pRecordset->adoEOF) {
			UserInfo->number = (TCHAR *)(_bstr_t)UserInfo->m_pRecordset->GetFields()->GetItem("WorkId")->Value;
			UserInfo->name = (TCHAR *)(_bstr_t)UserInfo->m_pRecordset->GetFields()->GetItem("Name")->Value;
			UserInfo->username = (TCHAR *)(_bstr_t)UserInfo->m_pRecordset->GetFields()->GetItem("UserName")->Value;
			UserInfo->password = (TCHAR *)(_bstr_t)UserInfo->m_pRecordset->GetFields()->GetItem("PassWord")->Value;
			UserInfo->sex = (TCHAR *)(_bstr_t)UserInfo->m_pRecordset->GetFields()->GetItem("Sex")->Value;
			UserInfo->phone = (TCHAR *)(_bstr_t)UserInfo->m_pRecordset->GetFields()->GetItem("Phone")->Value;
			UserInfo->dept = (TCHAR *)(_bstr_t)UserInfo->m_pRecordset->GetFields()->GetItem("Dept")->Value;
			UserInfo->pos = (TCHAR *)(_bstr_t)UserInfo->m_pRecordset->GetFields()->GetItem("POST")->Value;
			UserInfo->isLogin = TRUE;
			UserInfo->m_pRecordset->MoveNext();
		}
	}
	if (UserInfo->isLogin) {
		MessageBox(L"登录成功！", L"提示：");
		this->OnCancel();
	} else {
		MessageBox(L"登录失败！", L"提示：");
	}
}


void UserLogin::OnOK()
{
	// TODO:  在此添加专用代码和/或调用基类
	this->OnBnClickedButton1();
}
