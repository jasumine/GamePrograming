#include <iostream>
using namespace std;
#include <vector>
#include <queue>

int main()
{
    int n = 2; // ���� ������ �ִ� ����
    int k = 4; // pass��
    vector<int> enemy{ 4,2,4,5,3,3,1 };
    int answer = 0;

    for (int i = 0; i < enemy.size(); i++)
    {
        if (k == 0 && n<enemy[i]) // pass���� 0�̰�, n���� enemy�� �� ū��� break;
        {
            break;
        }
        // pass�� ��ߵǴ� ���
        else if ( k>0 && n < enemy[i])// �н����� �ְ�, n���� enemy�� ū ���
        {
            k--;
            answer++;
        }
        else if(n >0 && n>=enemy[i]) // pass�� �Ⱦ��� ���
        {
            n -= enemy[i];
            if (n >= 0)
                answer++;
        }
        else if (k > 0 ) // ���� pass���� �����ִٸ�
        {
            k--;
            answer++;
        }
    }

    cout << answer << endl;
}