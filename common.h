#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <cstdio>
#include <pthread.h>
#include <stdio.h>


#define BUF_SIZE 1024		// default buffer size
#define ARP_PACKET_SIZE 60	// ARP packet format size : ether_header + ether_arp

const int PCAP_ERROR_READ_PACKET = -1;
const int PCAP_ERROR_NO_MORE_PACKET = -2;

void error_handling(const char * message, const char * file_name, const char * func_name, int line_number);

#endif