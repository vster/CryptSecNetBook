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

	for ( i = 0; i < 16-n; i++)
		cout << "0 ";

	for ( i = n-1; i >= 0; i--)
		cout << x[i] << " ";

	cout << "]";
}

void GF2XFromZZ( GF2X &x, ZZ &n )
{
	const long MAXB = 10;
	byte buf[MAXB];

	BytesFromZZ( buf, n, MAXB );
	GF2XFromBytes(x, buf, MAXB);
	// cout << n << " " << x << endl;
}

void ZZFromGF2X ( ZZ &n, GF2X &x )
{
	const long MAXB = 10;
	byte buf[MAXB];

	BytesFromGF2X( buf, x, MAXB );
	ZZFromBytes( n, buf, MAXB );
}

int main()
{
	ZZ p;
	GF2X ax, bx, px, prodx, restx;
	ZZ a, b, c;
	
	a = 0x26;
	b = 0x9e;
	p = 0x11b;
	
	GF2XFromZZ ( ax, a );
	GF2XFromZZ ( bx, b );	
	GF2XFromZZ ( px, p );

	gf2x_output_be ( ax );	
	cout << endl;
	gf2x_output_be ( bx );	
	cout << endl;
	gf2x_output_be ( px );	
	cout << endl;

	prodx = ax * bx;

	// cout << prod << endl;

	gf2x_output_be ( prodx );	
	cout << endl;

	// GF2X restx;

	restx = prodx % px;

	gf2x_output_be ( restx );	
	cout << endl;

	// ZZFromGF2X( c, prod );
	// cout << hex << c << endl;

	return 0;
}
