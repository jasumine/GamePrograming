#include<iostream>

using namespace std;

//class Student
//{
//public:
//	Student(string name) : Student(0, name) // 위임 생성자
//	{
//
//	}
//	Student(int id, string name) : _id(id), _name(name)
//	{
//		/*_id = id;
//		_name = name;*/
//	}
//	void print()
//	{
//		cout << _id << " " << _name << endl;
//	}
//	int getId() const { return _id; } // 읽기전용 이라는 뜻으로 const를 붙인다.
//  const int getId() // 반환형이 const라는 뜻. return 되는 int 값이 const int라는 뜻?!
//
//private:
//	int _id;
//	string _name;
//};

//class Person
//{
//public:
//	// 보통 변수는 공유되지 않지만, static으로 선언된경우 객체끼리 공유가 된다.
//	static int sharedMoney;
//	static void addShared(int n)
//	{
//		sharedMoney += n;
//	}
//	void AddMoney(int money)
//	{
//		_money += money;
//	}
//
//public:
//	double _money;
//};
//
// int Person::sharedMoney = 100;
//// static 전역변수. 프로그램이 끝날때까지 살아있음.
//// 멤버변수. 다같이 사용. 변수이름만 다를뿐 같은주소를 사용한다.
//// 반드시 전역범위에 초기화를 해주어야 한다.

 class Something
 {
 public:
	 static int _value;
 };

 int Something::_value = 1;

/*
int generateId()
{
	static int s_id = 1;
	return s_id++;
}

class Marine
{
public:
	int _hp;
	static int s_attack;
	
	static void Test()
	{
		// _hp = 100; // hp는 static이 아니여서 접근 불가능
		s_attack = 10; // static 멤버 변수만 접근 가능.
	}
};

int Marine::s_attack = 0;

int mul(int a)
{
	return a * a;
}

int mul(float a = 10)
{
	return a * a;
}

void fillLine(int n = 20, char c = '*')
{
	for (int i = 0; i < n; i++)
		cout << c;
	cout << endl;
}

class Person
{
public:
	Person(string name) : _name(name)
	{

	}
	// friend 는 가끔 쓰인다!!
	friend void sayName(Person p); //함수도 친구가 가능
	friend class Men; // Men이 private에 접근할 수 있게 
private:
	string _name;
};

class Men
{
public:
	void print(Person p)
	{
		cout << p._name << endl;
	}
};

void sayName(Person p)
{
	cout << p._name << endl;
}
*/

 class Id
 {
 public:
	 static int _id;
 private:

 };

int main()
{
	/*Student student(0, "kim");
	student.print();

	Student student2(0, "lee");
	student2.print();*/

	/*Person p1;
	p1._money = 500;
	p1.sharedMoney = 1000;

	Person p2;
	p2._money = 400;
	p2.AddMoney(200);
	p2.addShared(500);

	cout << p1._money << ' ' << p2._money << endl; // 500, 600
	cout << p1.sharedMoney << ' ' << p2.sharedMoney << endl; // 1500 , 1500 */

	/*cout << Something::_value << endl;
	cout << &Something::_value << " " << Something::_value << endl;

	Something st1;
	Something st2;

	st1._value = 3;

	cout << st1._value << " " << &st1._value << endl;
	cout << st2._value << " " << &st2._value << endl;*/
	// 이름만 다를뿐 같은주소임을 확인
	
	/*
	cout << generateId() << endl;
	cout << generateId() << endl;
	cout << generateId() << endl;
	cout << generateId() << endl;

	Marine m1;
	m1._hp = 40;
	m1.s_attack = 6;

	Marine m2;
	m2._hp - 40;
	m2.s_attack = 6;

	Marine::s_attack = 7;

	cout << mul(5) << endl;

	fillLine();
	fillLine(30);
	fillLine(50, '&');
	fillLine('('); // ( 가 아스키코드로 40이라서 *이 40번 찍힌다.

	Person p1("정동규");
	sayName(p1);
	Men men1;
	men1.print(p1);*/
}

// static 아이디 생성해서 넘겨주기?!
// public 모두 접근 가능 , protected 자신과 상속받은 자신, private 자기자신만
// 상속성, 은닉성, 다형성