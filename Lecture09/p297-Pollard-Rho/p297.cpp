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

int F( int x )
{
	int f;
	int a = 1;

	f = x*x + a;

	return f;
}


int Pollard_Rho_Factor( int n )
{
	int x = 2;
	int y = 2;
	int p = 1;

	while ( p == 1 )
	{
		x = F(x)%n;
		y = F(F(y)%n)%n;
		if (y < 0 )
			y += n;
		p = nod ( abs(x-y), n );
	}
	return p;
}

int main()
{
	int n = 434617;
	// int B = 10;
	int p;

	for ( int i = n; i < n+100; i++ )
	{
		p = Pollard_Rho_Factor( i );
		
		if ( p > 0 )
			cout << i << '\t' << p << '\t' << i/p << '\t' << i%p << endl;
	}

	return 0;
}