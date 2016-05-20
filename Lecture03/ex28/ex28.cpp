#include <iostream>
#include <NTL/zz.h>

using namespace std;
using namespace NTL;

long n = 26;
const long MAXT = 100;

void EncryptAfin( char chTC[], char chTP[])
{
	long k1, k2;
	long i, lP, lC;
	long lLen = strlen(chTP);

	for(i = 0; i < lLen; i++)
	{
		k1 = (i+1)%12;
		k2 = (i+1)%26;
		lP = chTP[i] - 'a';
		lC = (lP * k1 + k2)%n;
		chTC[i] = (char)lC + 'A';
	}
	chTC[i] = '\0';
}

void DecryptAfin( char chTP[], char chTC[])
{
	long k1, k2;
	long i, lP, lC;
	long lLen = strlen(chTC);
	long k1inv, k2inv;



	for(i = 0; i < lLen; i++)
	{
		k1 = (i+1)%12;
		k2 = (i+1)%26;
		k1inv = InvMod(k1, n);
		k2inv = n - k2;		
		lC = chTC[i] - 'A';
		lP = ((lC + k2inv)* k1inv)%n;
		chTP[i] = (char)lP + 'a';
	}
	chTP[i] = '\0';
}

int main()
{

	char chOpenText[MAXT] = "cryptographyisfun";
	char chEncText[MAXT];
	char chDecText[MAXT];
	long k1, k2;

	/*
	cout << "Enter text: ";
	cin >> chOpenText;
	
	cout << "Enter keys: ";
	cin >> k1 >> k2;
	cout << endl;
	*/

	EncryptAfin(chEncText, chOpenText);
	
	cout << "Open text: " << chOpenText << endl;
	cout << "Encrypt text: " << chEncText << endl;

	DecryptAfin(chDecText, chEncText);
	
	cout << "Decrypt text: " << chDecText << endl;

	return 0;
}