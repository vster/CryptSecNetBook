#include <iostream>
#include <math.h>

using namespace std;

long InvMod( long x, long p )
{
	long power = 1L;
	for (int i = 0; i < p-2; i++)
	{
		power *= x;
		power %= p;
	}
	return power;
}

int main()
{
	long p = 41;
	long a, b;

	for ( a = 2; a < p; a++ )
	{
		b = InvMod ( a, p );
		// long c = ( a * b ) % p;
		cout << a << " " << b << endl;
	}
	
}