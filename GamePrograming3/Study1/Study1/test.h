#pragma once // 헤더 중복호출을 막아줌
void Test1();
void Test2();

class Player
{
public:
	Player(int, int);
	void Move();

public:
	int _hp;
	int _attack;

};
