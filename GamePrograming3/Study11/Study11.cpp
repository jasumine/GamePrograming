/* 
* 숫자야구게임 만들기.
랜덤하게 컴퓨터가 3개의 숫자를 정한뒤 
그걸 내가 풀고 
몇번만에 맞췄는지를 만들어주는 프로그램을 작성하여라.
컴퓨터가 내는 숫자는 중복이 되면 안된다(3, 3, 5 x) 
랜덤으로 생성하게해서 재미있게 야구게임을 만들어보자.
10번안에 맞추도록하기!
다 했으면 숫자가 3개아니라 4개맞추기로 바꾸기.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<int> answer;
	srand(time(0));
	int number = rand() % 9; // 랜덤한 숫자 생성
	answer.push_back(number);
	while (answer.size() < 3)
	{
		number = rand() % 9;
		for (int i = 0; i <answer.size(); i++)
		{
			// answer내에 number랑 숫자가 다르면 answer에 넣는다.
			if (answer.size()<3 && answer[i] != number)
			{
				answer.push_back(number);
			}
		}

	}

	for (auto it = answer.begin(); it != answer.end(); it++)
	{
		cout << *it << " ";
	}
	
	string choose;
	int trying = 0;

	cout << "야구게임 시작 " << endl;
	while(1)
	{
		int strike = 0, ball = 0;
		cout << "1~9 중 3개의 숫자를 입력하세요." << endl;
		cin >> choose[0] >> choose[1] >> choose[2];
		vector<int>::iterator it = answer.begin();
		for (int i = 0; i<answer.size(); i++)
		{
			it += i;
			for (int j = 0; j<choose.size(); j++)
			{
				if ( i == j && it[i] == choose[i])
				{// vector의 값과 chooose의 값이 같으면 strike
					strike++;
				}
				else if (it[i] == choose[i])
				{
					ball++;
				}
			}
			
		}
		cout << "Strike : " << strike
			<< "	Ball : " << ball << endl;
		trying++;
		cin.ignore();
		if (strike == 3)
		{
			break;
		}
	}

	cout << trying << "번 만에 맞췄습니다." << endl;
}


