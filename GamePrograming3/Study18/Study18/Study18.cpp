#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include <thread>

/*
struct S
{
    int m_x;
    S()
    {
        m_x = 42;
    }
};

const S test() { return S(); };
const int& test2() { return 123; };

void Test()
{
    vector<int> v{ 10,20 };

    auto a = test(); // a = S
    typedef decltype(test()) test_type; // const S

    auto b = test2(); // int
    typedef decltype(test2()) test_tyep; // const int&

    auto itr = v.begin(); // vector<int>::iterator
    typedef decltype(v.begin()) itr_type; // vector<int>::iterator

    auto first = v[0]; // int
    decltype(v[0]) first1 = first; // int&
}
*/

int main()
{
    int a = 0;
    int b(0);
    int c{ 0 };

    vector<int> v1;
    v1.push_back(10);
    
    vector<int> v2(10, 1); // 10칸에 1을 넣겠다.
    vector<int> v3{ 1,2,3,4,5,6 };

    //// int double 축소변환 문법적으로 막혀있다. ()는 되는데 { }는 안됨.
    //int x = 0;
    //double y{ x };
    
    //==============================================================

    // 람다 (되게 많이 쓴다!)
    // 함수를 간단하게 표현.

    // 캡쳐리스트    매개변수    리턴타입(생략가능)  함수내용.
    // []            ()         ->                  {}
    // 인자 2개를 받아서 리턴하는 함수    
    //[](int x, int y) -> int {return x + y; }; // 인자 2개를 받아서 int타입을 리턴함.
    //[](int x, int y) {return x + y; } (5, 10); // return 생략
    //[](int x, int y) {cout << "sum" << x + y; } (5, 10); // return 생략, 5,10을 매개변수로 넣음

    //double pi = 5.5;
    //// [] () {} <<람다 쓰는 순서
    //auto cal = [pi](int r) {return pi * r; }; // []는 복사방식으로 들어감.(기본) (원본변경불가)
    //cout << cal(10) << endl;

    //int sum = 0;
    //[&sum](int x, int y) {sum = x + y; }(10, 20); // [&]를 넣으면 참조방식.(원본변경)
    //// 여러 인자를 받을 경우
    //// [=, &sum] 기본적으로 복사방식으로 받는데 sum만 참조방식으로 받겠다. (대입연산자를 복사방식으로)
    //cout << sum << endl;

    //vector<int>v;
    //v.push_back(1);
    //v.push_back(2);
    //
    //auto func = [](int val) {cout << val << endl; }; // 다회성으로 사용가능
    //for_each(v.begin(), v.end(), func); // 처음부터 끝까지 func 함수를 실행-> v의 처음부터 끝까지 출력.
    //
    //for_each(v.begin(), v.end(), [](int val) {cout << val << endl; }); // 일회성으로 쓸 경우 이렇게 작성.
    //

    //int value(5);
    //[&value]() {return value += 10; }();

    //auto temp = [](int& input) {return input += 10; };
    //cout << temp(value) << endl;

    //==============================================================

    // auto 와 유사한 decltype
    
    //int x = 0;
    //int y = 0;
    //const int cx = 40;
    //const int cy = 50;
    //double d1 = 3.14;
    //double d2 = 5.43;

    //typedef decltype(x* y) xy_type; // xy_type = int
    //auto a = x * y;

    //typedef decltype(cx* cy) cxcy_type; 
    //auto b = cx * cy;

    //typedef decltype(d1 < d2 ? d1 : d2) double_type; // double&
    //auto c = d1 < d2 ? d1 : d2;

    //typedef decltype(x < d2 ? x : d2) type_midx;
    //auto d = x < d2 ? x : d2;

    //

    //struct S
    //{
    //    int m_x;
    //    S()
    //    {
    //        m_x - 42;
    //    }
    //};

    //int x;
    //const int cx = 42;
    //const int& crx = x;
    //const S* p = new S(); // p는 S를 동적할당받음.

    //typedef decltype(x) x_type; // int
    //typedef decltype((x)) x_type2; // int&
    //auto a = x; // int
   
    //typedef decltype(cx) cx_type; // const int
    //typedef decltype((cx)) cx_type2; // const int&
    //auto b = cx; // int -> auto 특성상 const , & 인식하지못함.

    //typedef decltype(crx) crx_type; // const int&
    //typedef decltype((crx)) crx_type2; // const int&& 라고 생각했는데? const int&임 ( &&는 move함수여서그런듯)
    //auto c = crx; // int -> 위와 마찬가지.

    //typedef decltype(p->m_x) s_type; // int
    //typedef decltype((p->m_x)) s_type2; // cont int&
    //auto d = p->m_x; // int

    // auto와 달리 decltype는 const 와 &를 인식해서 auto보다 더 낫다.

    //auto e = min(x, d2); // auto를 쓸 때 두값의 타입이 다르면 쓸 수 없음.

//

    //auto func = []() {return 42; };
    //decltype(func) func2(func); // func2 = func 'copy' 방식으로 사용
    //decltype((func)) func3(func); // func3 = func 'reference' 방식으로 사용

    //cout << &func << " " << func() << '\n';
    //cout << &func2 << " " << func2() << '\n';
    //cout << &func3 << " " << func3() << '\n'; // 참조로 받아와서 주소값이 똑같이 찍힌다.

    //==============================================================

    //// 람다 auto 사용 가능 // 일반 함수의 매개변수는 atuo 사용 불가능.
    //auto func = [](auto x, auto y) { return x + y; };
    //cout << func(1.1, 5) << " " << func(5.4, 2.3) << '\n';

    //==============================================================

// c# property  interface(다중상속)   delegate << c++보다 더 좋은 함수들?~
    
    // thread 서버 네트워크에서 주로 사용!
/*
    cout << thread::hardware_concurrency() << "\n"; // 논리 프로세서 갯수
    cout << this_thread::get_id() << "\n";

    const int num = thread::hardware_concurrency();

    vector<thread>my_threads;
    my_threads.resize(num);

    for (auto& e : my_threads)
        e = thread([]()
            {
                cout << this_thread::get_id() << endl;
                while (true)
                {
                }
            });
    
    for (auto& e : my_threads)
        e.join(); 

    // 하나가 끝나면 아이디를 가져오는 거

   // thread t1 = thread([] {cout << this_thread::get_id() << '\n'; });
   // t1.join();  // t1이 끝날때까지 기다린다. -> 유저 1명씩 접속하는데 사용?!
    */

   /* auto work_func = [](const string& name)
    {
        for (int i = 0; i < 5; i++)
        {
            this_thread::sleep_for(chrono::milliseconds(100));
            cout << name << this_thread::get_id() << " is woring " << i << endl;
        }
    };

    work_func("111");
    work_func("222");*/

    //==============================================================
    
    // try catch - 예외 처리에 사용한다.

    double x;
    cout << "입력 ";
    cin >> x;

    // x를 양수로 입력받고싶은데
    try
    {
        if (x < 0.0) // x가 음수일 경우
            throw string("-숫자 입력"); 
        
        cout << sqrt(x) << endl; // x를 양수로 바꿔준다.
    }
    catch (string errMesage)
    {
        cout << errMesage << endl;
    }
}
