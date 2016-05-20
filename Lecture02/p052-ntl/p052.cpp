#include <iostream>
#include <NTL/zz.h>

using namespace std;
using namespace NTL;

int main()
{
	long x, a, b, n;

/*	a = 17; b = 27; n = 14;
	x = AddMod(a%n, b%n, n);
	cout << x << endl;

	a = 12; b = 43; n = 13;
	x = SubMod(a%n, b%n, n);
	cout << x << endl;

	a = 123; b = -10; n = 19;
	x = MulMod(a%n, b%n, n);
	cout << x << endl;
*/
	a = 1723345;
	b = 2124945;
	n = 11;

	x = AddMod(a%n, b%n, n);
	cout << x << endl;

	x = SubMod(a%n, b%n, n);
	cout << x << endl;

	x = MulMod(a%n, b%n, n);
	cout << x << endl;



}