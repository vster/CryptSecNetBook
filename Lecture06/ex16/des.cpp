#include <iostream>
#include <iomanip>
#include <string>
#include "util.h"
#include "des.h"

using namespace std;

u64bit RoundKey[16];

const byte IPTab[64] =
{
58,50,42,34,26,18,10, 2,
60,52,44,36,28,20,12, 4,
62,54,46,38,30,22,14, 6,
64,56,48,40,32,24,16, 8,
57,49,41,33,25,17, 9, 1,
59,51,43,35,27,19,11, 3,
61,53,45,37,29,21,13, 5,
63,55,47,39,31,23,15, 7
};

const byte FPTab[64] =
{
40, 8,48,16,56,24,64,32,
39, 7,47,15,55,23,63,31,
38, 6,46,14,54,22,62,30,
37, 5,45,13,53,21,61,29,
36, 4,44,12,52,20,60,28,
35, 3,43,11,51,19,59,27,
34, 2,42,10,50,18,58,26,
33, 1,41, 9,49,17,57,25
};

const byte EPTab[48] = 
{
32, 1, 2, 3, 4, 5,
 4, 5, 6, 7, 8, 9,
 8, 9,10,11,12,13,
12,13,14,15,16,17,
16,17,18,19,20,21,
20,21,22,23,24,25,
24,25,26,27,28,29,
28,29,31,31,32, 1
};

const byte PDTab[56] = 
{
57,49,41,33,25,17, 9, 1,
58,50,42,34,26,18,10, 2,
59,51,43,35,27,19,11, 3,
60,52,44,36,63,55,47,39,
31,23,15, 7,62,54,46,38,
30,22,14, 6,61,53,45,37,
29,21,13, 5,28,20,12, 4
};

const byte ShiftKeyTab[16] =
{1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};

const byte KeyPermTab[48] =
{
14,17,11,24, 1, 5, 3,28,
15, 6,21,10,23,19,12, 4,
26, 8,16, 7,27,20,13, 2,
41,52,31,37,47,55,30,40,
51,45,33,48,44,49,39,56,
34,53,46,42,50,36,29,32
};

const byte SboxTab[8][4][16] = {
// S1
{
	{14, 4,13, 1, 2,15,11, 8, 3,10, 6,12, 5, 9, 0, 7},
	{ 0,15, 7, 4,14, 2,13, 1,10, 6,12,11, 9, 5, 3, 8},
	{ 4, 1,14, 8,13, 6, 2,11,15,12, 9, 7, 3,10, 5, 0},
	{15,12, 8, 2, 4, 9, 1, 7, 5,11, 3,14,10, 0, 6,13}
},
// S2
{
	{15, 1, 8,14, 6,11, 3, 4, 9, 7, 2,13,12, 0, 5,10},
	{ 3,13, 4, 7,15, 2, 8,14,12, 0, 1,10, 6, 9,11, 5},
	{ 0,14, 7,11,10, 4,13, 1, 5, 8,12, 6, 9, 3, 2,15},
	{13, 8,10, 1, 3,15, 4, 2,11, 6, 7,12, 0, 5,14, 9}
},
// S3
{
	{10, 0, 9,14, 6, 3,15, 5, 1,13,12, 7,11, 4, 2, 8},
	{13, 7, 0, 9, 3, 4, 6,10, 2, 8, 5,14,12,11,15, 1},
	{13, 6, 4, 9, 8,15, 3, 0,11, 1, 2,12, 5,10,14, 7},
	{1, 10,13, 0, 6, 9, 8, 7, 4,15,14, 3,11, 5, 2,12}
},
// S4
{
	{ 7,13,14, 3, 0, 6, 9,10, 1, 2, 8, 5,11,12, 4,15},
	{13, 8,11, 5, 6,15, 0, 3, 4, 7, 2,12, 1,10,14, 9},
	{10, 6, 9, 0,12,11, 7,13,15, 1, 3,14, 5, 2, 8, 4},
	{ 3,15, 0, 6,10, 1,13, 8, 9, 4, 5,11,12, 7, 2,14}
},

// S5
{
	{ 2,12, 4, 1, 7,10,11, 6, 8, 5, 3,15,13, 0,14, 9},
	{14,11, 2,12, 4, 7,13, 1, 5, 0,15,10, 3, 9, 8, 6},
	{ 4, 2, 1,11,10,13, 7, 8,15, 9,12, 5, 6, 3, 0,14},
	{11, 8,12, 7, 1,14, 2,13, 6,15, 0, 9,10, 4, 5, 3}
},

// S6
{
	{12, 1,10,15, 9, 2, 6, 8, 0,13, 3, 4,14, 7, 5,11},
	{10,15, 4, 2, 7,12, 9, 5, 6, 1,13,14, 0,11, 3, 8},
	{ 9,14,15, 5, 2, 8,12, 3, 7, 0, 4,10, 1,13,11, 6},
	{ 4, 3, 2,12, 9, 5,15,10,11,14, 1, 7, 6, 0, 8,13}
},

// S7
{
	{ 4,11, 2,14,15, 0, 8,13, 3,12, 9, 7, 5,10, 6, 1}, 
	{13, 0,11, 7, 4, 9, 1,10,14, 3, 5,12, 2,15, 8, 6}, 
	{ 1, 4,11,13,12, 3, 7,14,10,15, 6, 8, 0, 5, 9, 2}, 
	{ 6,11,13, 8, 1, 4,10, 7, 9, 5, 0,15,14, 2, 3, 12}
},

// S8
{
	{13, 2, 8, 4, 6,15,11, 1,10, 9, 3,14, 5, 0,12, 7},
	{ 1,15,13, 8,10, 3, 7, 4,12, 5, 6,11, 0,14, 9, 2},
	{ 7,11, 4, 1, 9,12,14, 2, 0, 6,10,13,15, 3, 5, 8},
	{ 2, 1,14, 7, 4,10, 8,13,15,12, 9, 0, 3, 5, 6,11}
}};

