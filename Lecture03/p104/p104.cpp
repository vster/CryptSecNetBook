#include <iostream>
#include <string.h>

using namespace std;

const long MAXT = 100;
const long MAXB = 20;
const long BSIZE = 5;

int key[5] = {3, 1, 4, 5, 2};

void EncryptPer( char TC[], char TP[] )
{
	char TPBlocks[MAXB][BSIZE];
	char TCBlocks[MAXB][BSIZE];
	long i, j, n, bnum;

	// Разбивка исходного текста по блокам
	for (i = 0; TP[i]; i++)
		TPBlocks[i/BSIZE][i%BSIZE] = TP[i];
	for ( ; i%BSIZE; i++)
		TPBlocks[i/BSIZE][i%BSIZE] = 'z';
	bnum = i/BSIZE;

	// Вывод блоков на экран
	for (j = 0; j < bnum; j++)
	{
		for (i = 0; i < BSIZE; i++)
			cout << TPBlocks[j][i];
		cout << endl;
	}
	cout << endl;

	// Перестановка столбцов в матрице
	for (j = 0; j < bnum; j++)
		for (i = 0; i < BSIZE; i++)
			TCBlocks[j][i] = TPBlocks[j][key[i]-1] - 'a' + 'A';

	// Вывод блоков на экран после перестановки
	for (j = 0; j < bnum; j++)
	{
		for (i = 0; i < BSIZE; i++)
			cout << TCBlocks[j][i];
		cout << endl;
	}
	cout << endl;

	// Считование по столбцам зашифрованного текста
	n = 0;
	for (i = 0; i < BSIZE; i++)	
		for (j = 0; j < bnum; j++)
			TC[n++] = TCBlocks[j][i];
	TC[n] = '\0';

}

void DecryptPer( char TP[], char TC[] )
{
	char TPBlocks[MAXB][BSIZE];
	char TCBlocks[MAXB][BSIZE];
	long i, j, n, bnum;

	// Перевод зашифрованного текста по столбцам в матрицу
	bnum = strlen(TC) / BSIZE;
	for (i = 0; TC[i]; i++)
		TCBlocks[i%bnum][i/bnum] = TC[i];

	// Вывод матрицы на экран
	for (j = 0; j < bnum; j++)
	{
		for (i = 0; i < BSIZE; i++)
			cout << TCBlocks[j][i];
		cout << endl;
	}
	cout << endl;

	// Обратная перестановка по столбцам
	for (j = 0; j < bnum; j++)
		for (i = 0; i < BSIZE; i++)
			TPBlocks[j][key[i]-1] = TCBlocks[j][i] - 'A' + 'a';

	// Вывод матрицы на экран
	for (j = 0; j < bnum; j++)
	{
		for (i = 0; i < BSIZE; i++)
			cout << TPBlocks[j][i];
		cout << endl;
	}
	cout << endl;

	// Считование матрицы в строку расшифрованного текста
	n = 0;
	for (j = 0; j < bnum; j++)
		for (i = 0; i < BSIZE; i++)
			TP[n++] = TPBlocks[j][i];
	TP[n] = '\0';
}

int main()
{
	char OpenText[MAXT] = "enemyattackstonight";
	char EncryptText[MAXT];
	char DecryptText[MAXT];
	
	cout << OpenText << endl;

	EncryptPer ( EncryptText, OpenText );

	cout << EncryptText << endl;

	DecryptPer ( DecryptText, EncryptText );

	cout << DecryptText << endl;

	return 0;
}
