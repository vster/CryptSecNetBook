#include <iostream>
#include <math.h>

using namespace std;


void pi_lim (  double &low, double &high,  double n )
{
	low = n / log ( n );
	high = n / ( log ( n ) - 1.08366 );
}


long Power(long x, long n)
{
	long power = 1L;

	for ( long i = 0; i < n; i++ )
		power *=x;

	return power;
}

long PowerMod(long x, long p, long n)
{
	long power = 1L;

	for ( long i = 0; i < p; i++)
	{
		power *= x;	
		power %= n;
	}
	return power;
}
long Factor2( long x )
{
	long k = 0L;
	
	while ( x%2 == 0 )
	{
		k++;
		x /= 2;
	}
	return k;
}

bool MillerRabinTest( long n, long a)
{
	long k = Factor2(n-1);
	long m = (n-1)/Power(2, k);

	long T = PowerMod( a, m, n );

	if ( (T == 1) || (T-n == -1))
		return true;

	for ( long i = 0; i < k-1; i++ )
	{
		T = PowerMod( T, 2, n );
		if ( T == 1 )
			return false;
		if ( T-n == -1 )
			return true;
	}
	return false;
}

int main()
{
	long max = 50000;
	double low, high;
	long prime_num = 0;
	//long n = 37;
	long a = 3;

	pi_lim( low, high, max );

	for ( long n = 2; n < max; n++ )
	{
		if ( MillerRabinTest( n, 2 ) && MillerRabinTest( n, 3 ) )
			++prime_num;
			// cout << n << " ";
	}
	cout << "\nMax num = " << max << endl;
	cout << "Limits are from " << low << " to " << high << endl;
	cout << "Number of tested primes is " << prime_num << endl;
	
	return 0;
}