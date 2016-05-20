#include <iostream>
#include <iomanip>
#include <string>
#include "util.h"
#include "des.h"
#include "vchtest.h"

using namespace std;

void run_one_test(  byte to[MAXT][BS], 
				    byte key[KL], 
				    u32bit n )
{
	u64bit tod[MAXT];	
	u64bit tsd[MAXT];
	u64bit tdd[MAXT];

	u64bit keyd;

	keyd = make_u64bit( key[0],key[1],key[2],key[3], 
						key[4],key[5],key[6],key[7] );

	cout << "Key = \n"
		 << hex << setw(16) << setfill('0')
		 << u64bit ( keyd ) << endl;	
	
	KeyGen ( keyd );

	for ( u32bit i = 0; i < n; i++) 
		tod[i] = make_u64bit(  to[i][0],to[i][1],
							to[i][2],to[i][3],
							to[i][4],to[i][5],
							to[i][6],to[i][7]);


	cout << "\nOpen data = \n";
	for ( u32bit i = 0; i < n; i++)
		cout << hex << setw(16) << setfill('0')
			 << u64bit ( tod[i] ) << endl;

	for ( u32bit i = 0; i < n; i++)
		EncryptDES ( tod[i], tsd[i] );

	cout << "\nEncrypted data = \n";
	for ( u32bit i = 0; i < n; i++)
		cout << hex << setw(16) << setfill('0')
			<< u64bit ( tsd[i] ) << endl;

	for ( u32bit i = 0; i < n; i++)
		DecryptDES ( tsd[i], tdd[i] );

	cout << "\nDecrypted data = \n";
	for ( u32bit i = 0; i < n; i++)
		cout << hex << setw(16) << setfill('0')
			 << u64bit ( tdd[i] ) << endl;
}

int main()
{
	for (int k = 0; k < 5; k++)
	{
		cout << "\nTEST " << k+1 << endl;
		run_one_test( to1, kzu[k], 2);
	}
	cout << "\nTEST 6\n"; 
	run_one_test( to2, kzu[4], 32);
}
