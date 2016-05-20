#include <iostream>
#include <NTL/ZZ.h>
#include <NTL/matrix.h>
#include <NTL/mat_ZZ.h>
// #include <NTL/vec_vec_ZZ.h>

using namespace std;
using namespace NTL;


long lA[2][3] = {	{5, 2, 1},
						{3, 2, 10}};

long lB[2][3] = {	{7, 2, 3},
						{8, 10, 20}};

// long lC[2][3];

int main()
{
	long i, j;

	Mat<ZZ> A, B, C;

	A.SetDims(2,3);
	B.SetDims(2,3);
//	C.SetDims(2,3);

	for (i = 0; i < 2; i++)
		for (j = 0; j < 3; j++)
		{
			A[i][j] = lA[i][j];
			B[i][j] = lB[i][j];		
		}
	C = A + B;

	cout << A << endl;
	cout << B << endl;
	cout << C << endl;
}