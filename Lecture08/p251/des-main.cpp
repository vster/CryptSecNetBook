#include <iostream>
#include <iomanip>
#include <string>
#include "util.h"
#include "des.h"
#include "vchtest.h"

using namespace std;

// Output data
void output_data(byte tx[MAXT][BS], u32bit n, char* type)
{
	u32bit j, i;
	for ( j = 0; j < n; j++)
	{
		cout << type 
			 << dec << setfill('0') << setw(2) 
			 << j+1 << "  ";
		for (i = BS; i > 0; i--)
			cout << hex << setfill('0') << setw(2) 
				 << (int)tx[j][i-1] << " ";
		cout << endl;
	}
	cout << endl;
}

// Output init vector
void output_iv ( byte iv[BS] )
{
	int i;
	cout << "Init vector:" << endl;
	cout << "S  ";
	for (i = BS; i > 0; i--)
		cout << hex << setfill('0') << setw(2) 
			 << (int)iv[i-1] << " ";
	cout << endl << endl;
}

// Output key
void output_key( byte key[KL] )
{
	int i;
	cout << "Test key:" << endl;
	for (i = 0; i < KL/4; i++)
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

// Encrypt data in ECB mode
void ecb_encrypt( byte to[MAXT][BS], 
				  byte ts[MAXT][BS], 
				  u32bit n )
{
	for (u32bit j = 0; j < n; j++)
		EncryptDES( to[j], ts[j] );
}

// Decrypt data in ECB mode
void ecb_decrypt( byte ts[MAXT][BS], 
				  byte td[MAXT][BS], 
				  u32bit n)
{
	for (u32bit j = 0; j < n; j++)
		DecryptDES( ts[j], td[j] );
}	

// Encrypt data in CBC mode
void cbc_encrypt( byte to[MAXT][BS], 
				  byte ts[MAXT][BS], 
				  byte iv[BS], 
				  u32bit n)
{
	u32bit j;
	byte tt[BS];

	xor_buf(tt, to[0], iv, BS);
	EncryptDES( tt, ts[0] );
	// gg.encrypt(tt, ts[0]);
	for (j = 1; j < n; j++)
	{
		xor_buf(tt, to[j], ts[j-1], BS);
		EncryptDES( tt, ts[j] );		
		// Encrypt(tt, ts[j]);
	}
}

// Decrypt data in CBC mode
void cbc_decrypt ( byte ts[MAXT][BS], 
				   byte td[MAXT][BS], 
				   byte iv[BS], 
				   u32bit n)
{
	u32bit j;
	byte tt[BS];

	for (j = n-1; j >= 1; j--)
	{
		DecryptDES(ts[j], tt);		
		// gg.decrypt(ts[j], tt);
		xor_buf(td[j], tt, ts[j-1], BS);
	}
	DecryptDES(ts[0], tt);
	xor_buf(td[0], tt, iv, BS);
}

// Encrypt data in CFB mode
void cfb_encrypt( byte to[MAXT][BS], 
				  byte ts[MAXT][BS], 
				  byte iv[BS], 
				  u32bit n)
{
	byte gamma[BS];
	u32bit j;

	// Encrypt in CFB mode
	EncryptDES(iv, gamma);
	xor_buf(ts[0], to[0], gamma, BS);
	
	for (j = 1; j < n; j++)
	{
		EncryptDES(ts[j-1], gamma);
		xor_buf(ts[j], to[j], gamma, BS);
	}
}

// Decrypt data in CFB mode
void cfb_decrypt( byte ts[MAXT][BS], 
				  byte td[MAXT][BS], 
				  byte iv[BS], 
				  u32bit n)
{
	byte gamma[BS];
	u32bit j;

	EncryptDES(iv, gamma);
	xor_buf(td[0], ts[0], gamma, BS);

	for (j = 1; j < n; j++)
	{
		EncryptDES(ts[j-1], gamma);
		xor_buf(td[j], ts[j], gamma, BS);
	}
}

// Encrypt data in OFB mode
void ofb_encrypt( byte to[MAXT][BS], 
				  byte ts[MAXT][BS], 
				  byte iv[BS], 
				  u32bit n)
{
	byte gamma[BS];
	u32bit j;

	// Encrypt in OFB mode
	EncryptDES(iv, gamma);
	xor_buf(ts[0], to[0], gamma, BS);
	
	for (j = 1; j < n; j++)
	{
		
		EncryptDES(gamma, gamma);
		xor_buf(ts[j], to[j], gamma, BS);
	}
}

// Decrypt data in OFB mode
void ofb_decrypt( byte ts[MAXT][BS], 
				  byte td[MAXT][BS], 
				  byte iv[BS], 
				  u32bit n)
{
	byte gamma[BS];
	u32bit j;

	EncryptDES(iv, gamma);
	xor_buf(td[0], ts[0], gamma, BS);

	for (j = 1; j < n; j++)
	{
		EncryptDES(gamma, gamma);
		xor_buf(td[j], ts[j], gamma, BS);
	}
}

void run_one_test(  byte to[MAXT][BS], 
					byte iv[BS], 
					byte key[KL], 
				    u32bit n )
{
	byte ts[MAXT][BS];
	byte td[MAXT][BS];

	output_key ( key );
	KeyGen ( key );

	// Output init vector
	output_iv ( iv );

	// Output open data
	cout << "Open data:" << endl;
	output_data(to, n, "To");

	// ecb_encrypt ( to, ts, n);
	// cbc_encrypt ( to, ts, iv, n);
	// cfb_encrypt ( to, ts, iv, n);
	ofb_encrypt ( to, ts, iv, n);

	// Output encrypted data
	cout << "Encrypted data:" << endl;
	output_data(ts, n, "Ts");

	// ecb_decrypt ( ts, td, n);
	// cbc_decrypt ( ts, td, iv, n);
	// cfb_decrypt ( ts, td, iv, n);
	ofb_decrypt ( ts, td, iv, n);	

	// Output decrypted data
	cout << "Decrypted data:" << endl;
	output_data(td, n, "Td");
}

int main()
{
	for (int k = 0; k < 5; k++)
	{
		cout << "\nTEST " << k+1 << endl;
		run_one_test( to1, s1, kzu[k], 2);
	}
	cout << "\nTEST 6\n"; 
	run_one_test( to2, s2, kzu[4], 32);
}
