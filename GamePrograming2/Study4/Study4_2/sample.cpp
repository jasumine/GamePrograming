#include <iostream>
#include <string>
using namespace std;

// 전처리문 요즘엔 정의해서 쓰지 않음!
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
	// ***getline을 주로 입력해서 쓰고, 버퍼를 무시해야할 경우엔 ignore를 사용한다.***

	string name; 
	getline(cin, name); // 을쓰면 스페이스를 입력해도 된다.
	// cin >> name; // 아래와 마찬가지로 스페이스를 입력하면 a b
	cout << name << endl; // a

	cin >> name;
	cout << name << endl; // b 가 출력된다.
	
	/*
	char c1;
	cin >> c1; // 입력부분받을때 버퍼에 저장됨. 버퍼에 그대로 남아있다.
	cout << c1 << " " << endl; // 5 를 여기 출력하고
	cin.ignore(32768, '\n'); // 버퍼에 저장된걸 무사한다. (엔터를 무시하겠다는 뜻)

	cin >> c1;
	cout << c1 << " " << endl; // 0 을 여기 출력하는 이상한 현상.
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

	// 접을수 있는 기능 #pragma region , endregion
	// ifdef endif 여기서부터 저기까지 apple이다
	// ifndef endif 여기서부터저기까지는 출력되지 않는다?
	// error 에러출력??!
	// 모바일용, 테스트용 등등으로 사용
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
		cout << "가위(1), 바위(2), 보(3)를 선택해주세요!" << endl;
		if (total == 0)
		{
			cout << "현재 승률 : 없음" << endl;
		}

		else
		{
			int winPercent = wins / (float) total; // int를 int로 나누면 0 이 나온다.
			cout << "총 판수 : " << total << "현재 승률 :  " << winPercent << endl;
		}

		int input;
		cin >> input;

		switch (input)
		{
		case SISSORS:
			cout << "나의 선택은 가위 입니다." << endl;
			break;
		case ROCK:
			cout << "나의 선택은 바위 입니다." << endl;
			break;
		case PAPER:
			cout << "나의 선택은 보 입니다." << endl;
			break;
		}

		int cpu_Choice = 1 + rand() % 3;// 0 1 2

		switch (cpu_Choice)
		{
		case SISSORS:
			cout << "컴퓨터의 선택은 가위 입니다." << endl;
			break;
		case ROCK:
			cout << "컴퓨터의 선택은 바위 입니다." << endl;
			break;
		case PAPER:
			cout << "컴퓨터의 선택은 보 입니다." << endl;
			break;
		}

		if (input == cpu_Choice)
		{
			cout << "무승부입니다." << endl;
		}

		else if (input == SISSORS && cpu_Choice == PAPER)
		{
			cout << "당신의 승리입니다." << endl;
		}
		else if (input == ROCK && cpu_Choice == SISSORS)
		{
			cout << "당신의 승리입니다." << endl;
		}
		else if (input == PAPER && cpu_Choice == ROCK)
		{
			cout << "당신의 승리입니다." << endl;
		}

		else if (input == SISSORS && cpu_Choice == SISSORS)
		{
			cout << "무승부입니다." << endl;
		}
		else if (input == ROCK && cpu_Choice == ROCK)
		{
			cout << "무승부입니다." << endl;
		}
		else if (input == PAPER && cpu_Choice == PAPER)
		{
			cout << "무승부입니다." << endl;
		}

		else
		{
			cout << "컴퓨터의 승리입니다." << endl;
		}

		total++;
 	}

#pragma endregion 
}