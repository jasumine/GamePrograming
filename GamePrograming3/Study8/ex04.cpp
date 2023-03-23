/*4. 배열에서 데이터를 찾는 search() 함수를 템플릿으로 작성하여라.
main 예시)

int x[] = { 1,20,30,100,40,4 };

if (search(100, x, 5)) // 100 이란 숫자를 x배열에서 찾는다. 5는 배열의 크기.
	cout << " 포함되어 있다";
else
	cout << " 포함되어 있지않다";
*/
#include <iostream>
using namespace std;

template<typename T>
bool search(int findNum, T a[], int T_SIZE)
{
	for (int i = 0; i < T_SIZE; i++)
	{
		if (a[i] == findNum)
		{
			return true;
		}

	}
}

int main()
{
	int x[] = { 1,20,30,100,40,4 };

	if (search(100, x, 5)) // 100 이란 숫자를 x배열에서 찾는다. 5는 배열의 크기.
		cout << " 포함되어 있다";
	else
		cout << " 포함되어 있지않다";
}