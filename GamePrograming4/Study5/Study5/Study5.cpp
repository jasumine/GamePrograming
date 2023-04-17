#include <iostream>
#include <queue>
#include<stack>
#include<vector>
#include<string>
#include<list>
using namespace std;

// stack	last in first out // LIFO
// queue	first in firt out // FIFO	queue

// [1]	 [2]	[3]		[4]
// front				rear


// 1. 그냥구현, 2. container 구현

// List를 활용한 queue
template<class T>
class Lqueue
{
public:
	void push(const T& value) // 뒤로 차곡차곡 넣음
	{
		_container.push_back(value);

	}

	void pop() // 앞에 있는걸 뺌
	{
		_container.pop_front();
	}

	T& front()
	{
		return _container.front();
	}

	bool empty() { return _container.empty(); }
	int size() { return _container.size(); }

private:
	list<T> _container;
};

// [] [] [] [] [] [] [] [] << 미리 할당
// front				back/rear
// [] [front] [] [] [] [] [back] 
// vector를 이용한 queue 구현
template<class T>
class Vqueue
{
public:
	Vqueue()
	{
		_container.resize(100); // 미리 할당해줘서 속도를 높인다.
	}

	void push(const T& value)
	{
		if (_size == _container.size()) // 가득찰 경우
		{
			int newSize = max(1, _size * 2); // 0 이면, 1을 반환/ 1이면 2를 반환 -> 0,1방지.
			vector<T> newData;
			newData.resize(newSize); // 새로운 크기를 할당
			for (int i = 0; i < _size; i++)
			{
				int index = (_front + i) % _container.size();
				newData[i] = _container[index];
			}
			
			// [][front][][][][][back] [] [] [] [] []
			// 새로운 vector를 할당해서 front 는 0이 되고, back은 size부터 다시 ++
			_container.swap(newData);
			_front = 0;
			_back = _size; 
		}

		_container[_back] = value;
		_back = (_back + 1) % _container.size(); // container의 size가 넘는것을 막기위해. 100이차면 0으로 돌아옴
		_size++;
	}

	void pop()
	{
		_front = (_front + 1) % _container.size(); // container의 size가 넘는것을 막기위해. 100이차면 0으로 돌아옴
		_size--;
	}

	T& front()
	{
		return _container[_front];
	}

	bool empty() { return _size == 0; }
	int size() { return _size; }

public:
	vector<T> _container;
	int _front = 0;
	int _back = 0;
	int _size = 0;
};


int main()
{
	Vqueue<int> q;

	for (int i = 0; i < 100; i++)
	{
		q.push(i);
	}

	while (q.empty() == false)
	{
		int value = q.front(); // 제일 앞에 있는 값.[0]번째.
		q.pop();
		cout << value << endl;
	}
	
	int size = q.size();
	cout << size << endl;

}

