#include <iostream>
#include <string>
#include "util.h"

using namespace std;
const int MAXW = 64;

byte code3to8 ( byte x )
{
	byte b = 1;
	b <<= x;
	return b;
}

byte code8to3 ( byte x )
{
	for ( byte i = 0; i < 8; i++)
	{
		if ( x&1 )
			return i;
		x >>= 1;
	}	
}

int main()
{
	for ( byte i = 0; i < 8; i++)
	{
		output_bin( i );
		cout << "  ";
		byte b = code3to8 ( i );
		output_bin( b );
		cout << "  ";
		byte c = code8to3 ( b );
		output_bin( c );
		cout << endl;
	}
}
