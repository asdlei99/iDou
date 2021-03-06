#include "stdafx.h"
#include "CiTunesIPCClient.h"
#include <SIpcObject/SIpcObject.h>
CiTunesIPCClient::CiTunesIPCClient()
{
	CAutoRefPtr<IIpcFactory> ipcFactory;
	IPC::SCreateInstance((IObjRef**)&ipcFactory);
	ipcFactory->CreateIpcHandle(&m_ipcHandle);
	m_ipcHandle->SetIpcConnection(this);
}

CiTunesIPCClient::~CiTunesIPCClient() {
	m_ipcHandle->Disconnect();
	m_ipcHandle = NULL;
}

int CiTunesIPCClient::GetBufSize() const
{
	return 1024;
}

int CiTunesIPCClient::GetStackSize() const
{
	return 10;
}

IIpcHandle* CiTunesIPCClient::GetIpcHandle()
{
	return m_ipcHandle;
}

void CiTunesIPCClient::BuildShareBufferName(ULONG_PTR idLocal, ULONG_PTR idRemote, TCHAR szBuf[MAX_PATH]) const
{
	_stprintf(szBuf, iTunes_SHARE_BUF_NAME_FMT, (DWORD)(((LPARAM)idLocal) & 0xffffffff), (DWORD)(((LPARAM)idRemote) & 0xffffffff));
}

CiTunesIPCClientWnd::CiTunesIPCClientWnd() {}

CiTunesIPCClientWnd::~CiTunesIPCClientWnd() {} 

BOOL CiTunesIPCClientWnd::OnInitDialog(HWND wndFocus, LPARAM lInitParam)
{
	SASSERT(::IsWindow(wndFocus));
	HRESULT hr = GetIpcHandle()->ConnectTo((ULONG_PTR)m_hWnd, (ULONG_PTR)wndFocus);
	if (hr == S_OK)
	{
		Param_CONNECTED conneced;
		GetIpcHandle()->CallFun(&conneced);		
	}
	return hr == S_OK;
}

void CiTunesIPCClientWnd::OnDestroy()
{
	PostQuitMessage(0);
	SetMsgHandled(FALSE);
}

void CiTunesIPCClientWnd::OnClose(Param_CLOSE& param)
{
	DestroyWindow();
}

void CiTunesIPCClientWnd::OnStartCheck(Param_SATRTCHECK& param)
{
	Param_CHECKRET checkRet;
	if (m_iTunesService)
	{
		SStringT ver;
		if (m_iTunesService.GetVer(ver))
		{
			checkRet.ver = ver;
		}
		checkRet.checkRet = m_iTunesService.IsRun() ? CHK_OK : CHK_FAILE;
	}
	else
	{
		checkRet.checkRet = CHK_NO;
	}
	m_ipcHandle->CallFun(&checkRet);
}

void CiTunesIPCClientWnd::OnRepair(Param_REPAIR&)
{
	Param_REPAIR repairRet;
	if (m_iTunesService)
	{		
		repairRet.repairRet = m_iTunesService.RunService()?REPAIR_OK: REPAIR_FAILE;
	}
	else
	{
		repairRet.repairRet = REPAIR_FAILE;
	}
	m_ipcHandle->CallFun(&repairRet);
}
