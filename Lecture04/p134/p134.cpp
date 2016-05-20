#include <NTL/GF2X.h>
#include <NTL/GF2E.h>
// #include <NTL/vec_GF2.h>
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
	ZZ p;
	p = 0x13;
	
	GF2X Px;
	GF2XFromZZ ( Px, p );
	
	gf2x_output_be ( Px );
	cout << endl;

	GF2E::init(Px);
	
	ZZ a;
	a = 5;

	GF2X ax;
	GF2XFromZZ ( ax, a );

	GF2E ae, be;
	ae = conv<GF2E>(ax);
	
	gf2x_output_be ( conv<GF2X>(ae) );
	cout << endl;
	// cout << ae << endl;

	be = 1 / ae;

	// cout << be << endl;
	gf2x_output_be ( conv<GF2X>(be) );
	cout << endl;

	GF2E ce;

	ce = ae * be;

	gf2x_output_be ( conv<GF2X>(ce) );
	cout << endl;

	return 0;
}
