#include <iostream>
#include <NTL/zz.h>

using namespace std;
using namespace NTL;

int main()
{
	long x, a, b, n;

	a = 1;
	n = 29;
	for (b = 1; b < n; b++)
	{
		x = InvMod(b, n);
		cout << b << '\t' << x << endl;
	}

}
