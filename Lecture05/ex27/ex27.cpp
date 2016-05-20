#include <iostream>
#include <string>
#include "util.h"

using namespace std;


void Subst( byte out[4], byte in[4], const byte SBox[4][4] )
{
	
	for ( int i = 0; i < 4; i++ )
		for ( int j = 0; j < 4; j++)
			out[i] += in[j]*SBox[i][j];
}

int main()
{
	byte x[4] = {0x01,0x00,0x01,0x00};
	byte y[4] = {0x00};

	byte SBox[4][4] = 
	{
		{1,1,1,1},
		{0,1,0,0},
		{0,0,1,0},
		{0,0,0,1}
	};
	
	Subst ( y, x, SBox ); 
	
	return 0;
}

