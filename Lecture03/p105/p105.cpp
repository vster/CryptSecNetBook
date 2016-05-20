#include <iostream>

using namespace std;

const int KEYSIZE = 7;

int EncKey[KEYSIZE] = { 2, 6, 3, 1, 4, 7, 5  };
int DecKey[KEYSIZE];

int main()
{
	
	// Ключ шифрования
	for (int i = 0; i < KEYSIZE; i++)
		cout << EncKey[i] << " ";
	cout << endl;

	// Инверсия ключа шифрования в ключ дешифрования
	for (int i = 0; i < KEYSIZE; i++)
		DecKey[EncKey[i]-1] = i+1;

	// Ключ дешфирования
	for (int i = 0; i < KEYSIZE; i++)
		cout << DecKey[i] << " ";
	cout << endl;
}
