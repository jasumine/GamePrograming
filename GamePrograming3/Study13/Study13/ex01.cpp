// #1. map<int, string> �� ���� id�� nickname�� �ް� id�� �˻��ϸ� nickname�� ����ϰ� ���α׷��� �ۼ�����.
#include <iostream>
#include <map>
#include<string>
using namespace std;

int main()
{
	map <int, string> player;
	int id;
	string nickname;
	cout << "�÷��̾��� id�� nickname�� �Է¹޽��ϴ�." << '\n';
	while (1)
	{
		cout << "1. �Է�		2. �˻�		3. ����" << '\n';
		int input;
		cin >> input;

		if (input == 1)
		{
			cout << "id�� �Է��ϼ���." << '\n';
			cin >> id;
			cin.ignore();
			cout << "nickname�� �Է��ϼ���." << '\n';
			getline(cin, nickname);
			cin.ignore();

			player[id] = "nickname";
		}

		else if (input == 2)
		{
			cout << "�ñ��� id��?";
			cin >> id;
			if (player.find(id) != player.end())
			{
				cout << id << "�� �г����� " << nickname << '\n';
			}
			else
			{
				cout << "ã�� �� �����ϴ�." << '\n';
			}
		}

		else if(input == 3)
		{
			cout << "�����մϴ�." << '\n';
			break;
		}
		else
		{
			cout << "1, 2, 3 �� �Է� �����մϴ�." << '\n';
		}
	}
}