const byte PboxTab[32] = 
{
16, 7,20,21,29,12,28,17,
 1,15,23,26, 5,18,31,10,
 2, 8,24,14,32,27, 3, 9,
19,13,30, 6,22,11, 4,25
};

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

// Разбивка 64-битного блока на левую и правую половины по 32 бит
void SplitLR ( u32bit &L, u32bit &R, const u64bit in )
{
	u64bit temp = in;
	R = temp & 0xffffffff;
	temp >>= 32;
	L = temp & 0xffffffff;
}

// Слияние двух половинок 32 бит в 64-битный блок
void MergeLR ( u64bit &out, u32bit L, u32bit R )
{
	u64bit temp = 0;
	temp = L;
	temp <<= 32;
	temp += R;
	out = temp;
}

// P-блок 
void ExpandPermute ( u64bit &out, const u32bit in )
{
	u64bit y = 0;
	u32bit temp;

	// output_bin ( in );
	// cout << endl;

	int n = 48;
	for ( int i = 0; i < n; i++ )
	{
		y <<= 1;		
		temp = in;
		temp >>= 32 - EPTab[i];
		if ( temp&1 )
			y += 1;
	}
	out = y;	

	// output_bin ( out );
	// cout << endl;
}

// P-блок сжатия удаление битов четности
void ParDropPermute ( u64bit &out, const u64bit in )
{
	u64bit y = 0;
	u64bit temp;

	// cout << hex << setw(16) << setfill('0')
	// 	 << u64bit ( in ) << endl;	

	int n = 56;
	for ( int i = 0; i < 56; i++ )
	{
		// output_bin ( y );
		// cout << endl;	
		y <<= 1;		
		temp = in;
		temp >>= 64 - PDTab[i];
		if ( temp&1 )
			y += 1;
	}
	out = y;	
	
	// output_bin ( out );
	// cout << endl;

	// cout << hex << setw(16) << setfill('0')
	// 	 << u64bit ( out ) << endl;	
}

void CompressPermute ( u64bit &out, const u64bit in )
{
	u64bit y = 0;
	u64bit temp;

	cout << hex << setw(16) << setfill('0')
		<< u64bit ( in ) << endl;	
	
	// output_bin ( in );
	// cout << endl;

	int n = 48;
	for ( int i = 0; i < n ; i++ )
	{
		y <<= 1;		
		temp = in;
		temp >>= 56 - KeyPermTab[i];
		if ( temp&1 )
			y += 1;	
	}
	out = y;	
	
	cout << hex << setw(16) << setfill('0')
		 << u64bit ( out ) << endl;	

	// output_bin ( out );
	// cout << endl;
}

