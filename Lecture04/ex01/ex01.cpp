#include <iostream>
using namespace std;

const int P = 4;

bool find ( int a, int arr[], int n )
{
	for (int i = 0; i < n; i++)
		if ( a == arr[i] )
			return true;

	return false;
}

int main()
{
	int resarr[P][P];
	int i;

	for ( int b = 1; b < P; b++ )
	{
		for (int n = 0, i = 0; n < P; n++)
		{
			int result = (n * b)%P;
			if ( !find ( result, resarr[b], i ) )
			{
				resarr[b][i] = result;
				cout << b << '\t' << n << '\t' <<  resarr[b][i++] << endl;
			}
		}
	cout << endl;
	}
}