#include <iostream>
#include <NTL/zz.h>

using namespace std;
using namespace NTL;

long n = 26;
const long MAXT = 100;

char key[26] =
{'N','O','A','T','R','B','E','C','F','U','X','D','Q',
'G','Y','L','K','H','V','I','J','M','P','Z','S','W'};

void EncryptS(char chTS[], char chTO[])
{
	int i, iP, iC;
	int iLen = strlen(chTO);

	for(i = 0; i < iLen; i++)
	{
		iP = chTO[i] - 'a';
		chTS[i] = key[iP];
	}
	chTS[i] = '\0';	
}

int main()
{

	char chOpenText[MAXT];
	char chEncText[MAXT];
	char chDecText[MAXT];
	long k1, k2;

	cout << "Enter text: ";
	cin >> chOpenText;
	
	// cout << "Enter keys: ";
	// cin >> k1 >> k2;
	// cout << endl;

	EncryptS(chEncText, chOpenText);
	
	cout << "Open text: " << chOpenText << endl;
	cout << "Encrypt text: " << chEncText << endl;

	// DecryptS(chDecText, chEncText, k1, k2);
	
	//cout << "Decrypt text: " << chDecText << endl;

	return 0;
}