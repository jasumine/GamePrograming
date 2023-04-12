#pragma once


enum CreatureType
{
	CT_PLAYER = 0,
	CT_MONSTER = 1
};

class Creature
{
public:
	Creature(int creatureType)
		: _creatureType(creatureType) , _hp(1) , _attack(1), _attackSpeed(1)
	{

	}
	virtual ~Creature()
	{

	}
	
	virtual void PrintInfo() = 0;
	virtual void OnAttacked(Creature* attacker);
	bool IsDead() { return _hp <= 0; }

	int getHp() { return _hp; }
	int getAttack() { return _attack; }
	int getAttackSpeed() { return _attackSpeed; }

protected:
	int _creatureType;
	int _hp;
	int _attack;
	float _attackSpeed;
};

