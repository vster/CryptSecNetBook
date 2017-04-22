#include <NTL/GF2X.h>
#include <NTL/GF2E.h>
#include <NTL/vector.h>
// #include <NTL/vec_GF2E.h>
// #include <NTL/matrix.h>
#include <NTL/mat_GF2.h>
#include <iomanip>

typedef unsigned char byte;

using namespace std;
using namespace NTL;

const byte xmat0[8][8] =  {
	{1,0,0,0,1,1,1,1},
	{1,1,0,0,0,1,1,1},
	{1,1,1,0,0,0,1,1},
	{1,1,1,1,0,0,0,1},
	{1,1,1,1,1,0,0,0},
	{0,1,1,1,1,1,0,0},
	{0,0,1,1,1,1,1,0},
	{0,0,0,1,1,1,1,1}
};

mat_GF2 X;

const byte yarr0[8] = {1,1,0,0,0,1,1,0};

vec_GF2 yarr;

const byte invxmat0[8][8] = {
	{0,0,1,0,0,1,0,1},
	{1,0,0,1,0,0,1,0},
	{0,1,0,0,1,0,0,1},
	{1,0,1,0,0,1,0,0},
	{0,1,0,1,0,0,1,0},
	{0,0,1,0,1,0,0,1},
	{1,0,0,1,0,1,0,0},
	{0,1,0,0,1,0,1,0}
};

mat_GF2 InvX;

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

GF2X GF2XFromZZ( ZZ &n )
{
	GF2X x;
	const long MAXB = 10;
	byte buf[MAXB];

	BytesFromZZ( buf, n, MAXB );
	GF2XFromBytes(x, buf, MAXB);
	// cout << n << " " << x << endl;
	return x;
}

void ZZFromGF2X ( ZZ &n, GF2X &x )
{
	const long MAXB = 10;
	byte buf[MAXB];

	BytesFromGF2X( buf, x, MAXB );
	ZZFromBytes( n, buf, MAXB );
}

ZZ ZZFromGF2X ( GF2X &x )
{
	ZZ n;
	const long MAXB = 10;
	byte buf[MAXB];

	BytesFromGF2X( buf, x, MAXB );
	ZZFromBytes( n, buf, MAXB );
	return n;
}

void InitSubsBytes()
{
	X.SetDims (8,8);

	for ( int i = 0; i < 8; i++ )
		for ( int j = 0; j < 8; j++ )
			X[i][j] = xmat0[i][j];

	// cout << endl << X << endl;

	yarr.SetLength(8);

	for ( int i = 0; i < 8; i++)
		yarr[i] = yarr0[i];
}

void InitInvSubsBytes()
{
	InvX.SetDims (8,8);

	for ( int i = 0; i < 8; i++ )
		for ( int j = 0; j < 8; j++ )
			InvX[i][j] = invxmat0[i][j];

	// cout << endl << X << endl;

	yarr.SetLength(8);

	for ( int i = 0; i < 8; i++)
		yarr[i] = yarr0[i];
}

byte SubsOneByte ( byte in )
{
	ZZ p;
	p = 0x11b;
	
	GF2X Px;
	GF2XFromZZ ( Px, p );
	//cout << endl;

	GF2E::init(Px);
	
	long a = in;

	// cout << hex << int ( a ) << endl;

    ZZ za = conv<ZZ>( a );
    GF2X ax = GF2XFromZZ( za );
	GF2E axe = conv<GF2E>( ax );

	// cout << axe << endl;

	GF2E bxe;
	vec_GF2 barr;
	barr.SetLength(8);

	if ( axe == conv<GF2E>(0) )
	{	
		for ( int i = 0; i < 8; i++ ) 
			barr[i] = 0;
	}
	else
	{
		bxe = inv( axe );
		barr = conv<vec_GF2>( conv<GF2X>(bxe) );	
		barr.SetLength(8);	
	}
	

	// cout << barr << endl;

	vec_GF2 carr = X * barr;

	vec_GF2 darr = carr + yarr;
	// cout << darr << endl;

	GF2X dx = conv<GF2X>(darr);
	// cout << dx << endl;

	ZZ d = ZZFromGF2X ( dx );
	long dl = conv <long>( d );
	// cout << hex << dl << endl;

	return byte ( dl );
}

byte InvSubsOneByte ( byte in )
{
	ZZ p;
	p = 0x11b;
	
	GF2X Px;
	GF2XFromZZ ( Px, p );
	// cout << endl;

	GF2E::init(Px);
	
	long d = in;

	GF2X dx;
    ZZ zd = conv<ZZ>( d );
    dx = GF2XFromZZ( zd );

	GF2E dxe	= conv<GF2E>( dx );

	// cout << dxe << endl;

	vec_GF2 darr = conv<vec_GF2>( conv<GF2X>(dxe) );

	darr.SetLength(8);

	vec_GF2 carr = darr - yarr;

	vec_GF2 barr = InvX * carr;	

	GF2X bx = conv<GF2X>(barr);

	GF2E bxe = conv<GF2E>( bx );
	
	GF2E axe;

	if ( bxe == conv<GF2E>(0) )
		axe = conv<GF2>( 0 ); 
	else
		axe = inv( bxe );
	
	GF2X ax = conv<GF2X>( axe );
	ZZ a = ZZFromGF2X ( ax );

	long al = conv <long>( a );

	return byte ( al );
}

int main()
{
	
	byte result1, result2;
	byte a = 0x00;

	InitSubsBytes();

	InitInvSubsBytes();

	for ( int i = 0; i < 256; i++ )
	{
		result1 = SubsOneByte ( byte(i) );
		result2 = InvSubsOneByte ( result1 );
		
		cout << hex << setw(2) << setfill('0') << int (i) << " " 
			 << hex << setw(2) << setfill('0') 			 
			 << int ( result1 ) << " "
			 << hex << setw(2) << setfill('0') 
			 << int ( result2 ) << endl;
	}
	
}	
