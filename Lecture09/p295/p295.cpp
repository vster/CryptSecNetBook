#include <iostream>
#include <math.h>

using namespace std;

int nod( int a, int b)
{
	int r1 = a;
	int r2 = b;
	int r;

	while ( r2 > 0)
	{
		int q = r1/r2;

		r = r1 - q*r2;
		r1 = r2;
		r2 = r;
	}
	return r1;
}


int PowerMod ( int x, int p, int n )
{
	long long power = 1;
	for ( int i = 0; i < p; i++)
	{
		power *= x;
		power = (long long) power%n;
	}
	return (int) power;
}

int Pollard_p1_Factor ( int n, int B )
{
	int a = 2;
	int e = 2;
	while ( e <= B )
	{
		a = PowerMod( a, e, n );
		e++;
	}
	int p = nod( a-1, n);
	if ( (p>1) && (p<n) )
		return p;
	else
		return 0;
}

int main()
{
	int n = 57247159;
	int B = 20;
	int p;

	for ( int i = n; i < n+100; i++ )
	{
		p = Pollard_p1_Factor ( i, B );
	
		if ( p > 0 )
			cout << i << '\t' << p << '\t' << i/p << '\t' << i%p << endl;
	}
	return 0;
}