/*4. �迭���� �����͸� ã�� search() �Լ��� ���ø����� �ۼ��Ͽ���.
main ����)

int x[] = { 1,20,30,100,40,4 };

if (search(100, x, 5)) // 100 �̶� ���ڸ� x�迭���� ã�´�. 5�� �迭�� ũ��.
	cout << " ���ԵǾ� �ִ�";
else
	cout << " ���ԵǾ� �����ʴ�";
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

	if (search(100, x, 5)) // 100 �̶� ���ڸ� x�迭���� ã�´�. 5�� �迭�� ũ��.
		cout << " ���ԵǾ� �ִ�";
	else
		cout << " ���ԵǾ� �����ʴ�";
}