#include <iostream>
#include <NTL/lzz_p.h>
#include <NTL/matrix.h>
#include <NTL/mat_lzz_p.h>
#include <NTL/vector.h>
#include <NTL/vec_lzz_p.h>

using namespace std;
using namespace NTL;

const int MS = 3;

int main()
{
	int iAM[MS][MS] = 
	{{3,5,7},
	{1,4,13},
	{2,7,3}};
	
	int iV[MS] = 
	{3,5,4};

	long p = 16;
	long i, j;

	zz_p::init(p);

	Mat<zz_p> A, B, C;
	Vec<zz_p> v1, v2, v3;

	A.SetDims(MS,MS);

	for (i = 0; i < MS; i++)
		for (j = 0; j < MS; j++)
			A[i][j] = iAM[i][j];

	
	v1.FixLength(MS);

	for (i = 0; i < MS; i++)
		v1[i] = iV[i];

	cout << A << endl;
	cout << v1 << endl;

	B.SetDims(MS,MS);
	
	inv(B, A);

	v2.FixLength(MS);

	v2 = B*v1;

	cout << v2 << endl;


}