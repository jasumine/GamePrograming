#include <iostream>

using namespace std;

// 가위바위보 게임
enum Type
{
	SISSORS = 1,
	ROCK,
	PAPER
};

int main()
{
	int total = 0;
	int win_number = 0;
	float win_rate;
	while (1)
	{
		win_rate = (float) win_number / total * 100;
		cout << "가위(1), 바위(2), 보(3) 중 하나를 선택하세요." << endl;
		if(total == 0)
			cout << "총 판수 : " << total << " 현재 승률 : 0 " << endl;
		else cout << "총 판수 : " << total << " 현재 승률 : " <<win_rate << endl;

		
		int my_choice;
		cin >> my_choice;
		if (my_choice != 1 && my_choice != 2 && my_choice != 3)  continue;
		switch (my_choice)
		{
		case SISSORS:
			cout << "플레이어는 가위를 골랐습니다." << endl;
			break;
		case ROCK:
			cout << "플레이어는 바위를 골랐습니다." << endl;
			break;
		case PAPER:
			cout << "플레이어는 보를 골랐습니다." << endl;
			break;
		}
		
		srand(time(0));
		int cpu_choice = rand() % 2 + 1; // 1 2 3

		switch (cpu_choice)
		{
		case SISSORS:
			cout << "컴퓨터는 가위를 골랐습니다." << endl;
			break;
		case ROCK:
			cout << "컴퓨터는 바위를 골랐습니다." << endl;
			break;
		case PAPER:
			cout << "컴퓨터는 보를 골랐습니다." << endl;
			break;
		}

		if (my_choice == cpu_choice)
		{
			cout << "무승부 입니다." << endl;
			total++;
		}
		
		// 플레이어 승리
		else if (my_choice == SISSORS && cpu_choice == PAPER)
		{
			cout << "플레이어가 이겼습니다." << endl;
			win_number++;
			total++;
		}
		else if (my_choice == ROCK && cpu_choice == SISSORS)
		{
			cout << "플레이어가 이겼습니다." << endl;
			win_number++;
			total++;
		}
		else if (my_choice == PAPER && cpu_choice == ROCK)
		{
			cout << "플레이어가 이겼습니다." << endl;
			win_number++;
			total++;
		}

		else 
		{ 
			cout << "컴퓨터의 승리입니다." << endl;
			total++;
		}
	}
}