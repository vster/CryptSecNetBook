#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

const long MAXN = 1000;

long primes[MAXN] = {2,3,5,7,11,13,17,19,23,29,31,37};	
long nprimes = 12;

// Решето Эратосфена
void resheto( long hn )
{
	vector<char> pt;
	pt.resize( hn );

	pt[0] = 0; pt[1] = 0;

	for ( long i = 2; i < hn; i++ )
		pt[i] = 1;

	long high = sqrt( float( hn ));

	for ( long i = 0; primes[i] < high; i++)
	{
		long min = primes[i]+1;
		for ( long j = min; j < hn; j++ )
			if ( (pt[j] > 0) & (j%primes[i] == 0) )
				pt[j] = 0;
	}
	for ( long i = primes[nprimes-1]+1; i < hn; i++ )
	{
		if ( pt[i] > 0 )
			primes[nprimes++] = i;
	}
}

int main()
{
	long n = 500;
	resheto ( n );

	cout << "primes = " << nprimes << endl;
	for ( long j = 0; j < nprimes; j++ )
	{
		cout << primes[j] << " ";
		if ( (primes[j+1]/100) > (primes[j]/100) )
			cout << endl;
	}
}