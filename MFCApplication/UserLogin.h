#pragma once


// UserLogin �Ի���

class UserLogin : public CDialogEx
{
	DECLARE_DYNAMIC(UserLogin)

public:
	UserLogin(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~UserLogin();

// �Ի�������
	enum { IDD = IDD_LOGIN_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	virtual void OnOK();
};
