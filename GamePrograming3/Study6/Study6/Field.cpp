#include "Field.h"
#include "Player.h"
#include "Monster.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

Field::Field() : _monster(nullptr)
{
}

Field::~Field()
{
	if (_monster != nullptr) delete _monster;
}

void Field::Update(Player* player)
{
	if (_monster == nullptr)
		CreateMonster();

	Battle(player);
}

void Field::CreateMonster()
{
	int randValue = rand() % 2;
	switch (randValue)
	{
	case MT_Orc:
		_monster = new Orc();
		cout << "몬스터 Orc가 생성되었습니다." << endl;
		break;
	case MT_Dragon:
		_monster = new Dragon();
		cout << "몬스터 Dragon이 생성되었습니다." << endl;
		break;

	default:
		break;
	}
}

void Field::Battle(Player* player)
{
	while (true)
	{
		player->PrintInfo();
		_monster->PrintInfo();
	
		// 플레이어 선빵
		_monster->OnAttacked(player);
		if (_monster->IsDead())
		{
			_monster->PrintInfo();
			delete _monster;
			_monster = nullptr;
			break;
		}

		player->OnAttacked(_monster);

		if (player->IsDead())
		{
			player->PrintInfo();
			break;
		}
	}
}
