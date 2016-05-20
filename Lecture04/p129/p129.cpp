#include <NTL/ZZ.h>
#include <NTL/ZZ_p.h>

using namespace std;
using namespace NTL;

int main()
{
	ZZ p;
	p = 5;

	ZZ_p::init(p);

	ZZ i, j;
	ZZ_p sum, mul;

	for ( i = 0; i < p; i++)
	{
		for ( j = 0; j < p; j++)
		{
			sum = conv<ZZ_p>(i) + conv<ZZ_p>(j);
			cout << sum << " ";
		}
	cout << endl;
	}

	cout << endl;

	for ( i = 0; i < p; i++)
	{
		for ( j = 0; j < p; j++)
		{
			mul = conv<ZZ_p>(i) * conv<ZZ_p>(j);
			cout << mul << " ";
		}
	cout << endl;
	}

	cout << endl;

	ZZ_p add_inv, mul_inv;

	for ( i = 0; i < p; i++)
	{
		add_inv = - conv<ZZ_p>(i);
		cout << i << " " << add_inv << endl;
	}
	
	cout << endl;
	
	for ( i = 1; i < p; i++)
	{
		mul_inv = inv ( conv<ZZ_p>(i) );
		cout << i << " " << mul_inv << endl;
	}

	return 0;
}