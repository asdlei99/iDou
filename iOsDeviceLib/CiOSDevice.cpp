#include "pch.h"
#include "CiOSDevice.h"
#include "../../libimobiledevice-vs/libimobiledevice/common/utils.c"
#include "iOSUtils.h"
#include <string/strcpcvt.h>
#include "libimobiledevice/diagnostics_relay.h"

CiOSDevice::CiOSDevice()
{
}


CiOSDevice::~CiOSDevice()
{
}

bool CiOSDevice::OpenDevice(LPCSTR udid)
{
	if (udid)
	{
		if (idevice_new(&m_device, udid) == IDEVICE_E_SUCCESS)
		{
			return lockdownd_client_new_with_handshake(m_device, &m_client, "my_iOSDevice") == LOCKDOWN_E_SUCCESS;
		}
	}
	return false;
}

void CiOSDevice::CloseDevice()
{
	if (m_device)
	{
		idevice_free(m_device);
		m_device = NULL;
	}
	if (m_client)
	{
		lockdownd_client_free(m_client);
		m_client = NULL;
	}
}

bool CiOSDevice::IsOpen()
{
	return m_device && m_client;
}

bool CiOSDevice::GetDevName(SStringT& outName)
{
	if (m_iosInfo.m_strDevName.IsEmpty())
	{
		char* name = NULL;
		lockdownd_get_device_name(m_client, &name);
		if (name) {
			using namespace SOUI;
			m_iosInfo.m_strDevName = S_CA2T(name, CP_UTF8);
			free(name);
		}
		else
			return false;
	}
	outName = m_iosInfo.m_strDevName;
	return true;
}

