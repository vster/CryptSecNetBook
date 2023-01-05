#include <iostream>
#include <iomanip>
// #include <string>
#include "util.h"
// #include "des.h"

using namespace std;

byte RoundKey[2] = {0xbc,0xd3};

byte IPTab[8] = 
{2,6,3,1,4,8,5,7};

byte FPTab[8] =
{4,1,3,5,7,2,8,6};

byte EPTab[8] = 
{4,1,2,3,2,3,4,1};

const byte SboxTab[2][4][4] = {
// S1	
{
	{1,0,3,2},
	{3,2,1,0},
	{0,2,1,3},
	{3,1,3,2}
},
// S2
{
	{0,1,2,3},
	{2,0,1,3},
	{3,0,1,0},
	{2,1,0,3}
}};

// Добавлены 4-ки для второго полубайта
const byte PboxTab[4] = 
{2,4,3,1};

// P-блок перестановок
template<typename T>
T Permute( T in, const byte KeyPermute[] )
{
	T y = 0;
	T temp;

	int n = 8 * sizeof( T );
	for ( int i = 0; i < n; i++ )
	{
		y <<= 1;		
		temp = in;
		temp >>= n - KeyPermute[i];
		if ( temp&1 )
			y += 1;
	}
	return y;
}

// P-блок 
void ExpandPermute ( byte &out, const byte in )
{
	byte y = 0;
	byte temp;

	// output_bin ( in );
	// cout << endl;

	int n = 8;
	for ( int i = 0; i < n; i++ )
	{
		y <<= 1;		
		temp = in;
		temp >>= 4 - EPTab[i];
		if ( temp&1 )
			y += 1;
	}
	out = y;	

	// output_bin ( out );
	// cout << endl;
}

void KeyGen( u16bit Key )
{


}


// Разбивка 8-битного блока на левую и правую половины по 4 бит
void SplitLR ( byte &L, byte &R, const byte in )
{
	byte temp = in;
	R = temp & 0xf;
	temp >>= 4;
	L = temp & 0xf;
}

// Разбивка 8-битного блока на 2 блока по 4 бита
void SplitForSbox ( byte Sin[], const byte x )
{
	byte temp = x;	
	
    output_bin ( x );
	cout << endl;

	for ( int i = 1; i >= 0; i-- )
	{
		Sin[i] = temp & 0xf;
		temp >>= 4;
	}
	
	for ( int i = 0; i < 2; i++ )
	{
        output_bin ( Sin[i] );
		cout << " ";
	}
	cout << endl;
	
}

// S-преобразование
void SubstSbox ( byte Sout[2], byte Sin[2] )
{
	for ( int i = 0; i < 2; i++ )
	{
		byte temp = Sin[i];
		// output_bin ( temp );
		// cout << endl;
		byte row = (temp&0x1) | ((temp & 0x8)>>2);
		byte col = (( temp & 0x6 ) >> 1);
		// cout << hex << int (row) << " " << int (col) << endl;
		Sout[i] = SboxTab[i][row][col];
		// cout << hex << int (Sout[i]) << endl;
	}
}

// Слияние 2-битовых блоков после S-преобразования
void MergeAfterSbox ( byte &out, byte Sout[] )
{
	byte temp = 0;
	for ( int i = 0; i < 2; i++)
	{
		temp <<= 2;
		temp += Sout[i];
	}
	out = temp;
}	
// Permute semi-bytes
byte PermuteSB ( byte &in, const byte KeyPermute[] )
{
	byte y = 0;
	byte temp;

	int n = 4;
	for ( int i = 0; i < n; i++ )
	{
		y <<= 1;		
		temp = in;
		temp >>= 4 - KeyPermute[i];
		if ( temp&1 )
			y += 1;
	}
	return y;
}

void SwapLR ( byte &L, byte &R )
{
	byte temp;
	temp = L;
	L = R;
	R = temp;
}

void MergeLR ( byte &out, byte L, byte R )
{
	byte temp = 0;
	temp = L;
	temp <<= 4;
	temp += R;
	out = temp;
}

