#include <iostream>
#include <string>
#include "util.h"

using namespace std;
const int MAXW = 64;

int main()
{
	byte a = 0x4d;
	byte b = 0xff;
	
	byte c;
	c = a^b;
	output_bin ( a );
	cout << endl;
	output_bin ( b );
	cout << endl;
	output_bin ( c );
	cout << endl;
}
