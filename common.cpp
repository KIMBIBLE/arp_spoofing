#include "common.h"
#include <iostream>
#include <string>
using namespace std;

void error_handling(const char * message, const char * file_name, const char * func_name, int line_number)
{
	cerr << "[!] " << file_name << " (" << func_name << ")" << " : " << line_number << " line"<< endl;
	exit(1);
}
