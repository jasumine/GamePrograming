#pragma once

class Player; 
class Field;
// ���漱��.  
// #include "Player.h"�� �ϸ� Ŀ��, ȿ�������� ����ϱ� ���� 

class Game
{
public:
	Game();
	~Game();

	void Init();
	void Update();
	void CreatePlayer();

private:
	Player* _player; // �ּҸ� ������.
	Field* _field;
};

