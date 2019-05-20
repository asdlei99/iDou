//stamp:15fc3695025b3b30
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
				XML_dlg_battry = _T("LAYOUT:XML_dlg_battry");
				XML_dlg_all = _T("LAYOUT:XML_dlg_all");
				XML_App_Info = _T("LAYOUT:XML_App_Info");
			}
			const TCHAR * XML_MAINWND;
			const TCHAR * XML_page;
			const TCHAR * XML_MyDevice;
			const TCHAR * XML_MyDevice_Info;
			const TCHAR * XML_dlg_battry;
			const TCHAR * XML_dlg_all;
			const TCHAR * XML_App_Info;
		}LAYOUT;
		class _values{
			public:
			_values(){
				string = _T("values:string");
				color = _T("values:color");
				skin = _T("values:skin");
				template_cpp = _T("values:template");
			}
			const TCHAR * string;
			const TCHAR * color;
			const TCHAR * skin;
			const TCHAR * template_cpp;
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
				png_iphonescreen = _T("IMG:png_iphonescreen");
				png_ipadscreen = _T("IMG:png_ipadscreen");
				png_battery = _T("IMG:png_battery");
				png_batterybk = _T("IMG:png_batterybk");
				png_BatteryCurrentCapacity = _T("IMG:png_BatteryCurrentCapacity");
				png_check = _T("IMG:png_check");
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
			const TCHAR * png_iphonescreen;
			const TCHAR * png_ipadscreen;
			const TCHAR * png_battery;
			const TCHAR * png_batterybk;
			const TCHAR * png_BatteryCurrentCapacity;
			const TCHAR * png_check;
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
		{L"BaseInfoWnd",65563},
		{L"Name",65549},
		{L"Txt_Tip",65554},
		{L"_name_start",65535},
		{L"app_check_all",65622},
		{L"apps_header",65621},
		{L"batterybk",65568},
		{L"batterycap",65607},
		{L"bkwnd",65550},
		{L"btn_",65590},
		{L"btn_CheckiTunes",65546},
		{L"btn_WARRANTYEXPIRATIONDATE",65582},
		{L"btn_appUninstall",65634},
		{L"btn_batteryInfo",65588},
		{L"btn_close",65544},
		{L"btn_etdevname",65559},
		{L"btn_installapp",65619},
		{L"btn_max",65542},
		{L"btn_min",65541},
		{L"btn_mydevice",65536},
		{L"btn_reboot",65560},
		{L"btn_restore",65543},
		{L"btn_showDevInfo",65591},
		{L"btn_shutdown",65561},
		{L"btn_skin",65540},
		{L"btn_sleep",65562},
		{L"cachesize",65631},
		{L"check",65624},
		{L"disk_app",65595},
		{L"disk_av",65597},
		{L"disk_free",65600},
		{L"disk_free1",65603},
		{L"disk_free2",65606},
		{L"disk_other",65599},
		{L"disk_photo",65596},
		{L"disk_sys",65594},
		{L"disk_u",65598},
		{L"disk_udisk",65605},
		{L"et_devname",65558},
		{L"face",65551},
		{L"img_appIcon",65625},
		{L"img_batterycurrentcap",65608},
		{L"img_batteryemtycap",65609},
		{L"img_srceenshot",65556},
		{L"img_srceenshotbk",65555},
		{L"lable_ActivationState",65572},
		{L"lable_ActuallyCapacity",65610},
		{L"lable_AppleIDLock",65579},
		{L"lable_BatteryBootVoltage",65614},
		{L"lable_BatteryCurrentCapacity",65569},
		{L"lable_BatteryDate",65617},
		{L"lable_BatteryIsCapacity",65567},
		{L"lable_BatteryOrigin",65616},
		{L"lable_BatterySerialNumber",65612},
		{L"lable_BatteryTemperature",65615},
		{L"lable_BatteryVoltage",65613},
		{L"lable_CPU",65584},
		{L"lable_CycleCount",65586},
		{L"lable_CycleLife",65587},
		{L"lable_DesignCapacity",65611},
		{L"lable_DevColor",65566},
		{L"lable_DiskSize",65565},
		{L"lable_DiskType",65585},
		{L"lable_ECID",65577},
		{L"lable_FirmwareVersion",65570},
		{L"lable_HardwareModel",65578},
		{L"lable_IMEI",65575},
		{L"lable_IsJailreak",65571},
		{L"lable_LOC",65583},
		{L"lable_ModelNumber",65574},
		{L"lable_ProductDate",65581},
		{L"lable_ProductName",65564},
		{L"lable_ProductType",65573},
		{L"lable_SerialNumber",65576},
		{L"lable_UDID",65589},
		{L"lable_appCacheSize",65632},
		{L"lable_appName",65626},
		{L"lable_appSize",65630},
		{L"lable_appVer",65628},
		{L"lable_datadisk",65604},
		{L"lable_fudisk",65593},
		{L"lable_iCloud",65580},
		{L"lable_sysdisk",65602},
		{L"lv_appsList",65620},
		{L"name",65623},
		{L"nav_dev_cmd",65552},
		{L"opt",65633},
		{L"staticsize",65629},
		{L"tab2",65537},
		{L"tab3",65538},
		{L"tab4",65539},
		{L"tab_apps",65618},
		{L"tab_dev_cmd",65553},
		{L"tab_dev_info",65547},
		{L"tab_main",65545},
		{L"tv_ios",65548},
		{L"txt_devname",65557},
		{L"ver",65627},
		{L"wnd_ipaddsk",65592},
		{L"wnd_iphonedsk",65601}		};
	class _R{
	public:
		class _name{
		public:
		_name(){
			BaseInfoWnd = namedXmlID[0].strName;
			Name = namedXmlID[1].strName;
			Txt_Tip = namedXmlID[2].strName;
			_name_start = namedXmlID[3].strName;
			app_check_all = namedXmlID[4].strName;
			apps_header = namedXmlID[5].strName;
			batterybk = namedXmlID[6].strName;
			batterycap = namedXmlID[7].strName;
			bkwnd = namedXmlID[8].strName;
			btn_ = namedXmlID[9].strName;
			btn_CheckiTunes = namedXmlID[10].strName;
			btn_WARRANTYEXPIRATIONDATE = namedXmlID[11].strName;
			btn_appUninstall = namedXmlID[12].strName;
			btn_batteryInfo = namedXmlID[13].strName;
			btn_close = namedXmlID[14].strName;
			btn_etdevname = namedXmlID[15].strName;
			btn_installapp = namedXmlID[16].strName;
			btn_max = namedXmlID[17].strName;
			btn_min = namedXmlID[18].strName;
			btn_mydevice = namedXmlID[19].strName;
			btn_reboot = namedXmlID[20].strName;
			btn_restore = namedXmlID[21].strName;
			btn_showDevInfo = namedXmlID[22].strName;
			btn_shutdown = namedXmlID[23].strName;
			btn_skin = namedXmlID[24].strName;
			btn_sleep = namedXmlID[25].strName;
			cachesize = namedXmlID[26].strName;
			check = namedXmlID[27].strName;
			disk_app = namedXmlID[28].strName;
			disk_av = namedXmlID[29].strName;
			disk_free = namedXmlID[30].strName;
			disk_free1 = namedXmlID[31].strName;
			disk_free2 = namedXmlID[32].strName;
			disk_other = namedXmlID[33].strName;
			disk_photo = namedXmlID[34].strName;
			disk_sys = namedXmlID[35].strName;
			disk_u = namedXmlID[36].strName;
			disk_udisk = namedXmlID[37].strName;
			et_devname = namedXmlID[38].strName;
			face = namedXmlID[39].strName;
			img_appIcon = namedXmlID[40].strName;
			img_batterycurrentcap = namedXmlID[41].strName;
			img_batteryemtycap = namedXmlID[42].strName;
			img_srceenshot = namedXmlID[43].strName;
			img_srceenshotbk = namedXmlID[44].strName;
			lable_ActivationState = namedXmlID[45].strName;
			lable_ActuallyCapacity = namedXmlID[46].strName;
			lable_AppleIDLock = namedXmlID[47].strName;
			lable_BatteryBootVoltage = namedXmlID[48].strName;
			lable_BatteryCurrentCapacity = namedXmlID[49].strName;
			lable_BatteryDate = namedXmlID[50].strName;
			lable_BatteryIsCapacity = namedXmlID[51].strName;
			lable_BatteryOrigin = namedXmlID[52].strName;
			lable_BatterySerialNumber = namedXmlID[53].strName;
			lable_BatteryTemperature = namedXmlID[54].strName;
			lable_BatteryVoltage = namedXmlID[55].strName;
			lable_CPU = namedXmlID[56].strName;
			lable_CycleCount = namedXmlID[57].strName;
			lable_CycleLife = namedXmlID[58].strName;
			lable_DesignCapacity = namedXmlID[59].strName;
			lable_DevColor = namedXmlID[60].strName;
			lable_DiskSize = namedXmlID[61].strName;
			lable_DiskType = namedXmlID[62].strName;
			lable_ECID = namedXmlID[63].strName;
			lable_FirmwareVersion = namedXmlID[64].strName;
			lable_HardwareModel = namedXmlID[65].strName;
			lable_IMEI = namedXmlID[66].strName;
			lable_IsJailreak = namedXmlID[67].strName;
			lable_LOC = namedXmlID[68].strName;
			lable_ModelNumber = namedXmlID[69].strName;
			lable_ProductDate = namedXmlID[70].strName;
			lable_ProductName = namedXmlID[71].strName;
			lable_ProductType = namedXmlID[72].strName;
			lable_SerialNumber = namedXmlID[73].strName;
			lable_UDID = namedXmlID[74].strName;
			lable_appCacheSize = namedXmlID[75].strName;
			lable_appName = namedXmlID[76].strName;
			lable_appSize = namedXmlID[77].strName;
			lable_appVer = namedXmlID[78].strName;
			lable_datadisk = namedXmlID[79].strName;
			lable_fudisk = namedXmlID[80].strName;
			lable_iCloud = namedXmlID[81].strName;
			lable_sysdisk = namedXmlID[82].strName;
			lv_appsList = namedXmlID[83].strName;
			name = namedXmlID[84].strName;
			nav_dev_cmd = namedXmlID[85].strName;
			opt = namedXmlID[86].strName;
			staticsize = namedXmlID[87].strName;
			tab2 = namedXmlID[88].strName;
			tab3 = namedXmlID[89].strName;
			tab4 = namedXmlID[90].strName;
			tab_apps = namedXmlID[91].strName;
			tab_dev_cmd = namedXmlID[92].strName;
			tab_dev_info = namedXmlID[93].strName;
			tab_main = namedXmlID[94].strName;
			tv_ios = namedXmlID[95].strName;
			txt_devname = namedXmlID[96].strName;
			ver = namedXmlID[97].strName;
			wnd_ipaddsk = namedXmlID[98].strName;
			wnd_iphonedsk = namedXmlID[99].strName;
		}
		 const wchar_t * BaseInfoWnd;
		 const wchar_t * Name;
		 const wchar_t * Txt_Tip;
		 const wchar_t * _name_start;
		 const wchar_t * app_check_all;
		 const wchar_t * apps_header;
		 const wchar_t * batterybk;
		 const wchar_t * batterycap;
		 const wchar_t * bkwnd;
		 const wchar_t * btn_;
		 const wchar_t * btn_CheckiTunes;
		 const wchar_t * btn_WARRANTYEXPIRATIONDATE;
		 const wchar_t * btn_appUninstall;
		 const wchar_t * btn_batteryInfo;
		 const wchar_t * btn_close;
		 const wchar_t * btn_etdevname;
		 const wchar_t * btn_installapp;
		 const wchar_t * btn_max;
		 const wchar_t * btn_min;
		 const wchar_t * btn_mydevice;
		 const wchar_t * btn_reboot;
		 const wchar_t * btn_restore;
		 const wchar_t * btn_showDevInfo;
		 const wchar_t * btn_shutdown;
		 const wchar_t * btn_skin;
		 const wchar_t * btn_sleep;
		 const wchar_t * cachesize;
		 const wchar_t * check;
		 const wchar_t * disk_app;
		 const wchar_t * disk_av;
		 const wchar_t * disk_free;
		 const wchar_t * disk_free1;
		 const wchar_t * disk_free2;
		 const wchar_t * disk_other;
		 const wchar_t * disk_photo;
		 const wchar_t * disk_sys;
		 const wchar_t * disk_u;
		 const wchar_t * disk_udisk;
		 const wchar_t * et_devname;
		 const wchar_t * face;
		 const wchar_t * img_appIcon;
		 const wchar_t * img_batterycurrentcap;
		 const wchar_t * img_batteryemtycap;
		 const wchar_t * img_srceenshot;
		 const wchar_t * img_srceenshotbk;
		 const wchar_t * lable_ActivationState;
		 const wchar_t * lable_ActuallyCapacity;
		 const wchar_t * lable_AppleIDLock;
		 const wchar_t * lable_BatteryBootVoltage;
		 const wchar_t * lable_BatteryCurrentCapacity;
		 const wchar_t * lable_BatteryDate;
		 const wchar_t * lable_BatteryIsCapacity;
		 const wchar_t * lable_BatteryOrigin;
		 const wchar_t * lable_BatterySerialNumber;
		 const wchar_t * lable_BatteryTemperature;
		 const wchar_t * lable_BatteryVoltage;
		 const wchar_t * lable_CPU;
		 const wchar_t * lable_CycleCount;
		 const wchar_t * lable_CycleLife;
		 const wchar_t * lable_DesignCapacity;
		 const wchar_t * lable_DevColor;
		 const wchar_t * lable_DiskSize;
		 const wchar_t * lable_DiskType;
		 const wchar_t * lable_ECID;
		 const wchar_t * lable_FirmwareVersion;
		 const wchar_t * lable_HardwareModel;
		 const wchar_t * lable_IMEI;
		 const wchar_t * lable_IsJailreak;
		 const wchar_t * lable_LOC;
		 const wchar_t * lable_ModelNumber;
		 const wchar_t * lable_ProductDate;
		 const wchar_t * lable_ProductName;
		 const wchar_t * lable_ProductType;
		 const wchar_t * lable_SerialNumber;
		 const wchar_t * lable_UDID;
		 const wchar_t * lable_appCacheSize;
		 const wchar_t * lable_appName;
		 const wchar_t * lable_appSize;
		 const wchar_t * lable_appVer;
		 const wchar_t * lable_datadisk;
		 const wchar_t * lable_fudisk;
		 const wchar_t * lable_iCloud;
		 const wchar_t * lable_sysdisk;
		 const wchar_t * lv_appsList;
		 const wchar_t * name;
		 const wchar_t * nav_dev_cmd;
		 const wchar_t * opt;
		 const wchar_t * staticsize;
		 const wchar_t * tab2;
		 const wchar_t * tab3;
		 const wchar_t * tab4;
		 const wchar_t * tab_apps;
		 const wchar_t * tab_dev_cmd;
		 const wchar_t * tab_dev_info;
		 const wchar_t * tab_main;
		 const wchar_t * tv_ios;
		 const wchar_t * txt_devname;
		 const wchar_t * ver;
		 const wchar_t * wnd_ipaddsk;
		 const wchar_t * wnd_iphonedsk;
		}name;

		class _id{
		public:
		const static int BaseInfoWnd	=	65563;
		const static int Name	=	65549;
		const static int Txt_Tip	=	65554;
		const static int _name_start	=	65535;
		const static int app_check_all	=	65622;
		const static int apps_header	=	65621;
		const static int batterybk	=	65568;
		const static int batterycap	=	65607;
		const static int bkwnd	=	65550;
		const static int btn_	=	65590;
		const static int btn_CheckiTunes	=	65546;
		const static int btn_WARRANTYEXPIRATIONDATE	=	65582;
		const static int btn_appUninstall	=	65634;
		const static int btn_batteryInfo	=	65588;
		const static int btn_close	=	65544;
		const static int btn_etdevname	=	65559;
		const static int btn_installapp	=	65619;
		const static int btn_max	=	65542;
		const static int btn_min	=	65541;
		const static int btn_mydevice	=	65536;
		const static int btn_reboot	=	65560;
		const static int btn_restore	=	65543;
		const static int btn_showDevInfo	=	65591;
		const static int btn_shutdown	=	65561;
		const static int btn_skin	=	65540;
		const static int btn_sleep	=	65562;
		const static int cachesize	=	65631;
		const static int check	=	65624;
		const static int disk_app	=	65595;
		const static int disk_av	=	65597;
		const static int disk_free	=	65600;
		const static int disk_free1	=	65603;
		const static int disk_free2	=	65606;
		const static int disk_other	=	65599;
		const static int disk_photo	=	65596;
		const static int disk_sys	=	65594;
		const static int disk_u	=	65598;
		const static int disk_udisk	=	65605;
		const static int et_devname	=	65558;
		const static int face	=	65551;
		const static int img_appIcon	=	65625;
		const static int img_batterycurrentcap	=	65608;
		const static int img_batteryemtycap	=	65609;
		const static int img_srceenshot	=	65556;
		const static int img_srceenshotbk	=	65555;
		const static int lable_ActivationState	=	65572;
		const static int lable_ActuallyCapacity	=	65610;
		const static int lable_AppleIDLock	=	65579;
		const static int lable_BatteryBootVoltage	=	65614;
		const static int lable_BatteryCurrentCapacity	=	65569;
		const static int lable_BatteryDate	=	65617;
		const static int lable_BatteryIsCapacity	=	65567;
		const static int lable_BatteryOrigin	=	65616;
		const static int lable_BatterySerialNumber	=	65612;
		const static int lable_BatteryTemperature	=	65615;
		const static int lable_BatteryVoltage	=	65613;
		const static int lable_CPU	=	65584;
		const static int lable_CycleCount	=	65586;
		const static int lable_CycleLife	=	65587;
		const static int lable_DesignCapacity	=	65611;
		const static int lable_DevColor	=	65566;
		const static int lable_DiskSize	=	65565;
		const static int lable_DiskType	=	65585;
		const static int lable_ECID	=	65577;
		const static int lable_FirmwareVersion	=	65570;
		const static int lable_HardwareModel	=	65578;
		const static int lable_IMEI	=	65575;
		const static int lable_IsJailreak	=	65571;
		const static int lable_LOC	=	65583;
		const static int lable_ModelNumber	=	65574;
		const static int lable_ProductDate	=	65581;
		const static int lable_ProductName	=	65564;
		const static int lable_ProductType	=	65573;
		const static int lable_SerialNumber	=	65576;
		const static int lable_UDID	=	65589;
		const static int lable_appCacheSize	=	65632;
		const static int lable_appName	=	65626;
		const static int lable_appSize	=	65630;
		const static int lable_appVer	=	65628;
		const static int lable_datadisk	=	65604;
		const static int lable_fudisk	=	65593;
		const static int lable_iCloud	=	65580;
		const static int lable_sysdisk	=	65602;
		const static int lv_appsList	=	65620;
		const static int name	=	65623;
		const static int nav_dev_cmd	=	65552;
		const static int opt	=	65633;
		const static int staticsize	=	65629;
		const static int tab2	=	65537;
		const static int tab3	=	65538;
		const static int tab4	=	65539;
		const static int tab_apps	=	65618;
		const static int tab_dev_cmd	=	65553;
		const static int tab_dev_info	=	65547;
		const static int tab_main	=	65545;
		const static int tv_ios	=	65548;
		const static int txt_devname	=	65557;
		const static int ver	=	65627;
		const static int wnd_ipaddsk	=	65592;
		const static int wnd_iphonedsk	=	65601;
		}id;

		class _string{
		public:
		const static int ActivationState	=	0;
		const static int ActuallyCapacity	=	1;
		const static int AppleIDLock	=	2;
		const static int BattaryInfo	=	3;
		const static int BatteryBootVoltage	=	4;
		const static int BatteryCurrentCapacity	=	5;
		const static int BatteryDate	=	6;
		const static int BatteryOrigin	=	7;
		const static int BatterySerialNumber	=	8;
		const static int BatteryTemperature	=	9;
		const static int BatteryVoltage	=	10;
		const static int BluetoothAddress	=	11;
		const static int CPU	=	12;
		const static int CycleCount	=	13;
		const static int CycleLife	=	14;
		const static int DesignCapacity	=	15;
		const static int DevInfo	=	16;
		const static int DiskType	=	17;
		const static int ECID	=	18;
		const static int FirmwareVersion	=	19;
		const static int HardwareModel	=	20;
		const static int IMEI	=	21;
		const static int IsJailreak	=	22;
		const static int LOC	=	23;
		const static int ModelNumber	=	24;
		const static int ProductDate	=	25;
		const static int ProductType	=	26;
		const static int SerialNumber	=	27;
		const static int ShowDevCheck	=	28;
		const static int ShowDevInfo	=	29;
		const static int WARRANTYEXPIRATIONDATE	=	30;
		const static int WiFiAddress	=	31;
		const static int app	=	32;
		const static int av	=	33;
		const static int cantread	=	34;
		const static int charging	=	35;
		const static int checkcoverage	=	36;
		const static int cmd1	=	37;
		const static int cmd2	=	38;
		const static int cmd3	=	39;
		const static int cmd4	=	40;
		const static int cmd5	=	41;
		const static int free	=	42;
		const static int iCloud	=	43;
		const static int nocharging	=	44;
		const static int noname	=	45;
		const static int other	=	46;
		const static int photo	=	47;
		const static int system	=	48;
		const static int title	=	49;
		const static int udisk	=	50;
		const static int ver	=	51;
		const static int waitpair	=	52;
		}string;

		class _color{
		public:
		const static int black	=	0;
		const static int blue	=	1;
		const static int disk_app	=	2;
		const static int disk_av	=	3;
		const static int disk_free	=	4;
		const static int disk_other	=	5;
		const static int disk_photo	=	6;
		const static int disk_sys	=	7;
		const static int disk_u	=	8;
		const static int gray	=	9;
		const static int gray2	=	10;
		const static int gray3	=	11;
		const static int gray4	=	12;
		const static int green	=	13;
		const static int infoborder	=	14;
		const static int infotabbknor	=	15;
		const static int infotabbkpush	=	16;
		const static int item_hov	=	17;
		const static int item_sel	=	18;
		const static int mainbk	=	19;
		const static int red	=	20;
		const static int white	=	21;
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
