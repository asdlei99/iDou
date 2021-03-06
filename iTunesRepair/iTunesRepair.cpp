// dui-demo.cpp : main source file
//

#include "stdafx.h"
#include "CiTunesIPCClient.h"


int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE, LPTSTR lpstrCmdLine, int)
{
	if (_tcslen(lpstrCmdLine) == 0)
	{
		MessageBox(NULL, L"你是谁？", L"Error", MB_OK);
		return -1;
	}
	INT64 i64tmp = NULL;
	if (!::StrToInt64ExW(lpstrCmdLine, STIF_SUPPORT_HEX, &i64tmp))
	{
		MessageBox(NULL, L"无法获取通信句柄", L"Error", MB_OK);
		return -1;
	}
	HWND hSvrWindow = (HWND)i64tmp;
	if (!IsWindow(hSvrWindow))
	{
		MessageBox(NULL, L"获取的通信句柄无效", L"Error", MB_OK);
		return -1;
	}

	HRESULT hRes = OleInitialize(NULL);

	SASSERT(SUCCEEDED(hRes));
	int nRet = 0;

	ChangeWindowMessageFilter(UM_CALL_FUN,MSGFLT_ADD);

	SApplication* theApp = new SApplication(NULL, hInstance);
	{
		CiTunesIPCClientWnd dlgMain;
		dlgMain.Create(L"itunesipc_msg_windows", 0, 0, 0, 0, 0, 0, HWND_MESSAGE, nullptr);
		if (dlgMain.SendMessage(WM_INITDIALOG, (WPARAM)hSvrWindow))
		{
			nRet = theApp->Run(dlgMain.m_hWnd);
		}
		else
			MessageBox(NULL, L"通信失败!!!!", L"Error", MB_OK);
	}	
	delete theApp;
	OleUninitialize();	
	return nRet;
}
