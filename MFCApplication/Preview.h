#pragma once


// Preview �Ի���

class Preview : public CDialogEx
{
	DECLARE_DYNAMIC(Preview)

public:
	Preview(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Preview();

// �Ի�������
	enum { IDD = IDD_PREVIEW_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonOpenImage();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};
