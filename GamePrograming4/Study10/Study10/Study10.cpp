#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <time.h>
#include <queue>
// sorting 정렬  sort 종류, 유형
// 정렬       버블 선택 삽입 힙 병합 퀵

// 버블 정렬  오름차순 or 내림차순
//  5 3 8 1 2 7     5 vs 3
//  3 5 8 1 2 7     5 vs 8
//  3 5 8 1 2 7     8 vs 1
//  3 5 1 8 2 7     8 vs 2
//  3 5 1 2 8 7     8 vs 7
//  3 5 1 2 7   8<< 1짱 3vs 5
//  3 5 1 2 7   5 vs 1
//  3 1 5 2 7   5 vs 2
//  3 1 2 5 7   7<< 2짱!
//  1 2 3 5 7 8 <- 최종
void Bubblesort(vector<int>& v)  // 2중포문 -> n^2 
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] > v[i + 1])
        {
            for (int j = 0; j < v.size() - 1; j++)
            {
                if (v[j] > v[j + 1])
                    swap(v[j], v[j + 1]);
            }
        }
    }

    for (auto a : v)
        cout << a << " ";
}


void BubbleSort(vector<int>& v)
{
    int n = v.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
            }
        }
    }
    for (auto a : v)
        cout << a << " ";
}

// 선택정렬

// 5 3 8 1 2 7
// 1(제외)       5 3 8 2 7
// 1 2 (제외)    5 3 8 7
// 1 2 3(제외)   5 8 7
// 1 2 3 5(제외) 8 7
// 1 2 3 5 7 8

// 제일 작은거랑 i번째 위치를 바꿔준다.
// 1 3 8 5 2 7
// 1 2 8 5 3 7
// 1 2 3 5 8 7

void SelectionSort(vector<int>& v) // 2중 for문 -> n^2 , 버블보다는 조금 더 빠르다.
{
    int size = v.size();

    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (v[i] > v[j])
                swap(v[i], v[j]);
        }
    }

    for (auto a : v)
        cout << a << " ";
}

void selectionSort(vector<int>& v)
{
    int n = v.size();

    for (int i = 0; i < n - 1; i++)
    {
        int bestIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < v[bestIdx])
                bestIdx = j;
        }
        swap(v[i], v[bestIdx]);
    }
}


// 삽입 정렬
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
    int size = v.size();

    for (int i = 0; i < size; i++)
    {
        int min = v[0];
        if (min > v[i])
        {
            v[0] = v[i];
        }

    }

    for (auto a : v)
        cout << a << " ";

}

void insertSort(vector<int>& v) // n^2, 만약 숫자가 순서대로 들어온다면 n의 속도를 냄 **최선의 케이스**
{
    int n = v.size();
    for (int i = 1; i < n; i++)
    {
        int insertData = v[i];

        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if (v[j] > insertData)
                v[j + 1] = v[j];
            else
                break;
        }

        v[j + 1] = insertData;
    }

    for (auto a : v)
        cout << a << " ";
}

void HeapSort(vector<int>& v) // logN *2N , for문을 한번 돌아서
{

    priority_queue<int, vector<int>, greater<int>> pq; // logN;

    for (int num : v)
        pq.push(num);

    v.clear();

    while (pq.empty() == false)
    {
        v.push_back(pq.top());
        pq.pop();
    }
}


int main()
{
    clock_t start, end;
    start = clock();

    //vector<int> v{5,3,8,1,2,7};
    vector<int> v;
    for (int i = 0; i < 100000; i++)
    {
        int randValue = rand() % 10000;
        v.push_back(randValue);
    }

    //BubbleSort(v);
    //SelectionSort(v);
    //insertSort(v);
    HeapSort(v);

    cout << endl;
    end = clock();
    double result = (double)(end - start);
    cout << result << endl;


    // 버블 최선 평균 최악   n^2
    // 선택                 n^2
    // 삽입                 n^2   최선의 케이스 n
    // 힙정렬 Nlogn
}

