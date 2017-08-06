#include "common.h"
#include <iostream>
#include <string>
using namespace std;

void error_handling(const char * message, const char * file_name, const char * func_name, int line_number)
{
	cerr << "[!] " << file_name << " (" << func_name << ")" << " : " << line_number << "lines"<< endl;
	//fprintf(stderr, "[%s %s:%03d] : %s\n", __FILE__, __FUNCTION__, __LINE__, message);
	exit(1);
}
