#pragma once


// UpdateInfo 对话框

class UpdateInfo : public CDialogEx
{
	DECLARE_DYNAMIC(UpdateInfo)

public:
	UpdateInfo(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~UpdateInfo();

// 对话框数据
	enum { IDD = IDD_UPDATE_INFO_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSave();
	virtual void OnOK();
	virtual BOOL OnInitDialog();
};
