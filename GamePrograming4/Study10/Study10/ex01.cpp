#include <iostream>
using namespace std;
#include<vector>
#include<queue>
#include<time.h>

// 1. ��������
// 5 3 8 1 2 7
// 0 1 �� -> 1 2 �� -> 2 3 ��
// ���������� �ǵ���

void BubbleSort(vector<int>& v)
{
    int n = v.size();

    for (int i = 0; i < n - 1; i++) // n��������  �˻��� �ʿ� X
    {
        for (int j = 0; j < n - 1 - i; j++) 
        {
            // ��������° ���� �̹� �������־ ������ �� �ʿ䰡 ���� -i
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
            }
        }
    }
}

// ��������
// ���� �����Ŷ� i��° ��ġ�� �ٲ��ش�.
// 5 3 8 1 2 7
// 1 3 8 5 2 7
// 1 2 8 5 3 7
// 1 2 3 5 8 7

void SelectionSort(vector<int>& v)
{
    int n = v.size();

    for (int i = 0; i < n - 1; i++)
    {
        int bestIdx = i; // i��° �������� �̹� �ּҰ��� ���־ i�� �ʱ�ȭ
        for (int j = i + 1; j < n; j++) // �̹� i�� ���� �˾ұ⶧���� i+1
        {
            if (v[j] < v[bestIdx]) // j�� �� �۴ٸ� ��ü
                bestIdx = j; // ����
        }
        swap(v[i], v[bestIdx]); // i��°�� �ּҰ��� ��ȯ�Ѵ�.
    }
}

// 5 3 8 1 2 7
// 5(ù��°)        3 8 1 2 7
// 5 3             8 1 2 7
// 3 5             8 1 2 7
// 3 5 8           1 2 7
// 1 3 5 8         2 7
// ���� vector�� ù��°�� ���ο� vector�� �������鼭
// ���ο� vector�� ������ ������ ���Ӱ� ����
// ->�ϳ��� ���;ȿ��� �տ����ڸ� ���ϰ� �����ϱ�

void InsertSort(vector<int>& v)
{
    int n = v.size();
    for (int i = 1; i < n; i++) // 0��°�� ���� ����̾�� 1���� ����
    {
        int insertData = v[i]; // i���� ���ڰ� �������Ŀ� ���ԵǾ��ؼ� ���� ����

        int j;
        for (j = i - 1; j >= 0; j--) // i�� ���� �̹� insertData�� �־ i-1����
        {
            if (v[j] > insertData) // j�� ���� insert���� Ŭ���
                v[j + 1] = v[j]; // j+1�� j�� ���� �� �ڷ� ������
            // 3 5 8 1 �� ��� 3 5 8 8 �� ��
            else
                break;
        }

        v[j + 1] = insertData; //  break, Ȥ�� 0���� ������� �ش��ڸ��� ����
        // 1 3 3 5 8 �̶�� 1 2 3 5 8 �̵�!
    }
}

// �� ����
void HeapSort(vector<int>& v)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int num : v)
        pq.push(num);

    v.clear();

    while (pq.empty() == false)
    {
        v.push_back(pq.top());
        pq.pop();
    }

    // �켱����ť�� �̿��ؼ� v�� ���� top, pop���� push
}


int main()
{
    clock_t start, end;
    start = clock();

    vector<int> v{5,3,8,1,2,7};
   /* vector<int> v;
    for (int i = 0; i < 100000; i++)
    {
        int randValue = rand() % 10000;
        v.push_back(randValue);
    }*/

    BubbleSort(v);
    //SelectionSort(v);
    //insertSort(v);
    //HeapSort(v);

    cout << endl;
    end = clock();
    double result = (double)(end - start);
    cout << result << endl;


}
