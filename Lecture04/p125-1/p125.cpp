#include <iostream>
using namespace std;

typedef unsigned long ulong;

const ulong P = 15;

bool find ( ulong a, ulong arr[], ulong n )
{
	for (ulong i = 0; i < n; i++)
		if ( a == arr[i] )
			return true;

	return false;
}

ulong npower( ulong g, ulong k, ulong n)
{
	ulong i;
	ulong power = 1;
	for ( i = 0; i < k; i++)
	{
		power *= g;
		power %= n;
	}
	return power;
}

ulong ninv ( ulong x, ulong n)
{ 
	ulong tm, i;
	for ( i = 1; i < n; i++)
	{
		tm = (x * i) % n;
//		cout << i << " " << x << " " << tm << " " << n << endl;
		if ( tm == 1 ) 
			return i;
	}
	return 0;
}
void gen_G_mult ( ulong Gmult[], ulong &ord, ulong &n ) 
{
	
	ulong i, j;
	for ( i = 1, j = 0; i < n; i++)
	{
		ulong i1 = ninv ( i, n );
		if ( i1 > 0 )
			Gmult[j++] = i;		
	}
	ord = j;
}


int main()
{
	ulong Gmult[P];
	ulong i, j, n;
	ulong ord = 0;
	 
	n = P;
	gen_G_mult ( Gmult, ord, n );

	cout << "Order = " << ord << endl;

	for ( ulong i = 0; i < ord; i++)
		cout << Gmult[i] << " ";
	cout << endl;

	return 0;
}
