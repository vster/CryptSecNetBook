#include <iostream>
// #include <NTL/matrix.h>
// #include <NTL/mat_lzz_p.h>

using namespace std;
// using namespace NTL;

// long p = 26;
const long MAXT = 100;
const long MAXB = 20;
const long BSIZE = 5;

int key[5] = {3, 1, 4, 5, 2};

void EncryptPer( char TC[], char TP[] )
{
	char TPBlocks[MAXB][BSIZE];
	char TCBlocks[MAXB][BSIZE];
	long i, j, n, bnum;

	for (i = 0; TP[i]; i++)
		TPBlocks[i/BSIZE][i%BSIZE] = TP[i];
	for ( ; i%BSIZE; i++)
		TPBlocks[i/BSIZE][i%BSIZE] = 'z';
	bnum = i/BSIZE;

	for (j = 0; j < bnum; j++)
	{
		for (i = 0; i < BSIZE; i++)
			cout << TPBlocks[j][i];
		cout << " ";
	}
	cout << endl;

	for (j = 0; j < bnum; j++)
		for (i = 0; i < BSIZE; i++)
			TCBlocks[j][i] = TPBlocks[j][key[i]-1] - 'a' + 'A';

	for (j = 0; j < bnum; j++)
	{
		for (i = 0; i < BSIZE; i++)
			cout << TCBlocks[j][i];
		cout << " ";
	}
	cout << endl;

	n = 0;
	for (j = 0; j < bnum; j++)
		for (i = 0; i < BSIZE; i++)
			TC[n++] = TCBlocks[j][i];
	TC[n] = '\0';

}

void DecryptPer( char TP[], char TC[] )
{
	char TPBlocks[MAXB][BSIZE];
	char TCBlocks[MAXB][BSIZE];
	long i, j, n, bnum;

	for (i = 0; TC[i]; i++)
		TCBlocks[i/BSIZE][i%BSIZE] = TC[i];
	bnum = i/BSIZE;

	for (j = 0; j < bnum; j++)
	{
		for (i = 0; i < BSIZE; i++)
			cout << TCBlocks[j][i];
		cout << " ";
	}
	cout << endl;

	for (j = 0; j < bnum; j++)
		for (i = 0; i < BSIZE; i++)
			TPBlocks[j][key[i]-1] = TCBlocks[j][i] - 'A' + 'a';

	for (j = 0; j < bnum; j++)
	{
		for (i = 0; i < BSIZE; i++)
			cout << TPBlocks[j][i];
		cout << " ";
	}
	cout << endl;

	n = 0;
	for (j = 0; j < bnum; j++)
		for (i = 0; i < BSIZE; i++)
			TP[n++] = TPBlocks[j][i];
	TP[n] = '\0';
}

int main()
{
	char OpenText[MAXT] = "enemyattackstonight";
	char EncryptText[MAXT];
	char DecryptText[MAXT];
	
	cout << OpenText << endl;

	EncryptPer ( EncryptText, OpenText );

	cout << EncryptText << endl;

	DecryptPer ( DecryptText, EncryptText );

	cout << DecryptText << endl;

	return 0;
}