#pragma once


// UserRegister �Ի���

class UserRegister : public CDialogEx
{
	DECLARE_DYNAMIC(UserRegister)

public:
	UserRegister(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~UserRegister();

// �Ի�������
	enum { IDD = IDD_REGISTER_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonCancel();
	virtual void OnOK();
	afx_msg void OnBnClickedButtonRegister();
};