void SplitKeyCD ( u32bit &C, u32bit &D, const u64bit in )
{
	u64bit temp = in;
	D = temp & 0xfffffff;
	temp >>= 28;
	C = temp & 0xfffffff;
}

void MergeKeyCD ( u64bit &out, u32bit C, u32bit D )
{
	u64bit temp = 0;
	temp = C;
	temp <<= 28;
	temp += D;
	out = temp;
}

void ShiftLeft ( u32bit &x, int rot )
{
	// output_bin( x );
	// cout << endl;

	x = (x << rot) | (x >> ( 28 - rot));
	
	x &= 0x0fffffff;

	// output_bin( x );	
	// cout << endl;
}

// Round Key Generation
void KeyGen ( u64bit Key )
{
	u64bit T1;
	
	// output_bin ( Key );
	// cout << endl;

	ParDropPermute ( T1, Key );

	cout << hex << setw(16) << setfill('0')
		 << u64bit ( T1 ) << endl;	

	u32bit C, D;
	SplitKeyCD ( C, D, T1 );
	
	cout << endl << hex << setw(8) << setfill('0')
		 << u32bit ( C ) << " "
		 << hex << setw(8) << setfill('0') 
		 << u32bit ( D ) 
		 << endl;	

	for ( int i = 0; i < 16; i++ )
	{
		cout << "\nRound = " << dec << i+1 << endl;
	
		ShiftLeft ( C, ShiftKeyTab[i] );
		ShiftLeft ( D, ShiftKeyTab[i] );
		u64bit T2 = 0;
		MergeKeyCD ( T2, C, D );
		
		cout << endl << hex << setw(16) << setfill('0')
			 << u64bit ( T2 ) << endl;
		
		u64bit T3 = 0;
		CompressPermute ( T3, T2 );
		RoundKey[i] = T3;

		cout << "\nRound key =\n" 
			 << hex << setw(16) << setfill('0')
			 << u64bit ( RoundKey[i] ) << endl;
	}
}


// Разбивка 48-битного блока на 8 блоков по 6 бит
void SplitForSbox ( byte Sin[8], const u64bit x )
{
	u64bit temp = x;	
	for ( int i = 7; i >= 0; i-- )
	{
		Sin[i] = temp & 0x3f;
		temp >>= 6;
	}
}
// S-преобразование
void SubstSbox ( byte Sout[8], byte Sin[8] )
{
	for ( int i = 0; i < 8; i++ )
	{
		byte temp = Sin[i];
		// output_bin ( temp );
		// cout << endl;
		byte row = (temp&0x1) | ((temp & 0x20)>>4);
		byte col = (( temp & 0x1e ) >> 1);
		// cout << hex << int (row) << " " << int (col) << endl;
		Sout[i] = SboxTab[i][row][col];
		// cout << hex << int (Sout[i]) << endl;
	}
}

// Слияние полубайтов после S-преобразования
void MergeSemiBytes ( u32bit &out, byte sb[] )
{
	u32bit temp = 0;
	for ( int i = 0; i < 8; i++)
	{
		temp <<= 4;
		temp += sb[i];
	}
	out = temp;
}	

// Перестановка левой и правой половин блока
void SwapLR ( u32bit &L, u32bit &R )
{
	u32bit temp;
	temp = L;
	L = R;
	R = temp;
}

// Функция F
u32bit Function( u32bit &R, const u64bit Key )
{
	u64bit T1;
	// P-блок расширения
	int n = 48;
	ExpandPermute( T1, R );

	output_bin( T1 );
	cout << endl;

	// Отбеливатель, XOR расширенной правой части с ключом раунда
	T1 ^= Key;

	output_bin( T1 );
	cout << endl;

	byte Sin[8];
	// Подготовка данных для S-бокса
	// Разбиваем 48-битный блок на 8 кусков по 6 бит
	SplitForSbox ( Sin, T1 );

	/*
	for ( int i = 0; i < 8; i++ )
	{
		output_bin ( Sin[i] );
		cout << endl;
	}
	cout << endl;
	*/

	byte Sout[8];
	SubstSbox ( Sout, Sin );
	
	/*
	for (int i = 0; i < 8; i++)
		cout << hex << u32bit ( Sout[i] ) << " ";
	cout << endl;
	*/

	u32bit T2 = 0;
	MergeSemiBytes ( T2, Sout );
	
	cout << hex << setw(8) << setfill('0') 
		 << u32bit ( T2 ) << endl;
	
	u32bit T3;
	// P-преобразование, перестановка битов
	T3 = Permute( T2, PboxTab );

	return T3;
}

