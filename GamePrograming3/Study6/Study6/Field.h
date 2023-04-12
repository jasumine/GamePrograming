#pragma once

class Player;
class Monster;

class Field
{

public:
	Field();
	virtual ~Field();
	
	void Update(Player* player);
	void CreateMonster();

	void Battle(Player* player);

private:
	Monster* _monster;
};

