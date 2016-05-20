#include <iostream>
#include <iomanip>
#include "util.h"

using namespace std;

const int BS = 256;
const int KL = 8;
const int MAXT = 100;

byte S[BS], K[BS];

void swap ( byte &x, byte &y )
{
	byte temp;
	temp = x;
	x = y;
	y = temp;
}

void Init ( byte Key[KL] )
{
	int i, j;

	// Первый шаг
	// Инициализация матрицы состояний S[i]
	// Создание массива ключей K[i]
	for ( i = 0; i < BS; i++ )
	{
		S[i] = i;
		K[i] = Key[ i%KL ];
	}
	// Второй шаг
	// Перестановка байтов матрицы состояний
	// на основе значений байта ключа
	j = 0;
	for ( i = 0; i < BS; i++)
	{
		j = ( j + S[i] + K[i] ) % BS;
		swap ( S[i], S[j] );
	}
}

void EncryptRC4 ( byte TO[MAXT], byte TC[MAXT] )
{	
	int i = 0, j = 0;
	int it;
	cout << "\nKey stream:\n";
	for ( it = 0; TO[it] > 0; it++ )
	{
		i = (i + 1) % BS;
		j = ( j + S[i] ) % BS;
		swap ( S[i], S[j] );
		byte k = S[ (S[i]+S[j])%BS ];

		TC[it] = TO[it] ^ k;
		cout << hex << setw(2) << setfill ( '0' ) << int ( k )<< " ";
		/*
		cout << dec << setw(2) << setfill ( '0' )
			 << it << " " << i << " " << j << " " 
			 << int( S[i] ) << " " << int ( S[j] ) << " " 
			 << int ( k  )<< " " << int ( TO[it] ) << " " << int ( TC[it] ) << endl;
		*/
	}
	cout << endl;
	TC[it] = '\0';
}

int main()
{
	
	byte OpenData[MAXT] = "text for test"; 
	byte EncryptData[MAXT];
	byte DecryptData[MAXT];


	// byte Key[KL] = { 0x00 };
	// byte Key[KL] = { 15, 202, 33, 6, 8};
	byte Key[KL] = { 0x33, 0x33, 0x33, 0x33,
	 				 0xcc, 0xcc, 0xcc, 0xcc };
	// int i, j;

	// cout.width(2);
	// cout.fill('0');

	cout << "Open data:\n";
	for ( int it = 0; OpenData[it] > 0; it++ )
		cout << hex << setw(2) << setfill('0') 
			 << int ( OpenData[it] ) << " ";
	cout << endl;

	// Зашифрование
	Init ( Key );

	EncryptRC4 ( OpenData, EncryptData );

	cout << "Encrypted data:\n";
	for ( int it = 0; EncryptData[it] > 0; it++ )
		cout << hex << setw(2) << setfill('0')  
			 <<	int ( EncryptData[it] ) << " ";
	cout << endl;


	// Расшифрование
	Init ( Key );

	EncryptRC4 ( EncryptData, DecryptData );

	cout << "Decrypted data:\n";
	for ( int it = 0; DecryptData[it] > 0; it++ )
		cout << hex << setw(2) << setfill('0')  
			 <<	int ( DecryptData[it] ) << " ";
	cout << endl;

	return 0;
}