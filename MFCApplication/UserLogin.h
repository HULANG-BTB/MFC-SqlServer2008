#pragma once


// UserLogin 对话框

class UserLogin : public CDialogEx
{
	DECLARE_DYNAMIC(UserLogin)

public:
	UserLogin(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~UserLogin();

// 对话框数据
	enum { IDD = IDD_LOGIN_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	virtual void OnOK();
};
