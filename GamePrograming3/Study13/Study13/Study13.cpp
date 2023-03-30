#include <iostream>
#include <map>
using namespace std;
#include <vector>
#include <string>

class Player
{
public:
	Player(int id, string name) : _id(id), _name(name)
	{

	}
	int getId() { return _id;}
	string getName() { return _name; }
private:
	int _id;
	string _name;
};

int main()
{
	/* #1
	map<int, string> Manager;

	cout << "플레이어의 id와 nickname을 입력받습니다. \n";
	while(true)
	{
		cout << "1. 입력  2. 검색  3.종료 \n";

		int id;
		string nickname;
		int n;
		cin >> n;

		switch (n)
		{
		case 1:
			cout << "id를 입력하세요. \n";
			cin >> id;
			cin.ignore();
			cout << "nickname을 입력하세요. \n";
			getline(cin, nickname);
			Manager.insert(make_pair(id, nickname));
			break;
		case 2:
			cout << "궁금한 id는?";
			cin >> id;

			if (Manager.find(id) == Manager.end())
				cout << "없음" << endl;
			else
				cout << id << "의 닉네임은" << nickname << "입니다. \n";
			break;
		case 3:
			cout << "종료합니다." << endl;
			return 0;
		}

	}
	*/

	vector<Player*> v;
	while (true)
	{
		int id;
		string name;

		int num;
		cout << "1.삽입  2.삭제  3.플레이어보기  4.종료 \n";
		cin >> num;
		switch (num)
		{
		case 1:
		{
			cout << "id를 입력하세요." << '\n';
			cin >> id;
			cin.ignore();
			cout << "nickname을 입력하세요. \n";
			getline(cin, name);
			v.push_back(new Player(id, name));
			break;
		}
		case 2:
		{
			cout << "삭제하고자 하는 플레이어의 id는?";
			cin >> id;

			vector<Player*>::iterator it = v.begin();

			for (int i = 0; i < v.size(); i++)
			{
				if (v[i]->getId() == id)
					v.erase(it + i);
			}
			break;
		}
		case 3:
		{
			for (int i = 0; i < v.size(); ++i) // i++보다 ++i가 더 빠르다.
			{
				cout << v[i]->getName() << endl;
			}
			break;
		}
		case 4:
			return 0;
			break;
		}
	}

	// 내일 stl마무리
	// set, multimap, multiset, algo
	// 다음주 월~목 최신문법. c+ 11 지금은 23이지만 11부터 모던이라고함.
	// nullptr enum class 람다 스마트포인터 move개념.
}
