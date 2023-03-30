// #1. map<int, string> 을 통해 id와 nickname을 받고 id를 검색하면 nickname을 출력하게 프로그램을 작성하자.
#include <iostream>
#include <map>
#include<string>
using namespace std;

int main()
{
	map <int, string> player;
	int id;
	string nickname;
	cout << "플레이어의 id와 nickname를 입력받습니다." << '\n';
	while (1)
	{
		cout << "1. 입력		2. 검색		3. 종료" << '\n';
		int input;
		cin >> input;

		if (input == 1)
		{
			cout << "id를 입력하세요." << '\n';
			cin >> id;
			cin.ignore();
			cout << "nickname을 입력하세요." << '\n';
			getline(cin, nickname);
			cin.ignore();

			player[id] = "nickname";
		}

		else if (input == 2)
		{
			cout << "궁금한 id는?";
			cin >> id;
			if (player.find(id) != player.end())
			{
				cout << id << "의 닉네임은 " << nickname << '\n';
			}
			else
			{
				cout << "찾을 수 없습니다." << '\n';
			}
		}

		else if(input == 3)
		{
			cout << "종료합니다." << '\n';
			break;
		}
		else
		{
			cout << "1, 2, 3 만 입력 가능합니다." << '\n';
		}
	}
}
