#include <iostream>

using namespace std;

// 가위바위보 게임
int main()
{

	int lose_number = 0;
	int win_number = 0;
	float win_rate = 0;
	int my_choice;

	while (1)
	{
		srand(time(0));
		int cpu_chocie = rand() & 2; // 0 == 가위, 1 == 바위 , 2 == 보
		
		cout << "가위(1), 바위(2), 보(3)를 선택해주세요!" << endl;
		cout << "현재 승률 : " << win_rate << endl;
		cin >> my_choice;

		// player가 가위 인경우
		if (my_choice== 1 && cpu_chocie == 0) // 가위 가위
		{
			cout << "가위를 고르셨습니다." << endl;
			cout << "컴퓨터는 가위를 골랐습니다." << endl;
			cout << "무승부 입니다." << endl;
			lose_number++;
		}
		else if (my_choice ==1 && cpu_chocie == 1 ) // 가위 바위
		{
			cout << "가위를 고르셨습니다." << endl;
			cout << "컴퓨터는 바위를 골랐습니다." << endl;
			cout << "컴퓨터의 승리 입니다." << endl;
			lose_number++;
		}
		else if (my_choice == 1 && cpu_chocie == 2) // 가위 보
		{
			cout << "가위를 고르셨습니다." << endl;
			cout << "컴퓨터는 보를 골랐습니다." << endl;
			cout << "당신의 승리 입니다." << endl;
			win_number++;
		}

		// player가 바위인 경우
		else if (my_choice == 2 && cpu_chocie == 0) // 바위 가위
		{
			cout << "바위를 고르셨습니다." << endl;
			cout << "컴퓨터는 가위를 골랐습니다." << endl;
			cout << "당신의 승리 입니다." << endl;
			win_number++;
		}
		else if (my_choice == 2 && cpu_chocie == 1) // 바위 바위
		{
			cout << "바위를 고르셨습니다." << endl;
			cout << "컴퓨터는 바위를 골랐습니다." << endl;
			cout << "무승부입니다." << endl;
			lose_number++;
		}
		else if (my_choice == 2 && cpu_chocie == 2) // 바위 보
		{
			cout << "바위를 고르셨습니다." << endl;
			cout << "컴퓨터는 보를 골랐습니다." << endl;
			cout << "컴퓨터의 승리입니다." << endl;
			lose_number++;
		}

		// player가 보인 경우
		else if (my_choice == 3 && cpu_chocie == 0) // 보 가위
		{
			cout << "보를 고르셨습니다." << endl;
			cout << "컴퓨터는 가위를 골랐습니다." << endl;
			cout << "컴퓨터의 승리 입니다." << endl;
			lose_number++;
		}
		else if (my_choice == 3 && cpu_chocie == 1) // 보 바위
		{
			cout << "보를 고르셨습니다." << endl;
			cout << "컴퓨터는 바위를 골랐습니다." << endl;
			cout << "당신의 승리입니다." << endl;
			win_number++;
		}
		else if (my_choice == 3 && cpu_chocie == 2) // 보 보
		{
			cout << "보를 고르셨습니다." << endl;
			cout << "컴퓨터는 보를 골랐습니다." << endl;
			cout << "무승부입니다." << endl;
			lose_number++;
		}

		else
		{
			cout << "가위(1), 바위(2), 보(3)만 입력할 수 있습니다." << endl;
			continue;
		}

		int total_socre = lose_number + win_number;
		win_rate = (float)win_number / total_socre * 100;
		cout << "총 전적 : " << total_socre << ", 승률 : " << win_rate << endl;

	}

}

