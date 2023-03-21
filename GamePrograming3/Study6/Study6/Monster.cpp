#include "Monster.h"
#include <iostream>
using namespace std;

void Monster::PrintInfo()
{
	cout << "------------------------------" << endl;
	cout << "monster hp:" << _hp << "attack: " << _attack * _attackSpeed << endl;
	cout << "------------------------------" << endl;
}
