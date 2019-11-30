#pragma once


// Preview 对话框

class Preview : public CDialogEx
{
	DECLARE_DYNAMIC(Preview)

public:
	Preview(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Preview();

// 对话框数据
	enum { IDD = IDD_PREVIEW_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonOpenImage();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};
