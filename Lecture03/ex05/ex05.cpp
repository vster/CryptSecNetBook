#include <iostream>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

int main()
{
	ZZ i, p, i1;
	p = 39;
		
	// ����� ��������������� ��������
	for ( i = 1; i < p; i++ )
	{
		if ( !InvModStatus ( i1, i, p ) )
			InvMod ( i1, i, p );
		else
			continue;
		cout << i << " " << i1 << endl;
	}

}
