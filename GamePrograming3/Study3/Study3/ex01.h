#pragma once
#include <iostream>
using namespace std;
//player�� ��ӹ޴� ���, �ü�, ���縦 �����Ͻø�˴ϴ�.player �߻�Ŭ������ �ٲٱ�.

class Player
{
public:
	Player(string, int, int);
	virtual int Attack() = 0; //  ���ݷ�
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
