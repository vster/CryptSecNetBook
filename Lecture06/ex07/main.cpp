#include <iostream>
#include <iomanip>
#include <string>
#include "util.h"
#include "des.h"

using namespace std;
// const int MAXW = 64;


int main()
{
	byte Sin[8], Sout[8];

	for ( int i = 0; i < 32; i++)
	{
		for ( int j = 0; j < 8; j++)
			Sin[j] = i;
		
		for ( int j = 0; j < 8; j++)
			cout << setw(2) 
				 << int ( Sin[j] ) << " ";
		cout << endl;
		
		SubstSbox ( Sout, Sin );

		for ( int j = 0; j < 8; j++)
			cout << setw(2) 
				 << int ( Sout[j] ) << " ";
		cout << endl << endl;
	}

}
