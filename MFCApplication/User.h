#pragma once

#include "stdafx.h"

class User {
public:
	bool isLogin;
	CString name;
	CString number;
	CString username;
	CString password;
	CString sex;
	CString phone;
	CString dept;
	CString pos;
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;
	User();
	bool ExecSQL(CString sql);
};