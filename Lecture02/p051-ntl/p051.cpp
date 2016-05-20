#include <iostream>
#include <NTL/zz.h>

using namespace std;
using namespace NTL;

int main()
{
	long x, a, b, n;
	
	a = 7; b = 14; n = 15;
	x = AddMod(a, b, n);
	cout << "x = " << x << endl;

	a = 7; b = 11; n = 13;
	x = SubMod(a, b, n);
	cout << "x = " << x << endl;

	a = 7; b = 11; n = 20;
	x = MulMod(a, b, n);
	cout << "x = " << x << endl;

	a = 17; b = 27; n = 14;
	x = AddMod(a%n, b%n, n);
	cout << x << endl;

	a = 12; b = 43; n = 13;
	x = SubMod(a%n, b%n, n);
	cout << x << endl;

	a = 123; b = -10; n = 19;
	x = MulMod(a%n, b%n, n);
	cout << x << endl;

}