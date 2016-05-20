#include <iostream>
#include <string>
#include "util.h"

using namespace std;

/*
typedef unsigned char byte;
typedef unsigned short u16bit;
typedef unsigned int u32bit;

typedef signed int s32bit;
*/



int main()
{
	byte key[8] =	{0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07};
	byte m[8];
	byte out[8];
	u16bit a1 = 0x1234;
	u32bit a2 = 0xaf345678;
	u64bit a3 = 0x123456789abcdef0;
	// byte bt;


	for (int i = 0; i < 8; i++)
		m[i] = 0x1f;

	int len = 8;
	// xor_buf ( key, m, len);
	// xor_buf (out, key, m, len ); 
	/*
	u16bit b1 = reverse_bytes ( a1 );
	u32bit b2 = reverse_bytes ( a2 );
	u64bit b3 = reverse_bytes ( a3 );
	int rot = 8;
	
	b1 =  rotate_left ( a1, rot );
	b2 =  rotate_left ( a2, rot );
	b3 =  rotate_left ( a3, rot );

	b1 = rotate_right ( a1, rot );
	b2 = rotate_right ( a2, rot );
	b3 = rotate_right ( a3, rot );
	*/
	/*
	byte bt0 = get_byte (0, a2);	
	byte bt1 = get_byte (1, a2);
	byte bt2 = get_byte (2, a2);
	byte bt3 = get_byte (3, a2);

	u32bit x32  = make_u32bit ( bt1, bt2, bt0, bt3 );

	copy_mem ( out, key, 8 );

	clear_mem ( out , 8 );
	
	copy_mem ( out, m, 8 );
	*/
	
	string s1, s2;
	s1 = to_string ( a2 );

}