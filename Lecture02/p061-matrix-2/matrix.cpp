#include <iostream>
using namespace std;

/*
static int A[2][3] = {	{5,2,1},
						{3,2,4} };

static int B[3][4] = {	{7,3,2,1},
						{8,0,0,2},
						{1,3,4,0}};

*/

static int A[3][3] = 
{	{3,4,6},
	{1,1,8},
	{5,8,3}};

static int B[3][3] = 
{	{2,0,1},
	{1,1,

static int C[3][3];

void mult()
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 4; j++)
		{
			C[i][j] = 0;
			for ( int k = 0; k < 3; k++ )
				C[i][j] += A[i][k]*B[k][j];
		}
}

int main()
{
	mult();

	return 0;
}
