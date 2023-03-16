#pragma once
#include <iostream>
using namespace std;
//player를 상속받는 기사, 궁수, 법사를 구현하시면됩니다.player 추상클래스로 바꾸기.

class Player
{
public:
	Player(string, int, int);
	virtual int Attack() = 0; //  공격력
	virtual string getName() = 0;
protected:
	string _name;
	int _hp, _attack;
};

class Mage : public Player
{
public:
	Mage(string, int, int);
	int Attack() override;
	string getName();
};

class Archer : public Player
{
public:
	Archer(string, int, int);
	int Attack() override;
	string getName();
};

class Knight : public Player
{
public:
	Knight(string, int, int);
	int Attack() override;
	string getName();
};
