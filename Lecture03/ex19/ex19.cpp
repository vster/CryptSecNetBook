
#include <iostream>
#include <NTL/lzz_p.h>
#include <NTL/matrix.h>
#include <NTL/mat_lzz_p.h>
#include <NTL/vector.h>
#include <NTL/vec_lzz_p.h>

using namespace std;
using namespace NTL;

const int MS = 2;

int main()
{
	long p = 26;

	/*
	char a[] = "abgl";

	for (int i = 0; i < 4; i++)
	{
		int n = a[i] - 'a';
		cout << n << " ";
	}
	*/

	int iAM[MS][MS] = 
	{{0,1},
	{1,1}};
		
	int iV[MS] = 
	{6,11};

	long i, j;

	zz_p::init(p);

	Mat<zz_p> A, B, C;
	Vec<zz_p> v1, v2, v3;

	A.SetDims(MS,MS);
	B.SetDims(MS,MS);

	for (i = 0; i < MS; i++)
		for (j = 0; j < MS; j++)
			A[i][j] = iAM[i][j];

	v1.FixLength(MS);
	v2.FixLength(MS);

	for (i = 0; i < MS; i++)
		v1[i] = iV[i];

	cout << A << endl;
	cout << v1 << endl << endl;	
	
	inv(B,A);

	v2 = B * v1;

	cout << B << endl;
	cout << v2 << endl;
}