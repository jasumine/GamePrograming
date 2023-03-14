#include <iostream>
#include "Study11_1.h"
using namespace std;

// c언어 struct 함수x 상속 x ,  class 함수x 상속 o
// c++ struct class 차이가 거의 없어요. 함수 선언, 생성자 소멸자 선언 다가능, 상속 포인터
// c# 둘이 쪼끔 차이가 있다.
// 절차지향 -  pp procedure programing
// 
// 객체 지향 -oop object oritented programing (게임 대부분)

/*
struct Player // public default
{
	int hp;
};

class Monster // private default
{
	int hp;
};

class Circle
{
public:
	Circle() // 초기화 작업을 하기 위해서. 리턴 타입 X, 여러개 만들 수 있음. 객체 생성될 때 딱1번만 실행
	{
		_radius = 1;
		cout << "반지름이" << _radius << "인 원 생성." << endl;
	}
	
	Circle(int radius)
	{
		_radius = radius;
		cout << "반지름이" << _radius << "인 원 생성." << endl;
	}
	Circle(const Circle& c) //복사 생성자
	{
		cout << "반지름이" << _radius << "인 원 생성." << endl;

	}

	~Circle() // 소멸자. 객체가 사라질때 호출. 리턴 타입x , 이름은 '~' 를 붙인다
	{
		cout << "반지름이"<< _radius << "인 원 소멸" << endl;
	}

	double getArea()
	{
		return 3.14 * _radius * _radius;
	}
private:
	int _radius; // 지역변수의 경우 앞에 _를 붙인다. (팀마다 다름!)
};

class Rectangle
{
public:
	Rectangle()
	{
		_height = 1;
		_width = 1;
		cout << "높이가" << _height << "이고, 길이가" << _width << "인 사각형 생성" << endl;
	}
	Rectangle(int height, int width)
	{
		_height = height;
		_width = width;
		cout << "높이가" << _height << "이고, 길이가" << _width << "인 사각형 생성" << endl;
	}
	~Rectangle()
	{
		cout << "높이가" << _height << "이고, 길이가" << _width << "인 사각형 소멸" << endl;
	}

	double getArea()
	{
		return _height * _width;
	}

	bool checkRectangle()
	{
		if (this->_height == this->_width)
		{
			return true;
		}
		else false;
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
	}
	~Account()
	{
		cout << _name << "의 계좌가 소멸되었습니다." << endl;
	}
	string getOwner()
	{
		return _name;
	}
	int inquiry()
	{
		return _total;
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
private:
	string _name;
	int _total;
};

class Oval
{
public:
	Oval()
	{
		_height = 1; //높이와
		_width = 1; // 넓이
		cout << "높이가" << _height << "이고, 넓이가" << _width << "인 원 생성" << endl;


	}
	Oval(int height, int width)
	{
		_height = height; //높이와
		_width = width; // 넓이
		cout << "높이가" << _height << "이고, 넓이가" << _width << "인 원 생성" << endl;

	}
	~Oval()
	{
		cout << "높이가" << _height << "이고, 넓이가" << _width << "인 원 소멸" << endl;

	}

	void set(int height, int width)
	{
		_height = height; //높이와
		_width = width; // 넓이
	}

	void show()
	{
		cout << "높이 : " << _height << ", 넓이 : " << _width << endl;
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
*/
int main()
{
	/*
	Player player;
	player.hp = 5;

	Monster monster;
	monster.hp = 5; // 접근 불가능
	*/
	Circle circle;
	double area = circle.getArea();
	cout << "원의 면적은 " << area << "입니다." << endl;

	Circle circle2(5);
	double area2 = circle2.getArea();
	cout << "원2의 면적은 " << area2 << "입니다." << endl;

	cout << endl;
	
	// Rectangle
	// 멤버변수 : 높이와 길이, 생성자 소멸자, 면적을 반환하는 함수, 이녀석이 정사각형인지 아닌지를 체크하는 함수

	Rectangle rectangle;
	double rArea = rectangle.getArea();
	cout << "사각형의 면적은 " << rArea << "입니다." << endl;
	if (rectangle.checkRectangle() == true)
		cout << "정사각형입니다." << endl;
	else cout << "정사각형이 아닙니다."<< endl;

	//cout << "사각형의 높이와 길이를 입력하세요." << endl;
	//int h;
	//int w;
	//cin >> h;
	//cin >> w;
	//Rectangle rectangle2(h,w);
	Rectangle rectangle2(5,4);
	double rArea2 = rectangle2.getArea();
	cout << "사각형의 면적은 " << rArea2 << "입니다." << endl;
	if (rectangle2.checkRectangle() == true)
		cout << "정사각형입니다." << endl;
	else cout << "정사각형이 아닙니다." << endl;

	cout << endl;

	// 아래의 예제가 실행되도록 class 생성
	Account a("min", 10000);
	a.deposit(10000); //예금 , + 10000
	cout << a.getOwner() << "의 잔액은" << a.inquiry() << endl; // min의 잔액은 20000 출력
	int money = a.widhdraw(10000); // 출금 -10000
	cout << a.getOwner() << "의 잔액은" << a.inquiry() << endl; // min의 잔액은 20000 출력

	cout << endl;

	// 아래의 예제가 실행되도록 class 생성
	Oval c, d(3, 4); //기본 생성자, 인자 2개를 받는 생성자
	c.set(10, 20);// 높이와 넓이를 변경하는 함수.
	c.show(); // 높이와 넓이 출력
	cout << d.getWidth() << ", " << d.getHeight() << endl; //넓이랑 높이 출력

	cout << endl;

	Circle c1; //기본생성자
	Circle c2(10); // 인자를 받는 생성자.
	Circle c3(c1); // 복사생성자

	cout << endl;

} // 소멸자 호출 (생성자의 반대순대로 소멸된다.)
