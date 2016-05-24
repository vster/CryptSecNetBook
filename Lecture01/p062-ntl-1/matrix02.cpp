#include <iostream>
#include <NTL/ZZ.h>
#include <NTL/matrix.h>
#include <NTL/mat_ZZ.h>

using namespace std;
using namespace NTL;

const int MS = 3;

//

int main()
{
	int iA[MS][MS] = {	{5,2,1},
						{3,0,-4},
						{2,1,6}};

	Mat<ZZ> A;
	long i, j;
	ZZ d;

	A.SetDims( MS, MS );

	for (i = 0; i < MS; i++)
		for (j = 0; j < MS; j++)
			A[i][j] = iA[i][j];

	cout << A << endl;

	long deterministic=0;
	d = determinant(A, deterministic);

	cout << d << endl;

}
