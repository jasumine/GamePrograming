#include "Player.h"
#include <iostream>
using namespace std;

void Player::PrintInfo()
{
	cout << "------------------------------" << endl;
	cout << "player hp:" << _hp << "attack: " << _attack * _attackSpeed<< endl;
	cout << "------------------------------" << endl;
}
