#pragma once


// UpdateInfo �Ի���

class UpdateInfo : public CDialogEx
{
	DECLARE_DYNAMIC(UpdateInfo)

public:
	UpdateInfo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~UpdateInfo();

// �Ի�������
	enum { IDD = IDD_UPDATE_INFO_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSave();
	virtual void OnOK();
	virtual BOOL OnInitDialog();
};
