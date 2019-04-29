//stamp:107ccf7068061d5d
/*<------------------------------------------------------------------------------------------------->*/
/*该文件由uiresbuilder生成，请不要手动修改*/
/*<------------------------------------------------------------------------------------------------->*/
#pragma once
#include <res.mgr/snamedvalue.h>
#define ROBJ_IN_CPP \
namespace SOUI \
{\
    const _R R;\
    const _UIRES UIRES;\
}
namespace SOUI
{
	class _UIRES{
		public:
		class _UIDEF{
			public:
			_UIDEF(){
				XML_INIT = _T("UIDEF:XML_INIT");
			}
			const TCHAR * XML_INIT;
		}UIDEF;
		class _LAYOUT{
			public:
			_LAYOUT(){
				XML_MAINWND = _T("LAYOUT:XML_MAINWND");
				XML_page = _T("LAYOUT:XML_page");
				XML_MyDevice = _T("LAYOUT:XML_MyDevice");
				XML_MyDevice_Info = _T("LAYOUT:XML_MyDevice_Info");
			}
			const TCHAR * XML_MAINWND;
			const TCHAR * XML_page;
			const TCHAR * XML_MyDevice;
			const TCHAR * XML_MyDevice_Info;
		}LAYOUT;
		class _values{
			public:
			_values(){
				string = _T("values:string");
				color = _T("values:color");
				skin = _T("values:skin");
			}
			const TCHAR * string;
			const TCHAR * color;
			const TCHAR * skin;
		}values;
		class _IMG{
			public:
			_IMG(){
				traymenu_icons = _T("IMG:traymenu_icons");
				png_tab_main = _T("IMG:png_tab_main");
				png_page_icons = _T("IMG:png_page_icons");
				png_logo = _T("IMG:png_logo");
				png_mydevice = _T("IMG:png_mydevice");
				png_bell = _T("IMG:png_bell");
				png_skinbtn = _T("IMG:png_skinbtn");
				png_connect_dev = _T("IMG:png_connect_dev");
				png_pro_pc_apps = _T("IMG:png_pro_pc_apps");
				png_menu_bk = _T("IMG:png_menu_bk");
				png_icon_list = _T("IMG:png_icon_list");
				png_icon_article = _T("IMG:png_icon_article");
			}
			const TCHAR * traymenu_icons;
			const TCHAR * png_tab_main;
			const TCHAR * png_page_icons;
			const TCHAR * png_logo;
			const TCHAR * png_mydevice;
			const TCHAR * png_bell;
			const TCHAR * png_skinbtn;
			const TCHAR * png_connect_dev;
			const TCHAR * png_pro_pc_apps;
			const TCHAR * png_menu_bk;
			const TCHAR * png_icon_list;
			const TCHAR * png_icon_article;
		}IMG;
		class _ICON{
			public:
			_ICON(){
				ICON_LOGO = _T("ICON:ICON_LOGO");
			}
			const TCHAR * ICON_LOGO;
		}ICON;
		class _SMENU{
			public:
			_SMENU(){
				menu_skin = _T("SMENU:menu_skin");
				menu_tray = _T("SMENU:menu_tray");
			}
			const TCHAR * menu_skin;
			const TCHAR * menu_tray;
		}SMENU;
	};
	const SNamedID::NAMEDVALUE namedXmlID[]={
		{L"BaseInfoWnd",65556},
		{L"Name",65548},
		{L"Txt_Tip",65552},
		{L"_name_start",65535},
		{L"btn_",65569},
		{L"btn_batteryInfo",65567},
		{L"btn_close",65544},
		{L"btn_max",65542},
		{L"btn_min",65541},
		{L"btn_mydevice",65536},
		{L"btn_reboot",65553},
		{L"btn_restore",65543},
		{L"btn_shutdown",65554},
		{L"btn_skin",65540},
		{L"btn_sleep",65555},
		{L"face",65549},
		{L"lable_BluetoothAddress",65561},
		{L"lable_CycleCount",65565},
		{L"lable_CycleLife",65566},
		{L"lable_HardwareModel",65562},
		{L"lable_IMEI",65563},
		{L"lable_ModelNumber",65559},
		{L"lable_ProductName",65557},
		{L"lable_ProductType",65564},
		{L"lable_SerialNumber",65558},
		{L"lable_UDID",65568},
		{L"lable_WiFiAddress",65560},
		{L"nav_dev_cmd",65550},
		{L"tab2",65537},
		{L"tab3",65538},
		{L"tab4",65539},
		{L"tab_dev_cmd",65551},
		{L"tab_dev_info",65546},
		{L"tab_main",65545},
		{L"tv_ios",65547}		};
	class _R{
	public:
		class _name{
		public:
		_name(){
			BaseInfoWnd = namedXmlID[0].strName;
			Name = namedXmlID[1].strName;
			Txt_Tip = namedXmlID[2].strName;
			_name_start = namedXmlID[3].strName;
			btn_ = namedXmlID[4].strName;
			btn_batteryInfo = namedXmlID[5].strName;
			btn_close = namedXmlID[6].strName;
			btn_max = namedXmlID[7].strName;
			btn_min = namedXmlID[8].strName;
			btn_mydevice = namedXmlID[9].strName;
			btn_reboot = namedXmlID[10].strName;
			btn_restore = namedXmlID[11].strName;
			btn_shutdown = namedXmlID[12].strName;
			btn_skin = namedXmlID[13].strName;
			btn_sleep = namedXmlID[14].strName;
			face = namedXmlID[15].strName;
			lable_BluetoothAddress = namedXmlID[16].strName;
			lable_CycleCount = namedXmlID[17].strName;
			lable_CycleLife = namedXmlID[18].strName;
			lable_HardwareModel = namedXmlID[19].strName;
			lable_IMEI = namedXmlID[20].strName;
			lable_ModelNumber = namedXmlID[21].strName;
			lable_ProductName = namedXmlID[22].strName;
			lable_ProductType = namedXmlID[23].strName;
			lable_SerialNumber = namedXmlID[24].strName;
			lable_UDID = namedXmlID[25].strName;
			lable_WiFiAddress = namedXmlID[26].strName;
			nav_dev_cmd = namedXmlID[27].strName;
			tab2 = namedXmlID[28].strName;
			tab3 = namedXmlID[29].strName;
			tab4 = namedXmlID[30].strName;
			tab_dev_cmd = namedXmlID[31].strName;
			tab_dev_info = namedXmlID[32].strName;
			tab_main = namedXmlID[33].strName;
			tv_ios = namedXmlID[34].strName;
		}
		 const wchar_t * BaseInfoWnd;
		 const wchar_t * Name;
		 const wchar_t * Txt_Tip;
		 const wchar_t * _name_start;
		 const wchar_t * btn_;
		 const wchar_t * btn_batteryInfo;
		 const wchar_t * btn_close;
		 const wchar_t * btn_max;
		 const wchar_t * btn_min;
		 const wchar_t * btn_mydevice;
		 const wchar_t * btn_reboot;
		 const wchar_t * btn_restore;
		 const wchar_t * btn_shutdown;
		 const wchar_t * btn_skin;
		 const wchar_t * btn_sleep;
		 const wchar_t * face;
		 const wchar_t * lable_BluetoothAddress;
		 const wchar_t * lable_CycleCount;
		 const wchar_t * lable_CycleLife;
		 const wchar_t * lable_HardwareModel;
		 const wchar_t * lable_IMEI;
		 const wchar_t * lable_ModelNumber;
		 const wchar_t * lable_ProductName;
		 const wchar_t * lable_ProductType;
		 const wchar_t * lable_SerialNumber;
		 const wchar_t * lable_UDID;
		 const wchar_t * lable_WiFiAddress;
		 const wchar_t * nav_dev_cmd;
		 const wchar_t * tab2;
		 const wchar_t * tab3;
		 const wchar_t * tab4;
		 const wchar_t * tab_dev_cmd;
		 const wchar_t * tab_dev_info;
		 const wchar_t * tab_main;
		 const wchar_t * tv_ios;
		}name;

