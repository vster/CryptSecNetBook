#include <iostream>
#include <iomanip>
#include <string>
#include "util.h"

using namespace std;

byte KeyArr[8] = { 0x01, 0x02, 0x03, 0x04, 0x5, 0x6, 0x7, 0x8 };

void SplitLR ( byte &L, byte &R, const u16bit x )
{
	u16bit temp = x;
	R = temp & 0xff;
	temp >>= 8;
	L = temp & 0xff;
}

void SwapLR ( byte &L, byte &R )
{
	byte temp;
	temp = L;
	L = R;
	R = temp;
}


byte F( byte fin, byte key )
{
	byte fout; 
	fout = ( fin + key ) % 256;
	
	return fout;
}

void EncRound ( byte &L, byte &R, byte key )
{
	byte T1;
	T1 = F( R, key );

	T1 = rotate_left ( T1, 3 );

	L ^= T1;

	SwapLR ( L, R );
}

void DecRound ( byte &L, byte &R, byte key )
{
	byte T1;
	SwapLR ( L, R );

	T1 = F( R, key );
	
	T1 = rotate_left ( T1, 3 );

	L ^= T1;
}

int main()
{
	u16bit TO = 0x1234; 
	byte mask = 0xff;
	byte L, R, key;

	L = R = 0;
	SplitLR ( L, R, TO );

	cout << hex << setw(2) << int (L) << " " << int (R) << endl << endl ;
	
	int rnum = 8;

	for ( int i = 0; i < rnum; i++)
	{
		key = KeyArr[i];
		EncRound ( L, R, key );
		cout << hex << setw(2) << int (L) << " " << int (R) << endl;
	}
	cout << endl;

	for ( int i = 0; i < rnum; i++)
	{
		key = KeyArr[rnum-i-1];
		DecRound ( L, R, key  );
		cout << hex << setw(2) << int (L) << " " << int (R) << endl;
	}

	return 0;
}