#include <iostream>

using namespace std;

class Player
{
public:
	Player()
	{
		cout << "기본 생성자 호출 " << endl;
		_hp = 1;
		_name = "none";
	}
	Player(int hp)
	{
		cout << "기본 생성자 호출 " << endl;
		_hp = hp;
		_name = "none";
	}
	Player(int hp, string name)
	{
		cout << "기본 생성자 호출 " << endl;
		_hp = hp;
		_name = name;
	}
	~Player()
	{
		cout << "소멸자 호출" << endl;
	}
	void SetHp(int hp) { _hp = hp; }
	int GetHp() { return _hp; }
	void SetName(string name) { _name = name; }
	string GetName() { return _name; }
	
	bool checkHp(int minHp)
	{
		if (_hp > minHp) return true;
		else return false;
	}
private:
	int _hp;
	string _name;
};

int main()
{
/*	cout << sizeof(Player) << endl;

	Player* arrayPtr = new Player[3];
	arrayPtr[0].SetHp(10);
	arrayPtr[1].SetHp(20);
	arrayPtr[2].SetHp(30);

	for (int i = 0; i < 3; i++)
		cout << arrayPtr[i].GetHp() << endl;

	Player* ptr2 = arrayPtr;
	for (int i = 0; i < 3; i++)
	{
		cout << ptr2->GetHp() << endl;
		ptr2++;
	}
	delete[] arrayPtr;
	*/

/*	// 1)
	Player player[3];
	for (int i = 0; i < 3; i++)
	{
		int hp;
		cout << "player " << i + 1 << "의 hp : ";
		cin >> hp;
		player[i].SetHp(hp);
	}
	int count = 0;
	for (int i = 0; i < 3; i++)
	{
		//if (player[i].GetHp() > 20) count++;
		if (player[i].checkHp(20)) count++;
	}
	cout << "hp가 20보다 높은 플레이어는 " << count << "명 입니다." << endl;
*/
/*	// 2)
	
	int numberOfPlayer;
	cout << "플레이어의 숫자를 입력하세요.";
	cin >> numberOfPlayer;
	Player* player = new Player[numberOfPlayer];
	for (int i = 0; i < numberOfPlayer; i++)
	{
		int hp;
		cout << "player " << i + 1 << "의 hp : ";
		cin >> hp;
		player[i].SetHp(hp);
	}
	int count = 0;
	for (int i = 0; i < numberOfPlayer; i++)
	{
		//if (player[i].GetHp() > 20) count++;
		if (player[i].checkHp(20)) count++;
	}
	cout << "hp가 20보다 높은 플레이어는 " << count << "명 입니다." << endl;
	delete[] player;
*/
	// 3)
	cout << "플레이어의 숫자를 입력하세요.";
	int numberOfPlayer;
	cin >> numberOfPlayer;
	Player* player = new Player[numberOfPlayer];
	for (int i = 0; i < numberOfPlayer; i++)
	{
		cout << "player " << i + 1 << "의  name과 hp : ";
		string name;
		int hp;
		cin >> name >> hp;
		player[i].SetName(name);
		player[i].SetHp(hp);
	}

	cout << "최소 hp를 입력하세요 : ";
	int minHp;
	cin >> minHp;

	cout << minHp << "보다 hp가 높은 플레이어는 ";
	for (int i = 0; i < numberOfPlayer; i++)
	{
//		if(player[i].GetHp()>minHp)
//			cout << player[i].GetName() << " " << player[i].GetHp() << " ";
		if (player[i].checkHp(minHp))
			cout << player[i].GetName() << "-" << player[i].GetHp() << " ";
	}
	cout << " 입니다.";
	delete[] player;
}