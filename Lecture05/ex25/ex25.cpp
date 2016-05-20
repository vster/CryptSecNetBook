#include <iostream>
#include "util.h"

using namespace std;

template<typename T>
T power ( T x, int n )
{
	T p = 1;
	for ( T i = 0; i < n; i++ )
		p *= x;
	return p;
}

template<typename T>
void rotate ( T &x, int k )
{
	int n = 8 * sizeof( x );
	
	k %= n;
	if ( k < 0 ) 
		k += n;

	T mask = power (2, k) - 1;
	T temp = x & mask;
	
	x >>= k;
	temp <<= n-k;
	x += temp;
}

int main()
{
	u16bit a;

	a = 0xe915;
	
	int k;
	k = -8;

	output_bin ( a );
	cout << endl;

	rotate ( a, k );

	output_bin ( a );
	cout << endl;

}