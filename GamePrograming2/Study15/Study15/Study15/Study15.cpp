#include<iostream>

using namespace std;

//class Student
//{
//public:
//	Student(string name) : Student(0, name) // ���� ������
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
//	int getId() const { return _id; } // �б����� �̶�� ������ const�� ���δ�.
//  const int getId() // ��ȯ���� const��� ��. return �Ǵ� int ���� const int��� ��?!
//
//private:
//	int _id;
//	string _name;
//};

//class Person
//{
//public:
//	// ���� ������ �������� ������, static���� ����Ȱ�� ��ü���� ������ �ȴ�.
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
//// static ��������. ���α׷��� ���������� �������.
//// �������. �ٰ��� ���. �����̸��� �ٸ��� �����ּҸ� ����Ѵ�.
//// �ݵ�� ���������� �ʱ�ȭ�� ���־�� �Ѵ�.

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
		// _hp = 100; // hp�� static�� �ƴϿ��� ���� �Ұ���
		s_attack = 10; // static ��� ������ ���� ����.
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
	// friend �� ���� ���δ�!!
	friend void sayName(Person p); //�Լ��� ģ���� ����
	friend class Men; // Men�� private�� ������ �� �ְ� 
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
	// �̸��� �ٸ��� �����ּ����� Ȯ��
	
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
	fillLine('('); // ( �� �ƽ�Ű�ڵ�� 40�̶� *�� 40�� ������.

	Person p1("������");
	sayName(p1);
	Men men1;
	men1.print(p1);*/
}

// static ���̵� �����ؼ� �Ѱ��ֱ�?!
// public ��� ���� ���� , protected �ڽŰ� ��ӹ��� �ڽ�, private �ڱ��ڽŸ�
// ��Ӽ�, ���м�, ������