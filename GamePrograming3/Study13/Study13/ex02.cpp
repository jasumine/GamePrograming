/* #2. ����.
class Player
{
public:
	Player(int id, string name) : _id(id), _name(name)
	{
	}
	int getId() { return _id; }
	string getName() { return _name; }
private:
	int _id;
	string _name;
};

Ŭ���� �÷��̾ �ִ�.vector �� ���ؼ� �÷��̾
1.���� 2.���� 3.��ü �÷��̾�� 4.���Ḧ �����.
vector<Player*> �� �Ẹ�°� ��õ!
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Player
{
public:
	Player(int id, string name) : _id(id), _name(name)
	{

	}
	int getId() { return _id; }
	string getName() { return _name; }
private:
	int _id;
	string _name;
};

int main()
{
	vector<Player*>player;
	int id;
	string nickname;
	
	cout << "�÷��̾ �����ϰ� �����ϴ� ���α׷��Դϴ�." << '\n';
	while (1)
	{
		cout << "1.����		2.����		3.��ü �÷��̾� ����		4.����" << '\n';
		int input;
		cin >> input;
		if (input == 1)
		{
			cout << "id�� �Է��ϼ���." << '\n';
			cin >> id;
			cin.ignore();
			cout << "nickname�� �Է��ϼ���." << '\n';
			getline(cin, nickname);

			Player* p1 = new Player(id, nickname);
			player.push_back(p1);
		}
		if (input == 2)
		{
			cout << "�����ϰ��� �ϴ� �÷��̾��� id��??";
			cin >> id;
			cin.ignore();
			for (vector<Player*>::iterator it = player.begin(); it != player.end(); it++)
			{
				int count = 0;
				if ((*it)->getId() == id)
				{
					player.erase(it+count);
					break;
				}
				count++;
			}
		}
		if (input == 3)
		{
			int i = 1;
			for (auto it = player.begin(); it != player.end(); it++)
			{
				
				cout << "==" << i << " : " << (*it)->getName() << "==" << '\n';
				i++;
			}
		}
		if (input == 4)
		{
			cout << "���α׷��� �����մϴ�." << '\n';
			break;
		}

	}
}