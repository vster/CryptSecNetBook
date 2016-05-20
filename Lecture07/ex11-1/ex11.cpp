#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	for ( int i = 0, a = 1; i < 14; i++)
	{
		a %= 256;
		cout << setw(2) << i << " " 
			 << hex << a << endl;
		a <<= 1;
	}
	
	return 0;
}