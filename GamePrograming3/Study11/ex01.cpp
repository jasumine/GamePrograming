#include <iostream>
#include <vector>
#include <string>

using namespace std;

void makeAnswer(vector<int>& answer, int num)
{
	answer.resize(5);
	vector<int>candidate(10, 0); // 10칸의 0을 생성
	for (int i = 0; i < 10; i++)
	{
		candidate[i] = i;
	}
	for (int i = 0; i < num; i++)
	{
		int idx = rand() % candidate.size();
		answer[i] = candidate[idx]; //0~9 랜덤으로 넣는다.
		candidate.erase(candidate.begin() + idx); //넣었으니까 지워준다.
	}
}

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	cout << "야구게임 시작" << endl;
	int count = 0;
	int strike = 0;
	int ball = 0;

	vector<int> aiAnswer;
	vector<int> myAnswer;
	
	myAnswer.resize(5); // 미리 공간을 할당해 주면 느려지는 걸 막을 수 있다. 효율 상승
	makeAnswer(aiAnswer, 3);
	while (count < 10)
	{
		cout << "1~9 중에 3개의 숫자를 입력하세요." << '\n';
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
			cout << count << "번 만에 맞췄습니다." << '\n';
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