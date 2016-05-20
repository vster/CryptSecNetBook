#include <iostream>
using namespace std;

int nod( int a, int b)
{
	int r1 = a;
	int r2 = b;
	int r, q;

	while ( r2 > 0)
	{
		q = r1/r2;

		r = r1 - q*r2;
		r1 = r2;
		r2 = r;
	}
	return r1;
}

int main()
{
	int a, b, n;
	char ch;

	do {
		cout << "Enter a and b: ";
		cin >> a >> b;
		n = nod(a,b);
		cout << "a = " << a << " b = " << b << " nod = " << n << endl;;
		cout << "Continue (y/n)? ";
		cin >> ch;
	} while (ch != 'n');

	return 0;
}
