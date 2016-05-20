#include <iostream>
#include "util.h"
#include "gost.h"

const byte K[8][16] = {
{0x4,0x2,0xf,0x5,0x9,0x1,0x0,0x8,0xe,0x3,0xb,0xc,0xd,0x7,0xa,0x6},		//1
{0xc,0x9,0xf,0xe,0x8,0x1,0x3,0xa,0x2,0x7,0x4,0xd,0x6,0x0,0xb,0x5},		//2		
{0xd,0x8,0xe,0xc,0x7,0x3,0x9,0xa,0x1,0x5,0x2,0x4,0x6,0xf,0x0,0xb},		//3
{0xe,0x9,0xb,0x2,0x5,0xf,0x7,0x1,0x0,0xd,0xc,0x6,0xa,0x4,0x3,0x8},		//4
{0x3,0xe,0x5,0x9,0x6,0x8,0x0,0xd,0xa,0xb,0x7,0xc,0x2,0x1,0xf,0x4},		//5
{0x8,0xf,0x6,0xb,0x1,0x9,0xc,0x5,0xd,0x3,0x7,0xa,0x0,0xe,0x2,0x4},		//6
{0x9,0xb,0xc,0x0,0x3,0x6,0x7,0x5,0x4,0x8,0xe,0xf,0x1,0xa,0x2,0xd},		//7
{0xc,0x6,0x5,0x2,0xb,0x0,0x9,0xd,0x3,0xe,0x7,0xa,0xf,0x4,0x1,0x8}		//8
};

// Разбивка блока на 8 кусков по 4 бита
// для подачи на вход в S-box
void SplitForSbox ( byte Sin[8], u32bit N1 )
{
	u32bit temp;
	temp = N1;
	for ( int i = 0; i < 8; i++ )
	{
		Sin[i] = temp&0xf;
		temp >>= 4;
	}
}
// Сборка блока из 8-ми полубайтов, 
// полученных на выходе S-box
void MergeAfterSbox ( u32bit &out, byte Sout[8] )
{
	u32bit temp = 0;
	for ( int i = 7; i >=0; i-- )
	{
		temp <<= 4;		
		temp += Sout[i];
	}
	out = temp;
}

// Меняем N1 и N2 местами
void SwapN12 ( u32bit &N1, u32bit &N2 )
{
	u32bit temp;
	temp = N1;
	N1 = N2;
	N2 = temp;
}
 
void Round ( u32bit &N1, u32bit &N2, const u32bit Key )
{
	u32bit T1 = N1;
	
	// Сложение с ключом
	T1 += Key;

	// S-Преобразование
	byte Sin[8], Sout[8];
	SplitForSbox ( Sin, T1 );
	
	for ( int i = 0; i < 8; i++ )
		Sout[i] = K[i][Sin[i]];

	u32bit T2;
	MergeAfterSbox ( T2, Sout );
	
	// Поворот влево на 11 -бит
	T2 = rotate_left ( T2, 11 );
	
	// Накладываем полученную маску на N2
	N2 ^= T2;

	// Меняем блоки местами
	SwapN12 ( N1, N2 );
	// cout << hex << u32bit( N1 ) << " " << u32bit( N2 ) << endl; 
}

void Encrypt(const byte in[BS], byte out[BS], byte key[KL])
{
	u32bit N1, N2;
	N1 = make_u32bit(in[3], in[2], in[1], in[0]);
    N2 = make_u32bit(in[7], in[6], in[5], in[4]);

	u32bit EK[8];
	for (int j = 0; j < 8; j++)
		EK[j] = make_u32bit(key[4*j+3], key[4*j+2], 
							key[4*j+1], key[4*j]);
	
	for ( int i = 0; i < 8; i++)
		Round ( N1, N2, EK[i] );
	for ( int i = 0; i < 8; i++)
		Round ( N1, N2, EK[i] );
	for ( int i = 0; i < 8; i++)
		Round ( N1, N2, EK[i] );
	for ( int i = 0; i < 8; i++)
		Round ( N1, N2, EK[7-i] );

	out[0] = get_byte(3, N2); out[1] = get_byte(2, N2);
	out[2] = get_byte(1, N2); out[3] = get_byte(0, N2);
	out[4] = get_byte(3, N1); out[5] = get_byte(2, N1);
	out[6] = get_byte(1, N1); out[7] = get_byte(0, N1);
}

void Decrypt(const byte in[BS], byte out[BS], byte key[KL])
{
	u32bit N1, N2;
	N1 = make_u32bit(in[3], in[2], in[1], in[0]);
    N2 = make_u32bit(in[7], in[6], in[5], in[4]);

	u32bit EK[8];
	for (int j = 0; j < 8; j++)
		EK[j] = make_u32bit(key[4*j+3], key[4*j+2], 
							key[4*j+1], key[4*j]);
	
	for ( int i = 0; i < 8; i++)
		Round ( N1, N2, EK[i] );
	for ( int i = 0; i < 8; i++)
		Round ( N1, N2, EK[7-i] );
	for ( int i = 0; i < 8; i++)
		Round ( N1, N2, EK[7-i] );
	for ( int i = 0; i < 8; i++)
		Round ( N1, N2, EK[7-i] );

	out[0] = get_byte(3, N2); out[1] = get_byte(2, N2);
	out[2] = get_byte(1, N2); out[3] = get_byte(0, N2);
	out[4] = get_byte(3, N1); out[5] = get_byte(2, N1);
	out[6] = get_byte(1, N1); out[7] = get_byte(0, N1);
}

