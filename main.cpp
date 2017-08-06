#include <iostream>
#include "str2hex.h"
#include "common.h"

using namespace std;



int main(int argc, char * argv[])
{
	if(argc < 4  || argc % 2 == 1){
		cerr << "Usage : " << argv[0] << "[interface] [sender IP] [target IP] [[sender2 IP] [target2 IP]....]" << endl;
		exit(1);
	}
	
	error_handling("mess", __FILE__, __FUNCTION__, __LINE__);

	return 0;
}