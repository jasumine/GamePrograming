#include <iostream>
using namespace std;

class Player 
{
public:

	virtual ~Player()
	{
		cout << "~player" << endl;
	}
	// 정적바인딩. :  컴파일 시점에 결정. 일반함수
	 virtual void Move() // 동적바인딩. 자식에서 재정의된 함수가 호출 될 때 (똑같은 함수)
		 // 자식클래스의 함수를 호출해준다. 실행시간에 결정하도록 미뤄준다.
	{
		cout << "move player" << endl;
	}
};

class Mage :public Player
{
public:
	~Mage() override
	{
		cout << "~Mage" << endl;
	}
	void Move() override final // 자식은 virtual 생략 가능, override는 표시해주면 보기 좋다! (c#은 void앞에 override를 붙인다.)
		// fianl을 붙이면, move를 더이상 상속시키지 않겠다는 뜻 -> Mage를 상속받은 DarkMage는 move를 쓸 수 없다.
		// player를 상속받은 archer는 move를 쓸 수 있다. 
	{
		cout << "move Mage" << endl;
	}
};

//class DarkMage : public Mage
//{
//public : 
//	void Move() 
//	{
//		cout << "move Dark Mage" << endl;
//	}
//};
//
//class archer :public Player
//{
//public:
//	void Move()
//	{
//		cout << "move archer" << endl;
//	}
//};


void MovePlayer(Player* player)
{
	player->Move();
}

void MoveMage(Mage* mage)
{
	mage->Move();
}

// 추상클래스. 부모에서는 설계만 한다.
class Calculator
{
public:
	virtual int add(int a, int b) = 0; // '=0'을 붙이면 추상클래스라는 뜻. 정의는 자식에서 하겠다.
	virtual int subtract(int a, int b) = 0; // 순수가상함수
};

class SubCalculator :public Calculator
{
public: // 자식에서는 반드시 구현을 해주어야한다.
	
	int add(int a, int b)
	{
		return a + b;
	}
	int subtract(int a, int b)
	{
		return a - b;
	}
};

// c++에서는 다중상속 가능. c# java 다중상속 애초에 막았다.
class Base
{
public:
	int mode;
};

class In : virtual public Base
{
public:
	int in;
};

class Out : virtual public Base
{
public :
	int out;
};

class Inout : public In, public Out
{
public:
	int inout;
	void Move()
	{
		mode = 10;
	}
};



int main()
{
	Inout inout;
	inout.in = 5;
	inout.out = 10;
	inout.mode = 5; // 1)in을 상속받은 mode인지, 2)out을 상속받은 mode인지 몰라서 오류가 발생
	// virtual public Base로 해결가능. -> inout.mode는 In에게서 상속받은 mode로 인식한다.(첫번째만) -> 다른언어에서는 인터페이스를 사용.


//	Calculator* cal = new Calculator(); // 설계도자체로, 만드는것도 불가능하다.
	Calculator* cal = new SubCalculator();
	cout << cal->add(5, 10) << endl;
	cout << cal->subtract(10, 5) << endl;


//	Player p;
//	MovePlayer(&p);
////	MoveMage(&p); // player -> mage 인가요? 아니요.
//	
//	Mage m;
//	MoveMage(&m);
//	MovePlayer(&m); // mage-> player 인가요? 네.
//	// 출력은 Player 함수가 호출된다 -> 함수에 virtual을 붙여주면, mage로 뜬다.
//	

	//Player* player = new Player();
	//Mage* mage = (Mage*)player; // 강제 형변환을 하면 가능, 없으면 불가능, 조심해야함!!!!! 

	//Mage* mage = new Mage();
	//Player* player = mage; // 암시적 형변환, 조심해야함!!

	Mage* mage = new Mage(); 
	Player* player = new Mage();

	delete mage; // 자식이 사라지면 부모도 같이 사라진다 -> ~mage, ~player
	delete player; // player만 소멸됨. mage는 소멸이 되지않았다. --> 소멸자에 virtual을 붙이면 해결된다.
}
