#include <iostream>
#include <math.h>

using namespace std;

void pi_lim (  double &low, double &high,  double n )
{
	low = n / log ( n );
	high = n / ( log ( n ) - 1.08366 );

}

bool primetest( long n )
{
	// long r = 2;
	double n2 = sqrt ( (double) n );

	for ( long r = 2; r <= n2; r++ )
		if ( n%r == 0 )
			return false;
		
	return true;
}

int main()
{
	long max = 3000000;
	// long n;
	long prime_num = 0;
	double low, high;
	
	pi_lim( low, high, max );

	for ( long n = 2; n < max; ++n )
		if ( primetest( n ) )
			++prime_num;

	cout << "Max num = " << max << endl;
	cout << "Limits are from " << low << " to " << high << endl;
	cout << "Real number of primes is " << prime_num << endl;
	
}