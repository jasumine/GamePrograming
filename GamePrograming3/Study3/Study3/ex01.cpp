#include "ex01.h"
//player를 상속받는 기사, 궁수, 법사를 구현하시면됩니다.player 추상클래스로 바꾸기.

Player::Player(string n = " ", int hp = 0, int attack = 0) : _name(n), _hp(hp), _attack(attack) {}

Mage::Mage(string n = " ", int hp = 0, int attack = 0) :Player(n, hp, attack) {}
int Mage::Attack() { return  _attack * _hp; } //  공격력
string Mage::getName() { return _name; }

Archer::Archer(string n = " ", int hp = 0, int attack = 0) :Player(n, hp, attack) {}
int Archer::Attack() { return  _attack * _hp * 0.5; } //  공격력
string Archer::getName() { return _name; }

Knight::Knight(string n = " ", int hp = 0, int attack = 0) :Player(n, hp, attack) {}
int Knight::Attack() { return  _attack * _hp * 0.7; } //  공격력
string Knight::getName() { return _name; }


/*
class Player
{
public:
	Player(string n = " ", int hp = 0, int attack = 0) : _name(n), _hp(hp), _attack(attack) {}
	virtual int Attack() = 0; //  공격력
	virtual string getName() = 0;
protected:
	string _name;
	int _hp, _attack;
};

class Mage : public Player
{
public:
	Mage(string n = " ", int hp = 0, int attack = 0) :Player(n, hp, attack) {}
	int Attack() override { return  _attack * _hp; } //  공격력
	string getName() override  { return _name; }
};

class Archer : public Player
{
public:
	Archer(string n = " ", int hp = 0, int attack = 0) :Player(n, hp, attack) {}
	int Attack() override { return  _attack * _hp * 0.5; } //  공격력
	string getName() override  { return _name; }
};

class Knight : public Player
{
public:
	Knight(string n = " ", int hp = 0, int attack = 0) :Player(n, hp, attack) {}
	int Attack() { return  _attack * _hp * 0.7; } //  공격력
	string getName() override  { return _name; }
};
*/

int main()
{
	Player* p[3];
	p[0] = new Mage("법사", 10, 20); // 공격력 * hp
	p[1] = new Knight("기사", 10, 20); // 공격력 * hp * 0.5
	p[2] = new Archer("궁수", 10, 20); // 공격력 * hp * 0.7

	for (int i = 0; i < 3; i++)
	{
		cout << p[i]->getName() << "공격력는" << p[i]->Attack() << endl;
	}

}