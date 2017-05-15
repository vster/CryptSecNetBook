#include <iostream>
#include <iomanip>
#include <cstring>
#include "util.h"
#include "aes.h"
#include "vchtest.h"

using namespace std;

enum Mode { ECB, CBC, CFB, OFB, CTR };

extern byte w[44][4];

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
	for (i = 8; i > 0; i--)
		cout << hex << setfill('0') << setw(2) 
			 << (int)iv[i-1] << " ";
	cout << endl << endl;
}

// Output key
void output_key( byte key[KL] )
{
	int i;
	cout << "Test key:" << endl;
	for (i = 0; i < 4; i++)
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
		EncryptAES( to[j], ts[j] );
}

// Decrypt data in ECB mode
void ecb_decrypt( byte ts[MAXT][BS], 
				  byte td[MAXT][BS], 
				  u32bit n)
{
	for (u32bit j = 0; j < n; j++)
		DecryptAES( ts[j], td[j] );
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
	EncryptAES( tt, ts[0] );
	// gg.encrypt(tt, ts[0]);
	for (j = 1; j < n; j++)
	{
		xor_buf(tt, to[j], ts[j-1], BS);
		EncryptAES( tt, ts[j] );		
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
		DecryptAES(ts[j], tt);		
		// gg.decrypt(ts[j], tt);
		xor_buf(td[j], tt, ts[j-1], BS);
	}
	DecryptAES(ts[0], tt);
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
	EncryptAES(iv, gamma);
	xor_buf(ts[0], to[0], gamma, BS);
	
	for (j = 1; j < n; j++)
	{
		EncryptAES(ts[j-1], gamma);
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

	EncryptAES(iv, gamma);
	xor_buf(td[0], ts[0], gamma, BS);

	for (j = 1; j < n; j++)
	{
		EncryptAES(ts[j-1], gamma);
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
	EncryptAES(iv, gamma);
	xor_buf(ts[0], to[0], gamma, BS);
	
	for (j = 1; j < n; j++)
	{
		EncryptAES(gamma, gamma);
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

	EncryptAES(iv, gamma);
	xor_buf(td[0], ts[0], gamma, BS);

	for (j = 1; j < n; j++)
	{
		EncryptAES(gamma, gamma);
		xor_buf(td[j], ts[j], gamma, BS);
	}
}

// Encrypt data in CTR mode
void ctr_encrypt( byte to[MAXT][BS], 
				  byte ts[MAXT][BS], 
				  byte iv[BS], 
				  u32bit n)
{
	byte gamma[BS];
	byte tt[BS];
	u32bit j;

	u64bit cnt;
	cnt = make_u64bit ( iv[0],iv[1],iv[2],iv[3],iv[4],iv[5],iv[6],iv[7] );

	// Encrypt in CTR mode
	for (j = 0; j < n; j++)
	{
		cnt = (cnt+j)%0xffffffffffffffff;
		for ( int i = 0; i < 8; i++ )
		{ 
			tt[i] = get_byte ( i, cnt );
			tt[2*i] = get_byte ( i, cnt );
		}
		EncryptAES(tt, gamma);
		xor_buf(ts[j], to[j], gamma, BS);
	}
}

// Decrypt data in CTR mode
void ctr_decrypt( byte ts[MAXT][BS], 
				  byte td[MAXT][BS], 
				  byte iv[BS], 
				  u32bit n)
{
	byte gamma[BS];
	byte tt[BS];	
	u32bit j;

	u64bit cnt;
	cnt = make_u64bit ( iv[0],iv[1],iv[2],iv[3],iv[4],iv[5],iv[6],iv[7] );

	// Decrypt in CTR mode
	for (j = 0; j < n; j++)
	{
		cnt = (cnt+j)%0xffffffffffffffff;
		for ( int i = 0; i < 8; i++ )
		{ 
			tt[i] = get_byte ( i, cnt );
			tt[2*i] = get_byte ( i, cnt );		
		}
		EncryptAES(tt, gamma);
		xor_buf(td[j], ts[j], gamma, BS);
	}
}

// Run one test
void run_one_test( Mode mode, 
				   byte to[MAXT][BS], 
				   byte iv[BS], 
				   byte key[KL], 
				   u32bit n)
{
	byte ts[MAXT][BS];
	byte td[MAXT][BS];
	// byte ip[4];

	// Output key
	output_key ( key );
	
	GenRoundKeys ( w, key );

	// Output init vector
	if ( (mode != ECB)  )
		output_iv ( iv );

	// Output open data
	cout << "Open data:" << endl;
	output_data(to, n, "To");

	// Encrypt 
	switch (mode)
	{
		case ECB: 		ecb_encrypt ( to, ts, n);		break;
		case CBC:		cbc_encrypt ( to, ts, iv, n);	break;
		case CFB:		cfb_encrypt ( to, ts, iv, n);	break;
		case OFB:		ofb_encrypt ( to, ts, iv, n);	break;
		case CTR:		ctr_encrypt ( to, ts, iv, n);	break;			
	}

	// Output encrypted data
	cout << "Encrypted data:" << endl;
	output_data(ts, n, "Ts");

	// Decrypt
	switch (mode)
	{
		case ECB: 		ecb_decrypt ( ts, td, n);		break;
		case CBC:		cbc_decrypt ( ts, td, iv, n);	break;
		case CFB:		cfb_decrypt ( ts, td, iv, n);	break;
		case OFB:		ofb_decrypt ( ts, td, iv, n);	break;
		case CTR:		ctr_decrypt ( ts, td, iv, n);	break;
	}

	// Output decrypted data
	cout << "Decrypted data:" << endl;
	output_data(td, n, "Td");

}


int main( int argc, char* argv[] )
{
	Mode mode;

	if (argc == 1)
	{
	     std::cout << "Usage: " << argv[0] << " mode\n"
						"mode:    ecb, cbc, cfb, ofb, ctr\n";                
		return 1;
	}

	if (strcmp (argv[1], "ecb") == 0 )
		mode = ECB;
	else if (strcmp (argv[1], "cbc") == 0 )
		mode = CBC;
	else if (strcmp (argv[1], "cfb") == 0 )
		mode = CFB;
	else if (strcmp (argv[1], "ofb") == 0 )
		mode = OFB;
	else if (strcmp (argv[1], "ctr") == 0 )
		mode = CTR;	
	else
	{
		cout << "\nUnknown mode\n";
		return 1;		
	}

	for (int k = 0; k < 5; k++)
	{
		cout << "\nTEST " << k+1 << endl;
		run_one_test( mode, to1, s1, kzu[k], 2);
	}
	cout << "\nTEST 6\n"; 
	run_one_test( mode, to2, s2, kzu[4], 32);

	return 0;
}
