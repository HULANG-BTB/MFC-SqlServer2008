
// MFCApplicationDlg.h : 头文件
//

#pragma once


// CMFCApplicationDlg 对话框
class CMFCApplicationDlg : public CDialogEx
{
// 构造
public:
	CMFCApplicationDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFCAPPLICATION_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	CMenu m_Menu;
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonOpenImage();
	afx_msg void OnBnClickedButtonExit();
	afx_msg void OnBnClickedButtonRun();
	afx_msg void OnBnClickedButtonAbout();
	afx_msg void OnMenuUpdateInfo();
	afx_msg void OnMenuUpdatePass();
	afx_msg void OnMenuPreview();
	afx_msg void OnMenuInfo();
	afx_msg void OnBnClickedButtonModifyInfo();
	afx_msg void OnBnClickedButtonModifyPass();
};
