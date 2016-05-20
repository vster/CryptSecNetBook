#include <iostream>
using namespace std;

static int A[3][3] = 
{	{3,4,6},
	{1,1,8},
	{5,5,3}};

/*
static int B[3][3] = 
{	{2,0,1},
	{1,1,0},
	{5,2,4}};
*/
static int B[3][3] = 
{{9,4,8},
{1,7,6},
{0,5,7}};

static int C[3][3];

void mult()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			C[i][j] = 0;
			for ( int k = 0; k < 3; k++ )
				C[i][j] += A[i][k]*B[k][j];	
			C[i][j] %= 10;
		}
}

int main()
{
	mult();

	return 0;
}