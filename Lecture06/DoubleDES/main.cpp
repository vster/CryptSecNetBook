#include <iostream>
#include <iomanip>
#include <string>
#include "util.h"
#include "des.h"

using namespace std;
// const int MAXW = 64;


int main()
 {
	u64bit OpenData =			0x123456abcd132536;
	u64bit EncData;
	u64bit DecData;

	u64bit Key1 = 0xAABB09182736CCDD;
	u64bit Key2 = 0x1111111111111111;

	// u64bit Key = 0x0123456789abcdef;
	// Слабые ключи
	// u64bit Key = 0x0101010101010101;
	// u64bit Key = 0x1f1f1f1f1f1f1f1f;
	// u64bit Key = 0xe0e0e0e0e0e0e0e0;
	// u64bit Key = 0xfefefefefefefefe;
	// Полуслабые ключи
	// u64bit Key = 0x01fe01fe01fe01fe;
	// u64bit Key = 0xfe01fe01fe01fe01;
	// u64bit Key = 0x1fe01fe00ef10ef1;


	cout << hex << setw(16) << setfill('0')
		 << u64bit ( Key1 ) << endl;	
	
	KeyGen ( Key1 );

	// Подготовить ключи для каждого раунда
	// for ( int i = 0; i < 16; i++ )
	//  	RoundKey[i] = i * 100;

	// output_bin( a4 );
	cout << "\n\nOpen data = \n";
	cout << hex << setw(16) << setfill('0')
		 << u64bit ( OpenData ) << endl;
	// cout << endl;
	
	cout << "\nEncryption...\n";

	EncryptDES ( EncData, OpenData );

	cout << endl;
	cout << hex << setw(16) << setfill('0')
		 << u64bit ( EncData ) << endl;

	KeyGen ( Key2 );

	EncryptDES ( EncData, EncData );


	cout << "\nDecryption...\n";	
	DecryptDES ( DecData, EncData );

	cout << endl;
	cout << hex << setw(16) << setfill('0')
		 << u64bit ( DecData ) << endl;

	KeyGen ( Key1 );

	DecryptDES ( DecData, DecData );
}
