#include <iostream>
#include "util.h"

using namespace std;


void lfsr_out ( u32bit &r, int n )
{
        for ( int j = n-1; j >= 0; j-- ) 
			cout << ((r >> j) & 1 );
}

void lfsr_step ( int lfsr, int &b, u32bit &r )
{
	int n;

	switch ( lfsr )	
	{
		case 1:		
			n = 19;
			// x^19 + x^5 + x^2 + x + 1
			r |= ( ((r&0x20)>>5) ^ ((r&0x4)>>2) ^ ((r&0x2)>>1) ^ (r&0x1) ) << n;
			break;
		case 2:	
			n = 22;
			// x^22 + x + 1
			r |= ( ((r&0x2)>>1) ^ (r&0x1) ) << n;
			break;
		case 3:
			n = 23;
			// x^23 + x^15 + x^2 + x + 1
			r |= ( ((r&0x8000)>>15) ^ ((r&0x4)>>2) ^ ((r&0x2)>>1) ^ (r&0x1) ) << n;
			break;
	}
	b = r & 1;    
	r >>= 1;	
}


int main()
{
 	u32bit r19 = 0x0;   
	u32bit r22 = 0x0;
	u32bit r23 = 0x0;

	// int n = 23;
	int b19 = 0;
	int b22 = 0;
	int b23 = 0;

	u32bit init;
	u64bit key = 0x1111111111111111;

    for ( int i = 0; i < 64; i++ ) 
	{
		init = key&1;	
		init <<= 18;
		r19 ^= init;

		init = key&1;
		init <<= 21;
		r22 ^= init;

		init = key&1;
		init <<= 22;
		r23 ^= init;

		lfsr_out ( r19, 19 );
		cout << " " << b19 << "  ";

		lfsr_out ( r22, 22 );
		cout << " " << b22 << "  ";

		lfsr_out ( r23, 23 );
		cout << " " << b23 << endl;		
		      
		lfsr_step ( 1, b19, r19 );
		lfsr_step ( 2, b22, r22 );
		lfsr_step ( 3, b23, r23 );
		key >>= 1;
	}
    
	for ( int i = 0; i < 22; i++ ) 
	{
		
		init = i;	
		init <<= 18;
		r19 ^= init;

		init = i;
		init <<= 21;
		r22 ^= init;

		init = i;
		init <<= 22;
		r23 ^= init;

		lfsr_out ( r19, 19 );
		cout << " " << b19 << "  ";

		lfsr_out ( r22, 22 );
		cout << " " << b22 << "  ";

		lfsr_out ( r23, 23 );
		cout << " " << b23 << endl;		
		      
		lfsr_step ( 1, b19, r19 );
		lfsr_step ( 2, b22, r22 );
		lfsr_step ( 3, b23, r23 );
	}


    return 0;
}