void Mixer ( u32bit &L, u32bit &R, u64bit Key )
{
	u32bit mask = Function( R, Key );

	cout << hex << setw(8) << setfill('0')
		 << u32bit ( L ) << " " 
		 << hex << setw(8) << setfill('0')
		 << u32bit ( mask ) << endl;

	//u32bit T4;
	L ^= mask;
	
	cout << hex << setw(8) << setfill('0')
		 << u32bit ( L ) << " " 
		 << hex << setw(8) << setfill('0')
		 << u32bit ( R ) << endl;
	// cout << hex << u32bit ( L ) << endl;
}


void EncryptDES ( u64bit &TC, u64bit TO )
{
	// u64bit RoundKey[16]  =	{0};

	// for ( int i = 0; i < 16; i++ )
	// 	RoundKey[i] = i * 100;

	u64bit T1;
	// Начальное P-преобразование
	T1 = Permute ( TO, IPTab );
	
	// Разделяем блок на левую L и правую R части
	u32bit L, R;
	SplitLR (L, R, T1);

	cout << hex << setw(8) << setfill('0') 
		 << u32bit ( L ) << " " 
		 << hex << setw(8) << setfill('0')
		 << u32bit ( R ) << endl;

	// output_bin( L );
	// cout << endl;
	// output_bin( R );
	// cout << endl;
	
	for ( int round = 0; round < 16; round++)
	{
		cout << dec << "\nRound = " << round+1 << endl;
		Mixer ( L, R, RoundKey[round] );
		
		//if ( round != 15 )
			SwapLR ( L, R );
		
		cout << endl;
		cout << hex << setw(8) << setfill('0')
			 << u32bit ( L ) << " "  
			 << hex << setw(8) << setfill('0')
			 << u32bit ( R ) << endl;	
	}

	/*
	cout << hex << setw(8) << setfill('0')
		 << u32bit ( L ) << " "  
		 << hex << setw(8) << setfill('0')
		 << u32bit ( R ) << endl;
	*/

	u64bit T2;
	// Слияние левой и правой 32-битных половинок
	MergeLR ( T2, L, R );
	
	// u64bit c4;
	// Конечное P-преобразование
	TC = Permute ( T2, FPTab );

	//cout << hex << setw(8) << setfill('0')
	//	 << u64bit ( TC ) << endl;
}

void DecryptDES ( u64bit &TD, u64bit TC )
{
	// u64bit RoundKey[16]  =	{0};	

	u64bit T1;
	T1 = Permute ( TC, IPTab );
	
	// Разделяем блок на левую L и правую R части
	u32bit L, R;
	SplitLR (L, R, T1);

	cout << hex << setw(8) << setfill('0') 
		 << u32bit ( L ) << " " 
		 << hex << setw(8) << setfill('0')
		 << u32bit ( R ) << endl;

	// output_bin( L );
	// cout << endl;
	// output_bin( R );
	// cout << endl;
	SwapLR ( L, R );	
	
	for ( int round = 0; round < 16; round++)
	{
		cout << dec << "\nRound = " << round+1 << endl;
		Mixer ( L, R, RoundKey[15-round] );
		if ( round != 15 )
			SwapLR ( L, R );
		cout << endl;
	}

	cout << hex << setw(8) << setfill('0')
		 << u32bit ( L ) << " "  
		 << hex << setw(8) << setfill('0')
		 << u32bit ( R ) << endl;
	
	u64bit T2;
	MergeLR ( T2, L, R );
	
	// u64bit c4;
	TD = Permute ( T2, FPTab );

	//cout << hex << setw(8) << setfill('0')
	//	 << u64bit ( TC ) << endl;
}
