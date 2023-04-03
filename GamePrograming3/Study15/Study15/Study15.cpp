#include <iostream>
#include <vector>
#include <map>
using namespace std;

// 이동과 스마트포인터.

// <사라진 auto_ptr의 생김새>
template<typename T>
class AutoPtr
{
public:
    AutoPtr(T* ptr = nullptr) : m_ptr(ptr)
    {

    }
    ~AutoPtr()
    {
        if (m_ptr != nullptr)
            delete m_ptr;
    }

    AutoPtr(AutoPtr& a) // 복사생성자.
    {
        m_ptr = a.m_ptr; // 자신의 값에 a를 넣고
        a.m_ptr = nullptr; // a의 값은 null로 바꿈
    }

    // 이동. 소유권이전 move
    AutoPtr& operator = (AutoPtr& a)
    {
        if (&a == this) // 자기 자신일 경우는 그냥 return.
            return *this;

        delete m_ptr; // 이미 메모리를 가지고 있으면 지움

        m_ptr = a.m_ptr; // 자기 자신에 a값을 넣고
        a.m_ptr = nullptr; // 원래 녀석은 null 로 바꾸고
        return *this; // 자기값(a값)을 return // move와 관련이 있음.
    }

    T& operator*() { return *m_ptr; }
    T* operator->() { return m_ptr; }

public:
    T* m_ptr = nullptr;
};


class Resource
{
public:
    Resource()
    {
        cout << "construct" << endl;
    }

    ~Resource()
    {
        cout << "destroy" << endl;
    }

public:
    int _m_data[100];
};

void Test()
{
    AutoPtr<Resource> res1(new Resource);
    AutoPtr<Resource> res2; // 생성자는 안찍히지만

    cout << res1.m_ptr << endl;
    cout << res2.m_ptr << endl;

    res2 = res1; // 서로 같은주소를 가르키고

    cout << res1.m_ptr << endl; // 1도 소멸자를 호출하고
    cout << res2.m_ptr << endl; // 2도 소멸자를 호출해서 오류가 발생한다.

    /* if (true)
         return;*/

         //    delete res; // autoptr에 자동으로 지워주는 기능이 있어서, 따로 delete 해주지 않아도 된다. -> 복사문제때문에 삭제됨.

    return;
}

int MultiPly()
{
    return 100 * 100;
}

void Something(int& ref)
{
    cout << "l-value" << endl;
}

void Something(int&& ref)
{
    cout << "r-value" << endl;
}

class Player
{
public:
    shared_ptr<Player> _target = nullptr;

};

// 값방식, 값을 복사해서 넣음 call by value 
// &player 원본수정 아무렇게나. //const Player& player 수정X 읽기만 
// &&player 원본을 넘겨줘서 니 맘대로하는데 우린이젠 사용안해.
void TestPlayer1(Player& player)
{

}
void TestPlayer(Player&& player)
{

}


int main()
{

    vector<string>v;
    string str = "World";

    v.push_back(str); // l-value;
    cout << str << endl; // World
    cout << v[0] << endl; // World

    v.push_back(move(str)); // r-value를 넘겨받은 방식

    cout << str << endl; // 없음. move로 이동해서 삭제됨
    cout << v[0] << " " << v[1] << endl; // World World // v[0]은 이미 str의 값이 넣어져있어서 나옴(주소를 가르키는게 아님!)

    // 스마트 포인터 - 요즘에는 대부분 생 포인터가 아닌, 스마트 포인터를 이용한다.
    // #1 unique_ptr 나만 쓸 수있는 녀석. auto_ptr 대체.
    unique_ptr<Resource> unptr = make_unique<Resource>();
    //unique_ptr<Resource> unptr2 = unptr; // 나만 쓸수있어서 할당 할 수 없음.
    unique_ptr<Resource> unptr2 = move(unptr); // 이동가능

    // #2 shared_ptr 공유가능
    shared_ptr<Player> share1 = make_shared<Player>();
    shared_ptr<Player> share2 = make_shared<Player>();

    // player   총알(객체)  --->  monster 
    // play를 바라보는 monster만큼 refcount ++;; 을 하다가 count가 0이 되면 소멸.
    // 플레이어가 몬스터를 향해 총알을 쐈는데, 총알이 몬스터의 주소를 가지고있다가 사라지면 갈곳일 잃어버림. -> 오류 발생
    // 이를 방지하기 위해서 나온게 shared_ptr
    share1->_target = share2;

    // #3 weak_ptr (rock을 걸어서 순환구조를 막음) 속도는 shared가 더 빠르다. 서로가 타켓일 경우에만 사용하기!
    // s1 -> s2     s2 -> s1 
    // 서로서로 target인 상황
    // 메모리가 삭제 되지않아 무한순환구조.
    // -> weak_ptr이 나오게 됨.
    share1->_target = share2;
    share2->_target = share1;

    // use after free 댕글링포인터. 소멸자 신경쓰지않아도 알아서 delete 해준다.. 완전 굿..

    // =====================================================================

    //Player p1;
    //// TestPlayer1(Player()); // 불가능함.
    //TestPlayer(Player());
    //// 복사. 이동 속도가 엄청빠르다. 서버쪽에서 주로사용
    //Player p2;
    //p2 = static_cast<Player&&>(p1);
    //p2 = move(p1);

   //  Test();

    int x = 5; // x = lvalue(왼쪽, 사라지지 않는다.) , 5 = rvalue(오른쪽, 넣은 다음에 사라짐)
    int y = x; // x는 rvalue? 가 아님. lvalue

    //  int y = MultiPly();
    const int cx = 5;
    const int cy = MultiPly();

    // 서버쪽에서 move를 많이쓴다.
    Something(x); // l-value
    Something(5); // r-value
    Something(MultiPly()); // r-value


    int& lr1 = x; // 참조값을 받아와서 가능
    //int& lr2 = cx; // const붙은 값들은 문법적으로 안된다.
    //int& lr3 = 5; // rvalue는 안된다.
    //int& lr4 = MultiPly(); // 잠깐 왔다가 사라지는 값은 주소에 담을수 없다.

    // const는 수정이 안되서, cx나 5를 넣을 수 있다.
    const int& lr4 = x; // 참조 대상을 x에서 못바꾼다.
    const int& lr5 = cx; // 참조 대상을 cx에서 못바꾼다.
    const int& lr6 = 5; // 참조 대상을 10에서 못바꾼다.
    const int& lr7 = MultiPly();

    //int&& rr1 = x;
    //int&& rr2 = cx;
    int&& rr3 = 10; // 참조 두개(&&)는 이동한다는 의미 // && 곧 사라질 애들만 담을 수 있다. 안사라지는건 못함.
    int&& rr4 = MultiPly(); // 주소의 주소가 아니고, 새로운 문법임.
    cout << rr3 << endl
        << rr4 << endl;
    rr3 = 20;
    cout << rr3 << endl;

    //const int&& rr1 = x;
    //const int&& rr2 = cx;
    const int&& rr5 = 20;
    const int&& rr6 = MultiPly();
}
