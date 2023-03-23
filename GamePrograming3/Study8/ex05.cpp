/*
#5.
class Circle
{
public:
	Circle(int radius = 1) : _radius(radius)
	{
	}
	int getRadius()
	{
		return _radius;
	}
private:
	int _radius;
};

template <class T>
T getMax(T a, T b)
{
	if (a > b)
		return a;
	else
		return b;
}
​
int main()
{
	int a = 10, b = 30, c;
	c = getMax(a, b);
	cout << "큰 값은" << c << endl;
	Circle c1(10), c2(20), c3;
	c3 = getMax(c1, c2);
	cout << c3.getRadius() << endl; // 두 객체의 반지름중 큰값이 나오게 프로그램을 수정하여라. 20이 찍혀야됨.
}
*/

#include <iostream>
using namespace std;

class Circle
{
public:
	Circle(int radius = 1) : _radius(radius)
	{
	}
	int getRadius()
	{
		return _radius;
	}
	bool operator>(const Circle& c1)
	{
		if (this->_radius > c1._radius)
		{
			return true;
		}
		else
			return false;
	}
private:
	int _radius;
};

template <class T>
T getMax(T a, T b)
{
	if (a > b)
		return a;
	else
		return b;
}

template<>
Circle getMax(Circle a, Circle b)
{
	if (a > b)
		return a;
	else
		return b;
}


int main()
{
	int a = 10, b = 30, c;
	c = getMax(a, b);
	cout << "큰 값은" << c << endl;
	Circle c1(10), c2(20), c3;
	c3 = getMax(c1, c2);
	cout << c3.getRadius() << endl; // 두 객체의 반지름중 큰 값이 나오게 프로그램을 수정하여라. 20이 찍혀야됨.
}