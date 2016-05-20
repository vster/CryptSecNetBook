#include <iostream>
using namespace std;



static int iA[2][3] = {	{5, 2, 1},
						{3, 2, 10}};

static int iB[2][3] = {	{7, 2, 3},
						{8, 10, 20}};

static int iC[2][3];

void sum()
{
	int i,j;
	
	for (j = 0; j < 2; j++)
		for (i = 0; i < 3; i++)
			iC[j][i] = iA[j][i] + iB[j][i];
}

void sub()
{
	int i,j;
	
	for (j = 0; j < 2; j++)
		for (i = 0; i < 3; i++)
			iC[j][i] = iA[j][i] - iB[j][i];
}

int main()
{
	sum();
	
	sub();
	
	return 0;
}

