#pragma once


// UserRegister 对话框

class UserRegister : public CDialogEx
{
	DECLARE_DYNAMIC(UserRegister)

public:
	UserRegister(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~UserRegister();

// 对话框数据
	enum { IDD = IDD_REGISTER_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonCancel();
	virtual void OnOK();
	afx_msg void OnBnClickedButtonRegister();
};
