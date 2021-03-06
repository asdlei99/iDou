// MainDlg.cpp : implementation of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MainDlg.h"
#include "CDataCenter.h"
#include "iOsDeviceLib/iOSUtils.h"
#include "CiTunesRepairDlg.h"
#include <helper\SMenuEx.h>

CMainDlg::CMainDlg() : SHostWnd(_T("LAYOUT:XML_MAINWND"))
{
	m_bLayoutInited = FALSE;
}

CMainDlg::~CMainDlg()
{
}

int CMainDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	SetMsgHandled(FALSE);
	return 0;
}

void LoadSkinFormXml(SDemoSkin* skin, SkinType* skinType, SkinLoadInf* skininf)
{
	SStringT strSkinConfigPath = SApplication::getSingleton().GetAppDir() + _T("\\themes\\skin_config.xml");

	pugi::xml_document docLoad;
	pugi::xml_parse_result result = docLoad.load_file(strSkinConfigPath);
	if (result)
	{
		pugi::xml_node skinInf = docLoad.child(L"DEMO_SKIN_CONFIG").child(L"skinInf");
		*skinType = (SkinType)skinInf.attribute(L"type").as_int();
		switch (*skinType)
		{
			//纯色只有SkinSaveInf的color有效
			case color:
				skininf->color = skinInf.attribute(L"color").as_int();
				break;
				//此处为系统皮肤，只需要给文件路径和margin
			case sys:
				skininf->filepath = skinInf.attribute(L"skin_path").as_string();
				int v1 = 0, v2 = 0, v3 = 0, v4 = 0;
				swscanf(skinInf.attribute(L"skin_margin").as_string(), L"%d,%d,%d,%d", &v1, &v2, &v3, &v4);
				skininf->margin.left = v1;
				skininf->margin.top = v2;
				skininf->margin.right = v3;
				skininf->margin.bottom = v4;
				break;
		}
	}
}

LPCTSTR skinColor[] = { _T("#236ee7"), _T("#c0c0c0"),_T("#e79481") ,
		_T("#e1839f"), _T("#e97474"), _T("#8eae48"),
		_T("#7f74d1"), _T("#d59d66"), _T("#9f887a") };
int GetSelIdFormColor(LPCTSTR COLOR)
{
	for (int i = 0; i < ARRAYSIZE(skinColor); i++)
	{
		if (_tcsnicmp(COLOR, skinColor[i], 7) == 0)
		{
			return 600 + i;
		}
	}
	return 0;
}

bool CMainDlg::LoadSkin()
{
	SDemoSkin* skin = (SDemoSkin*)GETSKIN(L"skin_bk", GetScale());
	if (skin)
	{
		SkinLoadInf loadInf;
		SkinType type;
		LoadSkinFormXml(skin, &type, &loadInf);

		if (type == SkinType::color)
		{
			SStringW bkColor;
			bkColor.Format(L"#%02x%02x%02x%02x",
				GetRValue(loadInf.color),
				GetGValue(loadInf.color),
				GetBValue(loadInf.color),
				GetAValue(loadInf.color));
			m_selskinid = GetSelIdFormColor(bkColor);
			FindChildByID(R.id.Txt_Tip)->SetAttribute(L"colorText", bkColor);
		}

		skin->SetHander(this);
		return skin->LoadSkin(type, loadInf);
	}
	return false;
}

void CMainDlg::ShowToolTip(LPCTSTR tipMsg)
{
	SShellNotifyIcon* notify = FindChildByID2<SShellNotifyIcon>(110);
	notify->ShowNotify(GETSTRING(L"@string/title"), tipMsg);
}

