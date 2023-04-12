// 
//  _   _   _   _   _
// 
// 스크린 크기 5
// 사과를 받는 바구니크기 1
// 사과가 떨어지는 갯수 3개
// 처음 생성된 사과가 1번째 칸에 떨어지면 바구니는 0칸
// 두번째 생성된 사과가 5번째 칸에 떨어이면 바구니는 4칸>
// 3번째 생성된 크기가 3칸이면 <<2칸
// 총 6칸 움직임.
// 
//  _   _   _   _   _
//  _____   _____   _____(2칸바구니)
// 스크린 크기 5
// 바구니 크기 2 (2칸짜리)
// 떨어지는 사과 갯수
// 첫번때 사과가 1칸에 떨어지면 0칸
// 두번째사과가 5칸에 떨어지면 3번>
// 세번째사과가 3칸에 떨어지면 <1칸 
// 총 4칸 움직임
// 
// 바구니가 움직이는 최소칸을 구하기.
// 1. 스크린 크기
// 2. 바구니 크기
// 3. 사과의 갯수
// 4. 떨어지는 위치
// ---입력 받아서---
// 총 n번 움직였습니다 << 출력하기.
// 

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    cout << "스크린의 크기를 입력하세요. \n";
    int map_size;
    cin >> map_size;
    cin.ignore();

    cout << "바구니의 크기를 입력하세요. \n";
    int basket_size;
    cin >> basket_size;
    cin.ignore();

    cout << "떨어질 사과의 갯수를 입력하세요. \n";
    int apple;
    cin >> apple;
    cin.ignore();

    int apple_Count = 0;
    int basket_Position = 1;
    int basket_move = 0;
    int total_move = 0;
    while (apple_Count != apple)
    {
        cout << "사과가 떨어질 위치를 입력하세요.";
        int apple_positon;
        cin >> apple_positon;

        if (basket_size == 1)
        {
            basket_move = ((apple_positon - basket_Position) / basket_size);
            basket_Position = apple_positon;
        }
        else
        {
            if (apple_positon - basket_Position < basket_size)
            {
                basket_move += 0;
                basket_Position = apple_positon;
            }
            else
            {
                basket_move = ((apple_positon - basket_Position) / basket_size);
                basket_Position = apple_positon;
            }
        }
        apple_Count++;

        if (basket_move < 0)
            total_move = -basket_move + total_move;
        else
            total_move = basket_move + total_move;
    }
    cout << "바구니는 총 " << total_move << "움직였습니다. \n";
}

