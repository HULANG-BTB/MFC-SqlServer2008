#include "stdafx.h"
#include "User.h"

User::User() {
	this->isLogin = false;
}

bool User::ExecSQL(CString sql) {
	_bstr_t m_sqlCmd = _bstr_t(sql);
	_variant_t RecordsAffected;

	try {
		m_pRecordset = m_pConnection->Execute(m_sqlCmd, &RecordsAffected, adCmdText);
	}
	catch (_com_error e) {
		return FALSE;
	}

	return TRUE;
}



User *UserInfo = new User;