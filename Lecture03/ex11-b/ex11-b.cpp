#include <iostream>
#include <string.h>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

long n = 26;
const long MAXT = 100;

void EncryptMult( char chTC[], char chTP[], long k)
{
	long i, lP, lC;
	long lLen = strlen(chTP);

	for(i = 0; i < lLen; i++)
	{
		lP = chTP[i] - 'a';
		lC = (lP * k)%n;
		chTC[i] = (char)lC + 'A';
	}
	chTC[i] = '\0';
}

void DecryptMult( char chTP[], char chTC[], long k)
{
	long i, lP, lC;
	long lLen = strlen(chTC);
	long kinv;

	kinv = InvMod (k, n);

	for(i = 0; i < lLen; i++)
	{
		lC = chTC[i] - 'A';
		lP = (lC * kinv)%n;
		chTP[i] = (char)lP + 'a';
	}
	chTP[i] = '\0';
}

int main()
{

	char chOpenText[MAXT] = "thisisexercise";
	char chEncText[MAXT];
	char chDecText[MAXT];
	long k = 15;

	// cout << "Enter text: ";
	// cin >> chOpenText;
	
	// cout << "Enter key: ";
	// cin >> k;
	// cout << endl;

	EncryptMult(chEncText, chOpenText, k);
	
	cout << "Open text: " << chOpenText << endl;
	cout << "Encrypt text: " << chEncText << endl;

	DecryptMult(chDecText, chEncText, k);
	
	cout << "Decrypt text: " << chDecText << endl;

	return 0;
}
