#include <iostream>
#include <string.h>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

long n = 26;
const long MAXT = 100;
const long KEYLEN = 6;

long key[KEYLEN] = {15,00,18,02,00,11};

void EncryptVig ( char chTC[], char chTP[] )
{
	int i, iP, iC;
	int iLen = strlen(chTP);

	for(i = 0; i < iLen; i++)
	{
		iP = chTP[i] - 'a';
		iC = (iP + key[i%KEYLEN])%n;
		chTC[i] = iC + 'A';
	}
	chTC[i] = '\0';
}
void DecryptVig ( char chTP[], char chTC[] )
{
	int i, iP, iC;
	int iLen = strlen(chTC);

	for(i = 0; i < iLen; i++)
	{
		iC = chTC[i] - 'A';
		iP = (iC - key[i%KEYLEN])%n;
		if (iP < 0 ) 
			iP +=n;
		chTP[i] = iP + 'a';
	}
	chTP[i] = '\0';
}

int main()
{

	char chOpenText[MAXT] = "sheislistening";
	char chEncText[MAXT];
	char chDecText[MAXT];

	// cout << "Enter text: ";
	// cin >> chOpenText;
	

	// cout << "Enter key: ";
	// cin >> k;
	// cout << endl;

	EncryptVig(chEncText, chOpenText);
	
	cout << "Open text: " << chOpenText << endl;
	cout << "Encrypt text: " << chEncText << endl;

	DecryptVig(chDecText, chEncText);
	
	cout << "Decrypt text: " << chDecText << endl;

	return 0;
}
