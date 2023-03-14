#include <iostream>

using namespace std;

class Player
{
public:
	Player(string name="", int hp = 0, double power = 0) :_name(name), _hp(hp), _power(power)
	{

	}

	void show()
	{
		cout << _name << "의 체력은 " << _hp << ", 파워는 " << _power << endl;
	}

	Player operator+= (int hp)
	{
		_hp += hp;
		return *this;
		// 자기자신을 반환할때는 *this를 사용
	}

	Player operator-= (int hp)
	{
		_hp -= hp;
		return Player(this->getName(), this->getHp(), this->getPower());
		// get해서 가져오지 않아도 class 내에서 있는 함수여서 private 변수를 쓴다.
	}

	bool operator==(double number)
	{
		return _power == number;
	}

	bool operator==(string name)
	{
		return _name == name;
	}

	bool operator==(const Player& player)
	{
		return (this->getName() == player._name &&
				this->getHp() == player._hp &&
				this->getPower() == player._power);
	}

	int getHp() { return _hp; }
	string getName() { return _name; }
	double getPower() { return _power; }

private:
	string _name;
	int _hp;
	double _power;
};

class Position
{
public:
	Position()
	{

	}
	Position(int x, int y) : _x(x), _y(y) { }

	Position operator++()
	{
		_x++;
		_y++;
		return Position(this->_x, this->_y);
	}
	Position operator++(int)
	{
		Position temp(_x, _y);
//		++_x; ++_y;
		_x++;
		_y++;
		return temp;
	}

	Position operator--()
	{
		_x--;
		_y--;
		return Position(this->_x, this->_y);
	}
	Position operator--(int)
	{
		Position temp(_x, _y);
		--_x; --_y;
		return temp;
	}

	bool operator==(const Position& po1)
	{
		return (_x &&po1._x &&
				_y == po1._y);
	}

	Position operator+(const Position& po1)
	{
		return Position(this->_x + po1._x, this->_y + po1._y);
	} // this* 로바꾸기

	Position operator+(int number)
	{
		return Position(this->_x + number, this->_y + number);
	}
	
	Position operator=(int number)
	{
		return Position(this->_x = number, this->_y = number);
	}


public:
	int _x;
	int _y;
};


int main()
{
	Player p1("기사", 10, 1000), p2("전사", 15, 800);
	p1 += 50; // 기사의 체력 50 상승
	p2 -= 50; // 전사의 체력 50 하락
	p1.show();
	p2.show();
	// += ,-= 연산자를 연산자오버로딩하여라. 


	if (p1 == 10)
		cout << "power가 10" << '\n';
	if (p1 == "기사")
		cout << "name이 기사" << '\n';
	if (p1 == p2)
		cout << "플레이어 둘이 같음" << '\n';
	// 이게되게 == 연산자 오버로딩 3개 하기. 방법은 위와같이 2가지.

	p1.show();
	p2.show();

	//x와 y좌표를 가지고 있는 포지션 클래스
	Position po1, po2;
	po1._x = 0;
	po1._y = 0;

	po2._x = 0;
	po2._y = 0;

	po1++, ++po1, --po2, po2--;  // ++전위 후위(x,y 1씩증가) , -- 전위후위(x,y 1씩감소)

	bool isSame = (po1 == po2);//  == 같은지
	if (isSame) cout << "po1과 po2는 같다." << endl;
	Position po3 = po1 + po2; // 두클래스를 더하는 연산자오버로딩. 
	po1 + 5; // x,y좌표 5씩증가.
	po3 = 5; // x,y좌표가 5가되게 구현.

	cout << po1._x << " " << po1._y << endl;
	cout << po2._x << " " << po2._y << endl;
	cout << po3._x << " " << po3._y << endl;

}  