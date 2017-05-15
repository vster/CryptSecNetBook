#include <iostream>
#include <iomanip>
#include <string>
#include "util.h"
#include "des.h"
#include "vchtest.h"

using namespace std;
// const int MAXW = 64;


int main()
 {
	u64bit OpenData =			0x123456abcd132536;
	u64bit EncData;
	u64bit DecData;

	u64bit Key;
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

	int k = 0;
	Key = make_u64bit ( kzu[k][0],kzu[k][1],kzu[k][2],kzu[k][3], 
						kzu[k][4],kzu[k][5],kzu[k][6],kzu[k][7] );

	cout << "Key = \n"
		 << hex << setw(16) << setfill('0')
		 << u64bit ( Key ) << endl;	
	
	// output_bin( a4 );
	cout << "\n\nOpen data = \n";
	cout << hex << setw(16) << setfill('0')
		 << u64bit ( OpenData ) << endl;
	// cout << endl;
	
	cout << "\nEncryption...\n";

	EncryptDES ( EncData, OpenData, Key );

	cout << "\nEncrypted data = \n";
	cout << hex << setw(16) << setfill('0')
		 << u64bit ( EncData ) << endl;

	cout << "\nDecryption...\n";	
	DecryptDES ( DecData, EncData, Key );

	cout << "\nDecrypted data = \n";
	cout << hex << setw(16) << setfill('0')
		 << u64bit ( DecData ) << endl;
}
