#pragma once

class Player; 
class Field;
// 전방선언.  
// #include "Player.h"를 하면 커서, 효율적으로 사용하기 위해 

class Game
{
public:
	Game();
	~Game();

	void Init();
	void Update();
	void CreatePlayer();

private:
	Player* _player; // 주소만 가져옴.
	Field* _field;
};

