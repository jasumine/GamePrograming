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
		cout << "�÷��̾ �׾� ������ �����մϴ�." << endl;
		exit(0);
	}

	_field->Update(_player);
}

void Game::CreatePlayer()
{
	while (_player == nullptr)
	{
		cout << "==============================" << endl;
		cout << "����� ���� ������ �����ϼ���." << endl;
		cout << "1. �ǽ����� 2. �Ƹ�ī�� 3. �ٵ�" << endl;
		cout << "==============================" << endl;

		int input = 0;
		cin >> input;
		if (input == PT_Gunslinger)
		{
			_player = new Gunslinger();
			cout << "�ǽ���� �����ϼ̽��ϴ�." << endl;
			cout << "Hp : " << _player->getHp() << endl;
			cout << "Attack : " << _player->getAttack() << endl;
			cout << "AttackSpeed : " << _player->getAttackSpeed() << endl;
		}
		
		else if (input == PT_Arcana)
		{
			_player = new Arcana();
			cout << "�Ƹ�ī���� �����ϼ̽��ϴ�." << endl;
			cout << "Hp : " << _player->getHp() << endl;
			cout << "Attack : " << _player->getAttack() << endl;
			cout << "AttackSpeed : " << _player->getAttackSpeed() << endl;

		}
		else if (input == PT_Bard)
		{
			_player = new Bard();
			cout << "�ٵ带 �����ϼ̽��ϴ�." << endl;
			cout << "Hp : " << _player->getHp() << endl;
			cout << "Attack : " << _player->getAttack() << endl;
			cout << "AttackSpeed : " << _player->getAttackSpeed() << endl;
		}
		else
		{
			cout << "1,2,3�߿��� ������ �ּ���."<< endl;
		}
	}
}

\

