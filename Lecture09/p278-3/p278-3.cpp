#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

// const long MAXN = 1000;

long parr[] = {2,3,5,7,11,13,17,19,23,29,31,37};

vector<long> primes(parr, parr+12);

// vector<long> primes = {2,3,5,7,11,13,17,19,23,29,31,37};	
// long nprimes = 12;

// Решето Эратосфена
void resheto( long hn )
{
	vector<char> pt;
	pt.resize( hn );

	long nprimes = primes.size();

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
			primes.push_back(i);
	}
}

int main()
{
	long n = 900;

	resheto ( n );

	long nprimes = primes.size();

	cout << "primes = " << nprimes << endl;
	for ( long j = 0, c = 0; j < nprimes; j++ )
	{
		if ( primes[j]/100 > c )
		{
			cout << endl;
			c++;
		}
		cout << primes[j] << " ";
	}

	n = 2000;
	resheto ( n );
	
	nprimes = primes.size();

	cout << "\nprimes = " << nprimes << endl;
	for ( long j = 0, c = 0; j < nprimes; j++ )
	{
		if ( primes[j]/100 > c )
		{
			cout << endl;
			c++;
		}
		cout << primes[j] << " ";
	}
}