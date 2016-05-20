#include <iostream>
#include <string>
#include "util.h"

using namespace std;


byte Key[2] = { 0x00, 0x00};

byte SBox[2][2] = 
{
	{1,0},
	{0,1}
};

// int KeyPermute[8] = {1,2,3,4,5,6,7,8};
int KeyPermute[8] = {8,7,6,5,4,3,2,1};

void Subst ( byte out[], byte in[] )
{
	for ( int i = 0; i < 2; i++ )
		for ( int j = 0; j < 2; j++)
		{
			out[i] += in[j]*SBox[i][j];
			out[i] %= 2;
		}	
}

template<typename T>
T Permute( T x )
{
	T y = 0;
	T temp;

	int n = 8 * sizeof( T );
	for ( int i = n-1; i>=0; i-- )
	{
		y <<= 1;		
		temp = x;
		temp >>= KeyPermute[i]-1;
		if ( temp&1 )
			y += 1;
	}
	return y;
}

void output_le ( byte x )
{
	// byte bit;
	for ( int i = 0; i < 8; i++ )
	{
		cout << int ( x&1 ) << " ";
		x >>= 1;
	}
}

byte Round ( byte in )
{
	byte T1 = ( in + Key[0] ) % 256;

	output_le ( T1 );
	cout << endl;

	byte Sin[4][2] = {0x0}, Sout[4][2] = {0x0};
	// byte temp = T1;
	for ( int i = 0; i < 4; i++)
		for ( int j = 0; j < 2; j++)
		{
			Sin[i][j] = T1 & 1;
			T1 >>= 1;
		}
	
	for ( int i = 0; i < 4; i++)
	{
		for ( int j = 0; j < 2; j++)
			cout << int (Sin[i][j]) << " ";
		cout << endl;
	}

	for ( int i = 0; i < 4; i++)
		Subst ( Sout[i], Sin[i] );

	byte T2 = 0;
	for ( int i = 3; i >= 0; i-- )
		for ( int j = 1; j >= 0; j-- )
		{
			T2 <<= 1;			
			T2 += Sout[i][j];
		}

	output_le ( T2 );
	cout << endl;

	byte T3 = Permute ( T2 );

	output_le ( T3 );
	cout << endl;

	return T3;
}

int main()
{
	byte TO = 0x3e;
	byte rout;

	byte rin = TO;
	for ( int i = 0; i < 2; i++ )
	{
		rout = Round ( rin );
		rin = rout;
		cout << endl;
	}
	output_le ( rout );	
}