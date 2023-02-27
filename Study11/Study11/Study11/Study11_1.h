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
		cout << "반지름이 " << _radius << "인 원 생성" << endl;
	}
	Circle(int radius)
	{
		_radius = radius;
		cout << "반지름이 " << _radius << "인 원 생성" << endl;
	}
	~Circle()
	{
		cout << "반지름이 " << _radius << "인 원 소멸" << endl;
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
		cout << "높이 : " << _height << 
			", 길이 : " << _width << "인 사각형 생성" << endl;
	}
	Rectangle(int height, int width)
	{
		_height = height;
		_width = width;
		cout << "높이 : " << _height <<
			", 길이 : " << _width << "인 사각형 생성" << endl;
	}
	~Rectangle()
	{
		cout << "높이 : " << _height <<
			", 길이 : " << _width << "인 사각형 소멸" << endl;
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
		cout << "이름 : " << _name <<
			", 잔액 : " << _total << "인 계좌 생성" << endl;
	}
	~Account()
	{
		cout << "이름 : " << _name <<
			", 잔액 : " << _total << "인 계좌 소멸" << endl;
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
		cout << "높이 : " << _height <<
			", 넓이 : " << _width << "인 타원 생성" << endl;
	}
	Oval(int height, int widht)
	{
		_height = height;
		_width = widht;
		cout << "높이 : " << _height <<
			", 넓이 : " << _width << "인 타원 생성" << endl;
	}
	~Oval()
	{
		cout << "높이 : " << _height <<
			", 넓이 : " << _width << "인 계좌 소멸" << endl;
	}
	void set(int height, int width)
	{
		_height = height;
		_width = width;
	}
	void show()
	{
		cout << "높이 : " << _height <<
			", 넓이 : " << _width << endl;
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