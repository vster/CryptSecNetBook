#include <iostream>

using namespace std;

const int KEYSIZE = 7;

int EncKey[KEYSIZE] = { 2, 6, 3, 1, 4, 7, 5  };
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
