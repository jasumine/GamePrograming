/* #6. 두 배열를 이어주는 concat 함수를 템플릿을 써서 작성하여라.
ex) int* concat(int a[], int sizea, int b[], int sizeb)
int main()
{
	int a[] = { 1,2,3,4,5 };
	int b[] = { 6,7,8,9,10 };
	int* p = concat(a, 5, b, 5);
	
	for (int i = 0; i < 10; i++)
	{
		cout << p[i] << " "; // 1 2 3 4 5 6 7 8 9 10 이찍히게.
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
// 함수가 끝이나도 temp의 값을 받아와야한다.
// static으로 선언해주거나 , 동적할당 ( T* temp = new T[10];) 해주면 된다.

int main()
{
	int a[] = { 1,2,3,4,5 };
	int b[] = { 6,7,8,9,10 };
	int* p = concat(a, 5, b, 5);
	for (int i = 0; i < 10; i++)
	{
		cout << p[i] << " "; // 1 2 3 4 5 6 7 8 9 10 이찍히게.
	}
}