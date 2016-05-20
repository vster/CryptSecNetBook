#include <iostream>
using namespace std;

int n = 26;
const int MAXT = 100;


int Key[5][5] = 
{
	{'z','q','p','f','e'},
	{'y','r','o','g','d'},
	{'x','s','n','h','c'},
	{'w','t','m','i','b'},
	{'v','u','l','k','a'}
};

void EncryptPolybius ( int TC[], char TO[], int len )
{
	int i, j, n;
	
	// k = 0;
	for ( n = 0; n < len; n++)
	{
		for (i = 0; i < 5; i++)
			for (j = 0; j < 5; j++)
				if ( TO[n] == Key[i][j] )
				{
					TC[2*n] = i;
					TC[2*n+1] = j;
					// cout << TO[n] << " " << i << " " << j << endl;
					break;
				}
	}
}

void DecryptPolybius ( char TO[], int TC[], int len )
{
	int i;

	for ( i = 0; i < len; i++)
		TO[i] = Key[TC[2*i]][TC[2*i+1]];
	TO[i] = '\0';
}

int main()
{
	char OpenText[MAXT] = "sinhrofazotron";
	int	 EncryptData[MAXT];
	char DecryptText[MAXT];
	// int i, j, n, k;
	int len = strlen( OpenText );
	
	EncryptPolybius ( EncryptData, OpenText, len );

	for ( int i = 0; i < 2*len; i++)
		cout << EncryptData[i] << " ";
 
	cout << endl;

	DecryptPolybius ( DecryptText, EncryptData, len );

	cout << DecryptText << endl;

return 0;
}