#include "ex01.h"
//player�� ��ӹ޴� ���, �ü�, ���縦 �����Ͻø�˴ϴ�.player �߻�Ŭ������ �ٲٱ�.

Player::Player(string n = " ", int hp = 0, int attack = 0) : _name(n), _hp(hp), _attack(attack) {}

Mage::Mage(string n = " ", int hp = 0, int attack = 0) :Player(n, hp, attack) {}
int Mage::Attack() { return  _attack * _hp; } //  ���ݷ�
string Mage::getName() { return _name; }

Archer::Archer(string n = " ", int hp = 0, int attack = 0) :Player(n, hp, attack) {}
int Archer::Attack() { return  _attack * _hp * 0.5; } //  ���ݷ�
string Archer::getName() { return _name; }

Knight::Knight(string n = " ", int hp = 0, int attack = 0) :Player(n, hp, attack) {}
int Knight::Attack() { return  _attack * _hp * 0.7; } //  ���ݷ�
string Knight::getName() { return _name; }


/*
class Player
{
public:
	Player(string n = " ", int hp = 0, int attack = 0) : _name(n), _hp(hp), _attack(attack) {}
	virtual int Attack() = 0; //  ���ݷ�
	virtual string getName() = 0;
protected:
	string _name;
	int _hp, _attack;
};

class Mage : public Player
{
public:
	Mage(string n = " ", int hp = 0, int attack = 0) :Player(n, hp, attack) {}
	int Attack() override { return  _attack * _hp; } //  ���ݷ�
	string getName() override  { return _name; }
};

class Archer : public Player
{
public:
	Archer(string n = " ", int hp = 0, int attack = 0) :Player(n, hp, attack) {}
	int Attack() override { return  _attack * _hp * 0.5; } //  ���ݷ�
	string getName() override  { return _name; }
};

class Knight : public Player
{
public:
	Knight(string n = " ", int hp = 0, int attack = 0) :Player(n, hp, attack) {}
	int Attack() { return  _attack * _hp * 0.7; } //  ���ݷ�
	string getName() override  { return _name; }
};
*/

int main()
{
	Player* p[3];
	p[0] = new Mage("����", 10, 20); // ���ݷ� * hp
	p[1] = new Knight("���", 10, 20); // ���ݷ� * hp * 0.5
	p[2] = new Archer("�ü�", 10, 20); // ���ݷ� * hp * 0.7

	for (int i = 0; i < 3; i++)
	{
		cout << p[i]->getName() << "���ݷ´�" << p[i]->Attack() << endl;
	}

}