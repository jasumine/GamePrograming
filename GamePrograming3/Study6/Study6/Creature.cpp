#include "Creature.h"
#include <iostream>
using namespace std;

void Creature::OnAttacked(Creature* attacker)
{
	int damage = attacker->_attack * _attackSpeed;

	_hp -= damage;
	
	if (_hp < 0)
		_hp = 0;
}
