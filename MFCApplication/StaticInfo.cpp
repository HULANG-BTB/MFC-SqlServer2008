// StaticInfo.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication.h"
#include "StaticInfo.h"
#include "afxdialogex.h"
#include "User.h"

extern User* UserInfo;

// StaticInfo 对话框

IMPLEMENT_DYNAMIC(StaticInfo, CDialogEx)

StaticInfo::StaticInfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(StaticInfo::IDD, pParent)
{

}

StaticInfo::~StaticInfo()
{
}

void StaticInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_list);
}


BEGIN_MESSAGE_MAP(StaticInfo, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &StaticInfo::OnBnClickedButtonClose)
	ON_BN_CLICKED(IDC_BUTTON_RELOAD_DATA, &StaticInfo::OnBnClickedButtonReloadData)
END_MESSAGE_MAP()


// StaticInfo 消息处理程序


BOOL StaticInfo::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	this->setHeader();
	this->setData();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}

void StaticInfo::setHeader() {
	
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list.InsertColumn(0, _T("编号"), LVCFMT_LEFT, 50);
	m_list.InsertColumn(1, _T("正反信息"), LVCFMT_LEFT, 70);
	m_list.InsertColumn(2, _T("形心横坐标"), LVCFMT_LEFT, 83);
	m_list.InsertColumn(3, _T("形新纵坐标"), LVCFMT_LEFT, 83);
	m_list.InsertColumn(4, _T("偏转角度"), LVCFMT_LEFT, 83);
	m_list.InsertColumn(5, _T("倾斜角度"), LVCFMT_LEFT, 83);
	m_list.InsertColumn(6, _T("X轴偏移"), LVCFMT_LEFT, 83);
	m_list.InsertColumn(7, _T("Y轴偏移"), LVCFMT_LEFT, 83);
	m_list.InsertColumn(8, _T("深度信息"), LVCFMT_LEFT, 83);
}


void StaticInfo::setData() {
	int row = 0;
	CString SQL;
	SQL = "SELECT WorkPieceId, Pn, CentroidX, CentroidY, DAngle, IAngle, DeviationX, DeviationY, Depth FROM WorkPieces";
	bool flag = UserInfo->ExecSQL(SQL);
	if (flag) {
		m_list.DeleteAllItems();
		while (!UserInfo->m_pRecordset->adoEOF) {
			m_list.InsertItem(row, (TCHAR *)(_bstr_t)UserInfo->m_pRecordset->GetFields()->GetItem("WorkPieceId")->Value);
			m_list.SetItemText(row, 1, (TCHAR *)(_bstr_t)UserInfo->m_pRecordset->GetFields()->GetItem("Pn")->Value);
			m_list.SetItemText(row, 2, (TCHAR *)(_bstr_t)UserInfo->m_pRecordset->GetFields()->GetItem("CentroidX")->Value);
			m_list.SetItemText(row, 3, (TCHAR *)(_bstr_t)UserInfo->m_pRecordset->GetFields()->GetItem("CentroidY")->Value);
			m_list.SetItemText(row, 4, (TCHAR *)(_bstr_t)UserInfo->m_pRecordset->GetFields()->GetItem("DAngle")->Value);
			m_list.SetItemText(row, 5, (TCHAR *)(_bstr_t)UserInfo->m_pRecordset->GetFields()->GetItem("IAngle")->Value);
			m_list.SetItemText(row, 6, (TCHAR *)(_bstr_t)UserInfo->m_pRecordset->GetFields()->GetItem("DeviationX")->Value);
			m_list.SetItemText(row, 7, (TCHAR *)(_bstr_t)UserInfo->m_pRecordset->GetFields()->GetItem("DeviationY")->Value);
			m_list.SetItemText(row, 8, (TCHAR *)(_bstr_t)UserInfo->m_pRecordset->GetFields()->GetItem("Depth")->Value);
			UserInfo->m_pRecordset->MoveNext();
			row++;
		}
	}
}


void StaticInfo::OnBnClickedButtonClose()
{
	// TODO:  在此添加控件通知处理程序代码
	this->OnCancel();
}


void StaticInfo::OnBnClickedButtonReloadData()
{
	// TODO:  在此添加控件通知处理程序代码
	this->setData();
}
