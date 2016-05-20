#include <NTL/GF2.h>
#include <NTL/vec_GF2.h>

using namespace std;
using namespace NTL;

int main()
{
	vec_GF2 btab[256];
	long i, j, k;

	// a_bin.SetLength(2);

	for ( k = 0; k < 256; k++)
	{
		btab[k].SetLength(8);

		for ( i = 0; i < 8; i++)
			btab[k][1-i] = bit(k,i);
	}

	for ( k = 0; k < 256; k++)
		cout << btab[k] << endl;

	cout << endl;
}