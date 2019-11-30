#pragma once
#include "afxcmn.h"


// StaticInfo �Ի���

class StaticInfo : public CDialogEx
{
	DECLARE_DYNAMIC(StaticInfo)

public:
	StaticInfo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~StaticInfo();

// �Ի�������
	enum { IDD = IDD_STATIC_INFO_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	virtual BOOL OnInitDialog();
	void setHeader();
	void setData();
	afx_msg void OnBnClickedButtonClose();
	afx_msg void OnBnClickedButtonReloadData();
};
