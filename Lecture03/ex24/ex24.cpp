#include <iostream>

using namespace std;

const int KEYSIZE = 6;

int EncKey[KEYSIZE] = { 3, 2, 6, 1, 5, 4  };
int DecKey[KEYSIZE];

int main()
{
	
	// ���� ����������
	for (int i = 0; i < KEYSIZE; i++)
		cout << EncKey[i] << " ";
	cout << endl;

	// �������� ����� ���������� � ���� ������������
	for (int i = 0; i < KEYSIZE; i++)
		DecKey[EncKey[i]-1] = i+1;

	// ���� ������������
	for (int i = 0; i < KEYSIZE; i++)
		cout << DecKey[i] << " ";
	cout << endl;
}