		class _id{
		public:
		const static int BaseInfoWnd	=	65556;
		const static int Name	=	65548;
		const static int Txt_Tip	=	65552;
		const static int _name_start	=	65535;
		const static int btn_	=	65569;
		const static int btn_batteryInfo	=	65567;
		const static int btn_close	=	65544;
		const static int btn_max	=	65542;
		const static int btn_min	=	65541;
		const static int btn_mydevice	=	65536;
		const static int btn_reboot	=	65553;
		const static int btn_restore	=	65543;
		const static int btn_shutdown	=	65554;
		const static int btn_skin	=	65540;
		const static int btn_sleep	=	65555;
		const static int face	=	65549;
		const static int lable_BluetoothAddress	=	65561;
		const static int lable_CycleCount	=	65565;
		const static int lable_CycleLife	=	65566;
		const static int lable_HardwareModel	=	65562;
		const static int lable_IMEI	=	65563;
		const static int lable_ModelNumber	=	65559;
		const static int lable_ProductName	=	65557;
		const static int lable_ProductType	=	65564;
		const static int lable_SerialNumber	=	65558;
		const static int lable_UDID	=	65568;
		const static int lable_WiFiAddress	=	65560;
		const static int nav_dev_cmd	=	65550;
		const static int tab2	=	65537;
		const static int tab3	=	65538;
		const static int tab4	=	65539;
		const static int tab_dev_cmd	=	65551;
		const static int tab_dev_info	=	65546;
		const static int tab_main	=	65545;
		const static int tv_ios	=	65547;
		}id;

		class _string{
		public:
		const static int BluetoothAddress	=	0;
		const static int CycleCount	=	1;
		const static int CycleLife	=	2;
		const static int HardwareModel	=	3;
		const static int IMEI	=	4;
		const static int ModelNumber	=	5;
		const static int ProductType	=	6;
		const static int SerialNumber	=	7;
		const static int ShowDevCheck	=	8;
		const static int ShowDevInfo	=	9;
		const static int WiFiAddress	=	10;
		const static int cantread	=	11;
		const static int cmd1	=	12;
		const static int cmd2	=	13;
		const static int cmd3	=	14;
		const static int cmd4	=	15;
		const static int cmd5	=	16;
		const static int noname	=	17;
		const static int title	=	18;
		const static int ver	=	19;
		const static int waitpair	=	20;
		}string;

		class _color{
		public:
		const static int black	=	0;
		const static int blue	=	1;
		const static int gray	=	2;
		const static int green	=	3;
		const static int infoborder	=	4;
		const static int infotabbknor	=	5;
		const static int infotabbkpush	=	6;
		const static int mainbk	=	7;
		const static int red	=	8;
		const static int white	=	9;
		}color;

	};

#ifdef R_IN_CPP
	 extern const _R R;
	 extern const _UIRES UIRES;
#else
	 extern const __declspec(selectany) _R & R = _R();
	 extern const __declspec(selectany) _UIRES & UIRES = _UIRES();
#endif//R_IN_CPP
}
