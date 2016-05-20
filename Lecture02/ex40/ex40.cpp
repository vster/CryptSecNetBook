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
	long p;
/* 
a)
	p = 5;
	int iAM[MS][MS] = 
	{{3,5},
	{2,1}};
		
	int iV[MS] = 
	{4,3};
	
*/
/*	
б)
	p = 7;

	int iAM[MS][MS] = 
	{{3,2},
	{4,6}};
		
	int iV[MS] = 
	{5,4};
*/

//в)
	p = 7;

	int iAM[MS][MS] = 
	{{7,3},
	{4,2}};
		
	int iV[MS] = 
	{3,5};

/*
г) нет решения
	p = 8;

	int iAM[MS][MS] = 
	{{2,5},
	{1,6}};
		
	int iV[MS] = 
	{5,3};
*/

	// long p = 5;
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

	inv(B,A);

	v2 = B * v1;

	cout << A << endl;
	cout << v1 << endl << endl;

	cout << B << endl;
	cout << v2 << endl;
}
