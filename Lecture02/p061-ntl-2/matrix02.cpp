#include <iostream>
#include <NTL/ZZ.h>
#include <NTL/matrix.h>
#include <NTL/mat_ZZ.h>

using namespace std;
using namespace NTL;

/*
static int iA[1][3] = { 5, 2, 1 };

static int iB[3][1] = { {7}, {8}, {2} };
*/

static int iA[2][3] = {	{5,2,1},
						{3,2,4} };

static int iB[3][4] = {	{7,3,2,1},
						{8,0,0,2},
						{1,3,4,0}};

int main()
{
	
	Mat<ZZ> A, B, C;
	long i, j;

	long k = 3;

	A.SetDims(2,3);
	B.SetDims(3,4);

	for (i = 0; i < 2; i++)
		for (j = 0; j < 3; j++)
			A[i][j] = iA[i][j];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 4; j++)
			B[i][j] = iB[i][j];

	// C = A * B;

	C = k * A;

	cout << A << endl;
	// cout << B << endl;
	cout << C << endl;

}
