#include <iostream>
// #include <math.h>

using namespace std;

long sqr( long x, long n )
{
	return ( (x*x)%n );
};

int main()
{
	long n = 20;
	for ( long i = 1; i < n; i++ )
	{
		cout << i << " " << sqr(i, n) << endl;
	}
}