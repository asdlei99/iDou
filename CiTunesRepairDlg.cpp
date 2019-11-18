#include "stdafx.h"
#include "CiTunesRepairDlg.h"
#include <versionhelpers.h>

#include <Sddl.h>
//检查并根据系统版本选择打开程序方式
BOOL ShellExecuteExOpen(SStringT appName, SStringT appPath, SStringT par,SStringT &ec)
{

	SHELLEXECUTEINFO sei = { sizeof(SHELLEXECUTEINFO) };
	sei.fMask = SEE_MASK_NOCLOSEPROCESS;
	sei.lpVerb = IsWindowsVistaOrGreater() ? TEXT("runas") : NULL;
	sei.lpFile = appName;
	sei.lpDirectory = appPath;
	sei.nShow = SW_SHOWNORMAL;
	sei.lpParameters = par;
	if (!ShellExecuteEx(&sei))
	{
		DWORD dwStatus = GetLastError();
		if (dwStatus == ERROR_CANCELLED)
		{
			ec= L"提升权限被用户拒绝！";
		}
		else if (dwStatus == ERROR_FILE_NOT_FOUND)
		{
			ec = L"所要执行的文件没有找到！";
		}
		else
		{
			ec.Format(L"无法启动修复程序,错误：%d", dwStatus);
		}
		return FALSE;
	}
	return TRUE;
}

BOOL CiTunesRepairDlg::OnInitDialog(HWND hWnd, LPARAM lParam)
{
	m_ipcSvr->Init((ULONG_PTR)m_hWnd, this);
	wchar_t wszHWnd[64] = {};
	::wnsprintfW(wszHWnd, _countof(wszHWnd), L"0x%p", m_hWnd);
	SStringT outMsg;
	BOOL bRet = ShellExecuteExOpen(L"iTunesRepair.exe", SApplication::getSingleton().GetAppDir(), wszHWnd, outMsg);
	if (!bRet)
	{
		//lable_error_msg
		STabCtrl* tab = FindChildByID2<STabCtrl>(R.id.tab_repair);
		SASSERT(tab);
		tab->SetCurSel(6);
		tab->FindChildByID(R.id.lable_error_msg)->SetWindowText(outMsg);
	}
	return bRet;
}


// 通过 IIpcSvrCallback 继承

void CiTunesRepairDlg::OnNewConnection(IIpcHandle* pIpcHandle, IIpcConnection** ppConn)
{
	*ppConn = new CiTunesIPCSvrConnect(pIpcHandle, this);
}

SECURITY_ATTRIBUTES* Helper_BuildLowIntegritySA()
{
#define LOW_INTEGRITY_SDDL_SACL      SDDL_SACL             \
	SDDL_DELIMINATOR      \
	SDDL_ACE_BEGIN        \
	SDDL_MANDATORY_LABEL  \
	SDDL_SEPERATOR        \
	SDDL_SEPERATOR        \
	SDDL_NO_WRITE_UP      \
	SDDL_SEPERATOR        \
	SDDL_SEPERATOR        \
	SDDL_SEPERATOR        \
	SDDL_ML_LOW           \
	SDDL_ACE_END

#define LOCAL_SYSTEM_FILE_ACCESS     SDDL_ACE_BEGIN        \
	SDDL_ACCESS_ALLOWED   \
	SDDL_SEPERATOR        \
	SDDL_SEPERATOR        \
	SDDL_FILE_ALL         \
	SDDL_SEPERATOR        \
	SDDL_SEPERATOR        \
	SDDL_SEPERATOR        \
	SDDL_LOCAL_SYSTEM     \
	SDDL_ACE_END

#define EVERYONE_FILE_ACCESS         SDDL_ACE_BEGIN        \
	SDDL_ACCESS_ALLOWED   \
	SDDL_SEPERATOR        \
	SDDL_SEPERATOR        \
	SDDL_FILE_ALL         \
	SDDL_SEPERATOR        \
	SDDL_SEPERATOR        \
	SDDL_SEPERATOR        \
	SDDL_EVERYONE         \
	SDDL_ACE_END

#define ALL_APP_PACKAGES_FILE_ACCESS SDDL_ACE_BEGIN        \
	SDDL_ACCESS_ALLOWED   \
	SDDL_SEPERATOR        \
	SDDL_SEPERATOR        \
	SDDL_FILE_ALL         \
	SDDL_SEPERATOR        \
	SDDL_SEPERATOR        \
	SDDL_SEPERATOR        \
	SDDL_ALL_APP_PACKAGES \
	SDDL_ACE_END


	SECURITY_ATTRIBUTES* sa = new SECURITY_ATTRIBUTES;
	PSECURITY_DESCRIPTOR pSD = NULL;
	LPCTSTR pszDesc = IsWindows8OrGreater()
		? LOW_INTEGRITY_SDDL_SACL
		SDDL_DACL
		SDDL_DELIMINATOR
		LOCAL_SYSTEM_FILE_ACCESS
		EVERYONE_FILE_ACCESS
		ALL_APP_PACKAGES_FILE_ACCESS
		: LOW_INTEGRITY_SDDL_SACL
		SDDL_DACL
		SDDL_DELIMINATOR
		LOCAL_SYSTEM_FILE_ACCESS
		EVERYONE_FILE_ACCESS;

	ConvertStringSecurityDescriptorToSecurityDescriptor(pszDesc, SDDL_REVISION_1, &pSD, NULL);
	sa->nLength = sizeof(SECURITY_ATTRIBUTES);
	sa->lpSecurityDescriptor = pSD;
	sa->bInheritHandle = TRUE;
	return sa;
}


