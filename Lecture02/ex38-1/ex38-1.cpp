#include <iostream>
#include <NTL/ZZ.h>
#include <NTL/matrix.h>
#include <NTL/mat_ZZ.h>

using namespace std;
using namespace NTL;

const int MS = 3;

int main()
{
	int iA[MS][MS] = 
{	{3,4,6},
	{1,1,8},
	{5,5,3}};


	int iB[MS][MS] = 
{	{2,0,1},
	{1,1,0},
	{5,2,4}};
/*
static int B[3][3] = 
{{9,4,8},
{1,7,6},
{0,5,7}};
*/
	long i, j;
	Mat<ZZ> A, B, C;

	A.SetDims(MS,MS);
	B.SetDims(MS,MS);
	C.SetDims(MS,MS);

	for (i = 0; i < MS; i++)
		for (j = 0; j < MS; j++)
		{
			A[i][j] = iA[i][j];
			B[i][j] = iB[i][j];		
		}

	C = A * B;

	cout << A << endl;
	cout << B << endl;
	cout << C << endl;
}
