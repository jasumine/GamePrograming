#pragma once
#include <iostream>

using namespace std;

struct Player
{
	int hp;
};

class monster
{
	int hp;
};

class Circle
{
public:
	Circle()
	{
		_radius = 1;
		cout << "�������� " << _radius << "�� �� ����" << endl;
	}
	Circle(int radius)
	{
		_radius = radius;
		cout << "�������� " << _radius << "�� �� ����" << endl;
	}
	~Circle()
	{
		cout << "�������� " << _radius << "�� �� �Ҹ�" << endl;
	}
	int getArea()
	{
		return 3.14 * _radius * _radius;
	}

private:
	int _radius;
};

class Rectangle
{
public:
	Rectangle()
	{
		_height, _width = 1;
		cout << "���� : " << _height << 
			", ���� : " << _width << "�� �簢�� ����" << endl;
	}
	Rectangle(int height, int width)
	{
		_height = height;
		_width = width;
		cout << "���� : " << _height <<
			", ���� : " << _width << "�� �簢�� ����" << endl;
	}
	~Rectangle()
	{
		cout << "���� : " << _height <<
			", ���� : " << _width << "�� �簢�� �Ҹ�" << endl;
	}

	int getArea()
	{
		return _height * _width;
	}
	
	bool checkRectangle()
	{
		if (_height == _width) return true;
		else return false;
	}
private:
	int _height;
	int _width;
};

class Account
{
public:
	Account(string name, int money)
	{
		_name = name;
		_total = money;
		cout << "�̸� : " << _name <<
			", �ܾ� : " << _total << "�� ���� ����" << endl;
	}
	~Account()
	{
		cout << "�̸� : " << _name <<
			", �ܾ� : " << _total << "�� ���� �Ҹ�" << endl;
	}
	void deposit(int money)
	{
		_total += money;
	}
	int widhdraw(int money)
	{
		_total -= money;
		return _total;
	}
	string getOwner()
	{
		return _name;
	}
	int inquiry()
	{
		return _total;
	}
private:
	string _name;
	int _total;
};

class Oval 
{
public:
	Oval()
	{
		_height, _width = 1;
		cout << "���� : " << _height <<
			", ���� : " << _width << "�� Ÿ�� ����" << endl;
	}
	Oval(int height, int widht)
	{
		_height = height;
		_width = widht;
		cout << "���� : " << _height <<
			", ���� : " << _width << "�� Ÿ�� ����" << endl;
	}
	~Oval()
	{
		cout << "���� : " << _height <<
			", ���� : " << _width << "�� ���� �Ҹ�" << endl;
	}
	void set(int height, int width)
	{
		_height = height;
		_width = width;
	}
	void show()
	{
		cout << "���� : " << _height <<
			", ���� : " << _width << endl;
	}
	int getWidth()
	{
		return _width;
	}
	int getHeight()
	{
		return _height;
	}
private:
	int _height;
	int _width;
};