#include <iostream>
#include <iomanip>
#include "util.h"

using namespace std;

int main()
{
	byte A[4][4];
	
	byte OpenText[] = "AESUSESAMATRIXZZ";

	for ( u32bit i = 0, k = 0; i < 4; i++ )
		for ( u32bit j = 0; j < 4; j++ )
			A[j][i] = OpenText[k++] - 'A';


	for ( u32bit i = 0; i < 4; i++ )
	{
		for ( u32bit j = 0; j < 4; j++ )
			cout << hex << setfill('0') << setw(2) 
				 << u16bit(A[i][j]) << " ";
		cout << endl;
	}
}
