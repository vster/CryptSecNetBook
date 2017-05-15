#include <iostream>
#include <iomanip>
#include <cstring>
#include "util.h"
#include "des.h"
#include "dmodes.h"
#include "vchtest.h"

using namespace std;

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
