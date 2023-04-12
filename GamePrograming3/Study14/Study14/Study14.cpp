#include <iostream>
using namespace std;
#include <set>
#include <map>

#include <unordered_map> 
// 정렬되지않았다.  hash. 검색이 엄청 빠른데, 메모리를 엄청 잡아먹는다.(N)

#include <algorithm>

class Player
{

};

// map set multimap multiset 연관컨테이너.
int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    vector<int>v;
    
    for (int i = 0; i < 100; i++)
    {
        int num = rand() % 100;;
        v.push_back(num);
    }

    // #1. 30이란 숫자가 존재하는지, 그게 몇번째인지.
    // #2. 10으로 나눠지는 숫자가 존재하는지.
    // #3. 홀수의 갯수가 몇개인지.
    // #4. 이벡터에 전부 *5를 하기.

   // #1. 30이란 숫자가 존재하는지, 그게 몇번째인지.
    int count1 = 0;
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        if (*it == 30)
        {
            cout << "30은 " << count1 << "번 째에 있습니다. \n";
        }
        count1++;
    }

    int number = 30;
    auto it = v.begin();
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == number)
        {
            it = v.begin() + i; // i를 더해준다.
        }
    }

    auto iffind = find(v.begin(), v.end(), number); // 처음부터 끝까지 number라는 숫자를 찾아준다.

    
    // #2. 10으로 나눠지는 숫자가 존재하는지.
    int count2 = 0;
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        if (*it % 10 == 0)
        {
            cout << "10으로 나누어지는 숫자가 " << count2 << "번째에 존재합니다. \n";
        }
        count2++;
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] % 10 == 0)
        {
            it = v.begin() + i;
        }
    }

    struct Divide
    {
        bool operator()(int n)
        {
            return (n % 12 == 0);
        }
    };
    auto ifFind = find_if(v.begin(), v.end(), Divide()); 


    // #3. 홀수의 갯수가 몇개인지.
    int count3 = 0;
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        if (*it % 2 == 1)
        {
            count3++;
        }
    }
    cout << "홀수의 갯수는 " << count3 << "개 입니다. \n";

    
    int count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] % 2 != 0)
            count++;
    }

    struct Odd
    {
        bool operator() (int n)
        {
            return n % 2 != 0;
        }
    };

    int n = count_if(v.begin(), v.end(), Odd()); // 처음부터 끝까지 odd의 갯수를 반환
    cout << n << endl;

    bool one = all_of(v.begin(), v.end(), Odd()); // 모든 데이터가 홀수입니까?  라는뜻 맞으면 true 아니면 false
    bool two = any_of(v.begin(), v.end(), Odd()); // 홀수인 데이터가 하나라도 있는지? 맞으면 true, 아니면 false
    //none_of(v.begin(), v.end(), return n % 2 != 0); // 모두 홀수가 아닙니까? 맞으면 true, 아니면 false
    // 람다식.. /. ..  배우고 설명해준다고 함! 원래는 된다는듯 하네요
 
    // #4. 이 벡터에 전부 *5를 하기.
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        *it *= 5;
    }

    for (auto it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " ";
    }

    for (int i = 0; i < v.size(); i++)
    {
        v[i] *= 4;
    }

    struct Multi
    {
        bool operator()(int n)
        {
           return n *= 4;
        }
    };

    for_each(v.begin(), v.end(), Multi());
    // 처음부터 끝까지 각각 *4를 해준다.
    
    int a = 10;
    int b = 5;
    int c = max(a, b); // 10이 출력된다.
    cout << c << endl;


    /*
    // map<key, value> set은 key == value
    // 균형이진트리(logN) -> searching이 빠르다.
    // key 값 중복 X 
    set<int> s;

    s.insert(10); // 10 == 10
    s.insert(20);
    s.insert(30);

    s.erase(10);

    set<int>::iterator findIt = s.find(20);

    if (findIt == s.end())
    {
        cout << "not find" << endl;
    }
    else
    {
        cout << "find" << endl;
    }

    for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
    {
        cout << (*it) << endl;
    }

    cout << s.empty() << endl;
    cout << s.size() << endl;
    cout << s.max_size() << endl; // set의 최고크기가 찍힌다.

    // map 딱하나만 중복x
    // multimap 중복이 가능!! key값이 중복이다. #include <map>

    multimap<int, int>mm;

    mm.insert(make_pair(1, 100));
    mm.insert(make_pair(1, 200));
    mm.insert(make_pair(1, 300));
    mm.insert(make_pair(1, 400));
    mm.insert(make_pair(2, 100));
    mm.insert(pair<int,int>(2, 200));
   // mm[1] = 500; multimap은 불가능.

    // int count = mm.erase(1); // 4개 , key값 전부 날라간다.

    cout << mm.size() << endl;
    
    for (auto it = mm.begin(); it != mm.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }


    // set key == value 지만 중복X
    // multiset key == value 지만 중복 O ?!

    multiset<int>ms;

    ms.insert(10);
    ms.insert(10);
    ms.insert(10);

    ms.insert(20);
    ms.insert(20);

    auto findit2 = ms.find(10);
    if (findit2 == ms.end())
    {
        cout << "not find" << endl;
    }
    else
    {
        cout << "find" << endl;
    }

    for (auto it = ms.begin(); it != ms.end(); it++)
    {
        cout << *it << endl;
    }

    // multimap도 똑같다.
    multiset<int>::iterator start, end;
    start = ms.lower_bound(10); // 10의 첫번째
    end = ms.upper_bound(10); // 10의 마지막번째
    
    cout << "========================" << endl;

    // 10 3개만 출력하는 방법
    for (multiset<int>::iterator it = start; it != end; ++it)
    {
        cout << *it << endl;
    }

    // hash
    unordered_map<string, int>hs;
    hs.insert(make_pair("green", 1));
    hs.insert(make_pair("red", 2));
    hs.insert(make_pair("blue", 3));
    hs.insert(make_pair("black", 4));

    cout << hs["green"] << endl;

    for (auto it = hs.begin(); it != hs.end(); ++it)
    {
        cout << it->first << ", " << it->second << endl;
    }
    */
}
