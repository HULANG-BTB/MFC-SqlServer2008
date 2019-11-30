// UpdatePass.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication.h"
#include "UpdatePass.h"
#include "afxdialogex.h"
#include "User.h"

extern User* UserInfo;

// UpdatePass 对话框

IMPLEMENT_DYNAMIC(UpdatePass, CDialogEx)

UpdatePass::UpdatePass(CWnd* pParent /*=NULL*/)
	: CDialogEx(UpdatePass::IDD, pParent)
{

}

UpdatePass::~UpdatePass()
{
}

void UpdatePass::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(UpdatePass, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &UpdatePass::OnBnClickedButtonSave)
END_MESSAGE_MAP()


// UpdatePass 消息处理程序


void UpdatePass::OnBnClickedButtonSave()
{
	// TODO:  在此添加控件通知处理程序代码
	CString password;
	CString rePassword;
	GetDlgItemText(IDC_EDIT1, password);
	GetDlgItemText(IDC_EDIT2, rePassword);
	if (password != rePassword) {
		MessageBox(L"密码不一致", L"提示：");
		return;
	} else {
		UserInfo->password = password;
		CString SQL;
		SQL = "UPDATE Users SET PassWord='";
		SQL += UserInfo->password;
		SQL += "' WHERE WorkId='";
		SQL += UserInfo->number;
		SQL += "'";
		if (UserInfo->ExecSQL(SQL)) {
			MessageBox(L"修改成功！", L"提示：");
			this->OnCancel();
		}
		else {
			MessageBox(L"修改失败！", L"提示：");
		}
	}
}


void UpdatePass::OnOK()
{
	// TODO:  在此添加专用代码和/或调用基类

	this->OnBnClickedButtonSave();
}


BOOL UpdatePass::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
