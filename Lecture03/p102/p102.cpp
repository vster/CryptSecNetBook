#include <iostream>
#include <string.h>
#include <NTL/matrix.h>
#include <NTL/mat_lzz_p.h>

using namespace std;
using namespace NTL;

long p = 26;
const long MAXT = 100;


void EncryptPer( char TC[], char TP[] )
{
	zz_p::init(p);
	Mat<zz_p> A;
	long i, j, n, len;

	len = strlen( TP );

	A.SetDims(4,4);

	n = 0;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
		{
			A[i][j] = TP[n++] - 'a';
			if ( n == len ) break;
		}	
	cout << A << endl;

	n = 0;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
		{
			TC[n++] = conv<int>(A[j][i]) + 'A';
			if ( n == len ) break;			
		}
	TC[n] = '\0';
}

void DecryptPer ( char TP[], char TC[] )
{
	zz_p::init(p);
	Mat<zz_p> A;
	long i, j, n, len;

	len = strlen( TC );

	A.SetDims(4,4);
	
	n = 0;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
		{
			A[j][i] = TC[n++] - 'A';			
			if ( n == len ) break;			
		}
	cout << A << endl;	

	n = 0;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
		{
			TP[n++] = conv<int>(A[i][j]) + 'a';
			if ( n == len ) break;
		}
	TP[n] = '\0';
}

int main()
{
	char OpenText[MAXT] = "meetmeatthepark";
	char EncryptText[MAXT];
	char DecryptText[MAXT];
	long i, j, n, len;

	zz_p::init(p);
	Mat<zz_p> A, B;
	
	cout << OpenText << endl;
	
	EncryptPer ( EncryptText, OpenText );

	cout << EncryptText << endl;

	DecryptPer ( DecryptText, EncryptText );

	cout << DecryptText << endl;

}
