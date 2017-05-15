#include <iostream>
#include <string>
#include "util.h"

using namespace std;

const int BSIZE = 64;

int main()
{
	int len = 2013;
	int bitlen = 8 * len;
	int pad;
	
	int rest = bitlen % BSIZE;

	if ( rest > 0 )
	{
		pad = BSIZE-rest;
		bitlen += pad;
	}

	int bnum = bitlen / BSIZE;

    cout << bnum;
    cout << endl;
}
