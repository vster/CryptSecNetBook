#include <iostream>
#include <iomanip>
// #include <NTL/ZZ.h>
// #include <NTL/GF2X.h>
#include <NTL/GF2E.h>
// #include <NTL/vector.h>
// #include <NTL/mat_GF2.h>
#include <NTL/mat_GF2E.h>
#include "util.h"

using namespace std;
using namespace NTL;

const long MAXB = 100;
const u32bit BS = 16;

const byte SubBytesTab[16][16] = {
	{0x63,0x7C,0x77,0x7B,0xF2,0x6B,0x6F,0xC5,0x30,0x01,0x67,0x2B,0xFE,0xD7,0xAB,0x76}, 
	{0xCA,0x82,0xC9,0x7D,0xFA,0x59,0x47,0xF0,0xAD,0xD4,0xA2,0xAF,0x9C,0xA4,0x72,0xC0}, 
	{0xB7,0xFD,0x93,0x26,0x36,0x3F,0xF7,0xCC,0x34,0xA5,0xE5,0xF1,0x71,0xD8,0x31,0x15},
	{0x04,0xC7,0x23,0xC3,0x18,0x96,0x05,0x9A,0x07,0x12,0x80,0xE2,0xEB,0x27,0xB2,0x75},
	{0x09,0x83,0x2C,0x1A,0x1B,0x6E,0x5A,0xA0,0x52,0x3B,0xD6,0xB3,0x29,0xE3,0x2F,0x84},
	{0x53,0xD1,0x00,0xED,0x20,0xFC,0xB1,0x5B,0x6A,0xCB,0xBE,0x39,0x4A,0x4C,0x58,0xCF},
	{0xD0,0xEF,0xAA,0xFB,0x43,0x4D,0x33,0x85,0x45,0xF9,0x02,0x7F,0x50,0x3C,0x9F,0xA8},
	{0x51,0xA3,0x40,0x8F,0x92,0x9D,0x38,0xF5,0xBC,0xB6,0xDA,0x21,0x10,0xFF,0xF3,0xD2},
	{0xCD,0x0C,0x13,0xEC,0x5F,0x97,0x44,0x17,0xC4,0xA7,0x7E,0x3D,0x64,0x5D,0x19,0x73},
	{0x60,0x81,0x4F,0xDC,0x22,0x2A,0x90,0x88,0x46,0xEE,0xB8,0x14,0xDE,0x5E,0x0B,0xDB},
	{0xE0,0x32,0x3A,0x0A,0x49,0x06,0x24,0x5C,0xC2,0xD3,0xAC,0x62,0x91,0x95,0xE4,0x79},
	{0xE7,0xC8,0x37,0x6D,0x8D,0xD5,0x4E,0xA9,0x6C,0x56,0xF4,0xEA,0x65,0x7A,0xAE,0x08},
	{0xBA,0x78,0x25,0x2E,0x1C,0xA6,0xB4,0xC6,0xE8,0xDD,0x74,0x1F,0x4B,0xBD,0x8B,0x8A},
	{0x70,0x3E,0xB5,0x66,0x48,0x03,0xF6,0x0E,0x61,0x35,0x57,0xB9,0x86,0xC1,0x1D,0x9E},
	{0xE1,0xF8,0x98,0x11,0x69,0xD9,0x8E,0x94,0x9B,0x1E,0x87,0xE9,0xCE,0x55,0x28,0xDF},
	{0x8C,0xA1,0x89,0x0D,0xBF,0xE6,0x42,0x68,0x41,0x99,0x2D,0x0F,0xB0,0x54,0xBB,0x16}
};

