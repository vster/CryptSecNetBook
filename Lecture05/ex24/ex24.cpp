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
void swap ( T &x )
{
	int n = 8 * sizeof ( x );
	
	T mask = power(2,n/2)-1;
	T temp = x & mask;
	
	x >>= n/2;
	temp <<= n/2;
	x += temp;
}

int main()
{
    u32bit a;

	a = 0x59841f93;

	output_bin ( a );
	cout << endl;

	swap ( a );
	
	output_bin ( a );
	cout << endl;
}
