#include <iostream>
#include <math.h>

using namespace std;

void FactorFerma( long &a, long &b, long n )
{
	long x =  (long) sqrt ( (double) n )+1;
	while ( x <= n )
	{
		long w = x*x - n;
		double y = sqrt ( (double) w );
		if ( (y - int( y )) == 0 )
		{
			a = x + y;
			b = x - y;
			return;
		}
		x++;
	}
}

int main()
{
	// long n = 1233;
	long a, b;

	for ( long i = 10000; i < 10100; i++ )
	{
		FactorFerma (a, b, i);
		if ( a > 0 )
			cout << i << " : " << a << " " << b << " : " << a*b << endl;
		a = b = 0;
	}
}