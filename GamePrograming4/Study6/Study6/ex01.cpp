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
		_heap.push_back(value); // value�� ���� �ְ� ���Ѵ�.

		int now = static_cast<int>(_heap.size()) - 1; // ���� node�� ��ġ

		while (now >0) // now�� �ִ밪�� �ɶ�����
		{
			int next = (now - 1) / 2; // �θ��� ��ġ.

			// ���� ����
			if (_heap[now] < _heap[next]) // now�� next���� ������ 
				break;

			swap(_heap[now], _heap[next]); // now�� next�� ���� �ٲ۴�.
			now = next; // now�� next�� ��ġ�� �ִ´�.
		}
	}

	void pop()
	{
		// ���������� 0��°�� �ְ�, pop�ϰ�, �ٽ� ��ġ ��
		_heap[0] = _heap.back();
		_heap.pop_back();

		int now = 0;

		while (true)
		{
			int left = now * 2 + 1; // ���� �ڽ��� ��ġ
			int right = now * 2 + 2; // ������ �ڽ� ��ġ

			// ���ܼ���
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

