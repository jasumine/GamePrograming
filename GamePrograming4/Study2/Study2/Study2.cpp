#include <iostream>
#include <vector>
using namespace std;
#include <list>

// vector, list, stack, queue, 트리기초 힙, 이진탐색, 정렬 버블 선택 삽입 힙, 병합 퀵, dfs bfs, 동적계획법

// list 구현해보기 
// [노드] <-> [노드] <-> [노드] <-> [] 이중리스트

template<typename T>
class Node
{
public:
	Node() 
	{
	}
	Node(const T& value) : _next(nullptr), _prev(nullptr), _data(value)
	{

	}

public:
	
	Node* _next = nullptr;
	Node* _prev = nullptr;
	T _data;
};

template<typename T>
class Iterator
{
public:
	Iterator()
	{

	}
	Iterator(Node<T>* node) : _node(node)
	{

	}

	// ++it
	Iterator<T>& operator++()
	{
		_node = _node->_next; // +1은 다음주소를 가리킨다.
		return *this;
	}
	
	// it++
	Iterator<T> operator++(int)
	{
		Iterator<T> temp = *this; 
		_node = _node->_next;
		return temp;
	}

	// --it
	Iterator<T>& operator--()
	{
		_node = _node->_prev; // -1은 이전주소를 가리킨다.
		return *this;
	}

	// it--
	Iterator<T> operator--(int)
	{
		Iterator<T> temp = *this;
		_node = _node->_prev;
		return temp;
	}

	T& operator*()
	{
		return _node->_data;
	}

	bool operator==(const Iterator& it)
	{
		return _node == it._node;
	}

	bool operator!=(const Iterator& it)
	{
		return _node != it._node;
	}
public:
	Node<T>* _node = nullptr;
};


template<class T>
class List
{
public:
	List()
	{
		// 처음 생성시 header는 자기 자신을 가르킨다.
		_header = new Node<T>();
		_header->_next = _header;
		_header->_prev = _header;
	}

	// 이후 추가되는 값들은 AddNode 함수로 가게된다.
	void push_back(const T& value)
	{
		AddNode(_header, value);
	}

	void pop_back()
	{
		RemoveNode(_header->_prev); // 
	}


	// [1] <-> [2] <-> [prev] <-> [before]
	// [1] <-> [2] <-> [prev] <-> [node] <-> [before] <-> [header] header 는 계속 뒤에 머물러있다......
	Node<T>* AddNode(Node<T>* before, const T& value) // _header == before
	{
		Node<T>* node = new Node<T>(value); // node에 새로운 value값을 넣어주고
		Node<T>* prevNode = before->_prev; // node의 왼쪽에있는 prevNode는 before->_prev가 가르키고있는 녀석이다.

		// [prev] < ->[node]
		prevNode->_next = node; // prevNode의 next는 node를 가르키고
		node->_prev = prevNode; // node의 prev는 prevNode를 가르킨다.

		// [node] <-> [before]
		node->_next = before; // node의 next는 before를 가르키고
		before->_prev = node; // before의 prev는 node를 가르킨다.

		_size++; // node가 추가되서 size+1

		return node;
	}

	// [1] <-> [2] <-> [prev] <-> [node] <-> [before] <-> [header] 
	// [1] <-> [2] <-> [prev] <-> [next] <-> [header]
	Node<T>* RemoveNode(Node<T>* node)
	{
		// [prev] < ->[node] < ->[before]
		Node<T>* prevNode = node->_prev; // prevNode는 node의 prev가 가르키고 있던 녀석
		Node<T>* nextNode = node->_next; // nextNode는 node의 next가 가르키고 있던 녀석

		// [prev] < ->[next]
		prevNode->_next = nextNode; // prevNode의 next는 nextNode 가르키고
		nextNode->_prev = prevNode; // nextNode는 prevNode를 가르킨다.

		delete node; // 기존에 있던 node는 지우고

		_size--; // node가 지워져서 -1

		return nextNode;
	}

	int size() { return _size; }




public:
	typedef Iterator<T> iterator;
	iterator begin() { return _header->_next; } // 나의 바로 다음.
	iterator end() { return _header; } // 마지막 나 자신.?!
	iterator insert(iterator it, const T& value)
	{
		Node<T>* node = AddNode(it._node, value);
		return iterator(node);
	}
	iterator erase(iterator it)
	{
		Node<T>* node = RemoveNode(it._node);
		return iterator(node);
	}


public:
	Node<T>* _header;
	int _size = 0;

};


int main()
{
	List<int> li;
	List<int>::iterator eraseIt;

	for (int i = 0; i < 10; i++)
	{
		if (i == 5)
		{
			eraseIt = li.insert(li.end(), i);  // i가 5일경우, end(5번쨰) 에 i(5)를 삽입 / eraseIt은 5가 들어간 주소를 가르킨다.
		}
		else
		{
			li.push_back(i);
		}
	}

	li.pop_back(); // 제일 마지막에 있는걸 꺼내는것 -> 9
	li.erase(eraseIt); // -> eraseIt을 지운다.

	for (auto it = li.begin(); it != li.end(); ++it)
	{
		cout << *it << endl;
	}

}