const byte InvSubBytesTab[16][16] = {
	{0x52,0x09,0x6A,0xD5,0x30,0x36,0xA5,0x38,0xBF,0x40,0xA3,0x9E,0x81,0xF3,0xD7,0xFB},
	{0x7C,0xE3,0x39,0x82,0x9B,0x2F,0xFF,0x87,0x34,0x8E,0x43,0x44,0xC4,0xDE,0xE9,0xCB},
	{0x54,0x7B,0x94,0x32,0xA6,0xC2,0x23,0x3D,0xEE,0x4C,0x95,0x0B,0x42,0xFA,0xC3,0x4E},
	{0x08,0x2E,0xA1,0x66,0x28,0xD9,0x24,0xB2,0x76,0x5B,0xA2,0x49,0x6D,0x8B,0xD1,0x25},
	{0x72,0xF8,0xF6,0x64,0x86,0x68,0x98,0x16,0xD4,0xA4,0x5C,0xCC,0x5D,0x65,0xB6,0x92},
	{0x6C,0x70,0x48,0x50,0xFD,0xED,0xB9,0xDA,0x5E,0x15,0x46,0x57,0xA7,0x8D,0x9D,0x84},
	{0x90,0xD8,0xAB,0x00,0x8C,0xBC,0xD3,0x0A,0xF7,0xE4,0x58,0x05,0xB8,0xB3,0x45,0x06},
	{0xD0,0x2C,0x1E,0x8F,0xCA,0x3F,0x0F,0x02,0xC1,0xAF,0xBD,0x03,0x01,0x13,0x8A,0x6B},
	{0x3A,0x91,0x11,0x41,0x4F,0x67,0xDC,0xEA,0x97,0xF2,0xCF,0xCE,0xF0,0xB4,0xE6,0x73},
	{0x96,0xAC,0x74,0x22,0xE7,0xAD,0x35,0x85,0xE2,0xF9,0x37,0xE8,0x1C,0x75,0xDF,0x6E},
	{0x47,0xF1,0x1A,0x71,0x1D,0x29,0xC5,0x89,0x6F,0xB7,0x62,0x0E,0xAA,0x18,0xBE,0x1B},
	{0xFC,0x56,0x3E,0x4B,0xC6,0xD2,0x79,0x20,0x9A,0xDB,0xC0,0xFE,0x78,0xCD,0x5A,0xF4},
	{0x1F,0xDD,0xA8,0x33,0x88,0x07,0xC7,0x31,0xB1,0x12,0x10,0x59,0x27,0x80,0xEC,0x5F},
	{0x60,0x51,0x7F,0xA9,0x19,0xB5,0x4A,0x0D,0x2D,0xE5,0x7A,0x9F,0x93,0xC9,0x9C,0xEF},
	{0xA0,0xE0,0x3B,0x4D,0xAE,0x2A,0xF5,0xB0,0xC8,0xEB,0xBB,0x3C,0x83,0x53,0x99,0x61},
	{0x17,0x2B,0x04,0x7E,0xBA,0x77,0xD6,0x26,0xE1,0x69,0x14,0x63,0x55,0x21,0x0C,0x7D}
};

const byte C0[4][4] = {
	{0x02,0x03,0x01,0x01},
	{0x01,0x02,0x03,0x01},
	{0x01,0x01,0x02,0x03},
	{0x03,0x01,0x01,0x02}
};

const u32bit RCon[10][4] = {
	{0x01,0x00,0x00,0x00},
	{0x02,0x00,0x00,0x00},
	{0x04,0x00,0x00,0x00},
	{0x08,0x00,0x00,0x00},
	{0x10,0x00,0x00,0x00},
	{0x20,0x00,0x00,0x00},
	{0x40,0x00,0x00,0x00},
	{0x80,0x00,0x00,0x00},
	{0x1b,0x00,0x00,0x00},
	{0x36,0x00,0x00,0x00}
};


void GF2XFromZZ( GF2X &x, ZZ &n )
{
	// const long MAXB = 10;
	byte buf[MAXB];

	BytesFromZZ( buf, n, MAXB );
	GF2XFromBytes(x, buf, MAXB);
	// cout << n << " " << x << endl;
}

GF2X GF2XFromZZ( ZZ &n )
{
	GF2X x;
	// const long MAXB = 10;
	byte buf[MAXB];

	BytesFromZZ( buf, n, MAXB );
	GF2XFromBytes(x, buf, MAXB);
	// cout << n << " " << x << endl;
	return x;
}

void ZZFromGF2X ( ZZ &n, GF2X &x )
{
	// const long MAXB = 10;
	byte buf[MAXB];

	BytesFromGF2X( buf, x, MAXB );
	ZZFromBytes( n, buf, MAXB );
}

ZZ ZZFromGF2X ( GF2X &x )
{
	ZZ n;
	// const long MAXB = 10;
	byte buf[MAXB];

	BytesFromGF2X( buf, x, MAXB );
	ZZFromBytes( n, buf, MAXB );
	return n;
}

