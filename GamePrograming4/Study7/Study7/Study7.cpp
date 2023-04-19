// 라운드 통과하기
// 
// 7    4 2 4
// 1라운드 pass / 2라운드 5 / 3라운드 pass/ 4라운드  pass/ 5라운드 2 / 6라운드 fail
// answer-> 5
// 
//  n = 2, k = 4, / enemy{3,3,3,3} / answer = 4
// 내가 가지고있는 n 과 k(패스권)을 사용해서 최대 라운드가 어디까지 갈 수 있을까?
#include <iostream>
using namespace std;
#include <vector>

int main()
{
    int n = 7; // 내가 막을수 있는 숫자
    int k = 3; // pass권
    vector<int> enemy{ 4,2,4,5,3,3,1 };


    int n;
    cout << "나의 hp를 입력하세요. ";
    cin >> n;

    int k;
    cout << "pass권의 갯수를 입력하세요. ";
    cin >> k;

    int count;
    cout << "생성할 enemy의 수를 입력하세요. ";
    cin >> count;

    vector<int>enemyArray;
    for (int i = 0; i < count; i++)
    {
        int enemy;
        cout << "enemy[" << i << "]의 atk을 입력하세요.";
        cin >> enemy;
        enemyArray.push_back(enemy);
    }


    int answer = 0;
    for (int i = 0; i < enemy.size(); i++)
    {
        if (n > 0 && n>enemy[i])
        {
            n -= enemy[i];
            answer++;
        }
        else if(k==0)
        {
            break;
        }
        else
        {
            k--;
            answer++;
        }
    }

    cout << "총 " << answer << "번째 enemy까지 막았습니다." << endl;

}
