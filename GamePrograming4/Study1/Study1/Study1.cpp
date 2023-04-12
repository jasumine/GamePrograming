#include <iostream>
using namespace std;
#include <vector>

/*
BIG-O표기법(빅오표기법)
빠름								느림
1 > log n > n > n log n > n^2 > 2^n 
				-마지노선-

for문		 n
2중 for문	 n^2  -> 실제로는 쓰지 않는다.


배열 - 사용할 메모리를 고정으로 두고 연속된 방을 배정받아 사용
동적 배열 - 사용할 메모리를 유동적으로 쓰고, 연속된 방을 배정받아 사용 / 실제  사용 메모리 x 1.5 , c#은 2배 / push_front가 없음.
리스트 - 연속되지않고, 서로가 서로를 연결한다. 중간 삽입,삭제가 빠르지만 임의접근이 불가능하다.

*/

// vector 구현해보기!
template<class T>
class Iterator
{
public:
	Iterator() : _ptr(nullptr)
	{

	}
	Iterator(T* ptr) : _ptr(ptr)
	{

	}

	Iterator& operator++()
	{
		_ptr++;
		return *this;
	}

	Iterator operator++(int)
	{
		Iterator temp = *this;
		_ptr++;
		return temp;
	}

	Iterator operator+(int count)
	{
		Iterator temp = *this;
		temp._ptr += count; // 값만 증가
		return temp; // 주소는 같고
	}

	Iterator operator-(int count)
	{
		Iterator temp = *this;
		temp._ptr -= count; // 값만 증가
		return temp; // 주소는 같고
	}

	Iterator& operator--()
	{
		_ptr--;
		return *this;
	}

	Iterator operator--(int)
	{
		Iterator temp = *this;
		_ptr--;
		return temp;
	}

	bool operator==(const Iterator& right)
	{
		return _ptr == right.ptr;
	}

	bool operator!=(const Iterator& right)
	{
		return _ptr != right._ptr;
	}

	T& operator*()
	{
		return *_ptr; //값을 넘긴다.
	}

public:
	T* _ptr;
};


template<class T>
class Vector
{

public:
	Vector()
	{

	}
	~Vector()
	{
		// 데이터가 존재할 경우 삭제.
		if (_data)
			delete[] _data;
	}

	void push_back(const T& value)
	{
		if (_size == _capacity) // 같다면, 공간이 없다는 뜻.
		{
			// 새로운 용량을 1.5배 해주어서 reserve해준다.
			int newCapacity = static_cast<int>(_capacity * 1.5);
			if (newCapacity == _capacity) // capacity가 0이거나 1 이면 값이 증가가 안되서, 예외처리를 해준다.
				newCapacity++;
			// 새롭게 증설 작업을 하고 넣어주기.
			reserve(newCapacity);
		}
		_data[_size] = value; // [1] [2] [3] [4] 뒤에서 추가되서, 그냥 추가한다.
		_size++; // 사이즈를 증가시켜준다.
	}

	void clear()
	{
		if (_data) // 데이터가 있다면
		{
			delete[] _data; // 지우고
			_data = new T[_capacity]; // 새로운 배열을 할당해준다.
		}
		_size = 0;
	}

	T& operator[] (int pos)
	{
		return _data[pos];
	}

	void reserve(int capacity)
	{
		if (_capacity >= capacity) // 예외처리, 크다면 굳이 늘리지않아도 된다.
			return;
		_capacity = capacity;

		T* newData = new T[capacity]; // 새로 할당함

		for (int i = 0; i < _size; i++) // 새로 할당받은 곳에 데이터를 다 옮겨준다.
		{
			newData[i] = _data[i];
		}

		if (_data) // 할당을 해줬으니, 원래있던 데이터를 지워준다.
			delete[] _data;

		_data = newData; // 새로운 주소값 가리키기.
	}

	int size() { return _size; }
	int capacity() { return _capacity; }

public:
	typedef Iterator<T> iterator;
	iterator begin() { return iterator(&_data[0]); } // 0번째의 주소를 넘겨준다.
	iterator end() { return begin() + _size; } // iteraotr(&_data[_size]);
private:
	T* _data = nullptr;
	int _size = 0;
	int _capacity = 0;

};




int main()
{
	Vector<int>v; // vector가 아닌 내가만든 Vector를 넣어도 구현이 되도록!

	// v.resize(10); // 미리 할당한다.(채워져잇음)
	cout << v.size() << " " << v.capacity() << endl;

	v.reserve(150); // 사이즈를 늘려준다.
	cout << v.size() << " " << v.capacity() << endl;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		cout << v[i] << " " << v.size()<< " " << v.capacity() << endl;
	}
	v.clear();
	cout << v.size() << " " << v.capacity() << endl;

	for (Vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << (*it) << endl;
	}
}
