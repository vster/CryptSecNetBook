
#include <iostream>
#include <string>
#include "util.h"

using namespace std;
const int MAXW = 64;

template<typename T>
T WordPermute ( T x, int KeyPermute[] )
{
	int arr1[MAXW], arr2[MAXW];
	T y;
	
	int len = 8*sizeof( T );

	for ( int i = 0; i < len; i++ )
	{
		arr1[i] = x&1;
		x >>= 1;
	}
	
	for ( int i = 0; i < len; i++ )
		arr2[i] = arr1[ KeyPermute[i]-1 ];

	y = 0;
	for ( int i = 0, b = 1; i < len; i++ )
	{
		if ( arr2[i] == 1 )
			y += b;
		b <<= 1;
	}
	return y;
}

int main()
{
	byte a = 0xa3;
	u16bit a2 = 0xa3b9;
	u32bit a3 = 0x12345678;

	// int KeyPermute[8] = {1,2,3,4,5,6,7,8};
	// int KeyPermute[16] = {16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	int KeyPermute[32];

	for ( int i = 0; i < 32; i++ )
		KeyPermute[i] = 32 - i;
	
	cout << hex << int(a3) << endl;
	output_bin ( a3 );
	cout << endl;

	u32bit b3;
	b3 = WordPermute ( a3, KeyPermute );
	
	cout << hex << int(b3) << endl;
	output_bin ( b3 );
	cout << endl;

}
