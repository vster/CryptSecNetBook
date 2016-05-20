#include <iostream>
#include <iomanip>
using namespace std;

const int P = 7;

bool find ( int a, int arr[], int n )
{
	for (int i = 0; i < n; i++)
		if ( a == arr[i] )
			return true;

	return false;
}

int main()
{
	int H[P][P];
	int n, i, ord;

	for ( int b = 0; b < P; b++ )
	{
	// cout << b << '\t';
		for ( n = 0, i = 0; n < P; n++)
		{
			int result = (n * b)%P;
			if ( !find ( result, H[b], i ) )
			{
				H[b][i++] = result;
				// cout <<  resarr[b][i++] << " ";
			}
		}
	ord = i;
	cout << setw(2)<< b << "  ord = " << setw(2) << ord << "  ";
	for ( i = 0; i < ord; i++)
		cout << H[b][i] << " ";
	cout << endl;
	}
}