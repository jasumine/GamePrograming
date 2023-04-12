/*2. nickname과 name 그리고 id(숫자) 를 가진 Player클래스 만들고 
player타입의 vector를 만들어, 
name을 통해 nickname과 id를 찾는 프로그램을 작성해라.
입력받을떄 cin.ignore() 생각하기!!
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
			<< "이름은 : " << _name
			<< "닉네임은 : " << _nickname
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
		cout << "플레이어를 생성합니다. id를 입력해주세요. -1을 입력하면 생성을 종료합니다." << endl;
		cin >> id;
		if (id == -1)
		{
			if (player.size() == 0)
			{
				cout << "생성된 플레이어가 없습니다." << endl;
				return 0;
			}
			cout << "총 생성된 플레이어는" << player.size() << "입니다." << endl;
			cout << "찾고자 하는 플레이어의 이름을 입력하세요." << endl;
			cin>>name;
		
			// vector player안에 저장된 newPlayer중 같은이름일경우 
			// it-> getName을 해서.!!!
			// 해당 player의 findInfo를 출력.
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

		cout << "이름";
		cin >> name;
		getline(cin, name);
		cin.ignore();

		cout << "닉네임";
		getline(cin, nickname);
		cin.ignore();

		Player newPlayer(id, name, nickname);
		player.push_back(newPlayer);
	}
	// id == -1이면 break를 써서 while문 밖에서 id를 찾아도된다!


}
