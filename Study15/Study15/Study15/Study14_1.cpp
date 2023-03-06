#include <iostream>
using namespace std;
#pragma warning(disable:4996)

class Student
{
public:
	Student()
	{

	}
	
	Student(const Student& student)
	{
		_name = new char[strlen(student._name)+1];
		strcpy(_name, student._name);
		_age = student._age;
	}
	
	Student(const char* name, int age)
	{
		_name = new char[strlen(name) + 1]; // 길이 + \0(1) 포함해서 할당
		strcpy(_name, name); // 이름 복사
		_age = age;
	}

	~Student() {}
public:
	char* _name;
	int _age;
};

int main()
{
	Student s1 = Student("Kim", 20);
	Student s2 = s1; //복사 생성자
	cout << s1._name << " " << s1._age << endl; // kim, 20
	delete[] s1._name;
	cout << s2._name << " " << s2._age << endl; // (복사생성자를 작성하지 않은경우) X , 20 // (복사생성자를 생성한 경우) Kim, 20
}