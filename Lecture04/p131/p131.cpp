#include <NTL/GF2X.h>
#include <NTL/vec_GF2.h>
#include <iomanip>

typedef unsigned char byte;

using namespace std;
using namespace NTL;

void gf2x_output_be ( GF2X x )
{
	long i;
	long n = NumBits(x);

	cout << "[ ";

	for ( i = 0; i < 8-n; i++)
		cout << "0 ";

	for ( i = n-1; i >= 0; i--)
		cout << x[i] << " ";

	cout << "]";
}

void GF2XFromLong( GF2X &x, long &n )
{
	const long MAXB = 10;
	byte buf[MAXB];

	BytesFromZZ( buf, conv<ZZ>(n), MAXB );
	GF2XFromBytes (x, buf, MAXB);
	// cout << n << " " << x << endl;
}

int main()
{
	GF2X ax;

	for ( long i = 0; i < 256; i++)
	{
		GF2XFromLong ( ax, i );

		cout << hex << setw(2) << i << '\t';

		//cout << ax << endl;
		gf2x_output_be ( ax );
		cout << endl;
		// cout << a << endl;
	}
	return 0;
}
