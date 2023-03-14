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
		cout << _color << "색으로 " << _x << ", " << _y << "에 위치해있습니다." << endl;
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
point를 상속받은 colorpoint 작성.
main에서 실행.

ColorPoint zeroPoint; // white, 0,0위치.
zeroPoint.show(); // white색으로 0,0에 위치해있습니다.

ColorPoint cp(5, 5, "white");
cp.setColor("Blue");// 색깔바꾸기
cp.setPoint(10, 20); // 위치바꾸기
cp.show(); // blue색으로 10,20 위치에 있습니다.
*/