#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int euler(int n)
{
	int t = sqrt(float(n))+1;
	int answ = 1, ta, i;
  
	for ( i = 2; i < t; i++ )
	{   
		ta = 0;
    
		while ( n%i == 0 )
		{
			ta++;
			n /= i;
		}   
		if ( ta )
			answ *= (int)pow(float(i),ta-1) * (i-1);    
	}
  
	if (n-1)   
		answ *= (n-1);
	return answ;
}
 
int main()
{
	const long Num = 100;

	vector <long> phi(Num);
	vector <long> phicnt(Num);
	vector <long> orig(Num);


	for ( int n = 1; n < Num; n++ )
	{
		phi[n] = euler(n);
		cout << n << " " << phi[n] << endl;	
	}

	/*
	for ( int n = 1; n < Num; n++ )
	{
		// phi[n] = euler(n);
		cout << n << " " << phi[n] << endl;	
	}
	*/

	for ( int n = 1; n < Num; n++ )
	{
		phicnt[ phi[n] ]++;
		// cout << n << " " << phi[n] << endl;	
	}

	for (  int n = 1; n < Num; n++ )
	{
		if ( phicnt[n] > 0 )
			cout << n << " " << phicnt[n] << endl;
	}

	return 0;
}