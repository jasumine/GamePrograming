/* #6. �� �迭�� �̾��ִ� concat �Լ��� ���ø��� �Ἥ �ۼ��Ͽ���.
ex) int* concat(int a[], int sizea, int b[], int sizeb)
int main()
{
	int a[] = { 1,2,3,4,5 };
	int b[] = { 6,7,8,9,10 };
	int* p = concat(a, 5, b, 5);
	
	for (int i = 0; i < 10; i++)
	{
		cout << p[i] << " "; // 1 2 3 4 5 6 7 8 9 10 ��������.
	}
}
*/
#include <iostream>
using namespace std;


template<typename T>
T* concat(T a[], int sizeA, T b[], int sizeB)
{
	//static T temp[10];
	T* temp = new T[sizeA + sizeB];
	for (int i = 0; i < sizeA; i++)
	{
		temp[i] = a[i];
	}
	for (int i = 0; i < sizeB; i++)
	{
		temp[sizeA + i] = b[i];
	}
	
	return temp;
}
// �Լ��� ���̳��� temp�� ���� �޾ƿ;��Ѵ�.
// static���� �������ְų� , �����Ҵ� ( T* temp = new T[10];) ���ָ� �ȴ�.

int main()
{
	int a[] = { 1,2,3,4,5 };
	int b[] = { 6,7,8,9,10 };
	int* p = concat(a, 5, b, 5);
	for (int i = 0; i < 10; i++)
	{
		cout << p[i] << " "; // 1 2 3 4 5 6 7 8 9 10 ��������.
	}
}