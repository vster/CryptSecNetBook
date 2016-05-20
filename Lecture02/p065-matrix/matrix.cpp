#include <math.h>
int gaus_ostatok;
// ������ ��������� ��������������
// 0 == ��

long double gaus_deter;
//  � ������ ��������� ��������� �����������

double gaus_minved;
//  ����������� ������� �������
//  ����� ������������ ��� ������ ��������


#define _NaN() (double&)*"Implementation dependent";
//  ����������� ��� ������������� ���������
//  ��� ������������� ���������

template<int N>
inline static  void  invers(double m[N][N])
{
       //  (c) Drobotenko    http://drobotenko.com

       int rn[N],cn[N];
       int j,k;

       for(j=N;j--;)
         rn[j]=cn[j]=j;
       gaus_minved=1e99;
       gaus_deter=1;
       for(gaus_ostatok=N;gaus_ostatok;gaus_ostatok--)
       {  
		  int jved,kved;
          double vved=-1,t;

          // ����� ��������
          for(j=N;j--;)
          {  
			if(~rn[j])
             for(k=N;k--;)
               if(~cn[k])
               if(vved<fabs(m[j][k]))
                  vved=fabs(m[j][k]),jved=j,kved=k;
          }
          
          if(gaus_minved>vved)
             gaus_minved=vved;
          gaus_deter*=m[jved][kved];
          if(vved<1e-99)
          {  for(j=N;j--;)
             {  
				if(~rn[j]) for(k=N;k--;)
                  m[j][k]=_NaN();
                if(~cn[j]) for(k=N;k--;)
                  m[k][j]=_NaN();
             }
             return;
          }

          int jt=rn[jved],kt=cn[kved];

          // ������������
          for(j=N;j--;)
              t=m[kt][j],m[kt][j]=m[jved][j],m[jved][j]=t;
          for(j=N;j--;)
              t=m[j][jt],m[j][jt]=m[j][kved],m[j][kved]=t;

          rn[jved]=rn[kt];
          cn[kved]=cn[jt];
          rn[kt]=cn[jt]=-1;

          vved=m[kt][jt];   m[kt][jt]=1;
          for(j=N;j--;)
          {  if(j==kt)
               continue;
             double mul=m[j][jt]/vved;
             m[j][jt]=0;
             for(k=N;k--;)
               m[j][k]-=m[kt][k]*mul;
               // ����� ���������� ���� ����� N^3 ��������
          }
          for(k=N;k--;)
              m[kt][k]/=vved;
       }
}

const int r=5;
double m[r][r],e[r][r];
double mval(int i,int j)
 {  // �������� �������
    return int(1000./(.1+fabs(i-.95*j)))/1000.;
 }

int main(int, char **)
{  
	for(int i=r;i--;)
    for(int j=r;j--;)
		m[i][j]=mval(i,j);

//   invers(m);
	invers<r>(m);	

	for(int i=r;i--;)
	for(int j=r;j--;)
	{ // �������� � � ���������� ��������� �������
      e[i][j]=0;
      for(int k=r;k--;)
			e[i][j]+=m[i][k]*mval(k,j);
	}
}