#include <iostream>
#include <math.h>
// #include <NTL/ZZ.h>

using namespace std;
// using namespace NTL;

void pi_lim (  double &low, double &high,  double n )
{
	low = n / log ( n );
	high = n / ( log ( n ) - 1.08366 );

}

int main()
{
	double n = 10;
	double low, high;
	for ( long i = 0; i < 12; i++ )
	{
		pi_lim ( low, high, n );
		cout << n << '\t' << low << '\t' << high << endl;
		n *= 10;
	}

}