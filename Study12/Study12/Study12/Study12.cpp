#include <iostream>

using namespace std;

int ab; // 데이터 영역

class Player
{
public: // 함수들은 코드 영역
	Player()
	{
		cout << "기본생성자호출" << endl;
		_hp = 1;
		_name = "None";
	}
	Player(int hp)
	{
		_hp = hp;
	}
	Player(int hp, string name)
	{
		_hp = hp;
		_name = name;
	}
	~Player() { };
	void SetHp(int hp){	_hp = hp; }
	int GetHp() { return _hp; }
	void SetName(string name) { _name = name; }
	string GetName() { return _name; }
	
	bool baseHP()
	{
		if (_hp >= 20) return true;
		else return false;
	}

	bool inputBaseHp(int hp)
	{
		if (_hp > hp) return true;
		else return false;
	}
	
private: // class의 크기
	int _hp;
	string _name;
};

// 플레이어 10000명

// Player player[10000]

int main()
{/*
	int a; // 스택 영역(메모리 할당)

	cout << sizeof(Player) << endl;
	
	// c 스타일 // 생성자 소멸자 호출 X
	void* pointer = malloc(sizeof(Player)); 
	Player* p1 = (Player*)pointer;
	p1->SetHp(100);
	free(pointer); // 메모리를 다썼다고 반납
	
	// c++ (malloc->new) // 생성자 소멸자 호출o
	// 객체 포인터
	Player* p2 = new Player;
	p1->SetHp(200);
	delete p1;
	

//	Player player[1000000]; // stack overflow 가 발생.

	Player p1;
	cout << p1.GetHp() << endl;

	Player* ptr;
	ptr = &p1; 
	cout << ptr->GetHp() << endl; // (*ptr)

	Player* arrayPtr = new Player[3]; // 객체 3칸짜리 포인터
	arrayPtr[0].SetHp(10);
	arrayPtr[1].SetHp(20);
	arrayPtr[2].SetHp(30);

	for (int i = 0; i < 3; i++) 
		cout << arrayPtr[i].GetHp() << endl;

	Player* ptr2 = arrayPtr; // 주소값을 넣어주는격
	for (int i = 0; i < 3; i++)
	{
		cout << ptr2->GetHp() << endl;
		ptr2++;
	}
	delete[] arrayPtr;
	*/

	// 1) 배열 3개짜리를 만들어서 player hp를 입력 받아서 다음과 같이 실해오디기
	// player 1의 hp : 10
	// player 2의 hp : 20
	// player 3의 hp : 40
	// hp가 20보다 높은 플레이어는 2명입니다.

	// 2) 플레이어의 숫자를 입력받기.
	// 플레이어의 숫자를 입력하세요. 4
	// player 1의 hp : 10
	// player 2의 hp : 20
	// player 3의 hp : 40
	// player 4의 hp : 30
	// hp가 20보다 높은 플레이어는 3명입니다.

	// 3) name 멤버변수 하나추가해서.
	// 플레이어의 숫자를 입력하세요. 3
	// 플레이어 1의 name과 hp : 정동규 30
	// 플레이어 2의 name과 hp : 임지우 40
	// 플레이어 3의 name과 hp : 최준하 10
	// 
	// 최소 hp를 입력하세요 : 20
	// 20보다 hp가 높은 플레이어는 정동규 30 임지우 40입니다.

/*	// 1)
	Player* player = new Player[3];
	for (int i = 0; i < 3; i++)
	{
		int num;
		cout << "player" << i + 1 << "의 HP :";
		cin >> num;
		player[i].SetHp(num);
	}
	int count = 0;
	for (int i = 0; i < 3; i++)
	{
		if (player[i].baseHP()) count++;
		// if(player[i].getHp()>20) count++;
	}
	cout << "hp가 20보다 높은 플레이어는 " << count << "명 입니다." << endl;
*/
/*	// 2)
	int playerNum = 0;
	cout << "플레이어의 숫자를 입력하세요. ";
	cin >> playerNum;
	Player* player = new Player[playerNum];
	for (int i = 0; i < playerNum; i++)
	{
		int num;
		cout << "player" << i + 1 << "의 HP :";
		cin >> num;
		player[i].SetHp(num);
	}
	int count = 0;
	for (int i = 0; i < playerNum; i++)
	{
		if (player[i].baseHP()) count++;
		// if(player[i].getHp()>20) count++;
	}
	cout << "hp가 20보다 높은 플레이어는 " << count << "명 입니다." << endl;
	delete[] player;
*/
	// 3)
	int playerNum;
	cout << "플레이어의 숫자를 입력하세요. ";
	cin >> playerNum;
	Player* player = new Player[playerNum];
	for (int i = 0; i < playerNum; i++)
	{
		string name;
		int hp;
		cout << "player" << i + 1 << "의 name과 HP : ";
		cin >> name >> hp;
		
		player[i].SetName(name);
		player[i].SetHp(hp);
	}

	int baseHp;
	cout << "최소 hp를 입력하세요 : ";
	cin >> baseHp;

	cout << "hp가 " << baseHp << "보다 높은 플레이어는 ";
	for (int i = 0; i < playerNum; i++)
	{
		if (player[i].inputBaseHp(baseHp))
		{
			cout << player[i].GetName() << " " << player[i].GetHp();
		}
		/*
		if(player[i].getHp()>baseHp) 
		{
			cout << player[i].GetName() << " " << player[i].GetHp();
		}
		*/
	}
	cout << "이 있습니다.";
}

