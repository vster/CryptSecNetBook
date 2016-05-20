#include <NTL/GF2X.h>
#include <NTL/GF2E.h>
#include <iomanip>

typedef unsigned char byte;

using namespace std;
using namespace NTL;

void gf2x_output_be ( GF2X x, long len )
{
	long i;
	long n = NumBits(x);

	cout << "[";

	for ( i = 0; i < len-n; i++)
		cout << "0";

	for ( i = n-1; i >= 0; i--)
		cout << x[i];

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
	p = 0x23;
	
	GF2X Px;
	GF2XFromZZ ( Px, p );
	
	gf2x_output_be ( Px, 8 );
	cout << endl;

	GF2E::init(Px);
	
	ZZ a, b;
	a = 0x13;
	b = 0x10;

	GF2X ax;
	GF2XFromZZ ( ax, a );
	GF2X bx;
	GF2XFromZZ ( bx, b );

	GF2E axe, bxe, cxe;
	axe = conv<GF2E>(ax);
	bxe = conv<GF2E>(bx);
	
	gf2x_output_be ( conv<GF2X>(axe), 8 );
	cout << endl;
	gf2x_output_be ( conv<GF2X>(bxe), 8 );
	cout << endl;

	cxe = axe * bxe;

	// cout << be << endl;
	gf2x_output_be ( conv<GF2X>(cxe), 8 );
	cout << endl;

/*
	GF2E cxe;

	cxe = axe * bxe;

	gf2x_output_be ( conv<GF2X>(cxe), 8 );
	cout << endl;
*/
	return 0;
}
