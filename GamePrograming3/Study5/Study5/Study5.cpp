#include <iostream>
using namespace std;
#include<cassert>

typedef int DATA; // int를 data라는 이름으로 대체

int ADD(int a, int b)
{
	return a + b;
}

int Sub(int a, int b)
{
	return a - b;
}

class funObject
{
public:
	void operator()() // ()를 연산자 오버로딩
	{
		cout << "Hello" << endl;
	}

	int operator()(int a, int b)
	{
		return a + b;
	}

private:
	int _value;
};

class Item
{
public:
	int _itemId = 0;
	int _rarity = 0; // 희귀도
};

class FindByItemID
{
public:
	bool operator()(const Item* item)
	{
		return (item->_itemId == _ownerId);
	}

public:
	int _ownerId;
};

// 아이템안에
/*
Item* FindItem(Item items[], int itemCount, FindByItemID selector)
{
	for (int i = 0; i < itemCount; i++)
	{
		Item* item = &items[i]; // 배열을 itemCount(아이템의 개수)만큼 만들고

		if (selector(item)) // selector(item)을 통해 찾는 id가 있을 경우(true), item을 반환
			return item;
	}
}
*/
class Player
{
public:
	virtual ~Player() {}
};

class Mage : public Player
{
public:
	//~Mage() override {};
};

class Archer : public Player
{
public:
	//~Archer() override {};
};

class Computer 
{

};

int main()
{
	int number = 5;
	assert(number == 4); // false는 런타임에러가 나는데 release모드는 관여X, debug 모드에선 에러가 발동. 위치까지 정확히 알려준다.
	// 디버깅시 편함


	// static_assert(number == 4, "error ,essage"); // 요런건 불가능 조건식.

	/*
	// cast 4종류 ( 2종류만 주로 사용 )

	// 1) static_cast : 상식적인 캐스팅만 허용해줌
	int hp = 10;
	float ratio = static_cast<float>(hp); // int 값을 float로 바꿔준다.


	Player* p = new Mage();
	// Mage* m = (Mage*)p; // 불안정. 형변환이 안된 p는 넣을 수 없음. 
	// Mage* mm = static_cast<Mage*>(p); // 불안정하지만 가능

	// 2) dynamic_cast : 상속관계에서 안전하게 변환을 시킴.
	// virtual을 선언하지 않을시 에러를 뱉으나 virtual 선언해버리면 가능.rtti 근데 완전히 말이 안되는 타입을 넣는다 null을 반환..(p가 아닌 p2를 넣을시)
	Player* p2 = new Archer();
	Mage* m1 = dynamic_cast<Mage*>(p);


	// 3) const_cast : const를 떼는 것. (수정이 가능)
	char str[] = "Hello";
	const char* ptr = str;
	cout << str << endl;

	char* c = const_cast<char*>(ptr);
	c[0] = 'Z';
	cout << str << endl;

	// 4) reinterpret_cast : 말이안되는 전혀 다른 타입의 녀석도 강제로 변환. 거의 쓰지 않는다.
	Computer* computer = reinterpret_cast<Computer*>(p); // player 타입으로 ㄷㄷ
	*/

	/*Item items[10];
	items[3]._itemId = 50;
	items[3]._rarity = 2;

	FindByItemID functor1;
	functor1._ownerId = 50;

	Item* item1 = FindItem(items, 10, functor1); // itemid를 찾는 함수)

	funObject funcObject;
	funcObject(); // 클래스를 함수처럼 사용
	int number = funcObject(4, 5);

	cout << number << endl;*/
	
	/*
	int a = 10;
	int b = 5;
	DATA aa = 5; // int aa = 5;
	DATA *aptr = &a; // int* aptr = &a;

	//typedef int(FUNC_)(int a, DATA b); // int 타입 인자를 2개받아서 int를 리턴하는 함수를 정의.
	//FUNC_* fn; // 함수의 주소를 담는 함수?!

	// 주로 위의 두줄을 합쳐서 아래처럼 적는다.
	typedef int(*FUNC_)(int a, int b);
	FUNC_ fn; // 함수포인터 선언

	fn = ADD; // 함수의 형태가 같을경우 함수포인터에 넣을 수 있다.
	fn = Sub; // 함수의 주소를 담았다. &생략가능 ( fn = &Sub ) 

	int result = ADD(5, 10);
	int result2 = fn(5, 10); // 함수의 이름은 함수의 시작주소와 같다. (배열과 유사)
	int result3 = (*fn)(5, 10); // 함수포인터는 *를 붙여도 함수주소를 가지고있다.
	int result4 = Sub(5, 10);

	cout << result << " "
		<< result2 << " "
		<< result3 << " "
		<< result4 << " " << endl; // 15 15

	// 포인터 - 주소를 담는 녀석.
	// 함수포인터. 함수도 포인터처럼 사용가능. 함수의 주소를 담는다
	*/
	
}
