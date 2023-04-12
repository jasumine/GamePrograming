/* 
3. 두개의 배열을 비교 같으면 true 아니면 false를 리턴하는 제네릭 함수 equalsArrays()를 작성하여라.
main 예시)
int x[] = { 1,20,30,100,40,30 };
int y[] = { 1,20,30,100,40,30 };

if (equalsArrays(x, y, 5))
cout << "same";
else
cout << "not same";
*/

#include <iostream>
using namespace std;

template<typename T>
bool equalsArrays(T a[], T b[], int T_SIZE)
{
	for (int i = 0; i < T_SIZE; i++)
	{
		if (a[i] != b[i])
		{
			return false;
		}
		else true;
	}
}

int main()
{
	int x[] = { 1,20,30,100,40,30 };
	int y[] = { 1,20,30,100,40,30 };

	if (equalsArrays(x, y, 5))
		cout << "same";
	else
		cout << "not same";
}