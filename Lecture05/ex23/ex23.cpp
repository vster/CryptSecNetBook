#include <iostream>
#include "util.h"

using namespace std;

template<typename T>
void merge ( T &x, T &s1, T &s2 )
{
	int n = 8 * sizeof( T );

	x = s2;
	x <<= n/2;
	x += s1;	
}

int main()
{
	u16bit a, a1, a2;

	a1 = 0x2f;
	a2 = 0xe3;

	output_bin ( a1 );
	cout << endl;

	output_bin ( a2 );
	cout << endl;
	
	merge ( a, a1, a2 );

	output_bin ( a );
	cout << endl;

}