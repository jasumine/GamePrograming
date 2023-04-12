/* #2. 문제.
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

클래스 플레이어가 있다.vector 를 통해서 플레이어를
1.삽입 2.삭제 3.전체 플레이어보기 4.종료를 만든다.
vector<Player*> 를 써보는걸 추천!
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
	
	cout << "플레이어를 삽입하고 삭제하는 프로그램입니다." << '\n';
	while (1)
	{
		cout << "1.삽입		2.삭제		3.전체 플레이어 보기		4.종료" << '\n';
		int input;
		cin >> input;
		if (input == 1)
		{
			cout << "id를 입력하세요." << '\n';
			cin >> id;
			cin.ignore();
			cout << "nickname을 입력하세요." << '\n';
			getline(cin, nickname);

			Player* p1 = new Player(id, nickname);
			player.push_back(p1);
		}
		if (input == 2)
		{
			cout << "삭제하고자 하는 플레이어의 id는??";
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
			cout << "프로그램을 종료합니다." << '\n';
			break;
		}

	}
}