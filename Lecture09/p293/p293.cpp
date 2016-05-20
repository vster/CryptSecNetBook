#include <iostream>
#include <math.h>

using namespace std;

void factor( int n )
{
	int a = 2;
	double n2 = sqrt ( (double) n );

	while ( a <= n2 )
	{
		while ( n%a == 0 )
		{
			cout << a << " ";
			n /= a;
		}
		a++;
	}
	if ( n>1 ) 
		cout  << n;
}

int main()
{
	// int n = 1523357784;
	for ( int i = 1000; i < 1100; i++ )
	{
		cout << i << " : ";	
		factor ( i );
		cout << endl;
	}
}