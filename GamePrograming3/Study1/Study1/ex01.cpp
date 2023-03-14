#include <iostream>

using namespace std;

class Point
{
public:
	Point(int x = 0, int y = 0) :_x(x), _y(y)
	{

	}

	int getX() { return _x; }
	int getY() { return _y; }

	void move(int x, int y)
	{
		_x = x;
		_y = y;
	}

protected:
	int _x;
	int _y;
};

class ColorPoint : public Point
{
public:
	ColorPoint(int x = 0, int y = 0, string color ="white") : Point(x,y), _color(color)
	{

	}

	void show()
	{
		cout << _color << "������ " << _x << ", " << _y << "�� ��ġ���ֽ��ϴ�." << endl;
	}

	void setPoint(int x, int y)
	{
		_x = x;
		_y = y;
		// move(x,y);
	}

	void setColor(string color)
	{
		_color = color;
	}
private:
	string _color;

};

int main()
{
	ColorPoint zeroPoint;
	zeroPoint.show(); 

	ColorPoint cp(5, 5, "white");
	cp.setColor("Blue");
	cp.setPoint(10, 20);
	cp.show();

}

/*
point�� ��ӹ��� colorpoint �ۼ�.
main���� ����.

ColorPoint zeroPoint; // white, 0,0��ġ.
zeroPoint.show(); // white������ 0,0�� ��ġ���ֽ��ϴ�.

ColorPoint cp(5, 5, "white");
cp.setColor("Blue");// ����ٲٱ�
cp.setPoint(10, 20); // ��ġ�ٲٱ�
cp.show(); // blue������ 10,20 ��ġ�� �ֽ��ϴ�.
*/