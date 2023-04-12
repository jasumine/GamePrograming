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

	// ������ ptr�� ���� ���������ְ�, this�� ���� return
	Iterator& operator++()
	{
		_ptr++;
		return *this;
	}

	// ������ temp�� this�� ���� �ְ�, ���� ���������� �Ŀ� temp�� return;
	Iterator operator++(int)
	{
		Iterator temp = *this;
		this._ptr++;
		return temp;
	}

	// +�� �ּҴ� ����, ���� �����ؼ�, ������ ���������� �ּҸ� temp�� �ְ�, ���� ���������� �� return temp;
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
	
	// ������ �ٸ����� ���⶧���� ���� ������ �޾ƿ;��Ѵ� const Iterator&
	bool operator==(const Iterator& right)
	{
		return _ptr == right._ptr;
	}

	bool operator!=(const Iterator& right)
	{
		return _ptr != right._ptr;
	}

	// �ּ��� ���� �Ѱܾ��ؼ� T&
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
		// 1. ũ�� �Ҵ�
		if (_size == _capacity) // ���ٸ�, ũ�⸦ �÷��ش�.
		{
			int newCapacity = static_cast<int>(_capacity * 1.5); // 1.5�� �� ����.
			if (newCapacity == _capacity) // _capacity�� 0, 1 �� ��� ������ ������
				newCapacity++; // ũ�⸦ �÷��ش�.
			reserve(newCapacity); // reserve���ش�.
		}
		// 2. �� �Է�
		_data[_size] = value;
		_size++;
	}

	void reserve(int capacity)
	{
		if (_capacity >= capacity) // ũ�ٸ� return
			return;

		_capacity = capacity;		// ũ�⸦ �÷��ش�.

		T* temp = new T[_capacity];		// ���ο� �����͸� ����

		for (int i = 0; i < _size; i++)	// ������ ���� �ű��,
		{
			temp[i] = _data[i];
		}
		
		if (_data) 	delete[] _data; // ���� �����͸� ���� ��
		
		_data = temp; // ���ο� �������� �ּҸ� ����Ų��.
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
	// Iterator<T>�� iterator�� ����
	typedef Iterator<T> iterator;
	iterator begin() { return iterator(&_data[0]); }
	iterator end() { return begin() + _size; }
	// begin �Լ��� 0��° ���� �Ѱܾ��ؼ�, _data[0]�� �ּҰ�. &_data[0]
	// end �Լ��� ������ ���̱⶧���� begin�� size�� ���ϸ� �� ���� ���´�.

private:
	T* _data;
	int _size = 0;
	int _capacity = 0;

};

int main()
{
	Vector<int>v; // vector�� �ƴ� �������� Vector�� �־ ������ �ǵ���!

	// v.resize(10); // �̸� �Ҵ��Ѵ�.(ä��������)
	cout << v.size() << " " << v.capacity() << endl;

	v.reserve(150); // ����� �÷��ش�.
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