#include <iostream>
#include <vector>
using namespace std;
#include <queue>
#include <time.h>

// ���� ����
// 0��°�� 1��° ��
// 1��°�� 2��° ��

void BubbleSort(vector<int>& v)
{
	int size = v.size();

	for (int i = 0; i < size-1; i++) // v[size-1]�����ϸ� v[size]���� �񱳰���
	{
		for (int j = 0; j < size-1-i; j++) // ���� �޺κ��� ū���ڷ� ���ĵǼ� i���� �񱳾��ص���
		{
			if (v[j] < v[j + 1])
				swap(v[j], v[j + 1]);
		}
	}
}

// ���� ����
// ���� ���� ���� ���ʺ��� ����

void SelectionSort(vector<int>& v)
{
	int size = v.size();

	for (int i = 0; i < size-1; i++) // �������� ������ �ִ밪
	{
		int minIdx = i;
		for (int j = i; j < size; j++) // ���������� ���ؾ���!
		{
			if (v[j] < v[minIdx])
				minIdx = j;
		}
		swap(v[i], v[minIdx]);
	}
}

// ���� ����
// i��° ������ ������� ����
void InsertSort(vector<int>& v)
{
	int size = v.size();

	for (int i = 1; i < size; i++) // ù��°�� ���� ���� X, 1��°����
	{
		int insertData = v[i];

		int j;
		for (int j = i-1; j >=0; j--)
		{
			if (v[j] > insertData)
				v[j + 1] = v[j];
			else
				break;
		}

		v[j + 1] = insertData; // �ش� ��ġ�� �������ش�!!!
	}
}

// ������
void HeapSort(vector<int>& v)
{
	priority_queue<int, vector<int>, greater<int>>pq;

	for (int a : v)
		pq.push(a);
	v.clear();

	for (int i = 0; i < pq.size(); i++)
	{
		v.push_back(pq.top());
		pq.pop();
	}
}

// ���� ����
// size�� �߰�(mid)�� �������� ���� ���������� ����� ��� ����
// �ϴٰ� 1���� ���ҵǾ�����, �ٽ� �����Ѵ�.
// ������ ���� ���ĵǾ ����!

void MergeResult(vector<int>& v, int left, int mid, int right)
{
	int leftIdx = left; // ���ʿ��� ���� �տ���
	int rightIdx = mid + 1; // �����ʿ��� ���� �տ���(mid+1)

	vector<int>temp;
	
	while (leftIdx <= mid && rightIdx <= right) // left�� mid�� ���� �� ����, right�� right�� ���� �� ����
	{
		// �̹� ���ĵǾ� �ִ� ���̿��� ���� �տ��� �������Ѵ�.
		if (v[leftIdx] <= v[rightIdx]) // ���� left�� �� �۴ٸ� 
		{
			temp.push_back(v[leftIdx]); // left�� �ְ�
			leftIdx++; // ������ �񱳵Ǵ� left�� ���� ++
		}
		else // right �������� �� ũ�ٸ�
		{
			temp.push_back(v[rightIdx]); // �������� �־��ش�
			rightIdx++; // ���� right�� ���� ++
		}
	}

	if (leftIdx > mid) // ���� ������ ���� �����ٸ�
	{
		while (rightIdx <= right) // right�� ����������
		{
			temp.push_back(v[rightIdx]);
			rightIdx++;
		}
	}
	else // �������� ���� �����ٸ�
	{
		while (leftIdx <= mid)
		{
			temp.push_back(v[leftIdx]);
			leftIdx++;
		}
	}

	// v�� ���ĵ� temp���� �־��ش�.
	for (int i = 0; i < temp.size();i++)
	{
		v[left + i] = temp[i]; // ���ʰ����� ���ʴ�� �־��ش�.
	  }
}

void MergeSort(vector<int>& v, int left, int right)
{
	if (left >= right) // ������ �����ʺ��� �۾ƾ��Ѵ�.
		return;

	int mid = (left / right) / 2; // �߰��� ����
	MergeSort(v, left, mid); // ���ʳ����� �� ����
	MergeSort(v, mid + 1, right); // �����ʳ����� �� ����

	MergeResult(v, left, mid, right); // �ٽ� ��ģ��

}


// ������
// 0��° pivot, 1��° low, ������ high
// low�� pivot���� ū���� ������ stop
// high�� pivot���� �������� ������  stop
// ���� low��  high ���� �����Ѵ�. low�� high�� ����������.
// ���� �����ٸ� pivot�� high ���� �ٲٰ� pivot�� �߰��� �Ǽ�
// pivot��  �������� ���� �������� �ٽ� ������

int Partition(vector<int>& v, int left, int right)
{
	int pivot = v[left]; // 0��°��
	int low = left + 1;
	int high = right;

	while (low <= high) // ���������� �ݺ�
	{
		while (low <= right && v[low] <= pivot) // pivot���� ũ�� stop
			low++;
		while (high >= left && v[high] >= pivot) // pivot���� ������ stop
			high++;

		if (low < high) // ���� ������ �ʾҴµ� �����ִٸ� ���� ���� ����
			swap(v[low], v[high]);
	}

	swap(v[left], v[high]); // pivot�� ���̿��� left�� high�� �ٲ㼭 pivot�� �߾ӿ��´�.

	return high; // high�� ��ġ�� ���� pivot�� �ִ��ڸ�.
}


void QuickSort(vector<int>& v, int left, int right)
{
	// left�� right�� ������ ����!
	if (left > right)
		return; 

	int pivot = Partition(v, left, right);
	// �ǹ����� �޾ƿͼ� �� �������� ���ʰ� �������� �ٽ� ������
	QuickSort(v, left, pivot - 1);
	QuickSort(v, pivot + 1, right);
}



int main()
{
	srand(time(0));
	//  ����      ���� ���� ���� ��  ���� ��
	clock_t start, end;

	start = clock();

	vector<int> v;

	for (int i = 0; i < 100; i++)
	{
		int randValue = rand() % 100;
		v.push_back(randValue);
	}

	QuickSort(v, 0, v.size() - 1);
	

	end = clock();
	double result = (double)(end - start);

	cout << result << endl;
}