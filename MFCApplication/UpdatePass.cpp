// UpdatePass.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication.h"
#include "UpdatePass.h"
#include "afxdialogex.h"
#include "User.h"

extern User* UserInfo;

// UpdatePass �Ի���

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


// UpdatePass ��Ϣ�������


void UpdatePass::OnBnClickedButtonSave()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString password;
	CString rePassword;
	GetDlgItemText(IDC_EDIT1, password);
	GetDlgItemText(IDC_EDIT2, rePassword);
	if (password != rePassword) {
		MessageBox(L"���벻һ��", L"��ʾ��");
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
			MessageBox(L"�޸ĳɹ���", L"��ʾ��");
			this->OnCancel();
		}
		else {
			MessageBox(L"�޸�ʧ�ܣ�", L"��ʾ��");
		}
	}
}


void UpdatePass::OnOK()
{
	// TODO:  �ڴ����ר�ô����/����û���

	this->OnBnClickedButtonSave();
}


BOOL UpdatePass::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
