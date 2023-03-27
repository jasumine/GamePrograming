/*2. nickname�� name �׸��� id(����) �� ���� PlayerŬ���� ����� 
playerŸ���� vector�� �����, 
name�� ���� nickname�� id�� ã�� ���α׷��� �ۼ��ض�.
�Է¹����� cin.ignore() �����ϱ�!!
*/
#include <iostream>
#include <vector>
#include <String>
using namespace std;

class Player
{
public:
	Player(int id, string name, string nickname) : _id(id), _name(name), _nickname(nickname)
	{

	}

	void findInfo(string name)
	{
		cout << "id : " << _id
			<< "�̸��� : " << _name
			<< "�г����� : " << _nickname
			<< endl;
	}
	string get_name() { return _name; }

private:
	int _id;
	string _name;
	string _nickname;
};

int main()
{
	vector<Player> player;
	while (1)
	{
		int id;
		string name, nickname;
		cout << "�÷��̾ �����մϴ�. id�� �Է����ּ���. -1�� �Է��ϸ� ������ �����մϴ�." << endl;
		cin >> id;
		if (id == -1)
		{
			if (player.size() == 0)
			{
				cout << "������ �÷��̾ �����ϴ�." << endl;
				return 0;
			}
			cout << "�� ������ �÷��̾��" << player.size() << "�Դϴ�." << endl;
			cout << "ã���� �ϴ� �÷��̾��� �̸��� �Է��ϼ���." << endl;
			cin>>name;
		
			// vector player�ȿ� ����� newPlayer�� �����̸��ϰ�� 
			// it-> getName�� �ؼ�.!!!
			// �ش� player�� findInfo�� ���.
			for (vector<Player>::iterator it = player.begin(); it < player.end(); it++)
			{
				if (name == it->get_name()) // name == (*it).get_name()
				{
					it->findInfo(name);
				}
			}
			return 0;
		}
		cin.ignore();

		cout << "�̸�";
		cin >> name;
		getline(cin, name);
		cin.ignore();

		cout << "�г���";
		getline(cin, nickname);
		cin.ignore();

		Player newPlayer(id, name, nickname);
		player.push_back(newPlayer);
	}
	// id == -1�̸� break�� �Ἥ while�� �ۿ��� id�� ã�Ƶ��ȴ�!


}
