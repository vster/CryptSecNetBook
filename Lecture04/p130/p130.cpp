// #include <NTL/vector.h>
#include <NTL/GF2.h>
#include <NTL/vec_GF2.h>

using namespace std;
using namespace NTL;

void gf2_mult ( vec_GF2 x, vec_GF2 a, vec_GF2 b, long n) 
{
	long i;
	// x.SetLength(n);
	for (i = 0; i < n; i++)
		x[i] = a[i] * b[i];
	cout << a << " " << b << " " << x << endl;

}

int main()
{
	vec_GF2 atab[4];
	long i, j, k;

	// a_bin.SetLength(2);

	for ( k = 0; k < 4; k++)
	{
		atab[k].SetLength(2);

		for ( i = 0; i < 2; i++)
			atab[k][1-i] = bit(k,i);
	}

	for ( k = 0; k < 4; k++)
		cout << atab[k] << endl;

	cout << endl;

	//for ( i = 0; i < 4; i++)
	//	cout << atab[i] << " ";

	vec_GF2 sum, mul;

	for ( i = 0; i < 4; i++ )
	{
		for ( j = 0; j < 4; j++ )
		{
			sum = atab[i] + atab[j];
			cout << sum << " ";
		}
	cout << endl;
	}
	
	cout << endl;

	// InnerProduct( mul, atab[0], atab[1]);
	// cout << mul;
	/*
	mul.SetLength(2);

	for ( i = 0; i < 4; i++ )
	{
		for ( j = 0; j < 4; j++ )
		{
			gf2_mult( mul, atab[i], atab[j], 2);
			// mul = atab[i] * atab[j];
			// cout << mul << " ";
		}
	cout << endl;
	}
	*/
}