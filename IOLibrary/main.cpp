#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main (int argc, char *argv[])
{
	cout << "hi!" << endl; // writes hi and a newline, then flushes the buffer
	cout << "hi!" << flush; // writes hi, then flushes the buffer; adds no data
	cout << "hi!" << ends; // writes hi and a null, then flushes the buffer
	return 0;
}