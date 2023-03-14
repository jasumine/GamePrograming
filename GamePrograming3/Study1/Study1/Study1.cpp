#include <iostream>
using namespace std;
#include "test.h"

class A
{
public:
    A(int a)
    {
        cout << "A: " << a << endl;
    }
    ~A()
    {
        cout << "~A" << endl;
    }
};

// C#에선 기본이 private임
// c++에선 기본이 private으로 상속
// 기본클래스의 protected, public 멤버변수가 모두 private로 바뀌어서 상속 (거의 쓸 일이 없음)
class B : public A
{
public:
    B(int a, double b) :A(a)
    {
        cout << "B : " << b << endl;
    }
    ~B()
    {
        cout << "~B" << endl;
    }
    
};

class C :public B
{
public:
    C(int a, double b, char c) :B(a, b)
    {
        cout << "C: " << c << endl;
    }
    ~C()
    {
        cout << "~C" << endl;
    }
};

class AA
{
public:
    AA(int value) : _value(value)
    {
    }
    void print()
    {
        cout << "AA" << endl;
    }

protected:
    int _value;
};

class BB :public AA
{
public:
    BB(int value2) :AA(_value)
    {

    }
    void print()
    {
        AA::print(); // b를 호출할때 a를 호출할 수 있음.
        cout << "BB" << endl;
    }
protected:
    int _value2;
};

int main()
{
  //  C c(500, 5.4f, 'a');
    // 생성될 때는 부모부터지만, 소멸될때는 반대로 소멸.

    AA aa(5);
    aa.print();

    BB bb(6);
    bb.print();

    Test1();

    Player p(10, 20);
    p.Move();
}