void OutputState ( const byte in[4][4] )
{
	for ( u32bit i = 0; i < 4; i++ )
	{
		for ( u32bit j = 0; j < 4; j++ )
			cout << hex << setfill('0') << setw(2) 
				 << u16bit( in[i][j] ) << " ";
		cout << endl;
	}
	cout << endl;
}

void OutputRoundKeys ( const byte w[44][4] )
{
	for ( int i = 0; i < 44; i++ )
	{
		int round = i/4;
		if ( i%4 == 0 )
			cout << endl << setw(2) << setfill ('0')
				 << round << " ";
		else
			cout << " ";
		for ( int j = 0; j < 4; j++ )
				cout << hex << setw(2) << setfill ('0')
					 << int( w[i][j] );
	}
	cout << endl;

}

void CopyState ( byte out[4][4], byte in[4][4] )
{
	for ( u32bit i = 0; i < 4; i++ )
		for ( u32bit j = 0; j < 4; j++ )
			out[i][j] = in[i][j];
}

// �����������
void SubBytes ( byte out[4][4], const byte in[4][4] )
{
	for ( u32bit i = 0; i < 4; i++ )
		for ( u32bit j = 0; j < 4; j++ )
			out[i][j] = SubBytesTab[in[i][j]/256][in[i][j]%256];  

}

// �������� �����������
void InvSubBytes ( byte out[4][4], const byte in[4][4] )
{
	for ( u32bit i = 0; i < 4; i++ )
		for ( u32bit j = 0; j < 4; j++ )
			out[i][j] = InvSubBytesTab[in[i][j]/256][in[i][j]%256];  

}

// ������������
void ShiftOneRow ( byte x[4], int n )
{
	byte temp[4];
	for ( int i = 0; i < 4; i++ )
		temp[i] = x[i];
	for ( int i = 0; i < 4; i++ )
	{
		int s = (i+n)%4;
		if ( s < 0 )
			s +=4;
		x[i] = temp[s];	
	}
}

// ������������
void ShiftRows ( byte x[4][4] )
{
	for ( int i = 1; i < 4; i++ )	
		ShiftOneRow ( x[i], i );
}

// �������� ������������
void InvShiftRows ( byte x[4][4] )
{
	for ( int i = 1; i < 4; i++ )	
		ShiftOneRow ( x[i], -i );
}

// ����������
void MixColumns ( byte out[4][4], byte in[4][4] )
{
	ZZ p;
	p = 0x11b;
	
	GF2X Px;
	GF2XFromZZ ( Px, p );

	GF2E::init(Px);

	mat_GF2E A, B, C;

	A.SetDims(4,4);
	for ( int  i = 0; i < 4; i++ )
		for ( int j = 0; j < 4; j++)
		{
			GF2X tx = GF2XFromZZ ( conv<ZZ>(in[i][j]) );
			A[i][j] = conv<GF2E>( tx );
		}
	// cout << endl << A << endl;
	
	C.SetDims(4,4);
	for ( int  i = 0; i < 4; i++ )
		for ( int j = 0; j < 4; j++)
		{
			GF2X tx = GF2XFromZZ ( conv<ZZ>(C0[i][j]) );
			C[i][j] = conv<GF2E>( tx );
		}
	// cout << endl << C << endl;

	B = C * A;

	// cout << endl << B << endl;

	for ( int  i = 0; i < 4; i++ )
		for ( int j = 0; j < 4; j++)
		{
			GF2X tx = conv<GF2X>( B[i][j] );
			out[i][j] =  (byte) conv <long> ( ZZFromGF2X( tx ) );
		}
}
// �������� ����������
void InvMixColumns ( byte out[4][4], byte in[4][4] )
{
	ZZ p;
	p = 0x11b;
	
	GF2X Px;
	GF2XFromZZ ( Px, p );

	GF2E::init(Px);

	mat_GF2E A, B, C;

	A.SetDims(4,4);
	for ( int  i = 0; i < 4; i++ )
		for ( int j = 0; j < 4; j++)
		{
			GF2X tx = GF2XFromZZ ( conv<ZZ>(in[i][j]) );
			A[i][j] = conv<GF2E>( tx );
		}
	// cout << endl << A << endl;
	
	C.SetDims(4,4);
	for ( int  i = 0; i < 4; i++ )
		for ( int j = 0; j < 4; j++)
		{
			GF2X tx = GF2XFromZZ ( conv<ZZ>(C0[i][j]) );
			C[i][j] = conv<GF2E>( tx );
		}
	// cout << endl << C << endl;

	mat_GF2E InvC;

	InvC = inv ( C );

	// cout << endl << InvC << endl;
	
	B = InvC * A;

	// cout << endl << B << endl;

	for ( int  i = 0; i < 4; i++ )
		for ( int j = 0; j < 4; j++)
		{
			GF2X tx = conv<GF2X>( B[i][j] );
			out[i][j] =  (byte) conv <long> ( ZZFromGF2X( tx ) );
		}
}

