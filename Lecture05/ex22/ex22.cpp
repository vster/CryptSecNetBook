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
void split ( T &x, T &s1, T &s2 )
{
	T mask;
	int n = 8 * sizeof( T );
	mask = power(2, n/2) - 1;

	// output_bin ( mask );
	// cout << endl;

	s1 = x & mask;

	mask <<= n/2;

	s2 = (x & mask);
	s2 >>= n/2;
}

int main()
{
	u32bit a, a1, a2;

	a = 0xe653fe03;
	// a1 = 0;
	// a2 = 0;

	output_bin ( a );
	cout << endl;

	split ( a, a1, a2 );

	output_bin ( a1 );
	cout << endl;

	output_bin ( a2 );
	cout << endl;

	// n = 6;
}