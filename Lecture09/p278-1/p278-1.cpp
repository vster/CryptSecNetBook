#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	const long MAXN = 1000;
	
	long prime[12] = {2,3,5,7,11,13,17,19,23,29,31,37};	
	
	long pt[MAXN];
	pt[0] = pt[1] = 0;
	for ( long i = 2; i < MAXN; i++ )
		pt[i] = 1;

	long high = sqrt ( float(MAXN) );

	// Решето Эратосфена
	for ( long i = 0; prime[i] < high; i++)
	{
		long min = prime[i]+1;
		for ( long j = min; j < MAXN; j++ )
			if ( (pt[j] > 0) & (j%prime[i] == 0) )
				pt[j] = 0;
	}

	for ( long j = 0; j < MAXN; j++ )
	{
		if ( pt[j] > 0 )
			cout << j << " ";
		if ( j%100 == 0 )
			cout << endl;
	}
}