void AddRoundKey ( byte in[4][4], byte w[44][4], int round )
{
	byte RoundKey[4][4];
	
	for ( u32bit i = 0; i < 4; i++ )
		for ( u32bit j = 0; j < 4; j++ )
			RoundKey[j][i] = w[4*round+i][j];

	cout << "\nRoundKey\n";
	OutputState ( RoundKey );

	for ( u32bit i = 0; i < 4; i++ )
		for ( u32bit j = 0; j < 4; j++ )
			in[i][j] ^= RoundKey[i][j];
}

void InvAddRoundKey ( byte in[4][4], byte w[44][4], int round )
{
	byte RoundKey[4][4];
	
	for ( u32bit i = 0; i < 4; i++ )
		for ( u32bit j = 0; j < 4; j++ )
			RoundKey[j][i] = w[4*(10-round)+i][j];

	cout << "\nRoundKey\n";
	OutputState ( RoundKey );

	for ( u32bit i = 0; i < 4; i++ )
		for ( u32bit j = 0; j < 4; j++ )
			in[i][j] ^= RoundKey[i][j];
}


void GenT ( byte t[4], byte in[4], int round )
{
	for ( int j = 0; j < 4; j++ )
		t[j] = in[j];

	// �������� �� 1 ����
	ShiftOneRow ( t, 1 );

	// �����������
	for ( u32bit j = 0; j < 4; j++ )
			t[j] = SubBytesTab[t[j]/256][t[j]%256];

	// ���������� � ���������� (���� � ������ ������)
	for ( u32bit j = 0; j < 4; j++ )
		t[j] ^= RCon[round-1][j];
}

void GenRoundKeys ( byte w[44][4], byte Key[] )
{
	for ( int i = 0; i < 4; i++ )
		for ( int j = 0; j < 4; j++ )
			w[i][j] = Key[4*i + j];

	for ( int round = 1; round < 11; round++ )
	{
		byte t[4];		
		GenT ( t, w[4*round-1], round );
		
		for ( int j = 0; j < 4; j++ )
			w[4*round][j] = t[j]^w[4*round-4][j];

 		for ( int i = 1; i < 4; i++ )
			for ( int j = 0; j < 4; j++ )
				w[4*round+i][j] = w[4*round+i-1][j]^w[4*round+i-4][j];		
	}
}

void Round ( byte State[4][4], byte w[44][4], int round )
{
	cout << "Round " << round << endl;
	cout << "\nStart Round State\n";
	OutputState ( State );

	// �����������
	byte State1[4][4];
	SubBytes( State1, State );
	
	// cout << "\nSubBytes\n";
	// OutputState ( State1 );
	
	// ������������
	ShiftRows ( State1 );

	// cout << "\nShiftRows\n";
	// OutputState ( State1 );

	if ( round != 10 )
	{
		// ����������
		// byte State2[4][4];
		MixColumns ( State, State1 );

		// cout << "\nMixColumns\n";
		OutputState ( State );
	}
	else
		CopyState ( State, State1 );

	// ���������� ������
	// int round = 0;
	AddRoundKey ( State, w, round );

	cout << "\nFinish Round State\n";
	OutputState ( State );
}

void InvRound ( byte State[4][4], byte w[44][4], int round )
{

	cout << "InvRound " << round << endl;

	cout << "\nStart Round State\n";
	OutputState ( State );
	
	// ������������
	InvShiftRows ( State );

	// cout << "\nInvShiftRows\n";
	// OutputState ( State );

	// �����������
	byte State1[4][4];
	InvSubBytes( State1, State );
	
	cout << "\nInvSubBytes\n";
	OutputState ( State1 );

	// ���������� ������
	// int round = 0;
	InvAddRoundKey ( State1, w, round );

	if ( round != 10 )
	{
		// ����������
		// byte State2[4][4];
		InvMixColumns ( State, State1 );

		// cout << "\nMixColumns\n";
		// OutputState ( State );
	}
	else
		CopyState ( State, State1 );

	cout << "\nFinish InvRound State\n";
	OutputState ( State );

}


