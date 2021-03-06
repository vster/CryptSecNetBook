#include <iostream>
#include <string.h>
#include <NTL/matrix.h>
#include <NTL/mat_lzz_p.h>

using namespace std;
using namespace NTL;

long p = 26;
const long MAXT = 100;
const long BSIZE = 6;

long EncKey[6][6] = 
{
	{0,0,0,1,0,0},
	{0,1,0,0,0,0},
	{1,0,0,0,0,0},
	{0,0,0,0,0,1},
	{0,0,0,0,1,0},
	{0,0,1,0,0,0}
};

void EncryptPer( char TC[], char TP[] )
{
	zz_p::init(p);
	Mat<zz_p> MP, MC, EK;
	long i, j, n, len;

	len = strlen( TP );
	long bnum = len/BSIZE;
	if (len%BSIZE > 0) bnum++;

	MP.SetDims(bnum, BSIZE);
	
	// ����������� ����� � �������
	n = 0;
	for (i = 0; i < bnum; i++)
		for (j = 0; j < BSIZE; j++)
		{
			MP[i][j] = TP[n++] - 'a';
			if ( n > len ) 
				MP[i][j] = 'z' - 'a';
		}	
	cout << MP << endl;

	// ������� ����� ������������
	EK.SetDims(BSIZE,BSIZE);
	// ��������� ����
	for ( i = 0; i < BSIZE; i++)
		for (j = 0; j < BSIZE; j++)
			EK[i][j] = EncKey[i][j];
	
	cout << EK << endl;
	// ������ ��������������
	// �������� ������� ��������� ������ �� ������� �����
	MC = MP * EK;

	cout << MC << endl;
	// ����������� �� �������� ������������� �������
	// � ������ �������������� ������
	n = 0;
	for (j = 0; j < BSIZE; j++)	
		for (i = 0; i < bnum; i++)
			TC[n++] = conv<int>(MC[i][j]) + 'A';
	TC[n] = '\0';
}

void DecryptPer ( char TP[], char TC[] )
{
	zz_p::init(p);
	Mat<zz_p> MD, MC, EK, DK;
	long i, j, n, len;

	len = strlen( TC );
	long bnum = len/BSIZE;
	
	MC.SetDims(bnum,BSIZE);
	// ��������� ������������� �����
	// � ������������� ������� �� ��������
	n = 0;
	for (j = 0; j < BSIZE; j++)
		for (i = 0; i < bnum; i++)
			MC[i][j] = TC[n++] - 'A';			
	cout << MC << endl;	

	EK.SetDims(BSIZE,BSIZE);
	// ��������� ����
	for ( i = 0; i < BSIZE; i++)
		for (j = 0; j < BSIZE; j++)
			EK[i][j] = EncKey[i][j];	
	
	cout << EK << endl;
	
	// ����������� ����
	inv(DK, EK);

	cout << DK << endl;
	
	// �������� �������������� 
	// �� ������������� ������� � ��������
	MD = MC * DK;

	cout << MD << endl;
	
	// ��������� ������������� �������
	// � ������������� �����
	n = 0;
	for (i = 0; i < bnum; i++)
		for (j = 0; j < BSIZE; j++)
			TP[n++] = conv<int>(MD[i][j]) + 'a';
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
