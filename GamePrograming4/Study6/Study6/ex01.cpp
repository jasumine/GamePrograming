#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

template<typename T>
class Priority_queue
{
public:
	void push(const T& value)
	{
		_heap.push_back(value); // value의 값을 넣고 비교한다.

		int now = static_cast<int>(_heap.size()) - 1; // 현재 node의 위치

		while (now >0) // now가 최대값이 될때까지
		{
			int next = (now - 1) / 2; // 부모의 위치.

			// 예외 설정
			if (_heap[now] < _heap[next]) // now가 next보다 작으면 
				break;

			swap(_heap[now], _heap[next]); // now와 next의 값을 바꾼다.
			now = next; // now에 next의 위치를 넣는다.
		}
	}

	void pop()
	{
		// 마지막값을 0번째에 넣고, pop하고, 다시 위치 비교
		_heap[0] = _heap.back();
		_heap.pop_back();

		int now = 0;

		while (true)
		{
			int left = now * 2 + 1; // 왼쪽 자식의 위치
			int right = now * 2 + 2; // 오른쪽 자식 위치

			// 예외설정
			if (left >= _heap.size())
				break;

			int next = now;

			if (_heap[next] < _heap[left])
				next = left;

			if (right< _heap.size() && _heap[next] < _heap[right])
				next = right;

			if (next == now)
				break;

			swap(_heap[now], _heap[next]);
			now = next;
		}
	}

	bool empty()
	{
		return _heap.empty();
	}

	T& top() { return _heap[0]; }

private:
	vector<T> _heap = {};
};


int main()
{
	Priority_queue<int> pq;

	pq.push(1);
	pq.push(2);
	pq.push(4);
	pq.push(10);
	pq.push(6);

	while (pq.empty() == false)
	{
		int value = pq.top();
		pq.pop();

		cout << value << endl;
	}
}

