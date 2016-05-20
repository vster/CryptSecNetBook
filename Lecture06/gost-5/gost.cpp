#include <iostream>
#include "util.h"
#include "gost.h"

const char* OID[6] = {
"1.2.643.2.2.31.0",
"1.2.643.2.2.31.1",
"1.2.643.2.2.31.2",
"1.2.643.2.2.31.3",
"1.2.643.2.2.31.4",
"1.2.643.7.1.2.5.1.1"};

const byte K[6][8][16] = 	{
// S-����� �� ����������� ������ ���� 28147-89
// OID 1.2.643.2.2.31.0

{
{0x4,0x2,0xf,0x5,0x9,0x1,0x0,0x8,0xe,0x3,0xb,0xc,0xd,0x7,0xa,0x6},		//1
{0xc,0x9,0xf,0xe,0x8,0x1,0x3,0xa,0x2,0x7,0x4,0xd,0x6,0x0,0xb,0x5},		//2		
{0xd,0x8,0xe,0xc,0x7,0x3,0x9,0xa,0x1,0x5,0x2,0x4,0x6,0xf,0x0,0xb},		//3
{0xe,0x9,0xb,0x2,0x5,0xf,0x7,0x1,0x0,0xd,0xc,0x6,0xa,0x4,0x3,0x8},		//4
{0x3,0xe,0x5,0x9,0x6,0x8,0x0,0xd,0xa,0xb,0x7,0xc,0x2,0x1,0xf,0x4},		//5
{0x8,0xf,0x6,0xb,0x1,0x9,0xc,0x5,0xd,0x3,0x7,0xa,0x0,0xe,0x2,0x4},		//6
{0x9,0xb,0xc,0x0,0x3,0x6,0x7,0x5,0x4,0x8,0xe,0xf,0x1,0xa,0x2,0xd},		//7
{0xc,0x6,0x5,0x2,0xb,0x0,0x9,0xd,0x3,0xe,0x7,0xa,0xf,0x4,0x1,0x8}		//8
},

// ����� ����� �� RFC 4357
// OID 1.2.643.2.2.31.1
// id-Gost28147-89-CryptoPro-A-ParamSet
{
{0x9,0x6,0x3,0x2,0x8,0xB,0x1,0x7,0xA,0x4,0xE,0xF,0xC,0x0,0xD,0x5},		//1
{0x3,0x7,0xE,0x9,0x8,0xA,0xF,0x0,0x5,0x2,0x6,0xC,0xB,0x4,0xD,0x1},		//2
{0xE,0x4,0x6,0x2,0xB,0x3,0xD,0x8,0xC,0xF,0x5,0xA,0x0,0x7,0x1,0x9},		//3
{0xE,0x7,0xA,0xC,0xD,0x1,0x3,0x9,0x0,0x2,0xB,0x4,0xF,0x8,0x5,0x6},		//4
{0xB,0x5,0x1,0x9,0x8,0xD,0xF,0x0,0xE,0x4,0x2,0x3,0xC,0x7,0xA,0x6},		//5
{0x3,0xA,0xD,0xC,0x1,0x2,0x0,0xB,0x7,0x5,0x9,0x4,0x8,0xF,0xE,0x6},		//6
{0x1,0xD,0x2,0x9,0x7,0xA,0x6,0x0,0x8,0xC,0x4,0x5,0xF,0x3,0xB,0xE},		//7
{0xB,0xA,0xF,0x5,0x0,0xC,0xE,0x8,0x6,0x2,0x3,0x9,0x1,0x7,0xD,0x4}		//8
},

// ����� ����� �� RFC 4357
// OID 1.2.643.2.2.31.2
// id-Gost28147-89-CryptoPro-B-ParamSet
{
{0x8,0x4,0xb,0x1,0x3,0x5,0x0,0x9,0x2,0xe,0xa,0xc,0xd,0x6,0x7,0xf},		//1
{0x0,0x1,0x2,0xa,0x4,0xd,0x5,0xc,0x9,0x7,0x3,0xf,0xb,0x8,0x6,0xe},		//2
{0xe,0xc,0x0,0xa,0x9,0x2,0xd,0xb,0x7,0x5,0x8,0xf,0x3,0x6,0x1,0x4},		//3
{0x7,0x5,0x0,0xd,0xb,0x6,0x1,0x2,0x3,0xa,0xc,0xf,0x4,0xe,0x9,0x8},		//4
{0x2,0x7,0xc,0xf,0x9,0x5,0xa,0xb,0x1,0x4,0x0,0xd,0x6,0x8,0xe,0x3},		//5
{0x8,0x3,0x2,0x6,0x4,0xd,0xe,0xb,0xc,0x1,0x7,0xf,0xa,0x0,0x9,0x5},		//6
{0x5,0x2,0xa,0xb,0x9,0x1,0xc,0x3,0x7,0x4,0xd,0x0,0x6,0xf,0x8,0xe},		//7
{0x0,0x4,0xb,0xe,0x8,0x3,0x7,0x1,0xa,0x2,0x9,0x6,0xf,0xd,0x5,0xc}		//8
},

// ����� ����� �� RFC 4357
// OID 1.2.643.2.2.31.3
// id-Gost28147-89-CryptoPro-C-ParamSet
{
{0x1,0xb,0xc,0x2,0x9,0xd,0x0,0xf,0x4,0x5,0x8,0xe,0xa,0x7,0x6,0x3},		//1
{0x0,0x1,0x7,0xd,0xb,0x4,0x5,0x2,0x8,0xe,0xf,0xc,0x9,0xa,0x6,0x3},		//2
{0x8,0x2,0x5,0x0,0x4,0x9,0xf,0xa,0x3,0x7,0xc,0xd,0x6,0xe,0x1,0xb},		//3	
{0x3,0x6,0x0,0x1,0x5,0xd,0xa,0x8,0xb,0x2,0x9,0x7,0xe,0xf,0xc,0x4},		//4
{0x8,0xd,0xb,0x0,0x4,0x5,0x1,0x2,0x9,0x3,0xc,0xe,0x6,0xf,0xa,0x7},		//5
{0xc,0x9,0xb,0x1,0x8,0xe,0x2,0x4,0x7,0x3,0x6,0x5,0xa,0x0,0xf,0xd},		//6
{0xa,0x9,0x6,0x8,0xd,0xe,0x2,0x0,0xf,0x3,0x5,0xb,0x4,0x1,0xc,0x7},		//7
{0x7,0x4,0x0,0x5,0xa,0x2,0xf,0xe,0xc,0x6,0x1,0xb,0xd,0x9,0x3,0x8}		//8
},

// ����� ����� �� RFC 4357
// OID 1.2.643.2.2.31.4
// id-Gost28147-89-CryptoPro-D-ParamSet
{
{0xf,0xc,0x2,0xa,0x6,0x4,0x5,0x0,0x7,0x9,0xe,0xd,0x1,0xb,0x8,0x3},		//1
{0xb,0x6,0x3,0x4,0xc,0xf,0xe,0x2,0x7,0xd,0x8,0x0,0x5,0xa,0x9,0x1},		//2
{0x1,0xc,0xb,0x0,0xf,0xe,0x6,0x5,0xa,0xd,0x4,0x8,0x9,0x3,0x7,0x2},		//3
{0x1,0x5,0xe,0xc,0xa,0x7,0x0,0xd,0x6,0x2,0xb,0x4,0x9,0x3,0xf,0x8},		//4
{0x0,0xc,0x8,0x9,0xd,0x2,0xa,0xb,0x7,0x3,0x6,0x5,0x4,0xe,0xf,0x1},		//5
{0x8,0x0,0xf,0x3,0x2,0x5,0xe,0xb,0x1,0xa,0x4,0x7,0xc,0x9,0xd,0x6},		//6
{0x3,0x0,0x6,0xf,0x1,0xe,0x9,0x2,0xd,0x8,0xc,0x4,0xb,0xa,0x5,0x7},		//7
{0x1,0xa,0x6,0x8,0xf,0xb,0x0,0x4,0xc,0x3,0x5,0x9,0x7,0xd,0x2,0xe}		//8
},

// S-����� �� ��������������� ��26 ������� 2
// OID 1.2.643.7.1.2.5.1.1
{
{0xc,0x4,0x6,0x2,0xa,0x5,0xb,0x9,0xe,0x8,0xd,0x7,0x0,0x3,0xf,0x1},		//1
{0x6,0x8,0x2,0x3,0x9,0xa,0x5,0xc,0x1,0xe,0x4,0x7,0xb,0xd,0x0,0xf},		//2
{0xb,0x3,0x5,0x8,0x2,0xf,0xa,0xd,0xe,0x1,0x7,0x4,0xc,0x9,0x6,0x0},		//3
{0xc,0x8,0x2,0x1,0xd,0x4,0xf,0x6,0x7,0x0,0xa,0x5,0x3,0xe,0x9,0xb},		//4
{0x7,0xf,0x5,0xa,0x8,0x1,0x6,0xd,0x0,0x9,0x3,0xe,0xb,0x4,0x2,0xc},		//5
{0x5,0xd,0xf,0x6,0x9,0x2,0xc,0xa,0xb,0x7,0x8,0x1,0x4,0x3,0xe,0x0},		//6
{0x8,0xe,0x2,0x5,0x6,0x9,0x1,0xc,0xf,0x4,0xb,0x0,0xd,0xa,0x3,0x7},		//7
{0x1,0x7,0xe,0xd,0x0,0x5,0x8,0x3,0x4,0xf,0xa,0x6,0x9,0xc,0xb,0x2}		//8
}};	