void CMainDlg::OnSkin()
{
	SWindow* pWnd = FindChildByID(R.id.btn_skin);
	if (pWnd)
	{
		CRect rcWnd = pWnd->GetWindowRect();
		ClientToScreen(&rcWnd);
		SMenuEx menu;
		menu.LoadMenu(_T("SMENU:menu_skin"));
		SMenuExItem* menuItem = menu.GetMenuItem(699);
		SASSERT(menuItem);
		SWindow* selWnd = menuItem->FindChildByID(m_selskinid);
		if (selWnd)
		{
			selWnd->EnableWindow(FALSE);
			selWnd->FindChildByID(R.id.check)->SetVisible(TRUE);
		}
		menu.TrackPopupMenu(0, rcWnd.left - 163, rcWnd.bottom + 2, m_hWnd);
	}
}

void CMainDlg::OnSetSkin(EventArgs* id)
{
	COLORREF color;
	if (SColorParser::ParseValue(skinColor[id->idFrom - 600], color))
	{
		SDemoSkin* skin = (SDemoSkin*)GETSKIN(L"skin_bk", GetScale());
		SWindow* pWnd = sobj_cast<SWindow>(id->sender);
		SASSERT(pWnd);
		if (skin)
		{
			pWnd->FindChildByID(R.id.check)->SetVisible(TRUE);
			pWnd->EnableWindow(FALSE, TRUE);
			pWnd = pWnd->GetTopLevelParent()->FindChildByID(m_selskinid);
			if (pWnd)
			{
				pWnd->FindChildByID(R.id.check)->SetVisible(FALSE);
				pWnd->EnableWindow(TRUE, TRUE);
			}
			m_selskinid = id->idFrom;
			skin->SetColor(color);
			FindChildByID(R.id.Txt_Tip)->SetAttribute(L"colorText", skinColor[id->idFrom - 600]);
			//SWindow::Invalidate();
			FindChildByID(R.id.root)->Invalidate();
		}
	}
}

void CMainDlg::SetThisToiTunesCallBack()
{
	if (IDEVICE_E_SUCCESS != CiOSDevice::SetCallBack(this))
	{
		SMessageBox(m_hWnd, L"应用程序无法初使化,请尝试重新启动或者升级到新版本！", L"错误", MB_OK);
	}
}

void CMainDlg::CheckiTunesService()
{
	CiTunesRepairDlg dlg;
	dlg.DoModal(m_hWnd);
}

void CMainDlg::BindTab()
{
	m_mainTabBinder.BindHost(FindChildByID2<STabCtrl>(R.id.tab_main));
	m_mainTabBinder.Bind(FindChildByID(R.id.btn_mydevice), 0);
	m_mainTabBinder.Bind(FindChildByID(R.id.btn_appcenter), 1);
}

void CMainDlg::InitHandler()
{
	m_MyDeviceHandler.OnInit(this);
}

void CMainDlg::OnMenu()
{
	SWindow* pWnd = FindChildByID(R.id.btn_menu);
	if (pWnd)
	{
		CRect rcWnd = pWnd->GetWindowRect();
		ClientToScreen(&rcWnd);
		SMenuEx menu;
		menu.LoadMenu(_T("SMENU:menu_main"));
		menu.TrackPopupMenu(0, rcWnd.left, rcWnd.bottom + 2, m_hWnd);
	}
}

BOOL CMainDlg::OnInitDialog(HWND hWnd, LPARAM lParam)
{
	ModifyStyle(WS_BORDER, 0);
	m_bLayoutInited = TRUE;
	//init all
	BindTab();
	InitHandler();
	LoadSkin();
	SetThisToiTunesCallBack();

	return 0;
}

