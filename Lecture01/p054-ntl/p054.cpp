#include <iostream>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

int main()
{
	long x, a, b, n;

	a = 0;
	// b = 1;
	n = 10;
	
	for (b = 0; b < 10; b++)
	{
		x = SubMod(a, b, n);
		cout << b << " " << x << endl;
	}
}
