#include <iostream>
#include <string.h>
#include "str2hex.h"
#include "common.h"
#include "ip.h"

using namespace std;

int main(int argc, char * argv[])
{
	if(argc < 4  || argc % 2 == 1){
		cerr << "Usage : " << argv[0] << "[interface] [sender IP] [target IP] [[sender2 IP] [target2 IP]....]" << endl;
		exit(1);
	}
	
	string dev = argv[1];
	Ip sender1_ip = argv[2];
	Ip target1_ip = argv[3];

	cout << "[*] interface type\t: " << dev << endl;
	cout << "[*] sender1 IP addr\t: " << sender1_ip << endl;
	cout << "[*] target1 IP addr\t: " << target1_ip << endl;

	Ip local_ip;
	local_ip.parse_local_ip();
	cout << "[*] local IP addr\t: " << local_ip << endl;

	return 0;
}