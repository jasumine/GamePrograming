// ���̰� 10�� �迭�� �����ϰ�, �� 10���� ������ �Է¹޴´�.
// ��, �Է¹��� ���ڰ� Ȧ���� �迭�� �պ���, ¦���� �ڿ������� ä��������.
// �׸��� �迭�� ����ϱ�.

#include <iostream>

using namespace std;

int main()
{
	char num[10];
	cout << "���� 10���� �Է��ϼ���." << endl;
	for (int i = 0; i < 10; i++)
	{
		cin >> num[i];
	}

	for (int i = 0; i < 10; i++)
	{
		if (num[i] % 2 == 1)
		{
			continue;
		}
	}

}