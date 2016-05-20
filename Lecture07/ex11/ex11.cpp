#include <iostream>
#include <iomanip>
#include "util.h"


#include <NTL/GF2E.h>

using namespace std;
using namespace NTL;

const long MAXB = 100;

void GF2XFromZZ( GF2X &x, ZZ &n )
{
	// const long MAXB = 10;
	byte buf[MAXB];

	BytesFromZZ( buf, n, MAXB );
	GF2XFromBytes(x, buf, MAXB);
	// cout << n << " " << x << endl;
}

GF2X GF2XFromZZ( ZZ &n )
{
	GF2X x;
	// const long MAXB = 10;
	byte buf[MAXB];

	BytesFromZZ( buf, n, MAXB );
	GF2XFromBytes(x, buf, MAXB);
	// cout << n << " " << x << endl;
	return x;
}

void ZZFromGF2X ( ZZ &n, GF2X &x )
{
	// const long MAXB = 10;
	byte buf[MAXB];

	BytesFromGF2X( buf, x, MAXB );
	ZZFromBytes( n, buf, MAXB );
}

ZZ ZZFromGF2X ( GF2X &x )
{
	ZZ n;
	// const long MAXB = 10;
	byte buf[MAXB];

	BytesFromGF2X( buf, x, MAXB );
	ZZFromBytes( n, buf, MAXB );
	return n;
}

int main()
{
	ZZ p;
	p = 0x11b;
	
	GF2X Px;
	GF2XFromZZ ( Px, p );

	GF2E::init(Px);

	for ( long i = 0, a = 1; i < 14; i++)
	{
		GF2X ax = GF2XFromZZ( conv<ZZ>( a ) );
		GF2E axe = conv<GF2E>( ax );
		
		ax = conv<GF2X>( axe );
		a = conv<long> ( ZZFromGF2X( ax ) ); 
		cout << "Round = " << dec << i+1 << '\t' 
			 << "RCon = " << hex << a << endl; 
		
		a <<= 1;
	}

	return 0;
}
