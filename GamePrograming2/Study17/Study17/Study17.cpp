#include <iostream>
#include <fstream> // 실제 file 만들기

using namespace std;
/*
class Cents
{
public:
	Cents(int cents = 0)
	{
		m_cents = cents;
	}
	int getCents()const
	{
		return m_cents;
	}

	// 연산자 오버로딩 #3
	Cents operator+(const Cents& cents)
	{
		return Cents(this->m_cents + cents.getCents());
	}

	// 연산자 오버로딩 #4
	//friend Cents operator+(const Cents& cents1, const Cents& cents2);

	Cents operator-(const Cents& cents)
	{
		return Cents(-m_cents);
	}

	// +
	Cents& operator++() // 전위 연산자 ++cents1
	{
		++m_cents; // 변수를 1 늘리고
		return *this; // 주소값을 리턴.
	}

	Cents operator++(int) // 후위 연산자 (헷갈려서 int 를 붙이기로함) cents1++
	{
		Cents temp(m_cents); // 새로만들어서
		++m_cents; // 더하는데
		return temp; // 더하기 전 값을 리턴
	}

	// -
	Cents& operator--() // 전위 연산자
	{
		--m_cents; // 변수를 1 늘리고
		return *this; // 주소값을 리턴.
	}

	Cents operator--(int) // 후위 연산자 (헷갈려서 int 를 붙이기로함)
	{
		Cents temp(m_cents);
		--m_cents;
		return temp;
	}

	friend bool operator==(const Cents& c1, const Cents& c2)
	{
		return c1.m_cents == c2.m_cents; // 같을 경우
	}
	friend bool operator!=(const Cents& c1, const Cents& c2)
	{
		return c1.m_cents != c2.m_cents; // 다를 경우
	}

	friend ostream& operator<< (ostream& out, const Cents& cents)
	{
		out << cents.m_cents;
		return out;
	}

public:
	int m_cents;
};

// 연산자 오버로딩 #1
Cents add(const Cents& cents1, const Cents& cents2) // 일반적인. class 밖에 원하는 기능.
{
	return Cents(cents1.getCents() + cents2.getCents());
}

// 연산자 오버로딩 #2
Cents operator+(const Cents& cents1, const Cents& cents2)
{
	return Cents(cents1.getCents() + cents2.getCents());
}
*/

class Point
{
public:
	// double x 에 값을 넣어줄경우 x y z 세개다 넣어주어야 한다.
	Point(double x = 0.0, double y= 0.0, double z = 0.0) : m_x(x), m_y(y), m_z(z)
	{

	}

	void print()
	{
		cout << m_x << " " << m_y << " " << m_z << endl;
	}

	// ostream은 ??때문에 꼭 friend 선언을 해주어야한다.
	friend ostream& operator<<(ostream& out, const Point& p)
	{
		out << "(" << p.m_x << " " << p.m_y << " " << p.m_z  << ")" << endl;
		return out; 
	}
	
	friend istream& operator>>(istream& in, Point& p)
	{
		in >> p.m_x >> p.m_y >> p.m_z;
		return in;
	}


private:
	double m_x;
	double m_y;
	double m_z;
};

int main()
{
	ofstream file("text.txt");

	//Point p1(0.1, 0.2, 0.3), p2(3.5, 1.4, 1.7);
	
	Point p1, p2;
	cin >> p1 >> p2;

	cout << p1 << p2 << endl; // class 출력
	file << p1 << " " << p2 << endl;

	file.close();

	//Point p3;
	//cin >> p3;
	//cout << p3 << endl;

//	Cents cents1(10), cents2(20);
////	cout << add(cents1, cents2).getCents() << endl;
//	cout << (cents1 + cents2 +Cents(5)).getCents() << endl;
//
//	cout << -cents1 << endl;
//
//	cents1++;
//	++cents1;
//
//	cents1--;
//	--cents1;

}