bool CMainDlg::SaveSkin(SkinType skinType, SkinSaveInf& skinSaveInf)
{
	pugi::xml_document docSave;
	pugi::xml_node rootNode = docSave.append_child(L"DEMO_SKIN_CONFIG");
	pugi::xml_node childSkinType = rootNode.append_child(L"skinInf");
	childSkinType.append_attribute(L"type") = skinType;
	SStringT strSkinConfigPath = SApplication::getSingleton().GetAppDir() + _T("\\themes\\skin_config.xml");
	switch (skinType)
	{
		case color://纯色只有SkinSaveInf的color有效
			childSkinType.append_attribute(L"color") = (int)skinSaveInf.color;
			break;
		case sys://此处为系统皮肤，只需要给文件路径和margin
			{
				childSkinType.append_attribute(L"skin_path") = skinSaveInf.filepath;
				SStringW margin;
				margin.Format(L"%d,%d,%d,%d", skinSaveInf.margin.left, skinSaveInf.margin.top, skinSaveInf.margin.right, skinSaveInf.margin.bottom);
				childSkinType.append_attribute(L"skin_margin") = margin;
			}
			break;
		case builtin:
		default:
			break;
	}
	return docSave.save_file(strSkinConfigPath);
}
//TODO:消息映射
void CMainDlg::OnClose()
{
	m_MyDeviceHandler.OnUninit();

	SNativeWnd::DestroyWindow();
	SDemoSkin* skin = (SDemoSkin*)GETSKIN(L"skin_bk", GetScale());
	if (skin)
	{
		skin->SaveSkin();
	}
}

void CMainDlg::OnMaximize()
{
	SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE);
}

void CMainDlg::OnRestore()
{
	SendMessage(WM_SYSCOMMAND, SC_RESTORE);
}

void CMainDlg::OnMinimize()
{
	//SendMessage(WM_SYSCOMMAND, SC_MINIMIZE);
	ShowWindow(SW_HIDE);
}

void CMainDlg::OnSize(UINT nType, CSize size)
{
	SetMsgHandled(FALSE);
	if (!m_bLayoutInited) return;

	SWindow* pBtnMax = FindChildByName(L"btn_max");
	SWindow* pBtnRestore = FindChildByName(L"btn_restore");
	if (!pBtnMax || !pBtnRestore) return;

	if (nType == SIZE_MAXIMIZED)
	{
		pBtnRestore->SetVisible(TRUE);
		pBtnMax->SetVisible(FALSE);
	}
	else if (nType == SIZE_RESTORED)
	{
		pBtnRestore->SetVisible(FALSE);
		pBtnMax->SetVisible(TRUE);
	}
}

//演示如何响应菜单事件
void CMainDlg::OnCommand(UINT uNotifyCode, int nID, HWND wndCtl)
{
	if (uNotifyCode == 0)
	{
		switch (nID)
		{
			case 6:
				PostMessage(WM_CLOSE);
				break;
			case 702:
				{
				
				}
				break;
			default:
				break;
		}
	}
}

void CMainDlg::idevice_event_cb_t(const idevice_event_t* event)
{
	//conn_type没什么用始终为1，
	//event 
	//IDEVICE_DEVICE_ADD = 1,添加
	//IDEVICE_DEVICE_REMOVE,拔出
	//IDEVICE_DEVICE_PAIRED 配对，一个新设备，会先收到添加，如果在手机点击信任电脑会收到配对
	switch (event->event)
	{
		case IDEVICE_DEVICE_ADD:
			{
				SRUNONUISYNC(
					bool bCan;
				if (CDataCenter::getSingleton().AddDevUDID(event->udid, bCan))
				{
					m_MyDeviceHandler.AddDev(event, bCan);
				});
			}break;
		case IDEVICE_DEVICE_REMOVE: {
				SRUNONUISYNC(
					m_MyDeviceHandler.TryEndInfoDlg(event->udid);
				if (CDataCenter::getSingleton().RemoveDevGUID(event->udid))
				{
					m_MyDeviceHandler.RemoveDev(event);
				});
			}break;
		case IDEVICE_DEVICE_PAIRED: {
				SRUNONUISYNC(
					bool bCan;
				if (CDataCenter::getSingleton().PairDev(event->udid, bCan))
					m_MyDeviceHandler.PairDev(event, bCan);
				);
			}break;
	}
}