byte SBOX[8][16];
u32bit EK[8];

// ���������� ������� �����
void generate_sbox ( int oidnum )
{
	for ( int i = 0; i < 8; i++)
		for ( int j = 0; j < 16; j++)
			SBOX[i][j] = K[oidnum][i][j];
}

// ���������� ��������� ������
void set_key ( const byte key[] )
{
	for (int j = 0; j < 8; j++)
		EK[j] = make_u32bit(key[4*j+3], key[4*j+2], 
							key[4*j+1], key[4*j]);
}

// �������� ����� �� 8 ������ �� 4 ����
// ��� ������ �� ���� � S-box
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
// ������ ����� �� 8-�� ����������, 
// ���������� �� ������ S-box
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

// ������ N1 � N2 �������
void SwapN12 ( u32bit &N1, u32bit &N2 )
{
	u32bit temp;
	temp = N1;
	N1 = N2;
	N2 = temp;
}
 
void Round ( u32bit &N1, u32bit &N2, u32bit Key  )
{
	u32bit T1 = N1;
	
	// �������� � ������
	T1 += Key;

	// S-��������������
	byte Sin[8], Sout[8];
	SplitForSbox ( Sin, T1 );
	
	for ( int i = 0; i < 8; i++ )
		Sout[i] = SBOX[i][Sin[i]];

	u32bit T2;
	MergeAfterSbox ( T2, Sout );
	
	// ������� ����� �� 11 ���
	T2 = rotate_left ( T2, 11 );
	
	// ����������� ���������� ����� �� N2
	N2 ^= T2;

	// ������ ����� �������
	SwapN12 ( N1, N2 );
	// cout << hex << u32bit( N1 ) << " " << u32bit( N2 ) << endl; 
}

void Encrypt(const byte in[BS], byte out[BS] )
{
	u32bit N1, N2;
	N1 = make_u32bit(in[3], in[2], in[1], in[0]);
    N2 = make_u32bit(in[7], in[6], in[5], in[4]);

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

void Decrypt(const byte in[BS], byte out[BS] )
{
	u32bit N1, N2;
	N1 = make_u32bit(in[3], in[2], in[1], in[0]);
    N2 = make_u32bit(in[7], in[6], in[5], in[4]);

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

void Encrypt16(const byte in[BS], byte out[BS] )
{
	u32bit N1, N2;
	N1 = make_u32bit(in[3], in[2], in[1], in[0]);
    N2 = make_u32bit(in[7], in[6], in[5], in[4]);

	for ( int i = 0; i < 8; i++)
		Round ( N1, N2, EK[i] );
	for ( int i = 0; i < 8; i++)
		Round ( N1, N2, EK[i] );

   out[0] = get_byte(3, N1); out[1] = get_byte(2, N1);
   out[2] = get_byte(1, N1); out[3] = get_byte(0, N1);
   out[4] = get_byte(3, N2); out[5] = get_byte(2, N2);
   out[6] = get_byte(1, N2); out[7] = get_byte(0, N2);
}