#include <iostream>
#include <string.h>
using namespace std;

int n = 26;
const int MAXT = 100;

void EncryptAtbash( char TC[], char TO[])
{
	int i, iP, iC;
	int iLen = strlen(TO);

	for(i = 0; i < iLen; i++)
	{
		iP = TO[i] - 'a';
		iC = (n - iP)%n;
		TC[i] = iC + 'A';
	}
	TC[i] = '\0';
}

void DecryptAtbash( char TO[], char TC[])
{
	int i, iP, iC;
	int iLen = strlen(TC);
	// int kinv;

	// kinv = n - k;
	
	for(i = 0; i < iLen; i++)
	{
		iC = TC[i] - 'A';
		iP = (n - iC)%n;
		TO[i] = iP + 'a';
	}
	TO[i] = '\0';
}


int main()
{

	char OpenText[MAXT] = "exercise";
	char EncText[MAXT];
	char DecText[MAXT];
	// int k;

	/*
	cout << "Enter text: ";
	cin >> chOpenText;
	
	cout << "Enter key: ";
	cin >> k;
	cout << endl;
	*/

	EncryptAtbash( EncText, OpenText );
	
	cout << "Open text: " << OpenText << endl;
	cout << "Encrypt text: " << EncText << endl;

	DecryptAtbash( DecText, EncText );
	
	cout << "Decrypt text: " << DecText << endl;
}
