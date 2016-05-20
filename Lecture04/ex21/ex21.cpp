#include <NTL/GF2X.h>
#include <NTL/vec_GF2.h>
#include <iomanip>

typedef unsigned char byte;

using namespace std;
using namespace NTL;

void gf2x_output_be ( GF2X x, int len )
{
	long i;
	long n = NumBits(x);

	cout << "[ ";

	for ( i = 0; i < len-n; i++)
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
	GF2X ax, bx, mult;
	ZZ a, b, c;
	
	a = 0xa;
	b = 0x8;
	
	GF2XFromZZ ( ax, a );
	GF2XFromZZ ( bx, b );	

	gf2x_output_be ( ax, 16 );	
	cout << endl;
	gf2x_output_be ( bx, 16 );	
	cout << endl;

	mult = ax * bx;

	gf2x_output_be ( mult, 16 );	
	cout << endl;
 
	ZZFromGF2X( c, mult );

	cout << hex << c << endl;

	return 0;
}
