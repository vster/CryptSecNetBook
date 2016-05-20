#include <iostream>
using namespace std;

int minv ( int n, int b )
{
	int r1 = n; 
	int r2 = b;
	int t1 = 0;
	int t2 = 1;
	int q;
	int b1;
	int r, t;

	while (r2 > 0)
	{
		q = r1 / r2;
		
		r = r1 - q * r2;
		r1 = r2;
		r2 = r;

		t = t1 - q * t2;
		t1 = t2;
		t2 = t;
	}
	if ( r1 == 1)
		b1 = t1;
	else
		b1 = 1;

//	if ( b1 < 0 )
//		b1 += n;

	if (b1 < 0)
		b1 += n;

	return b1;
}


int main()
{
	int b, n, b1;
	char ch;

	do {
		cout << "Enter n and b: ";
		cin >> n >> b;
		b1 = minv(n,b);
		cout << "n = " << n << " b = " << b << " b-1 = " << b1 << endl;;
		cout << "Continue (y/n)? ";
		cin >> ch;
	} while (ch != 'n');

	return 0;
}

/*
int main()
{
	int n=20, b1;
	for (int i = 1; i < 20-1; i++)
	{
		b1 = minv(n,i);
		if (b1 > 1)
			cout << "n = " << n << " b = " 
				<< i << " b-1 = " << b1 << endl;
	}
	return 0;
}
*/
