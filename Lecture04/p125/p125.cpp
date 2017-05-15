#include <iostream>
using namespace std;

typedef unsigned long ulong;

const ulong P = 10;

bool find ( ulong a, ulong arr[], ulong n )
{
	for (ulong i = 0; i < n; i++)
		if ( a == arr[i] )
			return true;

	return false;
}

ulong power( ulong x, ulong n )
{
	ulong p = 1;
	for ( ulong i = 0; i < n; i++ )
		p *= x;
	return p;
}

int main()
{
	ulong resarr[P][P];
	ulong i;

	for ( ulong b = 1; b < P; b++ )
	{
		for ( ulong n = 0, i = 0; n < P; n++)
		{
			ulong result = ( power( b, n) )%P;
			if ( !find ( result, resarr[b], i ) )
			{
				resarr[b][i] = result;
				cout << b << '\t' << n << '\t' <<  resarr[b][i++] << endl;
			}
		}
	cout << endl;
	}
}
