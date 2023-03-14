#include <iostream>

using namespace std;

void Func2();

void Func()
{
    cout << "Hello World" << endl;
    Func2(); // 절차 지향
}

void Func2()
{
    cout << "Hello World2" << endl;
}

int value = 20; // 전역 변수

int main()
{
    Func();
    int value = 10; // 지역 변수

    cout << ::value << endl; // ::을 넣으면 전역 변수, 넣지 않을경우 지역 변수를 우선으로 인식
    
    int selection;

    do // 처음 1번 무조건 실행하고, 
    {
        cout << "1. Add" << endl;
        cout << "2. Subtract " << endl;
        cin >> selection;

    } while (selection <= 0 || selection >= 3); // while의 조건을 만족하면 함수를 빠져나간다. 아닐 경우 do를 계속 반복

    for (int i = 0, j = 0; i < 10; i++, j--) // 조건을 두개 넣을 수 있다.
    {
        cout << i << " " << j << " " << endl; 
    }

    for (int i = 0, j = 0; (i + j) < 20; ++i, j += 2)
    {
        cout << i << " " << j << " " << endl;
    }

    int i = 0;
    int j = 0;
    for (; (i + j) < 20; ++i, j += 2)
    {
        cout << i << " " << j << " " << endl;
    }

    cout << " ======================" << endl;

//    const int students = 7;

    int scores[] { 10, 20, 30,50,60,70,100 }; // = 생략가능, 4바이트 x 7 개 = 28바이트.
    const int students = sizeof(scores) / sizeof(int); // 배열의 크기를 int의 크기로 나오면 배열의 개수를 구할 수 있다.

    int sum = 0;
    for (int i = 0; i < students; i++)
    {
        sum += scores[i];
    }

    double avg = static_cast <double> (sum) / students;
    cout << avg << endl;

    const int rows = 3;
    const int columns = 5;

    int array[rows][columns] // c++ 11부터 = 생략이 가능
    {
        {1,2,3,4,5},
        {1,2,3,4,5},
        {1,2,3,4,5}
    };

    // 2차원 1차원배열 = 15개. // 포인터.
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < columns; col++)
        {
            cout << array[row][col] << '\t'; // tab키 입력
        }
        cout << endl;
    }
}

