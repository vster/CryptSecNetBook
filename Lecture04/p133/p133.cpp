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
	GF2X ax, bx, sum;
	ZZ a, b, c;
	
	a = 0x13;
	b = 0xb;
	
	GF2XFromZZ ( ax, a );
	GF2XFromZZ ( bx, b );	

	gf2x_output_be ( ax );	
	cout << endl;
	gf2x_output_be ( bx );	
	cout << endl;

	sum = ax + bx;

	gf2x_output_be ( sum );	
	cout << endl;
 
	ZZFromGF2X( c, sum );

	cout << hex << c << endl;

	return 0;
}
