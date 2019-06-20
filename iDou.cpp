// dui-demo.cpp : main source file
//

#include "stdafx.h"
#include "MainDlg.h"
#include "trayicon\SShellNotifyIcon.h"
#include "CDataCenter.h"
#include <memory>
//从PE文件加载，注意从文件加载路径位置
#define RES_TYPE 2
//#define SYSRES_TYPE 2
// #define RES_TYPE 0   //PE
// #define RES_TYPE 1   //ZIP
// #define RES_TYPE 2   //7z
// #define RES_TYPE 2   //文件
//去掉多项支持，以免代码显得混乱
#if (RES_TYPE==1)
#include "resprovider-zip\zipresprovider-param.h"
#else 
#if (RES_TYPE==2)
#include "resprovider-7zip\zip7resprovider-param.h"
#endif
#include "Cafctask.h"
#endif
#ifdef _DEBUG
#define SYS_NAMED_RESOURCE _T("soui-sys-resourced.dll")
#else
#define SYS_NAMED_RESOURCE _T("soui-sys-resource.dll")
#endif


//定义唯一的一个R,UIRES对象,ROBJ_IN_CPP是resource.h中定义的宏。
ROBJ_IN_CPP

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPTSTR lpstrCmdLine, int /*nCmdShow*/)
{
	HRESULT hRes = OleInitialize(NULL);
	SASSERT(SUCCEEDED(hRes));

	int nRet = 0;

	SComMgr* pComMgr = new SComMgr;
	TCHAR szCurrentDir[MAX_PATH] = { 0 };
	GetModuleFileName(NULL, szCurrentDir, sizeof(szCurrentDir));	
	SetCurrentDirectory(szCurrentDir);
	{
		BOOL bLoaded = FALSE;
		CAutoRefPtr<SOUI::IImgDecoderFactory> pImgDecoderFactory;
		CAutoRefPtr<SOUI::IRenderFactory> pRenderFactory;
		bLoaded = pComMgr->CreateRender_Skia((IObjRef * *)& pRenderFactory);
		SASSERT_FMT(bLoaded, _T("load interface [render] failed!"));
		bLoaded = pComMgr->CreateImgDecoder((IObjRef * *)& pImgDecoderFactory);
		SASSERT_FMT(bLoaded, _T("load interface [%s] failed!"), _T("imgdecoder"));

		pRenderFactory->SetImgDecoderFactory(pImgDecoderFactory);
		SApplication* theApp = new SApplication(pRenderFactory, hInstance);
#ifdef _DEBUG
		//选择了仅在Release版本打包资源则系统资源在DEBUG下始终使用DLL加载
		{
			CAutoRefPtr<IResProvider> sysResProvider;
			CreateResProvider(RES_FILE, (IObjRef * *)& sysResProvider);
			bLoaded = sysResProvider->Init((LPARAM)_T("uires//theme_sys_res"), 0);
			SASSERT(bLoaded);
			theApp->LoadSystemNamedResource(sysResProvider);
		}
#else		
		//钩选了复制系统资源选项
		{
			CAutoRefPtr<IResProvider> pSysResProvider;
			bLoaded = pComMgr->CreateResProvider_7ZIP((IObjRef * *)& pSysResProvider);
			SASSERT_FMT(bLoaded, _T("load interface [%s] failed!"), _T("resprovider_zip"));
			ZIP7RES_PARAM param;
			param.ZipFile(pRenderFactory, _T("uires.7z"), "idou123321idou", _T("theme_sys_res"));
			bLoaded = pSysResProvider->Init((WPARAM)& param, 0);
			SASSERT(bLoaded);
			bLoaded = theApp->LoadSystemNamedResource(pSysResProvider);
			SASSERT(bLoaded);
		}
#endif

		CAutoRefPtr<IResProvider>   pResProvider;

		theApp->RegisterSkinClass<SDemoSkin>();
		theApp->RegisterWindowClass<STabCtrlTemplate>();
		theApp->RegisterWindowClass<SShellNotifyIcon>();
		theApp->RegisterWindowClass<SHeaderCtrlEx>();
		theApp->RegisterWindowClass<SMCListViewEx>();
		theApp->RegisterWindowClass<SToggle2>();
#ifdef _DEBUG		
		//选择了仅在Release版本打包资源则在DEBUG下始终使用文件加载
		{
			CreateResProvider(RES_FILE, (IObjRef * *)& pResProvider);
			bLoaded = pResProvider->Init((LPARAM)_T("uires"), 0);
			SASSERT(bLoaded);
		}
#else
		{
			bLoaded = pComMgr->CreateResProvider_7ZIP((IObjRef * *)& pResProvider);
			SASSERT_FMT(bLoaded, _T("load interface [%s] failed!"), _T("resprovider_zip"));
			ZIP7RES_PARAM param;
			param.ZipFile(pRenderFactory, _T("uires.7z"), "idou123321idou");
			bLoaded = pResProvider->Init((WPARAM)& param, 0);
			SASSERT(bLoaded);
		}
#endif
		theApp->InitXmlNamedID(namedXmlID, ARRAYSIZE(namedXmlID), TRUE);
		theApp->AddResProvider(pResProvider);


		// BLOCK: Run application
		{
			std::unique_ptr<SNotifyCenter> notifycenter(new SNotifyCenter());
			std::unique_ptr<CDataCenter> datacenter(new CDataCenter());
			std::unique_ptr <Cafctask> m_afctask(new Cafctask());
			CMainDlg dlgMain;
			dlgMain.Create(GetActiveWindow());
			dlgMain.SendMessage(WM_INITDIALOG);
			dlgMain.CenterWindow(dlgMain.m_hWnd);
			dlgMain.ShowWindow(SW_SHOWNORMAL);
			nRet = theApp->Run(dlgMain.m_hWnd);
			m_afctask.release();
			datacenter.release();
			notifycenter.release();
		}

		delete theApp;
	}

	delete pComMgr;

	OleUninitialize();
	return nRet;
}
