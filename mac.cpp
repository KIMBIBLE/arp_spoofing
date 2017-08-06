#include <iostream>
#include "mac.h"
#include "str2hex.h"

using namespace std;

Mac::Mac(){
	if(str2hexMac("0:0:0:0:0:0", hex_mac) == false)
		error_handling("MAC convert error", ERR_INFO);
}

Mac::Mac(const char *mac_str){
	if(str2hexMac(mac_str, hex_mac) == false)
		error_handling("MAC convert error", ERR_INFO);
}

void Mac::setMac(const char *mac_str){
	if(str2hexMac(mac_str, hex_mac) == false)
		error_handling("MAC convert error", ERR_INFO);
}

void Mac::getMac(uint8_t *mac_buf){
	memcpy(mac_buf, hex_mac, HEX_MAC_LEN);
}

Mac Mac::operator=(const char *mac_str){
	if(str2hexMac(mac_str, hex_mac) == false)
		error_handling("MAC convert error", ERR_INFO);
}

void Mac::operator<<(ostream &os){
	fprintf(stdout, "%02hhx:%02hhx:%02hhx:%02hhx:%02hhx:%02hhx", hex_mac[0], hex_mac[1], hex_mac[2], hex_mac[3], hex_mac[4], hex_mac[5]);
}

Mac &Mac::parse_local_mac()
{
	FILE *fp;
	char mac_buf[RAW_MAC_FORMAT_LEN] = {0, };

	fp = popen(LOCAL_MAC_PARSE_CMD, "r");
	if(fp == NULL)
		error_handling("FILE OPEN ERROR", ERR_INFO);

	if(fgets(mac_buf, RAW_MAC_FORMAT_LEN, fp) == NULL){
		pclose(fp);
		error_handling("FILE READ ERROR", ERR_INFO);
	}

	pclose(fp);
	(*this) = mac_buf;

	return *this;
}

ostream &operator<<(ostream &os, Mac &br)
{
	br << os;
	return os;
}

