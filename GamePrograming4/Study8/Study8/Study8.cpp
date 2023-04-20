#include <iostream>
using namespace std;
#include <vector>
#include "windows.h"

// bst 이진탐색트리 왼쪽을 타고가면 작고 오른쪽을 타고가면 크다

/*업다운 게임
vector<int> numbers;

void BinarySearch(int n)
{
	int left = 0;
	int right = (int)numbers.size() - 1;

	while (left <= right)
	{
		cout << "탐색 범위: " << left << "~" << right << endl;

		int mid = (left + right) / 2; // 중간 값

		if (n < numbers[mid]) // 중간 값 보다 n의 숫자가 더 작음 -> 0~중간값
		{
			cout << n << "<" << numbers[mid] << endl;
			right = mid - 1; // 중간값보다 숫자가 더 작기 때문에 -1
		}
		else if (n > numbers[mid]) // 중간 값 보다 n의 숫자가 더 큼 -> 중간값 ~ 100
		{
			cout << n << ">" << numbers[mid] << endl;
			left = mid + 1; // 중간값 보다 중간값보다 숫자가 더 크기 때문에 +1
		}
		else // 중간값과 같은경우
		{
			cout << "찾음" << endl;
			break;
		}
	}
}

int main()
{
	numbers = vector<int>{ 1,7,10,15,30,37,46,87,91,99 };
	BinarySearch(91);
}
*/

struct Node
{
	Node* parent = nullptr;
	Node* left = nullptr;
	Node* right = nullptr;
	int key = {};
};

class BinarySearchTree
{
public:
	void Insert(int key)
	{
		Node* newNode = new Node(); // 값이 들어오면 새로운 node생성
		newNode->key = key; // node의 값은 key

		if (_root == nullptr) // root가 없으면 
		{
			_root = newNode; // root에 새로운 newNode를 넣어준다.
			return;
		}

		// root가 있다면 node에 root를 넣음
		Node* node = _root;
		Node* parent = nullptr;

		while (node) // root가 있다면
		{
			parent = node; // 우선 부모에 root를 넣어준다.
			if (key < node->key) // 그리고 넣어준 key값보다 node(root)의 값보다 작으면
				node = node->left; // node는 root의 왼쪽에 넣어준다.
			else // 값이 크다면 
				node = node->right; // root의 오른쪽에 넣는다.
		}

		newNode->parent = parent; // 새로운 값의 parent에 while을 돌려서 나온 parent를 넣는다.

		if (key < parent->key) // key값이 부모의 값보다 작으면
			parent->left = newNode; // 부모의 왼쪽에 넣는다
		else // 부모보다 크다면 
			parent->right = newNode; // 부모의 오른쪽에 넣는다.
	}

	void Print()
	{
		Print(_root);
	}
	void Print(Node* node)
	{
		if (node == nullptr) // node가 빌 때까지 재귀함수
			return;
		
		cout << node->key << endl;
		Print(node->left);
		Print(node->right);
	}

	Node* Search(Node* node, int key)
	{
		if (node == nullptr || key == node->key) // 노드가 비어잇거나, key값과 노드의 key값이 같으면
			return node; // node를 return

		if (key < node->key) // key가 node의 값보다 작으면
			return Search(node->left, key); // 왼쪽으로 간다.
		else // key가 node의 값보다 같거나 크다면
			return Search(node->right, key); // 오른쪽으로 간다.
	}

	Node* Min(Node* node)
	{
		while (node->left)
			node = node->left;

		return node;
	}

	Node* Max(Node* node)
	{
		while (node->right)
			node = node->right;

		return node;
	}

	Node* Next(Node* node)
	{
		if (node->right) // node에 오른쪽 값이 있다면
			return Min(node->right); // 오른쪽 값의 최소값을 구해준다. (왼쪽트리일 경우 나의 다음값은 오른쪽 자식의 최소값.)

		// 오른쪽 트리에서 구할 경우
		Node* parent = node->parent; // 부모의 값을 넣고
		
		while (parent && node == parent->right) // 부모가 존재하고, 내가 오른쪽 자식이면
		{
			node = parent; // node에 부모를 넣고
			parent = parent->parent; // parent 는 부모의 부모를 넣는다.
		}
		return parent; // 부모의부모 값이 next가 된다.
	}

	void Delete(Node* node)
	{
		if (node == nullptr) // 비어있으면 return
			return;

		if (node->left == nullptr) // 지우는 값의 왼쪽이 비어있고, 오른쪽 자식만 있다면
			Replace(node, node->right); // node에 오른쪽 값을 넣고, node는 삭제된다.
		else if (node->right == nullptr) // 위와 반대로 왼쪽자식이 있고, 오른쪽 자식이 없다면
			Replace(node, node->left); // node에 왼쪽값을 넣고, node는 삭제된다.

		else // 왼쪽과 오른쪽 자식이 둘다 있는 경우 -> 왼쪽에서 큰값, 오른쪽에서 작은값을 가져와야한다. (next 사용)
		{
			Node* next = Next(node); // next에 node의 next값을 넣는다.
			node->key = next->key; // node의 key에 next의 키를 넣어주고
			Delete(next); // next는 지워버린다!
		}
	}

	void Replace(Node* u, Node* v) // u에 v를 넣는다.
	{
		if (u->parent == nullptr) // u가 root일 경우
			_root = v;  // root에 v를 넣어준다.

		else if (u == v->parent->left) // u가 v의 부모의 왼쪽자식이였다면
			u->parent->left = v; // 부모의 왼쪽값에 v를 넣는다
		else  // u가 v의 부모의 오른쪽 자식이였다면
			u->parent->right = v; // 부모의 오른쪽 값에 v를 넣는다.

		if (v) // v가 있다면
			v->parent = u->parent; // v의 parent는 u의 parent로 변경 / 자식은 v의 밑에 붙어있어서 수정안해줘도됨.
	}

private:
	Node* _root = nullptr;
};

int main()
{
	BinarySearchTree bst;
	bst.Insert(10);
	bst.Insert(20);
	bst.Insert(30);
	bst.Insert(40);
	bst.Insert(50);


	bst.Print();
}

