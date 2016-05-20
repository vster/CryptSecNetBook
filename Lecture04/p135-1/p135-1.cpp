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
	p = 0x11b;
	
	GF2X Px;
	GF2XFromZZ ( Px, p );
	
	gf2x_output_be ( Px, 10 );
	cout << endl;

	GF2E::init(Px);
	
	ZZ a1, a2 ;
	a1 = 0x26;
	a2 = 0x9e;

	GF2X ax1, ax2;
	GF2XFromZZ ( ax1, a1 );
	GF2XFromZZ ( ax2, a2 );

	GF2E axe1, axe2, bxe;
	axe1 = conv<GF2E>(ax1);
	axe2 = conv<GF2E>(ax2);
	
	gf2x_output_be ( conv<GF2X>(axe1), 10 );
	cout << endl;
	gf2x_output_be ( conv<GF2X>(axe2), 10 );
	cout << endl;

	// cout << ae << endl;

	bxe = axe1 * axe2;

	// cout << be << endl;
	gf2x_output_be ( conv<GF2X>(bxe), 10 );
	cout << endl;

	return 0;
}
