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

	for(i = 0; i < iLen; i++)
	{
		iC = chTS[i] - 'A';
		iP = (iC - k)%n;
		if (iP < 0)
			iP += n;
		chTO[i] = iP + 'a';
	}
	chTO[i] = '\0';
}


int main()
{

	char chOpenText[MAXT];
	char chEncText[MAXT] = "OTWEWNGWCBPQABIZVQAPMLJGZWTTQVOBQUMAPMIDGZCAB";
	char chDecText[MAXT];
	int k;

	/*
	cout << "Enter text: ";
	cin >> chOpenText;
	
	cout << "Enter key: ";
	cin >> k;
	cout << endl;

	EncryptShift(chEncText, chOpenText, k);
	
	cout << "Open text: " << chOpenText << endl;
	cout << "Encrypt text: " << chEncText << endl;
	cout << endl;
	*/

	int iKx;
	for (iKx = 0; iKx < n; iKx++)
	{
		DecryptShift(chDecText, chEncText, iKx);
		cout << "Key: " << iKx << "\ttext: " << chDecText << endl;
	}
}