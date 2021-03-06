#pragma once
#include <interface/sipcobj-i.h>
#include "protocol.h"
#include <commgr2.h>
#include "CiTunesService.h"

using namespace SOUI;

class CiTunesIPCClient :
	public TObjRefImpl<IIpcConnection>
{
	//CiTunesIPCClient& operator =(CiTunesIPCClient&) = delete;
public:
	CiTunesIPCClient();
	~CiTunesIPCClient();
	virtual int GetBufSize() const override;
	virtual int GetStackSize() const override;
	virtual IIpcHandle* GetIpcHandle() override;
	virtual void BuildShareBufferName(ULONG_PTR idLocal, ULONG_PTR idRemote, TCHAR szBuf[MAX_PATH]) const override;
protected:
	CAutoRefPtr<SOUI::IIpcHandle> m_ipcHandle;	
};
//SNativeWnd
class CiTunesIPCClientWnd : public SNativeWnd, public CiTunesIPCClient
{
private:
	CiTunesService m_iTunesService;
public:
	CiTunesIPCClientWnd();
	~CiTunesIPCClientWnd();
	BOOL OnInitDialog(HWND wndFocus, LPARAM lInitParam);
	void OnDestroy();
	void OnClose(Param_CLOSE& );
	void OnStartCheck(Param_SATRTCHECK& );
	void OnRepair(Param_REPAIR&);

	FUN_BEGIN
		FUN_HANDLER(Param_CLOSE, OnClose)
		FUN_HANDLER(Param_SATRTCHECK, OnStartCheck)
		FUN_HANDLER(Param_REPAIR,OnRepair)
	FUN_END
private:

	BEGIN_MSG_MAP_EX(CiTunesIPCClientWnd)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_DESTROY(OnDestroy)
		CHAIN_MSG_MAP_2_IPC(m_ipcHandle)
		CHAIN_MSG_MAP(SNativeWnd)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()
};