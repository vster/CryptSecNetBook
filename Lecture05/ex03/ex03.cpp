#include <iostream>
#include <string>
#include "util.h"

using namespace std;

/*
void byte_output_bin( byte x )
{
	for ( int j = 7; j >= 0; j-- ) 
			cout << ((x >> j) & 1 );
}

void u16bit_output_bin( u16bit x )
{
	for ( int j = 15; j >= 0; j-- ) 
			cout << ((x >> j) & 1 );
}
*/

int main()
{
	byte a = 0x9b;

	cout << hex << int(a) << endl;
	output_bin ( a );
	cout << endl;	
	
	byte b, c;
	
	b = rotate_left ( a, 3 );
	
	cout << hex << int(b) << endl;
	output_bin ( b );
	cout << endl;

	c = rotate_right ( a, 3 );

	cout << hex << int(c) << endl;
	output_bin ( c );
	cout << endl;

	u16bit a2 = 0x1234;	
	u16bit b2, c2;

	b2 = rotate_left ( a2, 3 );
	c2 = rotate_right ( a2, 3 );

	output_bin ( a2 );
	cout << endl;
	output_bin ( b2 );
	cout << endl;
	output_bin ( c2 );
	cout << endl;

}