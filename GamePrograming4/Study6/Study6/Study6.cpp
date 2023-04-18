#include <iostream>
using namespace std;
#include<queue>
#include <vector>
#include<algorithm>

// 이진트리
// 노드의 총 개수 = 2^n -1 ,간선의 개수 = 노드-1
// 자식의 위치 왼쪽 i*2+1 , 오른쪽 i*2+2
// 부모의 위치는 i-1/2

// 우선순위 queue는 최대값을 구하기 좋음!!!!
template<typename T>
class Priority_queue
{
public:
    void push(const T& value)
    {
        _heap.push_back(value); // 1. 갑을 넣는다.
        int now = static_cast<int>(_heap.size()) - 1; // 지금 추가된 노드의 위치

        while (now > 0)
        {
            int next = (now - 1) / 2; // 부모의 위치랑 비교

            if (_heap[now] < _heap[next]) // 부모가 나보다 클 경우 break
                break;
            
            swap(_heap[now], _heap[next]); // 부모가 나보다 작을 경우 값을 바꾼다.
            now = next; // now에  next값 위치 넣어준다.
        }
    }

    void pop()
    {
        _heap[0] = _heap.back(); // 꺼낼때 마지막에 있는 값을 넣어준다.
        _heap.pop_back(); // 그리고 마지막으로간 최대값(0번쨰값)을 빼준다.

        int now = 0;

        while (true)
        {
            int left = 2 * now + 1;
            int right = 2 * now + 2;

            if (left >= _heap.size()) // 트리의 크기보다 크면 break
                break;

            int next = now;

            // 왼쪽 비교
            if (_heap[next] < _heap[left])
                next = left;

            // 둘중 승자를 오른쪽과 비교
            if (right< _heap.size() && _heap[next] < _heap[right]) // 트리의 크기보다 작아야함(조건)
                next = right;
            
            // 더는 이동할 필요 x
            if (next == now)
                break;

            swap(_heap[now], _heap[next]); // now값과 next값을 바꿔준다.

            now = next; //그리고 now에 next의 위치를 넣어준다.
        }
    }

    T& top() { return _heap[0]; }
    bool empty() { return _heap.empty(); }

private:
    vector<T> _heap = {};
};


// 완전이진트리 중에서 힙트리 구현하기..!!!!!
int main()
{
    Priority_queue<int> pq; // 우선순위 큐 
    priority_queue<int, vector<int>, greater<int>> pqq; // 거꾸로 할경우 greater를 사용한다.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2; // 쌍으로 쓸 경우

    pq.push(100);
    pq.push(500);
    pq.push(600);
    pq.push(200);
    pq.push(700);

    while (pq.empty() == false)
    {
        int value = pq.top();
        pq.pop();

        cout << value << endl;
    }
}
