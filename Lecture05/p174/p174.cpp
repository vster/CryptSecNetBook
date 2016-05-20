#include <iostream>
using namespace std;

 
int main()
{
    int r = 0x11;
 
    for ( int i = 0; i < 31; i++ ) 
	{
        for ( int j = 4; j >= 0; j-- ) 
			cout << ((r >> j) & 1 );
        
		cout << "  " << (r&1) << endl; 
    
		r |= ((r & 1) ^ ((r & 2) >> 1)) << 4;
        r >>= 1;
    
	}
    return 0;
}