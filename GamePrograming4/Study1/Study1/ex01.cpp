#include <iostream>
using namespace std;
#include <vector>

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

	// 전위는 ptr의 값을 증가시켜주고, this의 값을 return
	Iterator& operator++()
	{
		_ptr++;
		return *this;
	}

	// 후위는 temp에 this의 값을 넣고, 값을 증가시켜준 후에 temp를 return;
	Iterator operator++(int)
	{
		Iterator temp = *this;
		this._ptr++;
		return temp;
	}

	// +는 주소는 같고, 값만 증가해서, 후위와 마찬가지로 주소를 temp에 넣고, 값만 증가시켜준 후 return temp;
	Iterator operator+(int count)
	{
		Iterator temp = *this;
		this->_ptr += count;
		return temp;
	}

	Iterator& operator--()
	{
		_ptr--;
		return *this;
	}

	Iterator operator--(int)
	{
		Iterator* temp = this;
		this._ptr--;
		return temp;
	}
	
	// 같은지 다른지를 보기때문에 같은 변수를 받아와야한다 const Iterator&
	bool operator==(const Iterator& right)
	{
		return _ptr == right._ptr;
	}

	bool operator!=(const Iterator& right)
	{
		return _ptr != right._ptr;
	}

	// 주소의 값을 넘겨야해서 T&
	T& operator*()
	{
		return	*_ptr;
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
		
	}

	void push_back(const T& value)
	{
		// 1. 크기 할당
		if (_size == _capacity) // 같다면, 크기를 늘려준다.
		{
			int newCapacity = static_cast<int>(_capacity * 1.5); // 1.5배 더 높이.
			if (newCapacity == _capacity) // _capacity가 0, 1 일 경우 같을수 있으니
				newCapacity++; // 크기를 늘려준다.
			reserve(newCapacity); // reserve해준다.
		}
		// 2. 값 입력
		_data[_size] = value;
		_size++;
	}

	void reserve(int capacity)
	{
		if (_capacity >= capacity) // 크다면 return
			return;

		_capacity = capacity;		// 크기를 늘려준다.

		T* temp = new T[_capacity];		// 새로운 데이터를 만들어서

		for (int i = 0; i < _size; i++)	// 데이터 값을 옮기고,
		{
			temp[i] = _data[i];
		}
		
		if (_data) 	delete[] _data; // 기존 데이터를 지운 후
		
		_data = temp; // 새로운 데이터의 주소를 가르킨다.
	}

	void clear()
	{
		if (_data)
		{
			delete[] _data;
			_data = new T[_capacity];
		}
		_size = 0;
	}

	int size() { return _size; }
	int capacity() { return _capacity; }

	T& operator[](int pos)
	{
		return _data[pos];
	}

public:
	// Iterator<T>를 iterator로 정의
	typedef Iterator<T> iterator;
	iterator begin() { return iterator(&_data[0]); }
	iterator end() { return begin() + _size; }
	// begin 함수는 0번째 값을 넘겨야해서, _data[0]의 주소값. &_data[0]
	// end 함수는 마지막 값이기때문에 begin에 size를 더하면 그 값이 나온다.

private:
	T* _data;
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
		cout << v[i] << " " << v.size() << " " << v.capacity() << endl;
	}
	v.clear();
	cout << v.size() << " " << v.capacity() << endl;

	for (Vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << (*it) << endl;
	}
}