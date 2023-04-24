#include <iostream>
using namespace std;
#include<vector>
#include<queue>
#include<time.h>

// 1. 버블정렬
// 5 3 8 1 2 7
// 0 1 비교 -> 1 2 비교 -> 2 3 비교
// 오름차순이 되도록

void BubbleSort(vector<int>& v)
{
    int n = v.size();

    for (int i = 0; i < n - 1; i++) // n까지가서  검사할 필요 X
    {
        for (int j = 0; j < n - 1 - i; j++) 
        {
            // 마지막번째 값은 이미 정해져있어서 끝까지 갈 필요가 없어 -i
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
            }
        }
    }
}

// 선택정렬
// 제일 작은거랑 i번째 위치를 바꿔준다.
// 5 3 8 1 2 7
// 1 3 8 5 2 7
// 1 2 8 5 3 7
// 1 2 3 5 8 7

void SelectionSort(vector<int>& v)
{
    int n = v.size();

    for (int i = 0; i < n - 1; i++)
    {
        int bestIdx = i; // i번째 이전에는 이미 최소값이 들어가있어서 i로 초기화
        for (int j = i + 1; j < n; j++) // 이미 i가 뭔지 알았기때문에 i+1
        {
            if (v[j] < v[bestIdx]) // j가 더 작다면 교체
                bestIdx = j; // 대입
        }
        swap(v[i], v[bestIdx]); // i번째와 최소값을 교환한다.
    }
}

// 5 3 8 1 2 7
// 5(첫번째)        3 8 1 2 7
// 5 3             8 1 2 7
// 3 5             8 1 2 7
// 3 5 8           1 2 7
// 1 3 5 8         2 7
// 기존 vector의 첫번째를 새로운 vector에 가져오면서
// 새로운 vector에 가져올 때마다 새롭게 정렬
// ->하나의 벡터안에서 앞에숫자만 비교하고 정렬하기

void InsertSort(vector<int>& v)
{
    int n = v.size();
    for (int i = 1; i < n; i++) // 0번째는 비교할 대상이없어서 1부터 시작
    {
        int insertData = v[i]; // i번재 숫자가 왼쪽정렬에 삽입되야해서 따로 구분

        int j;
        for (j = i - 1; j >= 0; j--) // i의 값은 이미 insertData에 있어서 i-1부터
        {
            if (v[j] > insertData) // j의 값이 insert보다 클경우
                v[j + 1] = v[j]; // j+1에 j를 복사 즉 뒤로 보낸다
            // 3 5 8 1 의 경우 3 5 8 8 이 됨
            else
                break;
        }

        v[j + 1] = insertData; //  break, 혹은 0까지 갔을경우 해당자리에 삽입
        // 1 3 3 5 8 이라면 1 2 3 5 8 이됨!
    }
}

// 힙 정렬
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

    // 우선순위큐를 이용해서 v를 비우고 top, pop으로 push
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
