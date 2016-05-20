#include <iostream>
#include <iomanip>
#include <string>
#include "util.h"

using namespace std;

// const byte PermTab[8] = {1,2,3,4,5,6,7,8};
const byte PermTab[8] = {8,7,6,5,4,3,2,1};

// P-блок перестановок
template<typename T>
T Permute( T x, const byte KeyPermute[] )
{
	T y = 0;
	T temp;

	int n = 8 * sizeof( T );
	for ( int i = 0; i < n; i++ )
	{
		y <<= 1;		
		temp = x;
		temp >>= 8-KeyPermute[i];
		if ( temp&1 )
			y += 1;
	}
	return y;
}

int main()
{
	byte a = 0x12;	
	
	output_bin ( a );
	cout << endl;

	byte b = Permute ( a, PermTab );

	output_bin ( b );
	cout << endl;

	
}