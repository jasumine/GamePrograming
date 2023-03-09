#include <iostream>
using namespace std;


class Player {

public:
	Player(string name = "", int power = 0, int hp = 0) : _name(name), _power(power), _hp(hp)
	{

	}
	void show()
	{
		cout << _name << "파워는" << _power << "체력은" << _hp << endl;
	}
	string getName() { return _name; }

private:
	string _name;
	int _power;
	int _hp;
};

class Position
{
	

public:
	int _x;
	int _y;
};

int main()
{
	Player p1("기사", 10, 1000), p2("전사", 15, 800);
	p1 += 50; // 기사의 체력 50상승
	p2 -= 50; // 전사의 체력 50 하락
	// += ,-= 연산자를 연산자오버로딩하여라. 
	// 방법은 2가지 (클래스 맴버함수로구현) or 외부함수로 구현하고 프렌즈쓰기.

	if (p1 == 10)
		cout << "power가 10" << '\n';
	if(p1 =="기사")
		cout << "name이 기사" << '\n';
	if(p1 == p2)
		cout << "플레이어 둘이 같음" << '\n';
	// 이게되게 == 연산자 오버로딩 3개 하기. 방법은 위와같이 2가지.






	// x와 y좌표를 가지고있는 포지션 클래스.
	

	Position p1, p2;
	p1++, ++p1, --p2, p2--;  // ++전위 후위(x,y 1씩증가) , -- 전위후위(x,y 1씩감고)
 	bool isSame = (pos1 == pos2);//  == 같은지
	Position p3 = p1 + p2; // 두클래스를 더하는 연산자오버로딩. 
	p1 + 5; // x,y좌표 5씩증가.
	p3 = 5; // x,y좌표가 5가되게 구현.
}
