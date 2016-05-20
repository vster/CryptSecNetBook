#include <iostream>
#include <NTL/zz.h>
#include <NTL/lzz_p.h>
#include <NTL/matrix.h>
#include <NTL/mat_lzz_p.h>
#include <NTL/vector.h>
#include <NTL/vec_lzz_p.h>


using namespace std;
using namespace NTL;

long p = 26;
const long MAXT = 100;

/*
static long lK[4][4] = 
{	
{9,7,11,13},
{4,7,5,6},
{2,21,14,9},
{3,23,21,8}
};
*/
/*
void EncryptHill ( char TC[], char TP[] )
{
	long i, j, n;
	zz_p::init(p);
	Mat<zz_p> P, C, K;

	P.SetDims(3,4);
	
	n = 0;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 4; j++)
			P[i][j] = TP[n++]-'a';

	cout << P << endl;

	K.SetDims(4,4);
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			K[i][j] = lK[i][j];

	cout << K << endl;

	C = P * K;

	cout << C << endl;	

	n = 0;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 4; j++)
			TC[n++] = conv<long>(C[i][j]) + 'A';
	TC[n] = '\0';
}

void DecryptHill ( char TP[], char TC[] )
{
	long i, j, n;
	zz_p::init(p);
	Mat<zz_p> P, C, K, K1;

	C.SetDims(3,4);
	
	n = 0;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 4; j++)
			C[i][j] = TC[n++]-'A';
	
	cout << C << endl;

	K.SetDims(4,4);
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			K[i][j] = lK[i][j];

	cout << K << endl;

	inv( K1, K );

	cout << K1 << endl;	

	P = C * K1;

	cout << P << endl;

	n = 0;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 4; j++)
			TP[n++] = conv<long>(P[i][j]) + 'a';
	TP[n] = '\0';

}
*/
int main()
{ 
	char OpenText[MAXT] =		"letusmeetnow";
	char EncryptText[MAXT] =	"HBCDFNOPIKLB";
	char DecryptText[MAXT];

	zz_p::init(p);
	Mat<zz_p> P, C, P1, K;
	long i, j, n;

	P.SetDims(4,3);
	n = 0;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 3; j++)
			P[i][j] = OpenText[n++]-'a';

	cout << OpenText << endl;

	cout <<  P << endl;

	C.SetDims(4,3);

	n = 0;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 3; j++)
			C[i][j] = EncryptText[n++]-'A';

	cout << EncryptText << endl;

	cout <<  C << endl;
	
	inv(P1, P);

	cout <<  P1 << endl;

	K = C * P1;

	cout <<  K << endl;

/*
	EncryptHill( EncryptText, OpenText );
	
	cout << EncryptText << endl;

	DecryptHill ( DecryptText, EncryptText );

	cout << DecryptText << endl;
*/
	return 0;
}