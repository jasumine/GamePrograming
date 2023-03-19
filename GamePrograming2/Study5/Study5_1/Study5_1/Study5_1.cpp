#include <iostream>
using namespace std;

// #1
// 길이가 10인 배열, 10개의 정수 입력받아서, 홀수와 짝수를 나누어 출력하는 프로그램
// 10개의 배열은 main에서 받고, 배열내에 존재하는 홀수만 출력하는 함수,
// 배열내에 짝수만 출력하는 함수를 정의해서 두 함수를 호출

void odd(int numbers[10]) // 홀수
{
    cout << "홀수 : ";
    for (int i = 0; i < 10; i++)
    {
        if (numbers[i] % 2 == 1)
        {
            cout << numbers[i] << ", ";
        }
    }
    cout << endl;
}

void even(int numbers[10]) // 짝수
{
    cout << "짝수 :";
    for (int i = 0; i < 10; i++)
    {
        if (numbers[i] % 2 == 0)
        {
            cout << numbers[i] << ", ";
        }
    }
    cout << endl;
}

// #2
// 길이가 10인 배열을 선언하고, 총 10개의 정수를 입력받는다.
// 단, 입력받은 숫자가 홀수면 배열의 앞부터, 짝수면 뒤에서부터 채워나간다.
// 그리고 배열을 출력하기.

void relocation(int str[10])
{
    int temp[10]{ 0 };
    int front = 0, back = 9;
    for (int i = 0; i < 10; i++)
    {
        if (str[i] % 2 == 1) // 홀수는 앞에서부터
        {
            temp[front] = str[i];
            front++;
        }
        else if (str[i] % 2 == 0) // 짝수는 뒤에서부터
        {
            temp[back] = str[i];
            back--;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        str[i] = temp[i];
    }
}

// #3
// 사용자로부터 10진수 숫자를 받으면 2진수로 출력하기 bitset X
// ex) 14 -> 1110

void binary(int num)
{
    int number[8]{ 0 }; // 8비트여서 8칸짜리 배열을 선언, num을 2로나눈 나머지
    int back = 7; // 숫자를 뒤에서부터 넣기위해 7
    int temp; // num을 2로 나눈 몫

    // 이후에 temp의 값을 계속 나눠주기위해서 처음 temp값을 분리
    number[back] = (num % 2);
    temp = num / 2;
    back--; // 마지막 칸에 값을 넣었으니 -1

    // temp를 계속 나누어준다.
    while (temp > 1)
    {
        number[back] = (temp % 2);
        temp = temp / 2;
        back--;
    }

    // 이미 back이 -1 되어있어서 몫이 1인경우 해당위치에 1을 넣어준다.
    if (temp == 1)
    {
        number[back] = 1;
    }
    
    // 출력
    for (int i = 0; i < 8; i++)
    {
        cout << number[i];
        if (i == 3) cout << " ";
    }
}


int main()
{
   cout << "정수 10개를 입력하세요." << endl;
    int str[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> str[i];
    }

    // #1
    odd(str);
    even(str);
    
    // #2
    relocation(str);
    for (int i = 0; i < 10; i++)
    {
        cout << str[i] << " ";
    }
   
    // #3
    cout << "정수를 1개 입력하세요.";
    int numbers;
    cin >> numbers;
    binary(numbers);
}


