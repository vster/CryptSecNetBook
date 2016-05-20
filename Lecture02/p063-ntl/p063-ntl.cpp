#include <iostream>
#include <NTL/lzz_p.h>
#include <NTL/matrix.h>
#include <NTL/mat_lzz_p.h>
#include <NTL/vector.h>
#include <NTL/vec_lzz_p.h>

using namespace std;
using namespace NTL;

const int MS = 4;

int main()
{
	int iAM1[MS][MS] = {	{3,5,7,2},
						{1,4,7,2},
						{6,3,9,17},
						{13,5,4,16}	};

	int iAM2[MS][MS] = {	{15,21,0,15},
						{23,9,0,22},
						{15,16,18,3},
						{24,7,15,3}};
	
	long p = 26;
	long i, j;

	zz_p::init(p);

	Mat<zz_p> A, B, C, D;

	A.SetDims(MS,MS);

	for (i = 0; i < MS; i++)
		for (j = 0; j < MS; j++)
			A[i][j] = iAM1[i][j];

	B.SetDims(MS,MS);

	inv(B, A);

	cout << A << endl;
	cout << B << endl;

	C.SetDims(MS,MS);

	C = A * B;

	cout << C << endl;

}