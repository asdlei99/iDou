// MainDlg.h : interface of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include "controls/STabCtrlHeaderBinder.h"
#include "iOsDeviceLib/CiOSDevice.h"
#include "CMyDeviceHandler/CMyDeviceHandler.h"

class CBaseInfoDlg;

class CMainDlg : public SHostWnd
	, public ISetOrLoadSkinHandler
	, public IDeviceEventCallBack
	, public TAutoEventMapReg<CMainDlg>
{
public:
	CMainDlg();
	~CMainDlg();
protected:	
	bool LoadSkin();
	void OnClose();
	void OnMaximize();
	void OnRestore();
	void OnMinimize();
	void OnSize(UINT nType, CSize size);
	//托盘通知消息处理函数
	//LRESULT OnIconNotify(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL/* bHandled*/);
	//演示如何响应菜单事件
	void OnCommand(UINT uNotifyCode, int nID, HWND wndCtl);
	int OnCreate(LPCREATESTRUCT lpCreateStruct);
	BOOL OnInitDialog(HWND wndFocus, LPARAM lInitParam);
	virtual bool SaveSkin(SkinType skinType, SkinSaveInf& skinSaveInf);
	void ShowToolTip(LPCTSTR tipMsg);
	void OnSkin();
	void OnSetSkin(EventArgs *id);
	void SetThisToiTunesCallBack();
	void CheckiTunesService();
	void BindTab();
	void InitHandler();
	void OnMenu();
protected:
	//soui消息
	EVENT_MAP_BEGIN()
		EVENT_ID_COMMAND(R.id.btn_close, OnClose)
		EVENT_ID_COMMAND(R.id.btn_min, OnMinimize)
		EVENT_ID_COMMAND(R.id.btn_max, OnMaximize)
		EVENT_ID_COMMAND(R.id.btn_restore, OnRestore)
		EVENT_ID_COMMAND(R.id.btn_skin, OnSkin)
		EVENT_ID_COMMAND(R.id.btn_menu,OnMenu)
		EVENT_ID_COMMAND(R.id.btn_CheckiTunes, CheckiTunesService)
		EVENT_ID_RANGE_HANDLER(600, 608,EVT_CMD, OnSetSkin)
		
		CHAIN_EVENT_MAP_MEMBER(m_MyDeviceHandler)
	EVENT_MAP_END()

		//HostWnd真实窗口消息处理
	BEGIN_MSG_MAP_EX(CMainDlg)
		MSG_WM_CREATE(OnCreate)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_CLOSE(OnClose)
		MSG_WM_SIZE(OnSize)
		//托盘消息处理
		//MESSAGE_HANDLER(WM_ICONNOTIFY, OnIconNotify)
		MSG_WM_COMMAND(OnCommand)
		CHAIN_MSG_MAP(SHostWnd)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()
private:
	BOOL			m_bLayoutInited;
	STabCtrlHeaderBinder m_mainTabBinder;
	// 通过 IDeviceEventCallBack 继承
	virtual void idevice_event_cb_t(const idevice_event_t* event) override;
	CMyDeviceHandler m_MyDeviceHandler;	
	int m_selskinid = 0;
};
