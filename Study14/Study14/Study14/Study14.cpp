#include <iostream>
#include <string>

using namespace std;

class Inventory
{
public:
    Inventory()
    {
        cout << "Inventory 기본 생성자" << endl;
    }
    Inventory(const Inventory& inventory)
    {
        cout << "Inventory 복사 생성자" << endl;
    }
    ~Inventory()
    {
        cout << "Inventory 소멸자" << endl;
    }
private:
    int _data = 0;
    int _data2 = 0;
    char _data3[2000]; 
};

class Player
{
public:
    // 컴파일러에서 기본생성자를 자동으로 만들어줌 (인자를 받아오는 것 제외)
    // 아무것도 안만들 시에는 컴파일러가 기본적으로 기본생성자, 복사생성자는 만들어준다
    // 
    Player()
    {
        _hp = 10;
        cout << "기본 생성자 hp는 " << _hp << endl;
        _inventory = new Inventory();
    }
    Player(int hp)
    {
        _hp = hp;
        cout << "인자를 하나 받는 생성자 hp는 " << _hp << endl;
    }
    Player(const Player& player)
    {
        _inventory = new Inventory(*player._inventory); 
        // player의 새로운 인벤토리를 만들어준다. (새로운 주소 할당)
        cout << "복사생성자 실행" << endl;
    }
    ~Player()
    {
        delete _inventory;
        cout << "소멸자 실행" << endl;
    }
    int GetHp() { return _hp; }
    void SetHp(int hp) { _hp = hp; }
private:
    int _hp;
    Inventory* _inventory; // 포인터를 사용해서 주소값만 가져올수 있음(8바이트)
};

void increase(Player* p) // 값을 넘겨야해서 포인터를 사용
{
    int hp = p->GetHp();
    p->SetHp(hp + 1);
}

void increase(Player& p) // 참조로 가져올 경우
{
    int hp = p.GetHp();
    p.SetHp(hp + 1);
}

Player getPlayer() // 객체를 만들어서 넘길 경우
{
    Player p2(31);
    return p2;
}

void TestNum(Inventory inventory)
{

}

void TestPtr(Inventory* inventory)
{

}

class Student
{
public:
    Student()
    {
        _name = "Kim";
        _age = 20;
        cout << "Student 기본생성자" << endl;
    }
    Student(char& name, int age)
    {
        _name = &name;
        _age = age;
        cout << "인자를 받아오는 생성자" << endl;
    }
    Student(const Student& student)
    {
        _name = new char(*student._name);
        _age = student._age;
        
    }
    char getName() { return *_name; }
    int getAge() { return _age; }

private:
    char* _name;
    int _age;
};

int main()
{
    /*
    Player p1(30);
    increase(p1);
    cout << p1.GetHp() << endl; // 30

   Player p2 = getPlayer();
   cout << p2.GetHp() << endl;


//   Player p1; // 기본생성자
//   Player p2(10); // 인자를 하나받는 생성자
//   Player p3(p1); // 복사생성자
 //   Player p4; // 기본생성자
 //   p4 = p1; // 복사대입연산자 (복사생성자와 다름)

    // 얕은복사 깊은복사의 차이
    // 컴퓨터가 기본적으로 만들어주는 복사생성자 (얕은복사
    // 멤버데이터를 비텨을 단위로 똑같이 복사(메모리 값을 그대로 복사)

    // stack p1(0x00ff...)  -> heap 0x00ff... 같은곳을 가르킨다. (주소가 같음)
    // stack p2(0x001a...)
    
    // new inventory ; 
    // delete inventory;
    // delete inventory;  같은곳을 가르키고있어서 같을걸 지우고있음
    
    // 깊은 복사
    // 멤버데이터가 주소값이라면 데이터를 새로 만들어줘야된다.
    // stack p1(0x00ff) -> heap 0x00ff inventroy[]
    // stack p2(0x001a) -> heap 0x001a inventory[]

   // Inventory inventory; // 2008바이트 . 스택에 저장
   // Inventory* inventory2 = new Inventory(); // 스택 주소 8바이트 안에 ->heap[2008바이트] 
   // 
   //  생성자랑 소멸자가 찍힌다.
   // TestNum(inventory); // 2008바이트 , 복사-> 소멸
   // TestNum(*inventory2); // 4~8 8바이트를 넘김, 복사 -> 소멸

   //  생성자랑 소멸자가 찍히지 않음 편하게 이용
   // TestPtr(&inventory);
   // TestPtr(inventory2);

   // delete inventory2;

   //Inventory inventory4[100]; // 2008 * 100 공간

   //Inventory* inventory5[100]; 
   // inventory5가 가리키는 주소값이 들어있고, 안에 데이터가 있는지 없는지 모름 
   // 800바이트 안에 2008*100 
*/

    Student s1 = Student("Kim", 10);
    Student s2 = s1;

    cout << s1.getName() << ", " << s2.getAge() << endl;
    cout << s2.getName() << ", " << s2.getAge() << endl;
}

