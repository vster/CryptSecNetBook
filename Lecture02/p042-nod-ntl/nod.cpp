#include <iostream>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

int main()
{
	ZZ a, b, n;
	char ch;

	do {
		cout << "Enter a and b: ";
		cin >> a >> b;
		n = GCD(a,b);
		cout << "a = " << a << " b = " << b << " nod = " << n << endl;;
		cout << "Continue (y/n)? ";
		cin >> ch;
	} while (ch != 'n');

	return 0;
}