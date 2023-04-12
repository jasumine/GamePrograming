#pragma once
#include "Creature.h"

enum PlayerType
{
	PT_Gunslinger = 1,
	PT_Arcana = 2,
	PT_Bard = 3,

};

class Player : public Creature
{
public:
	Player(int playerType)
		: Creature(CT_PLAYER), _playerType(playerType)
	{

	}
	virtual ~Player()
	{

	}

	virtual void PrintInfo();
protected:
	int _playerType;
};

class Gunslinger : public Player
{
public:
	Gunslinger() : Player(PT_Gunslinger)
	{
		_hp = 100;
		_attack = 8;
		_attackSpeed = 1;
	}

};

class Arcana : public Player
{
public:
	Arcana() : Player(PT_Arcana)
	{
		_hp = 100;
		_attack = 10;
		_attackSpeed = 0.8;
	}

};

class Bard : public Player
{
public:
	Bard() : Player(PT_Bard)
	{
		_hp = 100;
		_attack = 3;
		_attackSpeed = 0.2;
	}

};
