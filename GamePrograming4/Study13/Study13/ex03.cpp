#include <iostream>
using namespace std;

// 10�� ���� 2*5 =10
//			1 2 3 4 5 6 7 8 9 10 = 10!
//2�ǹ��	  1   1   1   1    1 =8��
//				  1		  1
//                1       1

int main()
{
	int a;

	int line;
	cin >> line;
	for (int i = 0; i < line; i++)
	{
		cin >> a;

		int ret2 = 0, ret5 = 0;

		// 2*5�� 10�� ����� ���ϱ����� 2�� ���ϴ��� ���� 5�� ����� ���� ���ϴ°� �ξ� ������
		/*for (int j = 2; j < a; j *=2)
		{
			ret2 += a / j;
		}*/
		for (int j = 5; j <= a; j *= 5)
		{
			ret5 += a / j;
		}

		cout << ret5 << "\n";
	}

}