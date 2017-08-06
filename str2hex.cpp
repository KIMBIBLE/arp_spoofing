#include "str2hex.h"


bool str2hexMac(const char *string_mac, uint8_t *hex_mac)
{
	if(6 != sscanf(string_mac, "%hhx:%hhx:%hhx:%hhx:%hhx:%hhx", hex_mac, hex_mac + 1 , hex_mac + 2, 
		hex_mac + 3, hex_mac + 4, hex_mac + 5))
		return false;

	return true;
}

bool str2hexIp(const char *string_ip, uint8_t *hex_ip)
{
	if(4 != sscanf(string_ip, "%hhd.%hhd.%hhd.%hhd", hex_ip, hex_ip + 1 , hex_ip + 2, hex_ip + 3))
		return false;

	return true;
}