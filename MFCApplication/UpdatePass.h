#pragma once


// UpdatePass �Ի���

class UpdatePass : public CDialogEx
{
	DECLARE_DYNAMIC(UpdatePass)

public:
	UpdatePass(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~UpdatePass();

// �Ի�������
	enum { IDD = IDD_UPDATE_PASS_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSave();
	virtual void OnOK();
	virtual BOOL OnInitDialog();
};
