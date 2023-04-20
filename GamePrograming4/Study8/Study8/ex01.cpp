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

		while (node) // rode�� �ִٸ�
		{
			parent = node; // �θ� rode��
			if (key < node->key) // key�� root���� �۴ٸ�
				node = node->left; // node���� node�� ���ʰ�
			else // key�� root���� ũ�ų� ���ٸ�
				node = node->right; // node���� node�� �������� �ִ´�.

			// �����̳� �������� ����ִٸ� while���� ������ �ȴ�.
		}
		
		newNode->parent = parent; // while�� ���鼭 parent���� ���ϰ�
		
		// while���� ���鼭 ������ִ� ���� ä��
		if (key < parent->key) // key�� �θ𺸴� ������
			parent->left = newNode; // �θ��� �������� �ְ�
		else // �θ𺸴� ũ�ų� ���ٸ�
			parent->right = newNode; // �θ��� �����ʰ��� �ִ´�.
	}

	Node* Search(Node* node, int key)
	{
		if (node == nullptr || key == node->key) // ����ְų� key���� ���ٸ�
			return node; // node�� ��ȯ

		if (key < node->key) // key ���� node���� �۴ٸ�
			return Search(node->left, key); // node�� ����Ʈ���� ���� key�� ã�´�.
		else // �ݴ��� ��� ���������� ����.
			return Search(node->right, key);
	}

	Node* Min(Node* node) // �ּҰ��� ��������
	{
		while (node->left)
			node = node->left;

		return node;
	}

	Node* Max(Node* node) // �ִ밪�� ����������
	{
		while (node->right)
			node = node->right;

		return node;
	}

	Node* Next(Node* node) // ������ �������� ū ��
	{
		// node�� ���� �ڽ��� ��� -> ���� �����ʰ��� next
		if (node->right) // node�� ������ ���� �ִٸ� -> ���ٸ� �θ� ���� return
			return Min(node->right); // ������ Ʈ������ �ּҰ��� ���� ������

		// node�� ������ �ڽ��� ��� -> �θ��� �θ��� ���� next��
		Node* parent = node->parent;

		while (parent && node == parent->right) // �θ� �����ϰ�, ���� �θ��� ������ �ڽ��� ���
		{
			node = parent; // node�� �θ� �ְ�
			parent = parent->parent; // �θ𿡴� �θ��� �θ� �ִ´�.
		}

		return parent; // ������ �θ��� ũ��.
	}

	void Delete(Node* node)
	{
		if (node == nullptr) //��������� return
			return;

		if (node->left == nullptr) // ����� �����ڽ��� ����ִٸ�
			Replace(node, node->right); // node�� ������ ���� �ְ�, node�� ��������.
		else if (node->right == nullptr) // ����� ������ �ڽ��� ����ִٸ�
			Replace(node, node->left); // ��忡 ���ʰ��� �ְ�, node�� ��������.

		else // �ڽ��� �Ѵ��ִ� ���-> ���ʿ��� ū�� or �����ʿ��� �������� �����´� == next
		{
			Node* next = Next(node); // node�� next���� ���ؼ�
			node->key = next->key; // next�� key���� node�� �ű��
			Delete(next); // next�� �����.
		}
	}

	void Replace(Node* u, Node* v) // u�� v�� �ִ´�.
	{
		if (u->parent == nullptr) // u�� �θ� ���ٸ�  root����
			_root = v; // root�� v�� �־��ش�.
		else if (u == v->parent->left) // u�� v�� �θ��� ���ʰ�, �� u�� v�� �������
			u->parent->left = v; // u�ڸ��� v�� �־��ش�
		else // u�� v�� �����ʰ�, u�� v�� �������
			u->parent->right = v; // u�ڸ��� v�� �־��ش�


		if (v) // v�� �ִٸ�
			v->parent = u->parent; // u�� parent�� v�� parent�� �־��ָ鼭 u�� �����ش�.

	}

	void Print()
	{
		Print(_root);
	}

	void Print(Node* node)
	{
		if (node == nullptr) // ����ִٸ� return
			return;

		//������� �ʴٸ� ����Լ��� ���
		cout << node->key << endl;
		Print(node->left); // ������
		Print(node->right); // ū��
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