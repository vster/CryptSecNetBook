#include <iostream>
#include <stdint.h>
using namespace std;

typedef unsigned char byte;
typedef unsigned short u16bit;
typedef unsigned int u32bit;
typedef uint64_t u64bit;

typedef signed int s32bit;

byte f( byte k )
{
	return ( k * k );
}

void bin_output ( byte x )
{
	int arr[8];
	int bitlen = 8 * sizeof ( byte );

	for ( int i = 0; i < bitlen; i++ )
	{
		arr[i] = x&0x1;
		x >>= 1;
	}
	for ( int i = bitlen-1; i >= 0; i-- )
		cout << arr[i];
	
}

int main()
{
	byte P = 0x7;
	byte K = 0x3;

	// cout << hex << P << endl;
	bin_output ( P );
	cout << endl;

	byte C = P ^ f ( K );
	bin_output ( C );
	cout << endl;

	// cout << hex << C << endl;
	byte D = C ^ f ( K );
	bin_output ( D );
	cout << endl;
}