void EncryptAES ( byte InBlock[16], byte OutBlock[16], byte Key[] )
{
	byte State[4][4];
	byte w[44][4];
	
	GenRoundKeys ( w, Key );
		
	// cout << "\nRound Keys\n";
	// OutputRoundKeys ( w );

	for ( u32bit i = 0, k = 0; i < 4; i++ )
		for ( u32bit j = 0; j < 4; j++ )
			State[j][i] = InBlock[k++];

	cout << "\nInitial Matrix\n";
	OutputState ( State );

	int round = 0;
	AddRoundKey ( State, w, round );

	cout << "\nRound 0\n";
	OutputState ( State );

	for ( round = 1; round < 11; round++)
		Round ( State, w, round );

	for ( u32bit i = 0, k = 0; i < 4; i++ )
		for ( u32bit j = 0; j < 4; j++ )
			OutBlock[k++] = State[j][i];
}

void DecryptAES ( byte InBlock[16], byte OutBlock[16], byte Key[] )
{
	byte State[4][4];
	byte w[44][4];
	
	GenRoundKeys ( w, Key );

	// cout << "\nRound Keys\n";
	// OutputRoundKeys ( w );

	for ( u32bit i = 0, k = 0; i < 4; i++ )
		for ( u32bit j = 0; j < 4; j++ )
			State[j][i] = InBlock[k++];

	cout << "\nInitial Matrix\n";
	OutputState ( State );

	// ���������� ������
	int round = 0;
	InvAddRoundKey ( State, w, round );

	cout << "\nRound 0\n";
	OutputState ( State );

	for ( round = 1; round < 11; round++)
		InvRound ( State, w, round );	
	
	/*
	cout << "\nAddKeys\n";
	OutputState ( State );
	
	// �������� ����������
	byte State1[4][4];
	InvMixColumns ( State1, State );

	cout << "\nInvMixColumns\n";
	OutputState ( State1 );

	// �������� ������������
	InvShiftRows ( State1 );

	cout << "\nInvShiftRows\n";
	OutputState ( State1 );

	// �������� �����������
	byte State2[4][4];
	InvSubBytes( State2, State1 );

	cout << "\nInvSubBytes\n";
	OutputState ( State2 );
	*/

	for ( u32bit i = 0, k = 0; i < 4; i++ )
		for ( u32bit j = 0; j < 4; j++ )
			OutBlock[k++] = State[j][i];
}

int main()
{
	byte State[4][4];
	
	// byte OpenText[] = "AESUSESAMATRIXZZ";
	byte OpenData[BS] = {
		0x00,0x04,0x12,0x14,0x12,0x04,0x12,0x00,
		0x0c,0x00,0x13,0x11,0x08,0x23,0x19,0x19};

	byte EncData[BS];
	byte DecData[BS];

	
	byte Key[] = {
		0x24,0x75,0xa2,0xb3,0x34,0x75,0x56,0x88,
		0x31,0xe2,0x12,0x00,0x13,0xaa,0x54,0x87};

	// byte Key[] = {
	// 	0x12,0x45,0xa2,0xa1,0x23,0x31,0xa4,0xa3,
	//	0xb2,0xcc,0xab,0x34,0xc2,0xbb,0x77,0x23};
	// byte Key[16] = { 0x00 };

	for ( int i = 0; i < BS; i++ )
		cout << hex << setw(2)<< setfill('0')
			 << int ( OpenData[i] ) << " ";
	cout << endl;

	EncryptAES ( OpenData, EncData, Key );

	for ( int i = 0; i < BS; i++ )
		cout << hex << setw(2)<< setfill('0')
			 << int ( EncData[i] ) << " ";
	cout << endl;

	DecryptAES ( EncData, DecData, Key );

	for ( int i = 0; i < BS; i++ )
		cout << hex << setw(2)<< setfill('0')
			 << int ( DecData[i] ) << " ";
	cout << endl;

	return 0;
}