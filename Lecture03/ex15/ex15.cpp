#include <iostream>
#include <NTL/ZZ.h>
#include <NTL/lzz_p.h>
#include <NTL/matrix.h>
#include <NTL/mat_lzz_p.h>
#include <NTL/vector.h>
#include <NTL/vec_lzz_p.h>


using namespace std;
using namespace NTL;

long p = 26;
const long MAXT = 100;
const long MAXB = 100;
const long BSIZE = 4;

static long lK[2][2] = 
{	
{3,2},
{5,7}
};

void EncryptHillBlock ( char TC[], char TP[] )
{
	long i, j, n;
	zz_p::init(p);
	Mat<zz_p> P, C, K;

	P.SetDims(2,2);
	
	n = 0;
	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
			P[i][j] = TP[n++]-'a';

	// cout << P << endl;

	K.SetDims(2,2);
	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
			K[i][j] = lK[i][j];

	// cout << K << endl;

	C = P * K;

	// cout << C << endl;	

	n = 0;
	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
			TC[n++] = conv<long>(C[i][j]) + 'A';
	TC[n] = '\0';
}

void DecryptHillBlock ( char TP[], char TC[] )
{
	long i, j, n;
	zz_p::init(p);
	Mat<zz_p> P, C, K, K1;

	C.SetDims(2,2);
	
	n = 0;
	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
			C[i][j] = TC[n++]-'A';
	
	// cout << C << endl;

	K.SetDims(2,2);
	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
			K[i][j] = lK[i][j];

	// cout << K << endl;

	inv( K1, K );

	// cout << K1 << endl;	

	P = C * K1;

	// cout << P << endl;

	n = 0;
	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
			TP[n++] = conv<long>(P[i][j]) + 'a';
	TP[n] = '\0';
}

void EncryptHill ( char EncryptText[], char OpenText[] )
{
	char TPBlocks[MAXB][BSIZE];
	char TCBlocks[MAXB][BSIZE];
	long i, j, n, bnum;
	
	for (i = 0; OpenText[i]; i++)
		TPBlocks[i/BSIZE][i%BSIZE] = OpenText[i];
	for ( ; i%BSIZE; i++)
		TPBlocks[i/BSIZE][i%BSIZE] = 'z';
	bnum = i/BSIZE;

	for (i = 0; i < bnum; i++)
		EncryptHillBlock ( TCBlocks[i], TPBlocks[i] );
	
	n = 0;
	for (i = 0; i < bnum; i++)	
		for (j = 0; j < BSIZE; j++)
			EncryptText[n++] = TCBlocks[i][j];
	EncryptText[n] = '\0';
}

void DecryptHill ( char DecryptText[], char EncryptText[] )
{
	char TCBlocks[MAXB][BSIZE];
	char TDBlocks[MAXB][BSIZE];
	long i, j, n, bnum;

	for (i = 0; EncryptText[i]; i++)
		TCBlocks[i/BSIZE][i%BSIZE] = EncryptText[i];
	//for ( ; i%BSIZE; i++)
	//	TCBlocks[i/BSIZE][i%BSIZE] = 'z';
	bnum = i/BSIZE;

	for (i = 0; i < bnum; i++)
		DecryptHillBlock ( TDBlocks[i], TCBlocks[i] );

	n = 0;
	for (i = 0; i < bnum; i++)	
		for (j = 0; j < BSIZE; j++)
			DecryptText[n++] = TDBlocks[i][j];
	DecryptText[n] = '\0';
}

int main()
{ 
	char OpenText[MAXT] = "helloworld";
	char EncryptText[MAXT];
	char DecryptText[MAXT];

	cout << OpenText << endl;

	EncryptHill ( EncryptText, OpenText );

	cout << EncryptText << endl;

	DecryptHill ( DecryptText, EncryptText );

	cout << DecryptText << endl;

	return 0;
}
