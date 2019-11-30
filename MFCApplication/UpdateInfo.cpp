// UpdateInfo.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication.h"
#include "UpdateInfo.h"
#include "afxdialogex.h"
#include "User.h"

extern User* UserInfo;

// UpdateInfo 对话框

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


// UpdateInfo 消息处理程序


void UpdateInfo::OnBnClickedButtonSave()
{
	// TODO:  在此添加控件通知处理程序代码
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
		MessageBox(L"修改成功！", L"提示：");
		this->OnCancel();
	} else {
		MessageBox(L"修改失败！", L"提示：");
	}
}


void UpdateInfo::OnOK()
{
	// TODO:  在此添加专用代码和/或调用基类
	this->OnBnClickedButtonSave();
	
}


BOOL UpdateInfo::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	SetDlgItemText(IDC_EDIT1, UserInfo->name);
	SetDlgItemText(IDC_EDIT2, UserInfo->number);
	SetDlgItemText(IDC_EDIT3, UserInfo->username);
	SetDlgItemText(IDC_EDIT4, UserInfo->sex);
	SetDlgItemText(IDC_EDIT5, UserInfo->phone);
	SetDlgItemText(IDC_EDIT6, UserInfo->dept);
	SetDlgItemText(IDC_EDIT7, UserInfo->pos);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
