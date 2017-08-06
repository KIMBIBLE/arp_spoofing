#ifndef __STR2HEX_H__
#define __STR2HEX_H__

#include "common.h"

#define RAW_IP_FORMAT_LEN 15	// IP addr format : xxx.xxx.xxx.xxx
#define RAW_MAC_FORMAT_LEN 18	// MAC addr format : XX:XX:XX:XX:XX:XX
#define HEX_IP_LEN 4
#define HEX_MAC_LEN 6

bool str2hexMac(const char *string_mac, uint8_t *hex_mac);
bool str2hexIp(const char *string_ip, uint8_t *hex_ip);

#endif