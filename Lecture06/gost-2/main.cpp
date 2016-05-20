#include <iostream>
#include <iomanip>
// #include <string>
#include "util.h"
#include "gost.h"
#include "vchtest.h"

using namespace std;

const int CT2 = 2;
const int CT32 = 32;

// Output data
void output_data(byte tx[MAXT][BS], u32bit n, char* type)
{
	u32bit j, i;
	for ( j = 0; j < n; j++)
	{
		cout << type 
			 << dec << setfill('0') << setw(2) 
			 << j+1 << "  ";
		for (i = 8; i > 0; i--)
			cout << hex << setfill('0') << setw(2) 
				 << (int)tx[j][i-1] << " ";
		cout << endl;
	}
	cout << endl;
}

// Output key
void output_key( byte key[KL] )
{
	int i;
	cout << "Test key:" << endl;
	for (i = 0; i < 8; i++)
	{
		cout << "X" << i << "  " 
			<< hex << setfill('0') << setw(2)
			<< (int)key[4*i+3] << "  "
			<< hex << setfill('0') << setw(2)
			<< (int)key[4*i+2] << "  "
			<< hex << setfill('0') << setw(2)
			<< (int)key[4*i+1] << "  "
			<< hex << setfill('0') << setw(2)
			<< (int)key[4*i]
			<< endl;
	}	
	cout << endl;
}	

void run_one_test (byte to[MAXT][BS], byte key[KL], u32bit n)
{

	byte ts[MAXT][BS];
	byte td[MAXT][BS];
	int i,j;

	output_key ( kzu[0] );

	// Output open data
	cout << "Open data:" << endl;
	// int n = 2;
	output_data(to, n, "To");

	for (j = 0; j < n; j++)
		Encrypt ( to[j], ts[j], key );

	// Output encrypted data
	cout << "Encrypted data:" << endl;
	output_data(ts, n, "Ts");

	for (j = 0; j < n; j++)
		Decrypt ( ts[j], td[j], key );
	
	// Output decrypted data
	cout << "Decrypted data:" << endl;
	output_data(td, n, "Td");	

}

int main()
{
	for ( int k = 0; k < 5; k++)
	{
		cout << "\nTEST " << k+1 << endl;	
		run_one_test ( to1, kzu[k], 2);
	}
	cout << "\nTEST 6\n"; 
	run_one_test( to2, kzu[4], 32);
}