// ���̰� 10�� �迭, 10���� ���� �Է¹޾Ƽ�, Ȧ���� ¦���� ������ ����ϴ� ���α׷�
// 10���� �迭�� main���� �ް�, �迭���� �����ϴ� Ȧ���� ����ϴ� �Լ�,
// �迭���� ¦���� ����ϴ� �Լ��� �����ؼ� �� �Լ��� ȣ��

#include <iostream>
#include <string>

using namespace std;

void zero(int numbers[]) // ¦�� ��� �Լ�
{
	for (int i = 0; i < 10; i++)
	{
		if (numbers[i] % 2 == 0)
		{
			cout << "¦�� : " << numbers[i] << ",";
		}
	}
}

void one(int numbers[]) // Ȧ�� ��� �Լ�
{
	for (int i = 0; i < 10; i++)
	{
		if (numbers[i] % 2 == 1)
		{
			cout << "Ȧ�� : " << numbers[i] << " ,";
		}
	}
}

int main()
{
	int numbers[10];
	cout << "���� 10���� �Է� �ϼ���." << endl;
	for (int i = 0; i < 10; i++)
	{
		cin >> numbers[i];
	}
	zero(numbers);
	one(numbers);
}