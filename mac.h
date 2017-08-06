#ifndef __MAC_H__
#define __MAC_H__

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "str2hex.h"

using namespace std;

const char * const LOCAL_MAC_PARSE_CMD = "ifconfig eth0 | grep HWaddr | awk '{print $5}'";

class Mac{
public:
	Mac();
	Mac(const char *mac_str);
	~Mac(){ };
	void setMac(const char *mac_str);
	void getMac(uint8_t *mac_buf);
	Mac operator=(const char *mac_str);
	void operator<<(ostream &os);
	Mac & parse_local_mac();

private:
	uint8_t hex_mac[HEX_MAC_LEN];	

};

ostream &operator<<(ostream &os, Mac &br);

#endif