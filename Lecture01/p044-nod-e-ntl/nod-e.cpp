#include <iostream>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

int main()
{
	ZZ a, b;
	ZZ r, s, t;
	char ch;
	// NOD n;

	do {
		cout << "Enter a and b: ";
		cin >> a >> b;
		XGCD(r, s, t, a, b);
		// n = nod_e(a,b);
		cout << "\na = " << a << "\nb = " << b 
			<< "\nr = " << r << "\ns = " << s << "\nt = " << t << endl;;
		cout << "Continue (y/n)? ";
		cin >> ch;
	} while (ch != 'n');

	return 0;
}
