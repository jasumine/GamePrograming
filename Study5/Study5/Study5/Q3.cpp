// 사용자로부터 10진수 숫자를 받으면 2진수로 출력하기 bitset X
// ex) 14 -> 1110
#include <iostream>

using namespace std;

int bitset(int number)
{
    int i = 0;
    int share[10];
    int remain[10];

    for (int i = 1; i < 10; i++)
    {
        share[0] = number / 2; // number이 10일 경우 share[0] 은 5
        remain[0] = number % 2;

        share[i] = share[i - 1] / 2; // share
        remain[i] = share[i - 1] % 2;
    }


}


int main()
{
    int bit = 0;
    int numbers;
    cin >> numbers;

    int i = 0;
    int share[10];
    float remain[10];

    share[0] = numbers / 2;

    // numbers/2 의 초기 값 
    while (share[i] / 2 != 0 || share[i] / 2 != 1) // 몫이 1이나 0이 아닌동안 실행한다.
    {
        share[i] = share[i] / 2;
        remain[i] = share[i] % 2;
        i++;
    }




    for (int j = 0; j < 10; j++)
    {
        int sum[10];
        sum[j] = (int)remain[j] * 2 ^ j;
        bit += sum[j];
    }


}
