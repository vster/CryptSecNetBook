#include <iostream>
#include <NTL/zz.h>

using namespace std;
using namespace NTL;

long n = 26;
const long MAXT = 100;
const long MAXB = 20;
const long BSIZE = 2;

char Key[5][5] =
{
	{'L','G','D','B','A'},
	{'Q','M','H','E','C'},
	{'U','R','N','I','F'},
	{'X','V','S','O','K'},
	{'Z','Y','W','T','P'}
};

void EncryptPF ( char TC[], char TP[] )
{
	char TPBlocks[MAXB][BSIZE];
	char TCBlocks[MAXB][BSIZE];
	long i, j, n, bnum;

	n = 0;
	bnum = 0;
	for ( i = 0; i < MAXB; i++)
	{
	
		for ( j = 0; j < BSIZE; j++)
		{
			TPBlocks[i][j] = TP[n];
			n++;
			if ( TP[n] == NULL )
			{
				if ( j == 0 )
					TPBlocks[i][1] = 'x';
				break;		
			}
		}
			
		if ( TPBlocks[i][0] == TPBlocks[i][1] )
		{
			TPBlocks[i][1] = 'x';
			n--;
		}
		if ( TP[n] == NULL )
			break;
	}
	bnum = i+1;

}

void DecryptPF( char TP[], char TC[] )
{
}

int main()
{

	char chOpenText[MAXT] = "hello";
	char chEncText[MAXT];
	char chDecText[MAXT];

	
	EncryptPF(chEncText, chOpenText);
	
	cout << "Open text: " << chOpenText << endl;
	cout << "Encrypt text: " << chEncText << endl;

	DecryptPF(chDecText, chEncText);
	
	cout << "Decrypt text: " << chDecText << endl;

	return 0;
}