#include <iostream>
#include <iomanip>
#include "util.h"
#include "gost.h"
#include "gmodes.h"
// #include "vchtest.h"

using namespace std;

// const int CT2 = 2;
// const int CT32 = 32;

int main()
{
	int oidnum = 1;
	generate_sbox ( oidnum );
	run_test_block ( CFB );

}