#include <iostream>
using namespace std;

struct NOD
{
	int r;
	int s;
	int t;
};

NOD nod_e(int a, int b)
{
	NOD nt;
	int r1 = a, r2 = b;
	int s1 = 1, s2 = 0;
	int t1 = 0, t2 = 1;
	int q;
	
	while ( r2 > 0)
	{
		q = r1 / r2;
		
		nt.r = r1 - q * r2;
		r1 = r2;
		r2 = nt.r;

		nt.s = s1 - q * s2;
		s1 = s2;
		s2 = nt.s;

		nt.t = t1 - q * t2;
		t1 = t2;
		t2 = nt.t;
	}
	nt.r = r1;
	nt.s = s1;
	nt.t = t1;
	
	return nt;
}

int main()
{
	int a, b;
	char ch;
	NOD n;

	do {
		cout << "Enter a and b: ";
		cin >> a >> b;
		n = nod_e(a,b);
		cout << "a = " << a << " b = " << b 
			<< " nod = " << n.r << " " << n.s << " " << n.t << endl;;
		cout << "Continue (y/n)? ";
		cin >> ch;
	} while (ch != 'n');

	return 0;
}
