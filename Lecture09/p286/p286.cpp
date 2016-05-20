#include <iostream>
#include <math.h>

using namespace std;

void pi_lim (  double &low, double &high,  double n )
{
	low = n / log ( n );
	high = n / ( log ( n ) - 1.08366 );
}

bool fermatest( long x, long n )
{
	long power = 1L;
	for (long i = 0; i < n-1; i++)
	{
		power *= x;
		power %= n;
	}
	return (power == 1)?true:false;
}

int main()
{
	long max = 20000;
	// long n;
	long prime_num = 0;
	double low, high;
	long a = 5;
	
	pi_lim( low, high, max );

	for ( long n = 2; n < max; ++n )
		if ( (fermatest(2,n))&&(fermatest(5,n)) )
		{
			// cout << n << " ";
			++prime_num;
		}

	cout << "\nMax num = " << max << endl;
	cout << "Limits are from " << low << " to " << high << endl;
	cout << "Number of tested primes is " << prime_num << endl;
	
}