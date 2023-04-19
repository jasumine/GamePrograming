#include <iostream>
using namespace std;
#include <vector>
#include <queue>

int main()
{
    int n = 2; // 내가 막을수 있는 숫자
    int k = 4; // pass권
    vector<int> enemy{ 4,2,4,5,3,3,1 };
    int answer = 0;

    for (int i = 0; i < enemy.size(); i++)
    {
        if (k == 0 && n<enemy[i]) // pass권이 0이고, n보다 enemy가 더 큰경우 break;
        {
            break;
        }
        // pass를 써야되는 경우
        else if ( k>0 && n < enemy[i])// 패스권이 있고, n보다 enemy가 큰 경우
        {
            k--;
            answer++;
        }
        else if(n >0 && n>=enemy[i]) // pass를 안쓰는 경우
        {
            n -= enemy[i];
            if (n >= 0)
                answer++;
        }
        else if (k > 0 ) // 만약 pass권이 남아있다면
        {
            k--;
            answer++;
        }
    }

    cout << answer << endl;
}