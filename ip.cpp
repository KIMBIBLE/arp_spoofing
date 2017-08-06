#include <iostream>
#include "ip.h"
#include "str2hex.h"

using namespace std;

Ip::Ip(){
	if(str2hexIp("0.0.0.0", hex_ip))
		error_handling("IP convert error", ERR_INFO);
}

Ip::Ip(const char *ip_str){
	if(str2hexIp(ip_str, hex_ip))
		error_handling("IP convert error", ERR_INFO);
}

void Ip::setIp(const char *ip_str){
	if(str2hexIp(ip_str, hex_ip))
		error_handling("IP convert error", ERR_INFO);
}

void Ip::getIp(uint8_t *ip_buf){
	memcpy(ip_buf, hex_ip, HEX_IP_LEN);
}

Ip Ip::operator=(const char *ip_str){
	if(str2hexIp(ip_str, hex_ip))
		error_handling("IP convert error", ERR_INFO);
}

void Ip::operator<<(ostream &os){
	fprintf(stdout, "%d.%d.%d.%d", hex_ip[0], hex_ip[1], hex_ip[2], hex_ip[3]);
}

Ip &Ip::parse_local_ip()
{
	FILE *fp;
	char ip_buf[RAW_IP_FORMAT_LEN] = {0, };

	fp = popen(LOCAL_IP_PARSE_CMD, "r");
	if(fp == NULL)
		error_handling("FILE OPEN ERROR", ERR_INFO);

	if(fgets(ip_buf, RAW_IP_FORMAT_LEN, fp) == NULL){
		pclose(fp);
		error_handling("FILE READ ERROR", ERR_INFO);
	}

	pclose(fp);
	(*this) = ip_buf;

	return *this;
}

ostream &operator<<(ostream &os, Ip &br)
{
	br << os;
	return os;
}

