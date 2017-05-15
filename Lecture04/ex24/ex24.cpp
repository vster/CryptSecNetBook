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
	p = 0x19;
	
	GF2X Px;
	GF2XFromZZ ( Px, p );
	
	// gf2x_output_be ( Px, 8 );
	cout << endl;

	GF2E::init(Px);
	
	GF2X ax;
	GF2E arr[16];

	long i, j;
	for ( i = 0; i < 16; i++)
	{
        ZZ ii=conv<ZZ>(i);
        GF2XFromZZ( ax, ii );
		arr[i] = conv<GF2E>(ax);
	}
	
	GF2E sum;
	for ( i = 0; i < 16; i++)
	{
		for ( j = 0; j < 16; j++)
		{
			sum = arr[i]+arr[j];
			gf2x_output_be( conv<GF2X>(sum), 4);
			cout << " ";
		}
		cout << endl;
	}
	cout << endl;

	GF2E mult;
	for ( i = 0; i < 16; i++)
	{
		for ( j = 0; j < 16; j++)
		{
			mult = arr[i]*arr[j];
			gf2x_output_be( conv<GF2X>(sum), 4);
			cout << " ";
		}
		cout << endl;
	}


	return 0;
}
