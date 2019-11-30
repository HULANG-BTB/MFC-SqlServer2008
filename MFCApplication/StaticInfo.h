#pragma once
#include "afxcmn.h"


// StaticInfo 对话框

class StaticInfo : public CDialogEx
{
	DECLARE_DYNAMIC(StaticInfo)

public:
	StaticInfo(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~StaticInfo();

// 对话框数据
	enum { IDD = IDD_STATIC_INFO_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	virtual BOOL OnInitDialog();
	void setHeader();
	void setData();
	afx_msg void OnBnClickedButtonClose();
	afx_msg void OnBnClickedButtonReloadData();
};
