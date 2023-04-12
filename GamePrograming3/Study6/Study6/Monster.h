#pragma once
#include "Creature.h"



enum MonsterType
{
    MT_Orc = 0,
    MT_Dragon = 1
};
class Monster :
    public Creature
{
public:
    Monster(int monsterType) : Creature(CT_MONSTER), _monsterType (monsterType)
    {

    }

    void PrintInfo() override;
protected:
    int _monsterType;
};

class Orc : public Monster
{
public:
    Orc() : Monster(MT_Orc)
    {
        _hp = 20;
        _attack = 5;
        _attackSpeed = 1;
    }
};

class Dragon : public Monster
{
public :
    Dragon() : Monster(MT_Dragon)
    {
        _hp = 50;
        _attack = 10;
        _attackSpeed = 1;
    }
};

