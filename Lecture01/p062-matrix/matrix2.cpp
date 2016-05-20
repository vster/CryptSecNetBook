#include <iostream>
#include <iomanip>

using namespace std;

const int MS = 3;

int pow ( int x, int n )
{
	int p = 1;
	for ( int i = 0; i < n; i++)
		p *= x;
	return p;
}

//ћинор матрицы
int** minor(int z,int x,int N, int** A){
	int **C = new int*[N-1];
	
	for(int i = 0; i < N-1; i++)
		C[i]=new int[N-1];
	
	for(int h=0, i=0; i<N-1; i++, h++)
	{
		if(i==z) 
			h++;
		for(int k=0,j=0; j<N-1; j++, k++)
		{
			if(k==x) 
				k++;
			C[i][j]=A[h][k];
		}
	}
	return C;
}

//Ќахождение определител€ матрицы
int det(int N,int** A){ // N-размерность матрицы, A-собственно матрица
	int sum=0;
  
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}	
	cout << endl;
  
	if(N!=2)
		for(int i=0;i<N;i++)
		{					//–азложение по первой строке
			sum+=pow((-1),(i+2))*A[0][i]*det(N-1,minor(0,i,N,A));
		}
	else
		sum=A[0][0]*A[N-1][N-1]-A[N-1][0]*A[0][N-1];
	return sum;
}

int main()
{
	int AM[MS][MS] = {	{5,2,1},
						{3,0,-4},
						{2,1,6}};

	int **A = new int*[MS];

	for(int i = 0; i<MS; i++)
		A[i]=new int[MS];
	
	for (int i = 0; i < MS; i++)
		for (int j = 0; j < MS; j++)
			A[i][j] = (int)AM[i][j];

	int d = det(MS, A);

	cout << d;

	return 0;
}