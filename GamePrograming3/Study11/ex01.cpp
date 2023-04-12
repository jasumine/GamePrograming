#include <iostream>
#include <vector>
#include <string>

using namespace std;

void makeAnswer(vector<int>& answer, int num)
{
	answer.resize(5);
	vector<int>candidate(10, 0); // 10ĭ�� 0�� ����
	for (int i = 0; i < 10; i++)
	{
		candidate[i] = i;
	}
	for (int i = 0; i < num; i++)
	{
		int idx = rand() % candidate.size();
		answer[i] = candidate[idx]; //0~9 �������� �ִ´�.
		candidate.erase(candidate.begin() + idx); //�־����ϱ� �����ش�.
	}
}

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	cout << "�߱����� ����" << endl;
	int count = 0;
	int strike = 0;
	int ball = 0;

	vector<int> aiAnswer;
	vector<int> myAnswer;
	
	myAnswer.resize(5); // �̸� ������ �Ҵ��� �ָ� �������� �� ���� �� �ִ�. ȿ�� ���
	makeAnswer(aiAnswer, 3);
	while (count < 10)
	{
		cout << "1~9 �߿� 3���� ���ڸ� �Է��ϼ���." << '\n';
		cin >> myAnswer[0] >> myAnswer[1] >> myAnswer[2];

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (aiAnswer[i] == myAnswer[j])
				{
					if (i == j)
					{
						strike++;
					}
					else
					{
						ball++;
					}
				}
			}
		}
		count++;
		if (strike == 3)
		{
			cout << count << "�� ���� ������ϴ�." << '\n';
		}
		else
		{
			cout << "Strike : " << strike
				<< '\t' << "Ball : " << ball << '\n';
			strike = 0;
			ball = 0;
		}
	}


}