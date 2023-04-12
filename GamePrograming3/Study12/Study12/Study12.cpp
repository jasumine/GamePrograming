#include <iostream>
#include <list>
#include <deque>
#include <map>
using namespace std;

// vector list deque map <- 넷 다 include 해주어야함.
// vector , map을 자주 사용 왕왕왕중요

// list는 node를 가지고 있음.
// [10] [] [] [] [] [15] [] [] [] [20]
// 10이 15의 주소를 가지고 있음.... 그래서 임의 접근이 불가능함.
// 15는 20의 주소를 가지고 있고, 접근을 할 수 있따. 바로 다음 주소를 가르킨다.
// 벡터랑 다르게 밀어주는게 아니여서 추가 삽입 삭제가 빠르다.
// [1] ->   [2] - > [3]  -> [4] 단일리스트
// [1] <-> [2] <-> [3] <-> [4] 이중리스트. // 1번으로 돌아갈 수 없다.
// [1] <-> [2] <-> [3] <-> [4]  -> [1] 4번(끝)에서 다음으로 이어지는게 1번(처음)이면, 원형리스트.

// [0] <-> [1]  1앞에 0이 새로 추가될 경우 1번의 이전 주소가 0번을 가리키게 된다.
// [2] <-> [5] <-> [3] 2와 3 사이에 5를 추가할 경우, 2의 다음주소가 3에서 5로 변경되고, 3의 이전주소가 2에서 5로 변경된다.
// 추가 삭제가 빠르다!!!!
// 하지만 임의접근이 안되는게 굉장히 큰 단점... vector를 많이 쓰는이유

// ======================================================================

// deque = double ended queue 
// queue FIFO(first in first out) 피포 -  먼저 들어간게 먼저 나온다. 
// stack  LIFO(last in first out) 마지막에 들어온게 먼저 나온다
// deque vector 가끔쓰인다.

// ======================================================================

// map 연관컨테이너 avl tree 균형이진트리를 사용해서 찾는다. serching 을 좀더 빠르게 찾아준다.
// key

class Player
{
public:
	Player(int id) : _id(id)
	{

	}

public:
	int _id;
};

class Node
{
public:
	Node* _prev; // 이전의 주소를 가지고 있으면, 이중리스트
	Node* _next; // 다음의 주소만 가지고 있으면, 단일리스트
	int _data;
};

// deque
// [0 1 2] (앞에 추가)
//	[1 1 2] [    ] [4 5 6] [  ] [ 5 6 7] [ ] [10 11 12]
// 더이상 넣을 공간이 없으면, 다른공간에 넣어버린다. ( 다른공간과 이어줌)
// vector와 비슷한 면이 많다. 처음 끝 삽입삭제  - 빠름. (공간만 할당)
// 2자리에 10을 넣을경우 한칸씩 뒤로 밀리게 되서 -> 중간 삽입삭제 굉장히 느림.

int main()
{
	// map 컨테이너를 사용해서, 한글단어를 저장하고, 영어로 찾는 사전만들기.
	// love 단어를 입력받으면 사랑이 출력되게
	// insert(love ,사랑) << 이런식으로

	map<int, int> m; // key(앞)와 value(뒤)를 쌍으로 가지고 있다.

	// m.insert(1, 500); // 1, 500  첫번째는 500을 가지고 잇따. <- 이렇게 쓰면 오류남
	//m.insert(make_pair(1, 500)); 
	//m.insert(make_pair(2, 200)); // 2번째는 200의 값을 가지고 있다.
	// m.erase(200); // 값만 지운다. 2번째 ( ) 비워져있음.

	// m[1] = 100; // vector 처럼 넣는것도 가능.

	for (int i = 0; i < 100; i++)
	{
		m.insert(pair<int, int>(i, i)); // 쌍으로 넣어준다.
	}
	
	m.insert(make_pair(1, 10)); // 중복삽입한다면? 무시. -> 이미 값이 들어와 있어서!

	// map의 find 함수를 사용하는 방법????
	map<int, int>::iterator findit = m.find(2); // key값으로 찾아야한다! value를 넣으면 안됨.
	if (findit != m.end())
	{
		cout << "find" << endl;
	}
	else
	{
		cout << "no find" << endl;
	}

	for (auto it = m.begin(); it != m.end(); ++it)
	{
		pair<const int, int>& p = *it;
		int key = p.first; // first는 key 값
		int value = p.second; // secone 는 value 값
		cout << key << " " << value << endl;
	}
	cout << "===================================" << endl;

	m[5] = 100; // key 5에 100의 값을 넣는다.
	m.erase(5); // key가 5인 값이 지워진다.
	m.erase(5); // vector는 중복으로 지울경우 오류발생. map은 오류 X
	m.clear(); // key와 value의 값이 지워진다.

	
	//deque<int> dq;
	//dq.push_back(5);
	//dq.push_front(10);
//	dq[5] = 4; // 임의 접근이 가능하다.
//	dq.capacity(); // 추가 될때마다 공간을 할당해서 capacity, reserve 존재하지 않는다.
	// 연속된 메모리가 아니여서 포인터 연산으로 접근 불가능.
	// deque 는 벡터보다 조금 복잡하게 되어있지만 벡터보다는 조금 빠름.

	list<int> li;

//	li[5] = 4; // 임의 접근 불가능.
	li.push_back(5); // 뒤에 넣는다.
	li.size();
	li.push_front(5); // vector(성능저하되서 막아둠.)랑 다르게 앞에서 넣을 수 있음.
//	li.capacity();  존재하지 않는다.
	li.push_front(10); // 10 5 5

	int first = li.front();
	int last = li.back();

	list<int>::iterator liBegin = li.begin();
	auto liEnd = li.end();

	for (auto it = li.begin(); it != li.end(); it++)
	{
		cout << *it << endl; // 10 5 5
	}

	li.insert(liBegin, 100);
	li.erase(li.begin());
	
	li.pop_front(); // 앞에 있는걸 지운다는 뜻?!

	li.remove(5); // 벡터랑 다르게 생김.
	// remove할 경우 같은것을 모두 지운다는 뜻 
	
}