bool CiOSDevice::_GetAddress(SStringT& outAddress, LPCSTR nodename)
{
	plist_t address_node = NULL;
	if (LOCKDOWN_E_SUCCESS == lockdownd_get_value(m_client, NULL, nodename, &address_node))
	{
		char* node_value = NULL;

		plist_type type = plist_get_node_type(address_node);
		switch (type)
		{
		case PLIST_STRING:
			plist_get_string_val(address_node, &node_value); break;
		case PLIST_BOOLEAN:
		{
			uint8_t boolvalue;
			plist_get_bool_val(address_node, &boolvalue);
			node_value =(char*) malloc(10);
			strcpy_s(node_value, 10, boolvalue ? "true" : false);
		}break;
		case PLIST_ARRAY:
		{
			
		}break;
		}
		plist_free(address_node);
		address_node = NULL;
		if (node_value) {
			using namespace SOUI;
			outAddress = S_CA2T(node_value, CP_UTF8).MakeUpper();
			free(node_value);
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool CiOSDevice::GetWifiAddress(SStringT& outMac)
{
	if (m_iosInfo.m_strDevWiFiAddress.IsEmpty())
	{
		if (!_GetAddress(m_iosInfo.m_strDevWiFiAddress, NODE_WIFI_ADDRESS))
			return false;
	}
	outMac = m_iosInfo.m_strDevWiFiAddress;
	return true;
}

bool CiOSDevice::GetBluetoothAddress(SStringT& outMac)
{
	if (m_iosInfo.m_strDevBluetoothAddress.IsEmpty())
	{
		if (!_GetAddress(m_iosInfo.m_strDevBluetoothAddress, NODE_BLUETOOTH_ADDRESS))
			return false;
	}
	outMac = m_iosInfo.m_strDevBluetoothAddress;
	return true;
}

bool CiOSDevice::SetDevName(LPCTSTR newName)
{
	if (newName)
	{
		using namespace SOUI;
		SStringA strU8Name = S_CT2A(newName, CP_UTF8);
		if (lockdownd_set_value(m_client, NULL, "DeviceName", plist_new_string(strU8Name)) == LOCKDOWN_E_SUCCESS) {
			m_iosInfo.m_strDevName = newName;
			return true;
		}
	}
	return false;
}

bool _GetAddress(lockdownd_client_t client, SOUI::SStringA& outAddress, LPCSTR nodename)
{
	plist_t address_node = NULL;
	if (LOCKDOWN_E_SUCCESS == lockdownd_get_value(client, NULL, nodename, &address_node))
	{
		char* node_value = NULL;
		plist_type type = plist_get_node_type(address_node);
		switch (type)
		{
		case PLIST_STRING:
			plist_get_string_val(address_node, &node_value); break;
		case PLIST_BOOLEAN:
		{
			uint8_t boolvalue;
			plist_get_bool_val(address_node, &boolvalue);
			node_value = (char*)malloc(10);
			strcpy_s(node_value, 10, boolvalue ? "true" : "false");
		}break;
		case PLIST_ARRAY:
		{
			plist_array_iter iter =NULL;
			plist_array_new_iter(address_node,&iter);
			while (iter)
			{
				plist_t item=NULL;
				plist_array_next_item(address_node,iter, &item);
				plist_type itemtype = plist_get_node_type(item);
				if (PLIST_DICT == plist_get_node_type(item))
				{
					plist_dict_iter iter2 = NULL;
					plist_dict_new_iter(item, &iter2);
					while (iter2)
					{
						plist_t val=NULL;
						char* key = NULL;
						//plist_dict_get_item_key(item, &key);
						plist_dict_next_item(item, iter2, &key, &val);
						if (PLIST_STRING == plist_get_node_type(val))
						{
							char* item_val=NULL;
							plist_get_string_val(val, &item_val);
							if (item_val)
								free(item_val);
						}
						if (key)
							free(key);
						else
							break;
					}
				}
			}

		}break;
		}
		plist_free(address_node);
		address_node = NULL;
		if (node_value) {
			using namespace SOUI;
			outAddress = node_value;
			free(node_value);
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool CiOSDevice::GetDeviceBaseInfo()
{
	if (!IsOpen())
		return false;
	//设备名
	_GetAddress(m_iosInfo.m_strDevName, NODE_DEVICENAME);
	//wifi address
	_GetAddress(m_iosInfo.m_strDevWiFiAddress, NODE_WIFI_ADDRESS);
	//蓝牙地址
	_GetAddress(m_iosInfo.m_strDevBluetoothAddress, NODE_BLUETOOTH_ADDRESS);
	//序列号
	_GetAddress(m_iosInfo.m_strDevSerialNumber, NODE_SERIALNUMBER);
	//型号
	_GetAddress(m_iosInfo.m_strDevModelNumber, NODE_MODELNUMBER);
	//硬件模型
	_GetAddress(m_iosInfo.m_strDevHardwareModel, NODE_HARDWAREMODEL);
	//IMEI
	_GetAddress(m_iosInfo.m_strDevIMEI, NODE_IMEI);
	//CPU类型
	_GetAddress(m_iosInfo.m_strDevCpuarc, NODE_CPUARC);
	//产品
	_GetAddress(m_iosInfo.m_strDevProductType, NODE_PRODUCTTYPE);
	//尝试转换成电话型号名称
	m_iosInfo.m_strDevProductName = m_iosInfo.m_strDevProductType;
	utils::productType_to_phonename(m_iosInfo.m_strDevProductName);
	//diagnostics(CMD_IOREGISTRY);


	plist_t node = NULL; char* key = NULL;
	char* xml_doc = NULL;
	int i = 0;
	FILE* out;
	out = fopen("e:\\abc.txt", "w+");//CarrierBundleInfoArray
	const char* id[] = { "Exclu-siveChipID", "ExcluSiveChipID", "ExclusiveChipID","CFBundleVersion","InternationalMobileSubscriberIdentity","MCC","MNC",NULL
	};
	while (id[i] != NULL)
	{
		SOUI::SStringA strout;
		if (::_GetAddress(m_client, strout, id[i]))
		{
			fprintf(out, "-----------%s-------------:%s\n", id[i], strout);
		}
		else
		{
			fprintf(out, "-----------%s-------------:%s\n", id[i], "no_value");
		}
		++i;
	}/*
	i = 0;
	while (domains[i] != NULL) {
		if (lockdownd_get_value(m_client, domains[i], NULL, &node) == LOCKDOWN_E_SUCCESS) {
			if (node) {
				fprintf(out, "-----------%s-------------\n", domains[i]);
				plist_print_to_stream(node, out);
				plist_free(node);
				node = NULL;
			}
		}
		++i;
	}*/
	fclose(out);
	return true;
}

const iOSDevInfo& CiOSDevice::GetiOSBaseInfo()
{
	return m_iosInfo;
}

void CiOSDevice::idevice_event_cb_t(const idevice_event_t* event, void* user_data)
{
	IDeviceEventCallBack* reCallBack = (IDeviceEventCallBack*)user_data;
	if (reCallBack)
		reCallBack->idevice_event_cb_t(event);
}

idevice_error_t CiOSDevice::SetCallBack(IDeviceEventCallBack* relCallBack)
{
	idevice_event_unsubscribe();
	return idevice_event_subscribe(idevice_event_cb_t, (void*)relCallBack);
}

bool CheckError(lockdownd_error_t err)
{
	bool bRet = true;
	switch (err) {
	case LOCKDOWN_E_SUCCESS:
		break;
	case LOCKDOWN_E_PASSWORD_PROTECTED:
		//("ERROR: Could not validate with device %s because a passcode is set. Please enter the passcode on the device and retry.\n", udid);
		break;
	case LOCKDOWN_E_INVALID_CONF:
	case LOCKDOWN_E_INVALID_HOST_ID:
		//("ERROR: Device %s is not paired with this host\n", udid);
		break;
	case LOCKDOWN_E_PAIRING_DIALOG_RESPONSE_PENDING:
		//("ERROR: Please accept the trust dialog on the screen of device %s, then attempt to pair again.\n", udid);
		break;
	case LOCKDOWN_E_USER_DENIED_PAIRING:
		//("ERROR: Device %s said that the user denied the trust dialog.\n", udid);
		break;
	default:
		//("ERROR: Device %s returned unhandled error code %d\n", udid, err);
		break;
	}
	return bRet;
}

bool CiOSDevice::IsPair(LPCSTR udid)
{
	if (udid)
	{
		lockdownd_client_t client = NULL;
		idevice_t device = NULL;
		idevice_error_t ret = IDEVICE_E_UNKNOWN_ERROR;
		lockdownd_error_t lerr;

		if (udid) {
			ret = idevice_new(&device, udid);
			if (ret != IDEVICE_E_SUCCESS) {
				return false;
			}
		}
		lerr = lockdownd_client_new_with_handshake(device, &client, "idevicepair");
		lockdownd_client_free(client);
		idevice_free(device);
		return (lerr == LOCKDOWN_E_SUCCESS);
	}
	return false;
}

bool CiOSDevice::GetiOSDeviceGUIDList(std::vector<std::string> & iosList)
{
	idevice_t device = NULL;
	char** dev_list = NULL;
	int i;
	const char* udid = NULL;

	if (idevice_get_device_list(&dev_list, &i) < 0) {
		return false;
	}
	for (int m = 0; m < i; i++) {
		iosList.push_back(dev_list[i]);
	}
	idevice_device_list_free(dev_list);
	return true;
}

bool CiOSDevice::diagnostics(diagnostics_cmd_mode cmd)
{
	lockdownd_service_descriptor_t service = NULL;
	diagnostics_relay_client_t diagnostics_client = NULL;

	plist_t node = NULL;

	lockdownd_error_t ret = lockdownd_start_service(m_client, "com.apple.mobile.diagnostics_relay", &service);
	if (ret != LOCKDOWN_E_SUCCESS) {
		/*  attempt to use older diagnostics service */
		ret = lockdownd_start_service(m_client, "com.apple.iosdiagnostics.relay", &service);
	}
	bool bRet = false;
	if ((ret == LOCKDOWN_E_SUCCESS) && service && (service->port > 0)) {
		if (diagnostics_relay_client_new(m_device, service, &diagnostics_client) == DIAGNOSTICS_RELAY_E_SUCCESS)
		{
			switch (cmd) {
			case CMD_SLEEP:
				if (diagnostics_relay_sleep(diagnostics_client) == DIAGNOSTICS_RELAY_E_SUCCESS) {
					bRet = true;
				}
				break;
			case CMD_RESTART:
				if (diagnostics_relay_restart(diagnostics_client, DIAGNOSTICS_RELAY_ACTION_FLAG_WAIT_FOR_DISCONNECT) == DIAGNOSTICS_RELAY_E_SUCCESS) {
					bRet = true;
				}
				break;
			case CMD_SHUTDOWN:
				if (diagnostics_relay_shutdown(diagnostics_client, DIAGNOSTICS_RELAY_ACTION_FLAG_WAIT_FOR_DISCONNECT) == DIAGNOSTICS_RELAY_E_SUCCESS) {
					bRet = true;
				}
				break;
				/*case CMD_MOBILEGESTALT:
					if (diagnostics_relay_query_mobilegestalt(diagnostics_client, keys, &node) == DIAGNOSTICS_RELAY_E_SUCCESS) {
						bRet = true;
						if (node) {
							//print_xml(node);
							//result = EXIT_SUCCESS;
						}
					}
					break;*/
			case CMD_IOREGISTRY_ENTRY:
				if (diagnostics_relay_query_ioregistry_entry(diagnostics_client, "", "", &node) == DIAGNOSTICS_RELAY_E_SUCCESS) {
					if (node) {
						char* xml = NULL;
						uint32_t len = 0;
						plist_to_xml(node, &xml, &len);
						if (xml) {
							puts(xml);
						}
						free(xml);
						plist_free(node);
						//print_xml(node);
						//result = EXIT_SUCCESS;
					}
				}
				break;
			case CMD_IOREGISTRY:
				if (diagnostics_relay_query_ioregistry_plane(diagnostics_client, "IOPower", &node) == DIAGNOSTICS_RELAY_E_SUCCESS) {
					if (node) {
						char* xml = NULL;
						uint32_t len = 0;
						plist_to_xml(node, &xml, &len);
						if (xml) {
							puts(xml);
						}
						free(xml);
						plist_free(node);
					}
				}
				break;
			case CMD_DIAGNOSTICS:
			default:
				if (diagnostics_relay_request_diagnostics(diagnostics_client, "All", &node) == DIAGNOSTICS_RELAY_E_SUCCESS) {
					if (node) {
						char* xml = NULL;
						uint32_t len = 0;
						plist_to_xml(node, &xml, &len);
						if (xml) {
							puts(xml);
						}
						free(xml);
						plist_free(node);
					}
				}/**/
			}
			diagnostics_relay_goodbye(diagnostics_client);
			diagnostics_relay_client_free(diagnostics_client);
		}
	}

	if (service) {
		lockdownd_service_descriptor_free(service);
		service = NULL;
	}
	return true;
}