// Функция F
byte Function( byte &R, const byte Key )
{
	byte T1;
	ExpandPermute ( T1, R );

	cout << "\nExpansion permute\n";
    output_bin ( T1 );
	cout << endl;

	cout << "\nKey = \n";
    output_bin ( Key );
	cout << endl;
	
	T1 ^= Key;

	cout << "\nXOR with key\n";
    output_bin ( T1 );
	cout << endl;

	byte Sin[2], Sout[2];
	SplitForSbox( Sin, T1 ); 
	SubstSbox( Sout, Sin );
	
	byte T2 = 0;
	MergeAfterSbox( T2, Sout );

	cout << "\nAfter S-box\n";
    output_bin ( T2 );
	cout << endl;
	
	byte T3;
    T3 = PermuteSB( T2, PboxTab );

	cout << "\After 4-bit P-box\n";
    output_bin ( T3 );
	cout << endl;	
	
	return T3;
}

void Mixer ( byte &L, byte &R, byte Key )
{	
	byte mask;
	mask = Function ( R, Key );

	// Складываем результат F-функции на левую часть
	L ^= mask;

    output_bin ( L );
	cout << " ";
    output_bin ( R );
	cout << endl;
}

void EncryptSDES ( byte &TC, byte TO, u16bit Key )
{
	// byte RoundKey = 0x0;
	

	cout << "\nEncryption...\n";

	// for ( int i = 0; i < 2; i++ )
	//	RoundKey[i] = 0;
	
    // KeyGen ( u16bit Key );

	byte T1;
	T1 = Permute ( TO, IPTab );

	cout << "\nInitial permute\n";
    output_bin ( T1 );
	cout << endl;

	byte L, R;
	SplitLR ( L, R, T1);  

	cout << "\nSplit to L and R\n";
    output_bin ( L );
	cout << " ";
    output_bin ( R );
	cout << endl;

	for ( int i = 0; i < 2; i++ )
	{
		cout << "\nRound = " << i+1 << endl;

		Mixer ( L, R, RoundKey[i] );

        output_bin ( L );
		cout << " ";
        output_bin ( R );
		cout << endl;

		if ( i != 1 )
			SwapLR ( L, R );

        output_bin ( L );
		cout << " ";
        output_bin ( R );
		cout << endl;
	}
	
	byte T2;
	MergeLR ( T2, L, R );
	
    output_bin ( T2 );
		cout << endl;

	TC = Permute ( T2, FPTab );
	
    output_bin ( TC );
		cout << endl;
}

void DecryptSDES ( byte &TD, byte TC, u16bit Key )
{
	cout << "\nDecryption...\n";

	// for ( int i = 0; i < 2; i++ )
	// 	RoundKey[i] = 0;

	// byte RoundKey[2] = {0xbc,0xd3};

	byte T1;
	T1 = Permute ( TC, IPTab );

	cout << "\nInitial permute\n";
    output_bin ( T1 );
	cout << endl;

	byte L, R;
	SplitLR ( L, R, T1);  

	cout << "\nSplit to L and R\n";
    output_bin ( L );
	cout << " ";
    output_bin ( R );
	cout << endl;

	for ( int i = 0; i < 2; i++ )
	{
		
		cout << "\nRound = " << i+1 << endl;

		Mixer ( L, R, RoundKey[1-i] );

        output_bin ( L );
		cout << " ";
        output_bin ( R );
		cout << endl;

		if ( i != 1 )
			SwapLR ( L, R );

        output_bin ( L );
		cout << " ";
        output_bin ( R );
		cout << endl;
	}
	
	byte T2;
	MergeLR ( T2, L, R );
	
    output_bin ( T2 );
		cout << endl;

	TD = Permute ( T2, FPTab );
	
    output_bin ( TD );
		cout << endl;
}


int main()
{
	byte OpenData = 0xf2;
	byte EncData;
	byte DecData;

	u16bit Key = 0x02e6;

	cout << "Open data\n";
    output_bin ( OpenData );
	cout << endl;

	EncryptSDES ( EncData, OpenData, Key );

	cout << "\nEncrypted data\n";
    output_bin ( EncData );
	cout << endl;

	DecryptSDES ( DecData, EncData, Key );

	cout << "\nDecrypted data\n";
    output_bin ( DecData );
	cout << endl;


}
