#include <iostream>

using namespace std;


class Player
{
public:
	void setName()
	{
		cout << "이름을 입력하세요.";
		cin >> _name;
	}
	string getName() { return _name; }

private:
	string _name;
};

class Game
{
public:
	void GamePlay(Player p[])
	{
		ans = rand() % 100; // 0~99중

		cout << "게임을 시작하겠습니다. " << endl;

		int i = 0;
		while (true)
		{
			cout << "답은 " << left << "와 " << right << "사이에 있습니다. " << endl;
			cout << p[i%2].getName() << ">>"; // 0, 1이 반복됨.
			
			int num;
			cin >> num;

			if (num == ans)
			{
				cout << p[i % 2].getName() << "가 이겼습니다." << endl;
				break;
			}
			else if (num > ans)
				right = num;
			else
				left = num;
		}
		

	}

private:
	int ans;
	int left = 0, right = 99;
};

int main()
{
	srand(static_cast<int>(time(NULL)));
	Player p[2];
	
	p[0].setName();
	p[1].setName();

	Game game;
	game.GamePlay(p);
}
