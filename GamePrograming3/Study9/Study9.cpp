//#include <iostream>
//using namespace std;
//#include <vector>
//
//// STL. standard template library 
//// 프로그래밍할 때 필요한 자료구조, 알고리즘을 템플릿으로 제공해주는 라이브러리
//// 
//// container : 데이터를 저장하는 객체.(자료구조 data structure)
//// vector
//
//class Player
//{
//
//};
//
//int main()
//{
//    // 배열. 크기를 지정해줘야된다.
//    // int array1[100];
//
//    /*
//    // 동적 배열.
//    // 크기를 줄였다 커졌다. 할 수 있음.
//
//    vector<int> v; // 얼마나 처음에 메모리를 차지하고있고, 그다음 증설은 얼마나 또 차지할까.
//    //v.push_back(1); // 값을 넣어준다.
//    //v.push_back(2);
//    //v.push_back(3);
//
//    // const int size = v.size(); // 동적배열의 크기
//
//    // 크기를 할당해줄때 1.5배씩 늘어난다.
//
////   v.resize(100); // 실제 사이즈를 잡아놓는 녀석. 실제 사이즈를 100 잡아두었다.(100칸이 이미 할당되어져있음.)
//
//    v.reserve(100); // capacity를 100까지 잡아둔다. (용량을 100 미리 잡아둠, int array[100]과 유사)
//
//    for(int i =0; i<100; i++)
//    {
//        // size(데이터 실제 사용 갯수)  , capacity(여유분을 포함한 용량 갯수)
//        v.push_back(5);
//        cout << v.size() <<" " <<v.capacity() << endl;
//    }
//
//    v.clear(); // 싹다 날림. 잡아둔 메모리 공간의 변화 x (안에 내용만 삭제)
//    cout << v.size() << " " << v.capacity() << endl;
//*/
//
//
//    // 반복자 iterator  stl 전부사용가능 map, list, set 등등
//    // 포인터와 굉장히 똑같다.
//
//    vector<int>v(10);
//
//    for (int i = 0; i < v.size(); i++)
//    {
//        v[i] = i;
//    }
//
//// ============ iterator 와 pointer의 사용법 비교(완전 흡사함) ============
//    
//    int* ptr;
//    ptr = &v[0]; // vector[0]의 주소를 넣는다.
//
//    vector<int>::iterator it;
//    it = v.begin(); // vector의 시작점을 넣는다.
//
//    cout << (*ptr) << endl;
//    cout << (*it) << endl;
//
//    ptr++;
//    ++ptr;
//    ptr--;
//    ptr += 2;
//
//    it++;
//    ++it;
//    it--;
//    ptr -= 2;
//
//    vector<int>::iterator Begin = v.begin();
//    vector<int>::iterator End = v.end();
//    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//    {
//        cout << *it << endl;
//    }
//
//    int* ptrB = &v[0];
//    int* ptrE = ptrB + 10;
//    for (int* ptr = ptrB; ptr != ptrE; ptr++)
//    {
//        cout << *ptr << endl;
//    }
//    
//    // 동적 배열의 특정.
//    // [1] [2] [3] [4] [5] ... -> 뒤에 공간을 할당할 경우 새로운 주소로 이동함.
//    // 속도가 느리다. 삽입 속도도 느림
//    // 삭제 속도 느림( 중간에 2를 지울경우 뒤에 있는 3 4 를 다시 앞으로 당겨야함.)
//    // 반전으로 뒤에 삽입속도는 빠름 [6] [7] [8] - push_back
//    // 의도적으로 front_backd은 만들어두지않음 (앞에 넣을경우 뒤에있는걸 늘리면서 속도가 더 느려진다.)
//    v.insert(v.begin() + 2, 5); // 시작주소에서 + 2(3번째에) 5를 추가하겠다. // 일부러 불편하게.
//    v.erase(v.begin() + 2); // 세번째를 지우고
//    v.erase(v.begin() + 2, v.begin() + 6); // 3번째자리를 지우고 6도지우고,,?? // 일부러 어렵게
//
//    v[2] = 10; // 임의 접근이 가능해서 편의성이 높다!
//
//   /* int a = 5;
//    float b = 3.1f;
//    double c = 1.23;
//    Player p = Player();*/
//    
//    // auto를 쓸 경우 자동으로 타입을 맞춰준다. c#의 var
//    // 가독성은 좀 떨어진다... p만 봤을때 무엇인지 한번에 알아보기 힘듬.
//    auto a = 5;
//    auto b = 3.1f;
//    auto c = 1.23;
//    auto p = Player();
//
//    auto f = &p;
//    //auto* t = a; //말도 안되는거까지는 해주지 않는다.
//   
//    int&  reference = a;
//    const int cst = a;
//    
//    // const, & 는 무시한다.  주의!!!!!!!!!!!!!!!
//    // int a의 값을 받아와서 int로 인식해버림
//    auto test1 = reference;
//    auto test2 = cst;
//
//    //// auto를 쓰기 편한 경우
//    //auto Begin = v.begin();
//    //auto End = v.end();
//    //for (auto it = v.begin(); it != v.end(); it++)
//    //{
//    //    cout << *it << endl;
//    //}
//
//    // vector string타입의 벡터를 만들어서 4개의 이름을 입력받고, 사전에서 제일 뒤에 나오는 이름을 출력하세요.
//
//
//}
