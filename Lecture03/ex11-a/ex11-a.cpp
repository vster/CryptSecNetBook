#include <iostream>
using namespace std;

int n = 26;
const int MAXT = 100;

void EncryptShift( char chTS[], char chTO[], int k)
{
	int i, iP, iC;
	int iLen = strlen(chTO);

	for(i = 0; i < iLen; i++)
	{
		iP = chTO[i] - 'a';
		iC = (iP + k)%n;
		chTS[i] = iC + 'A';
	}
	chTS[i] = '\0';
}

void DecryptShift( char chTO[], char chTS[], int k)
{
	int i, iP, iC;
	int iLen = strlen(chTS);
	int kinv;

	kinv = n - k;
	
	for(i = 0; i < iLen; i++)
	{
		iC = chTS[i] - 'A';
		iP = (iC + kinv)%n;
		chTO[i] = iP + 'a';
	}
	chTO[i] = '\0';
}


int main()
{

	char chOpenText[MAXT] = "thisisexercise";
	char chEncText[MAXT];
	char chDecText[MAXT];
	int k;

	// cout << "Enter text: ";
	// cin >> chOpenText;
	
	// cout << "Enter key: ";
	// cin >> k;
	// cout << endl;
	k = 20;

	EncryptShift(chEncText, chOpenText, k);
	
	cout << "Open text: " << chOpenText << endl;
	cout << "Encrypt text: " << chEncText << endl;

	DecryptShift(chDecText, chEncText, k);
	
	cout << "Decrypt text: " << chDecText << endl;
}