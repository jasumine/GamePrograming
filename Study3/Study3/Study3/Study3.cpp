#include <iostream>
#include <bitset>
#include <iomanip>

using namespace std;

int main()
{
    // =============bit연산==============
    /*unsigned int a = 2;

    cout << bitset<8>(a << 1) << " " << (a << 1) << endl;
    cout << bitset<8>(a << 2) << " " << (a << 2) << endl;
    cout << bitset<8>(a << 3) << " " << (a << 3) << endl;
    cout << bitset<8>(a << 4) << " " << (a << 4) << endl;
    */

    const unsigned char op0 = 1 << 0;
    const unsigned char op1 = 1 << 1;
    const unsigned char op2 = 1 << 2;
    const unsigned char op3 = 1 << 3;

    cout << bitset<8>(op0) << endl;
    cout << bitset<8>(op1) << endl;
    cout << bitset<8>(op2) << endl;
    cout << bitset<8>(op3) << endl;


    unsigned char items_flag = 0; // 0000 0000
    cout << "no items" << bitset<8>(items_flag) << endl;


    // ===========아이템을 획득했는지 용도로 쓸 수있다.=========
    // https://hannom.tistory.com/78 참고하기
    items_flag |= op3; // 0000 0000 |= 0000 1000
    cout << "item3 get" << bitset<8>(items_flag) << endl;

    items_flag |= op0; // 0000 1000 |= 0000 0001
    cout << "item0 get" << bitset<8>(items_flag) << endl;

    items_flag &= ~op3; // 0000 1001 ~0000 1000
    //            1111 0111
    // 0000 1001 &= 1111 0111
    // 0000 0001

    cout << "item3 lost" << bitset<8>(items_flag) << endl;

    if (items_flag & op0) // 0000 0001 & 0000 0001 == 0000 0001 == 1 true
    {
        cout << "have itme0" << endl;
    }
    else
    {
        cout << "not have item0" << endl;
    }

    /*
   if (100) // 0만 false고 나머지 숫자는 true로 인식한다.
   {
       cout << "!!" << endl;
   }
   else
   {
       cout << "00" << endl;
   }*/

    items_flag |= (op2 | op3); // 0000 0001 |= (0000 1100) 
    // 0000 1101
    cout << "item 2, 3 get" << bitset<8>(items_flag) << endl;

    // op2는 가지고 있고 op1은 없는 상태
    // item2는 날리고 item1을 get하게 할 수있을까?

    if ((items_flag & op2) && !(items_flag & op1))
    {
        items_flag ^= op2;
        // 0000 1101 ^= 0000 0100
        // 0000 1001

        items_flag ^= op1;
        // 0000 1001 ^= 0000 0010
        // 0000 1011

    }

    // ========================rgb비트, 커스터마이징===================================
    cout << "==========================" << endl;
    const unsigned int red_mask = 0xFF0000;
    const unsigned int green_mask = 0x00FF00;
    const unsigned int blue_mask = 0x0000FF;

    cout << bitset<32>(red_mask) << endl;
    cout << bitset<32>(green_mask) << endl;
    cout << bitset<32>(blue_mask) << endl;

    unsigned int pixel_color = 0xDAA520;

    unsigned char blue = pixel_color & blue_mask;
    unsigned char green = (pixel_color & green_mask) >> 8;
    unsigned char red = (pixel_color & red_mask) >> 16;

    cout << "blue " << bitset<8>(blue) << " " << int(blue) << endl;
    cout << "green " << bitset<8>(green) << " " << int(green) << endl;
    cout << "red " << bitset<8>(red) << " " << int(red) << endl;

    //=================================================
    cout << "=====================" << endl;
    char ch = 'a';
    cout << typeid(4.0).name() << endl;
    cout << typeid(ch).name() << endl;

    // 명시적 형변환 (int)123.5 앞에 붙여주는것
    int a = 123.5; // 암시적 형변환
    cout << a << endl; // 123이 나옴. 컴퓨터가 자동으로 바꿔준다.

    float b = 1.0f;
    double c = b; // 사이즈가 작은 거를 큰타입에 넣을때는 문제X

    int i = 30000;
    char d = i;
    cout << d << endl; // 사이즈가 큰 거를 작은타입에 넣을때는 문제 O 

    double e = 0.123456789;
    float f = e;

    cout << f << endl; // 반올림해서 0.123457까지 보여준다 (소수점 6의자리까지)
    cout << setprecision(12) << f << endl;

    int i1 = 7 / -2;
    cout << i1 << endl; // -3

    int i2 = -5 % 2;
    cout << i2 << endl; // -1

    int i3 = (int)4.0; // c
    int i4 = int(4.0); // c++
    int i5 = static_cast<int>(4.0); // 제일 많이 사용

    cout << char(65) << endl; 
    cout << int('A') <<  endl; // 강제성 형변환

    cout << static_cast<char>(65) << endl;
    cout << static_cast<int>('A') << endl; // 컴파일러가 체크한번확인.

    /*
    int c1;
    cin >> c1;
    cout << c1 << " " << endl;
    */

    // ================랜덤 함수===============
    cout << "========================" << endl;

    srand(time(0));

    cout << rand() << endl; // 0 ~ 32768
    cout << rand() << endl;
    cout << rand() << endl;
    cout << rand() << endl;
    cout << rand() << endl;
}

