#include "Game.h"
#include "Player.h"
#include "Field.h"
#include <iostream>
using namespace std;

Game::Game() : _player(nullptr) , _field(nullptr)
{

}

Game::~Game()
{
	if (_player != nullptr) delete _player;
	if (_field != nullptr) delete _field;
}

void Game::Init()
{
	_field = new Field();
}

void Game::Update()
{
	if (_player == nullptr)
		CreatePlayer();
	
	if (_player->IsDead())
	{
		delete _player;
		_player = nullptr;
		cout << "플레이어가 죽어 게임을 종료합니다." << endl;
		exit(0);
	}

	_field->Update(_player);
}

void Game::CreatePlayer()
{
	while (_player == nullptr)
	{
		cout << "==============================" << endl;
		cout << "만들고 싶은 직업을 선택하세요." << endl;
		cout << "1. 건슬링어 2. 아르카나 3. 바드" << endl;
		cout << "==============================" << endl;

		int input = 0;
		cin >> input;
		if (input == PT_Gunslinger)
		{
			_player = new Gunslinger();
			cout << "건슬링어를 선택하셨습니다." << endl;
			cout << "Hp : " << _player->getHp() << endl;
			cout << "Attack : " << _player->getAttack() << endl;
			cout << "AttackSpeed : " << _player->getAttackSpeed() << endl;
		}
		
		else if (input == PT_Arcana)
		{
			_player = new Arcana();
			cout << "아르카나를 선택하셨습니다." << endl;
			cout << "Hp : " << _player->getHp() << endl;
			cout << "Attack : " << _player->getAttack() << endl;
			cout << "AttackSpeed : " << _player->getAttackSpeed() << endl;

		}
		else if (input == PT_Bard)
		{
			_player = new Bard();
			cout << "바드를 선택하셨습니다." << endl;
			cout << "Hp : " << _player->getHp() << endl;
			cout << "Attack : " << _player->getAttack() << endl;
			cout << "AttackSpeed : " << _player->getAttackSpeed() << endl;
		}
		else
		{
			cout << "1,2,3중에서 선택해 주세요."<< endl;
		}
	}
}

\

