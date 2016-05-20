#include <iostream>
#include <math.h>

using namespace std;

int euler(int n)
{
	int t = sqrt(float(n))+1;
	int answ = 1, ta, i;
  
	for ( i = 2; i < t; i++ )
	{   
		ta = 0;
    
		while ( n%i == 0 )
		{
			ta++;
			n /= i;
		}   
		if ( ta )
			answ *= (int)pow(float(i),ta-1) * (i-1);    
	}
  
	if (n-1)   
		answ *= (n-1);
	return answ;
}

long InvMod( long x, long p )
{
	long power = 1L;
	long phi;
	
	phi = euler( p );

	for (int i = 0; i < phi-1; i++)
	{
		power *= x;
		power %= p;
	}
	return power;
}

int main()
{
	long p = 100;
	long a, b;

	for ( a = 2; a < p; a++ )
	{
		b = InvMod ( a, p );
		// long c = ( a * b ) % p;
		cout << a << " " << b << endl;
	}
	
}