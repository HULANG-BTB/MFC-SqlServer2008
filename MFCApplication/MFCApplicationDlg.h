
// MFCApplicationDlg.h : ͷ�ļ�
//

#pragma once


// CMFCApplicationDlg �Ի���
class CMFCApplicationDlg : public CDialogEx
{
// ����
public:
	CMFCApplicationDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCAPPLICATION_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	CMenu m_Menu;
	// ���ɵ���Ϣӳ�亯��
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
