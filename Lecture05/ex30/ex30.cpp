#include <iostream>
#include "util.h"

using namespace std;


void lfsr_out ( byte &r, int n )
{
        for ( int j = n-1; j >= 0; j-- ) 
			cout << ((r >> j) & 1 );
}

int lfsr_step ( byte &r, int n )
{
	int b = r & 1;

	r |= ((r & 1) ^ ((r & 2) >> 1)) << n;
    r >>= 1;
	return b;
}


int main()
{
    byte r = 0x11;

	int n = 5;
	int b = 0;
 
    for ( int i = 0; i < 31; i++ ) 
	{
		lfsr_out ( r, n );
		cout << " " << b << endl;
		      
		b = lfsr_step ( r, n ); 
	}
    return 0;
}