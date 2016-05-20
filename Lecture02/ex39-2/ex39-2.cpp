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
/*	int iAM1[MS][MS] =
	{{3,0},
	{1,1}};

	int iAM2[MS][MS] =
	{{4,2},
	 {1,1}};
*/

	int iAM3[MS][MS] = 
	{{3,4,6},
	{1,1,8},
	{5,5,3}};

	long p = 10;

	zz_p::init(p);

	Mat<zz_p> A1, A2, A3, B;

	A3.SetDims(MS,MS);
	// A2.SetDims(MS,MS);
	// B.SetDims(MS,MS);

	long i, j;

	for (i = 0; i < MS; i++)
		for (j = 0; j < MS; j++)
		{
			A3[i][j] = iAM3[i][j];
			// A2[i][j] = iAM2[i][j];		
		}
	
	zz_p d;
	d = determinant(A3);
	inv (B, A3);
		

	cout << A3 << endl;
	cout << d << endl;
	cout << B << endl;
	
/*	
	d = determinant(A2);

	cout << A2 << endl;
	cout << d << endl;
*/
}