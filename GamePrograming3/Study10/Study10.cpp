#include <iostream>
#include <vector>
using namespace std;

#include <tuple> // return을 여러개 받을수 있음. 개수에 제한이 없다.


enum Job
{
	None,
	Archer,
	Knight,
	Mage
};

enum class Monster
{
	Mage // job에 이미 mage가 있어서 에러가 생긴다. -> enum class를 써서 해결
};

/*
tuple<int, string>person()
{

	return tuple<int, string>(123, "abc");
}
*/
auto person()
{

	return tuple<int, string>(123, "abc");
}

int main()
{
	// tuple<int, string>result = person();

	auto result = person();
	cout << get<0>(result) << " " << get<1>(result);
	// result의 0번째 값 int 123 
	// result의 1번째 값 string "abc" 가 출력됨.

	int value = Knight;
	
	int value2 = Mage; // job의 mage로 인식
	int value3 = static_cast<int>(Monster::Mage); // static_cast를 해주어야 monster의 mage를 사용가능
}