#include <iostream>
#include <iomanip>
#include "util.h"
#include "aes.h"

using namespace std;
using namespace NTL;

int main()
{
	byte State[4][4];
	
	// byte OpenText[] = "AESUSESAMATRIXZZ";
	byte OpenData[BS] = {
		0x00,0x04,0x12,0x14,0x12,0x04,0x12,0x00,
		0x0c,0x00,0x13,0x11,0x08,0x23,0x19,0x19};

	// byte OpenData[BS] = { 0x00 };	
	byte EncData[BS];
	byte DecData[BS];

	
	byte Key[] = {
		0x24,0x75,0xa2,0xb3,0x34,0x75,0x56,0x88,
		0x31,0xe2,0x12,0x00,0x13,0xaa,0x54,0x87};

	// byte Key[] = {
	// 	0x12,0x45,0xa2,0xa1,0x23,0x31,0xa4,0xa3,
	//	0xb2,0xcc,0xab,0x34,0xc2,0xbb,0x77,0x23};
	// byte Key[16] = { 0x00 };

	cout << "\nOpen Data\n";
	for ( int i = 0; i < BS; i++ )
		cout << hex << setw(2)<< setfill('0')
			 << int ( OpenData[i] ) << " ";
	cout << endl;

	EncryptAES ( OpenData, EncData, Key );

	cout << "\nEncrypted Data\n";
	for ( int i = 0; i < BS; i++ )
		cout << hex << setw(2)<< setfill('0')
			 << int ( EncData[i] ) << " ";
	cout << endl;

	DecryptAES ( EncData, DecData, Key );

	cout << "\nDecrypted Data\n";
	for ( int i = 0; i < BS; i++ )
		cout << hex << setw(2)<< setfill('0')
			 << int ( DecData[i] ) << " ";
	cout << endl;

	return 0;
}