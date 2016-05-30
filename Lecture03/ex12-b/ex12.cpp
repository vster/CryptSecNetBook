#include <iostream>
#include <string.h>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

long n = 26;
const long MAXT = 100;

void EncryptAK ( char chTC[], char chTP[], long k )
{
	int i, iP, iC;
	int iLen = strlen(chTP);

	for(i = 0; i < iLen; i++)
	{
		iP = chTP[i] - 'a';
		iC = (iP + k)%n;
		chTC[i] = iC + 'A';
		k = iP;
	}
	chTC[i] = '\0';
}

void DecryptAK ( char chTP[], char chTC[], long k )
{
	int i, iP, iC;
	int iLen = strlen(chTC);

	for(i = 0; i < iLen; i++)
	{
		iC = chTC[i] - 'A';
		iP = (iC - k)%n;
		if (iP < 0 ) iP +=n;
		chTP[i] = iP + 'a';
		k = iP;
		// if (k<0) k+=n;
	}
	chTP[i] = '\0';
}

int main()
{

	char chOpenText[MAXT] = "thehouseisbeingsoldtonight";
	char chEncText[MAXT];
	char chDecText[MAXT];
	long k = 7;

	// cout << "Enter text: ";
	// cin >> chOpenText;
	

	// cout << "Enter key: ";
	// cin >> k;
	// cout << endl;

	EncryptAK(chEncText, chOpenText, k);
	
	cout << "Open text: " << chOpenText << endl;
	cout << "Encrypt text: " << chEncText << endl;

	DecryptAK(chDecText, chEncText, k);
	
	cout << "Decrypt text: " << chDecText << endl;

	return 0;
}
