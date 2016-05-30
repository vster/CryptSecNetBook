#include <iostream>
#include <string.h>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

long n = 26;
const long MAXT = 100;

int main()
{
	char chOpenText[MAXT];
	char chEncText[MAXT] = "JNHOVEJHWOBEVGWOCBWHNUGBLHGBGR";
	char chDecText[MAXT];

	int CharFreq[26] = { 0 };

	int len = strlen( chEncText );
	
	for (int i = 0; i < len; i++)
		 CharFreq[chEncText[i] - 'A']++;
	
	for (int i = 0; i < 26; i++)
		cout << i << " " << char(i+'A') << " " << CharFreq[i] << endl;
}
