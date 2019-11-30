#pragma once


// UpdatePass 对话框

class UpdatePass : public CDialogEx
{
	DECLARE_DYNAMIC(UpdatePass)

public:
	UpdatePass(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~UpdatePass();

// 对话框数据
	enum { IDD = IDD_UPDATE_PASS_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSave();
	virtual void OnOK();
	virtual BOOL OnInitDialog();
};
