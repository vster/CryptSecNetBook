#include <iostream>
using namespace std;

static int A[1][3] = { 5, 2, 1 };

static int B[3][1] = { {7}, {8}, {2} };

static int C[1][1];

void mult()
{
	C[0][0] = 0;
	for ( int i = 0; i < 3; i++)
		C[0][0] += A[0][i]*B[i][0];
}

int main()
{
	mult();

	return 0;
}