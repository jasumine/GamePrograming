#include "test.h"
#include <iostream>
using namespace std;

void Test1()
{
	Test2();
}

void Test2()
{
	cout << "Hello World" << endl;
}

Player::Player(int hp, int attack) : _hp(hp), _attack(attack)
{

}

void Player::Move()
{
	cout << "move" << endl;
}