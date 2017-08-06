#ifndef __IP_H__
#define __IP_H__

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "str2hex.h"

using namespace std;

const char * const LOCAL_IP_PARSE_CMD = "ifconfig eth0 | grep 'inet addr:' | cut -d: -f2 | awk '{print $1}'";

class Ip{
public:
	Ip();
	Ip(const char *ip_str);
	~Ip(){ };
	void setIp(const char *ip_str);
	void getIp(uint8_t *ip_buf);
	Ip operator=(const char *ip_str);
	void operator<<(ostream &os);
	Ip & parse_local_ip();

private:
	uint8_t hex_ip[HEX_IP_LEN];
	uint8_t hex_mac[HEX_MAC_LEN];	

};

ostream &operator<<(ostream &os, Ip &br);

#endif