#include <iostream>
using namespace std;


int det1 ( int A1 )
{
	int det = A1;
	return det;
}

int det2 ( int A2[2][2] )
{
	int det = A2[0][0] * det1(A2[1][1]) - A2[0][1] * det1(A2[1][0]);
	return det;
}

int det3 ( int A3[3][3] )
{
	int det = A3[0][0] * det2 (  )
			- A3[0][1] * det2 (  )
			+ A3[0][2] * det2 (  )
	return det;

}



int main()
{
	int A[2][2] = {	{5,2},
					{3,4}};	
	int d = det2( A );	

	return 0;
}
