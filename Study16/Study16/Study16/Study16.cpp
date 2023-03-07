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
	Game() { cout << "������ �����ϰڽ��ϴ�." << endl; }
	~Game() {}
	void randNumber() // answer �����Լ�
	{
		srand(time(0));
		_answer = rand() % 100;
		while(_answer == 0 || _answer == 99) // runGame�� while�� ���ǿ� ���߱� ���ؼ� �߰�
			_answer = rand() % 100; 
	}
	int runGame(Player p1, Player p2)
	{
		// �ּҰ��� �ִ밪�� ��� �ٸ� ��쿡 while���� ����
		while (_minNumber != _answer || _maxNumber != _answer)
		{
			// #player1
			cout << "����" << _minNumber << "�� " << _maxNumber << "���̿� �ֽ��ϴ�." << endl;
			cout << p1.getName() << ">>";
			cin >> p1.answerNum;

			// ���ڰ� �ƴϰų�, 0���� �۰� 99���� ū���
			if (isdigit(p1.answerNum) == 0 && p1.answerNum < 0 && p1.answerNum >99)
			{
				cout << "0 ~ 99 ������ ���ڸ� �Է��ϼ���." << endl;
			}

			// �Է��� ���� ���� ���
			if (p1.answerNum == _answer)
			{
				cout << p1.getName() << "�� �̰���ϴ�." << endl;
				return 0;
			}
			// �Է��� ���� ���� �ƴ� ���
			else
			{
				// �亸�� Ŭ��� max�� ������� min�� �־��ش�
				if (p1.answerNum > _answer) { _maxNumber = p1.answerNum; }
				else if (p1.answerNum < _answer) { _minNumber = p1.answerNum; }

				// #player2
				cout << "����" << _minNumber << "�� " << _maxNumber << "���̿� �ֽ��ϴ�." << endl;
				cout << p2.getName() << ">>";
				cin >> p2.answerNum;

				// ���ڰ� �ƴϰų�, 0���� �۰� 99���� ū���
				if (isdigit(p1.answerNum) == 0 && p1.answerNum <= 0 && p1.answerNum > 99)
				{
					cout << "0 ~ 99 ������ ���ڸ� �Է��ϼ���." << endl;
				}
				
				// �Է��� ���� ���� ���
				if (p1.answerNum == _answer)
				{
					cout << p2.getName() << "�� �̰���ϴ�." << endl;
					return 0;
				}
				// �Է��� ���� ���� �ƴ� ���
				else
				{	// �亸�� Ŭ��� max�� ������� min�� �־��ش�
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
	cout << "�̸��� �Է��ϼ���.";
	string player1;
	cin >> player1;
	Player p1(player1);

	cout << "�̸��� �Է��ϼ���.";
	string player2;
	cin >> player2;
	Player p2(player2);

	Game game;
	game.randNumber();
	game.runGame(p1, p2);

}