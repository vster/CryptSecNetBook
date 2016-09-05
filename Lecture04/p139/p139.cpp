#include <NTL/GF2X.h>
#include <NTL/GF2E.h>
#include <iostream>
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

void GF2XFromZZ( GF2X &x, ZZ n )
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
	
	// gf2x_output_be ( Px, 8 );
	cout << endl;

	GF2E::init(Px);
	
	GF2X ax;
	GF2E arr[16];

	long i, j, n;
	for ( i = 0, n = 1; i < 16; i++)
	{
		GF2XFromZZ( ax, conv<ZZ>(n) );
		arr[i] = conv<GF2E>(ax);
		n <<= 1;	
	}
	
	GF2E add_inv, mult_inv;
	for ( i = 1; i < 16; i++)
	{
		// add_inv = -arr[i];
		mult_inv = 1 / arr[i];
		// cout << arr[i] << add_inv << endl;
		cout << i << '\t';
		gf2x_output_be( conv<GF2X>(arr[i]), 4);
		// gf2x_output_be( conv<GF2X>(add_inv), 3);
		gf2x_output_be( conv<GF2X>(mult_inv), 4);
		gf2x_output_be( conv<GF2X>(arr[i]*mult_inv), 4);
		cout << endl;
	}

	return 0;
}