void Helper_FreeSa(SECURITY_ATTRIBUTES* psa)
{
	if (psa->lpSecurityDescriptor)
	{
		LocalFree(psa->lpSecurityDescriptor);
	}
	psa->lpSecurityDescriptor = NULL;
	delete psa;
}

void* CiTunesRepairDlg::GetSecurityAttr() const
{
	return Helper_BuildLowIntegritySA();
}

void CiTunesRepairDlg::ReleaseSecurityAttr(void* psa) const
{
	SECURITY_ATTRIBUTES* psa2 = (SECURITY_ATTRIBUTES*)psa;
	Helper_FreeSa(psa2);
}

void CiTunesRepairDlg::OnConnected(IIpcConnection* pConn)
{
	//此处连接未完全准备好，不能操作！！！！！！！！！！！！！！！！！！！！！！！
	/*Param_SATRTCHECK startChk;
	bool bRet= pConn->GetIpcHandle()->CallFun(&startChk);*/
	SWindow* pBtn = FindChildByID(R.id.btn_check);
	SASSERT(pBtn);
	pBtn->EnableWindow(TRUE, TRUE);
}

void CiTunesRepairDlg::OnDisconnected(IIpcConnection* pConn)
{
	//SMessageBox(m_hWnd, SStringT().Format(L"连接:Ox%p断开", pConn->GetIpcHandle()->GetRemoteId()), L"", MB_OK);
}

void CiTunesRepairDlg::OnCheckRet(Param_CHECKRET& ret)
{
	STabCtrl* tab = FindChildByID2<STabCtrl>(R.id.tab_repair);
	SASSERT(tab);

	switch (ret.checkRet)
	{
	case CHK_NO:
		tab->SetCurSel(1);
		break;
	case CHK_OK:
		tab->FindChildByID(R.id.lable_amds_ver)->SetWindowTextW(ret.ver.c_str());
		tab->SetCurSel(2);
		break;
	case CHK_FAILE:
		tab->SetCurSel(3);
		break;
	}
}

void CiTunesRepairDlg::OnRepairRet(Param_REPAIR& ret)
{
	STabCtrl* tab = FindChildByID2<STabCtrl>(R.id.tab_repair);
	SASSERT(tab);

	switch (ret.repairRet)
	{
	case REPAIR_OK:
	{
		tab->SetCurSel(5);
	}
	break;
	case REPAIR_FAILE:
		tab->SetCurSel(4);
		break;
	}
}

void CiTunesRepairDlg::OnConnectedr(Param_CONNECTED& ret)
{
	StartCheck();
}

void CiTunesRepairDlg::OnOpenItunesUrl()
{
	const TCHAR* Url = _T("https://support.apple.com/zh_CN/downloads/itunes");
	ShellExecute(NULL, L"open", Url, NULL, NULL, SW_SHOWNORMAL);
	OnOK();
}

void CiTunesRepairDlg::OnDestroy()
{
	Close();
	SetMsgHandled(FALSE);
}

void CiTunesRepairDlg::OnCheck() {
	StartCheck();
	SWindow* pBtn = FindChildByID(R.id.btn_check);
	SASSERT(pBtn);
	pBtn->EnableWindow(FALSE, TRUE);
}

void CiTunesRepairDlg::OnRepair() {
	StartRepair();
	SWindow* pBtn = FindChildByID(R.id.btn_repair);
	SASSERT(pBtn);
	pBtn->EnableWindow(FALSE, TRUE);
}
