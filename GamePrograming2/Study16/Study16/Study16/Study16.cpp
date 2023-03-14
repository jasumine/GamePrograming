#include <iostream>

using namespace std;

class Player
{
public:
	Player(string name) : _name(name) {}
	~Player() {}
	string getName() { return _name; }
	static int answerNum;
private:
	string _name;
};

int Player::answerNum = 0;

class Game
{
public:
	Game() { cout << "게임을 시작하겠습니다." << endl; }
	~Game() {}
	void randNumber() // answer 랜덤함수
	{
		srand(time(0));
		_answer = rand() % 100;
		while(_answer == 0 || _answer == 99) // runGame의 while문 조건에 맞추기 위해서 추가
			_answer = rand() % 100; 
	}
	int runGame(Player p1, Player p2)
	{
		// 최소값과 최대값이 답과 다를 경우에 while문을 실행
		while (_minNumber != _answer || _maxNumber != _answer)
		{
			// #player1
			cout << "답은" << _minNumber << "와 " << _maxNumber << "사이에 있습니다." << endl;
			cout << p1.getName() << ">>";
			cin >> p1.answerNum;

			// 숫자가 아니거나, 0보다 작고 99보다 큰경우
			if (isdigit(p1.answerNum) == 0 && p1.answerNum < 0 && p1.answerNum >99)
			{
				cout << "0 ~ 99 사이의 숫자만 입력하세요." << endl;
			}

			// 입력한 값이 답일 경우
			if (p1.answerNum == _answer)
			{
				cout << p1.getName() << "가 이겼습니다." << endl;
				return 0;
			}
			// 입력한 값이 답이 아닐 경우
			else
			{
				// 답보다 클경우 max에 작을경우 min에 넣어준다
				if (p1.answerNum > _answer) { _maxNumber = p1.answerNum; }
				else if (p1.answerNum < _answer) { _minNumber = p1.answerNum; }

				// #player2
				cout << "답은" << _minNumber << "와 " << _maxNumber << "사이에 있습니다." << endl;
				cout << p2.getName() << ">>";
				cin >> p2.answerNum;

				// 숫자가 아니거나, 0보다 작고 99보다 큰경우
				if (isdigit(p1.answerNum) == 0 && p1.answerNum <= 0 && p1.answerNum > 99)
				{
					cout << "0 ~ 99 사이의 숫자만 입력하세요." << endl;
				}
				
				// 입력한 값이 답일 경우
				if (p1.answerNum == _answer)
				{
					cout << p2.getName() << "가 이겼습니다." << endl;
					return 0;
				}
				// 입력한 값이 답이 아닐 경우
				else
				{	// 답보다 클경우 max에 작을경우 min에 넣어준다
					if (p1.answerNum >= _answer) { _maxNumber = p1.answerNum; }
					else if (p1.answerNum < _answer) { _minNumber = p1.answerNum; }
				}
			}

		} 
	}

private:
	int _answer;
	int _minNumber = 0;
	int _maxNumber = 99;

};

int main()
{
	cout << "이름을 입력하세요.";
	string player1;
	cin >> player1;
	Player p1(player1);

	cout << "이름을 입력하세요.";
	string player2;
	cin >> player2;
	Player p2(player2);

	Game game;
	game.randNumber();
	game.runGame(p1, p2);

}