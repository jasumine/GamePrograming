#include <iostream>
#include <string>
using namespace std;

// ��ó���� ���� �����ؼ� ���� ����!
#define ab = 20
#define APPLE
#define Squared(x) x*x

enum Type
{
	SISSORS = 1,
	ROCK,
	PAPER
};

int main()
{
	// ***getline�� �ַ� �Է��ؼ� ����, ���۸� �����ؾ��� ��쿣 ignore�� ����Ѵ�.***

	string name; 
	getline(cin, name); // ������ �����̽��� �Է��ص� �ȴ�.
	// cin >> name; // �Ʒ��� ���������� �����̽��� �Է��ϸ� a b
	cout << name << endl; // a

	cin >> name;
	cout << name << endl; // b �� ��µȴ�.
	
	/*
	char c1;
	cin >> c1; // �Էºκй����� ���ۿ� �����. ���ۿ� �״�� �����ִ�.
	cout << c1 << " " << endl; // 5 �� ���� ����ϰ�
	cin.ignore(32768, '\n'); // ���ۿ� ����Ȱ� �����Ѵ�. (���͸� �����ϰڴٴ� ��)

	cin >> c1;
	cout << c1 << " " << endl; // 0 �� ���� ����ϴ� �̻��� ����.
	cin.ignore(32768, '\n');

	cin >> c1;
	cout << c1 << " " << endl;
	cin.ignore(32768, '\n');
	*/

#if Squared(2) ==4
	cout << "11" << endl;
#elif
	cout << "22" << endl;
#else
	cout << "33" << endl;
#endif
	cout << "44" << endl;

	// ������ �ִ� ��� #pragma region , endregion
	// ifdef endif ���⼭���� ������� apple�̴�
	// ifndef endif ���⼭������������� ��µ��� �ʴ´�?
	// error �������??!
	// ����Ͽ�, �׽�Ʈ�� ������� ���
#ifdef APPLE
	cout << "apple" << endl;
#endif

#ifndef APPLE
	cout << "not apple" << endl;
#endif

	const int SCI = 1;
	const int ROC = 2;

	srand(static_cast<int>(time(NULL)));

	int wins = 0;
	int total = 0;

	while (1)
	{
		cout << "����(1), ����(2), ��(3)�� �������ּ���!" << endl;
		if (total == 0)
		{
			cout << "���� �·� : ����" << endl;
		}

		else
		{
			int winPercent = wins / (float) total; // int�� int�� ������ 0 �� ���´�.
			cout << "�� �Ǽ� : " << total << "���� �·� :  " << winPercent << endl;
		}

		int input;
		cin >> input;

		switch (input)
		{
		case SISSORS:
			cout << "���� ������ ���� �Դϴ�." << endl;
			break;
		case ROCK:
			cout << "���� ������ ���� �Դϴ�." << endl;
			break;
		case PAPER:
			cout << "���� ������ �� �Դϴ�." << endl;
			break;
		}

		int cpu_Choice = 1 + rand() % 3;// 0 1 2

		switch (cpu_Choice)
		{
		case SISSORS:
			cout << "��ǻ���� ������ ���� �Դϴ�." << endl;
			break;
		case ROCK:
			cout << "��ǻ���� ������ ���� �Դϴ�." << endl;
			break;
		case PAPER:
			cout << "��ǻ���� ������ �� �Դϴ�." << endl;
			break;
		}

		if (input == cpu_Choice)
		{
			cout << "���º��Դϴ�." << endl;
		}

		else if (input == SISSORS && cpu_Choice == PAPER)
		{
			cout << "����� �¸��Դϴ�." << endl;
		}
		else if (input == ROCK && cpu_Choice == SISSORS)
		{
			cout << "����� �¸��Դϴ�." << endl;
		}
		else if (input == PAPER && cpu_Choice == ROCK)
		{
			cout << "����� �¸��Դϴ�." << endl;
		}

		else if (input == SISSORS && cpu_Choice == SISSORS)
		{
			cout << "���º��Դϴ�." << endl;
		}
		else if (input == ROCK && cpu_Choice == ROCK)
		{
			cout << "���º��Դϴ�." << endl;
		}
		else if (input == PAPER && cpu_Choice == PAPER)
		{
			cout << "���º��Դϴ�." << endl;
		}

		else
		{
			cout << "��ǻ���� �¸��Դϴ�." << endl;
		}

		total++;
 	}

#pragma endregion 
}