#include <iostream>

using namespace std;


class Player
{
public:
	void setName()
	{
		cout << "�̸��� �Է��ϼ���.";
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
		ans = rand() % 100; // 0~99��

		cout << "������ �����ϰڽ��ϴ�. " << endl;

		int i = 0;
		while (true)
		{
			cout << "���� " << left << "�� " << right << "���̿� �ֽ��ϴ�. " << endl;
			cout << p[i%2].getName() << ">>"; // 0, 1�� �ݺ���.
			
			int num;
			cin >> num;

			if (num == ans)
			{
				cout << p[i % 2].getName() << "�� �̰���ϴ�." << endl;
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
