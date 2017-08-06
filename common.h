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

#define print_msg(io, msgtype, arg...) \
    flockfile(io); \
    fprintf(io, "["#msgtype"] [%s/%s:%03d] ", __FILE__, __FUNCTION__, __LINE__); \
    fprintf(io, arg); \
    fputc('\n', io); \
    funlockfile(io)

#define print_msg_no_enter(io, msgtype, arg...) \
    flockfile(io); \
    fprintf(io, "["#msgtype"] [%s/%s:%03d] ", __FILE__, __FUNCTION__, __LINE__); \
    fprintf(io, arg); \
    funlockfile(io)

#define pr_err(arg...) print_msg(stderr, ERR, arg)
#define pr_out(arg...) print_msg(stdout, REP, arg)
#define pr_out_n(arg...) print_msg_no_enter(stdout, REP, arg)

#endif