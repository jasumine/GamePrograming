#include <iostream>
using namespace std;
#include <vector>

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
		Node* newNode = new Node();
		newNode->key = key;
		
		if (_root == nullptr)
		{
			_root = newNode;
			return;
		}

		Node* node = _root;
		Node* parent = nullptr;

		while (node) // rode가 있다면
		{
			parent = node; // 부모에 rode값
			if (key < node->key) // key가 root보다 작다면
				node = node->left; // node에는 node의 왼쪽값
			else // key가 root보다 크거나 같다면
				node = node->right; // node에는 node의 오른쪽을 넣는다.

			// 왼쪽이나 오른쪽이 비어있다면 while문을 나오게 된다.
		}
		
		newNode->parent = parent; // while을 돌면서 parent값을 구하고
		
		// while문을 돌면서 비워져있던 곳을 채움
		if (key < parent->key) // key가 부모보다 작으면
			parent->left = newNode; // 부모의 왼족값에 넣고
		else // 부모보다 크거나 같다면
			parent->right = newNode; // 부모의 오른쪽값에 넣는다.
	}

	Node* Search(Node* node, int key)
	{
		if (node == nullptr || key == node->key) // 비어있거나 key값이 같다면
			return node; // node를 반환

		if (key < node->key) // key 값이 node보다 작다면
			return Search(node->left, key); // node의 왼쪽트리로 가서 key를 찾는다.
		else // 반대일 경우 오른족으로 간다.
			return Search(node->right, key);
	}

	Node* Min(Node* node) // 최소값은 왼쪽으로
	{
		while (node->left)
			node = node->left;

		return node;
	}

	Node* Max(Node* node) // 최대값은 오른쪽으로
	{
		while (node->right)
			node = node->right;

		return node;
	}

	Node* Next(Node* node) // 나보다 다음으로 큰 값
	{
		// node가 왼쪽 자식일 경우 -> 나의 오른쪽값이 next
		if (node->right) // node에 오른쪽 값이 있다면 -> 없다면 부모 값이 return
			return Min(node->right); // 오른쪽 트리에서 최소값이 나의 다음값

		// node가 오른쪽 자식일 경우 -> 부모의 부모값이 나의 next값
		Node* parent = node->parent;

		while (parent && node == parent->right) // 부모가 존재하고, 내가 부모의 오른쪽 자식일 경우
		{
			node = parent; // node에 부모를 넣고
			parent = parent->parent; // 부모에는 부모의 부모를 넣는다.
		}

		return parent; // 나보다 부모값이 크다.
	}

	void Delete(Node* node)
	{
		if (node == nullptr) //비어있으면 return
			return;

		if (node->left == nullptr) // 노드의 왼쪽자식이 비어있다면
			Replace(node, node->right); // node에 오른쪽 값을 넣고, node는 지워진다.
		else if (node->right == nullptr) // 노드의 오른쪽 자식이 비어있다면
			Replace(node, node->left); // 노드에 왼쪽값을 넣고, node는 지워진다.

		else // 자식이 둘다있는 경우-> 왼쪽에서 큰값 or 오른쪽에서 작은값을 가져온다 == next
		{
			Node* next = Next(node); // node의 next값을 구해서
			node->key = next->key; // next의 key값을 node로 옮기고
			Delete(next); // next는 지운다.
		}
	}

	void Replace(Node* u, Node* v) // u에 v를 넣는다.
	{
		if (u->parent == nullptr) // u의 부모가 없다면  root여서
			_root = v; // root에 v를 넣어준다.
		else if (u == v->parent->left) // u가 v의 부모의 왼쪽값, 즉 u가 v의 형제라면
			u->parent->left = v; // u자리에 v를 넣어준다
		else // u가 v의 오른쪽값, u가 v의 형제라면
			u->parent->right = v; // u자리에 v를 넣어준다


		if (v) // v가 있다면
			v->parent = u->parent; // u의 parent를 v의 parent에 넣어주면서 u를 없애준다.

	}

	void Print()
	{
		Print(_root);
	}

	void Print(Node* node)
	{
		if (node == nullptr) // 비어있다면 return
			return;

		//비어있지 않다면 재귀함수로 출력
		cout << node->key << endl;
		Print(node->left); // 작은값
		Print(node->right); // 큰값
	}

private:
	Node* _root = nullptr;
};


int main()
{
	BinarySearchTree bst;
	bst.Insert(10);
	bst.Insert(20);
	bst.Insert(40);
	bst.Insert(50);

	bst.Insert(30);
	bst.Insert(40);
	bst.Insert(50);


	bst.Print();
}