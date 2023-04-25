#include <iostream>
#include <vector>
using namespace std;
#include <queue>
#include <time.h>

// 버블 정렬
// 0번째와 1번째 비교
// 1번째와 2번째 비교

void BubbleSort(vector<int>& v)
{
	int size = v.size();

	for (int i = 0; i < size-1; i++) // v[size-1]까지하면 v[size]까지 비교가능
	{
		for (int j = 0; j < size-1-i; j++) // 제일 뒷부분은 큰숫자로 정렬되서 i까지 비교안해도됨
		{
			if (v[j] < v[j + 1])
				swap(v[j], v[j + 1]);
		}
	}
}

// 선택 정렬
// 가장 작은 값을 왼쪽부터 정렬

void SelectionSort(vector<int>& v)
{
	int size = v.size();

	for (int i = 0; i < size-1; i++) // 마지막은 어차피 최대값
	{
		int minIdx = i;
		for (int j = i; j < size; j++) // 마지막까지 비교해야함!
		{
			if (v[j] < v[minIdx])
				minIdx = j;
		}
		swap(v[i], v[minIdx]);
	}
}

// 삽입 정렬
// i번째 값까지 순서대로 정렬
void InsertSort(vector<int>& v)
{
	int size = v.size();

	for (int i = 1; i < size; i++) // 첫번째는 비교할 이유 X, 1번째부터
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

		v[j + 1] = insertData; // 해당 위치에 삽입해준다!!!
	}
}

// 힙정렬
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

// 병합 정렬
// size의 중간(mid)을 기준으로 왼쪽 오른쪽으로 나뉘어서 계속 분할
// 하다가 1까지 분할되었을때, 다시 결합한다.
// 결합할 때는 정렬되어서 결합!

void MergeResult(vector<int>& v, int left, int mid, int right)
{
	int leftIdx = left; // 왼쪽에서 제일 앞에값
	int rightIdx = mid + 1; // 오른쪽에서 제일 앞에값(mid+1)

	vector<int>temp;
	
	while (leftIdx <= mid && rightIdx <= right) // left는 mid를 넘을 수 없고, right는 right를 넘을 수 없다
	{
		// 이미 정렬되어 있는 값이여서 제일 앞에값 끼리비교한다.
		if (v[leftIdx] <= v[rightIdx]) // 만약 left가 더 작다면 
		{
			temp.push_back(v[leftIdx]); // left를 넣고
			leftIdx++; // 다음에 비교되는 left를 위해 ++
		}
		else // right 오른쪽이 더 크다면
		{
			temp.push_back(v[rightIdx]); // 오른쪽을 넣어준다
			rightIdx++; // 다음 right를 위해 ++
		}
	}

	if (leftIdx > mid) // 만약 왼쪽이 먼저 끝났다면
	{
		while (rightIdx <= right) // right와 같을때까지
		{
			temp.push_back(v[rightIdx]);
			rightIdx++;
		}
	}
	else // 오른쪽이 먼저 끝났다면
	{
		while (leftIdx <= mid)
		{
			temp.push_back(v[leftIdx]);
			leftIdx++;
		}
	}

	// v에 정렬된 temp값을 넣어준다.
	for (int i = 0; i < temp.size();i++)
	{
		v[left + i] = temp[i]; // 왼쪽값부터 차례대로 넣어준다.
	  }
}

void MergeSort(vector<int>& v, int left, int right)
{
	if (left >= right) // 왼쪽은 오른쪽보다 작아야한다.
		return;

	int mid = (left / right) / 2; // 중간값 설정
	MergeSort(v, left, mid); // 왼쪽내에서 또 분할
	MergeSort(v, mid + 1, right); // 오른쪽내에서 또 분할

	MergeResult(v, left, mid, right); // 다시 합친다

}


// 퀵정렬
// 0번째 pivot, 1번째 low, 마지막 high
// low는 pivot보다 큰값을 만나면 stop
// high는 pivot보다 작은값을 만나면  stop
// 멈춘 low와  high 값을 변경한다. low와 high가 만날때까지.
// 둘이 만났다면 pivot과 high 값을 바꾸고 pivot은 중간이 되서
// pivot을  기점으로 왼쪽 오른쪽이 다시 퀵정렬

int Partition(vector<int>& v, int left, int right)
{
	int pivot = v[left]; // 0번째값
	int low = left + 1;
	int high = right;

	while (low <= high) // 만날때까지 반복
	{
		while (low <= right && v[low] <= pivot) // pivot보다 크면 stop
			low++;
		while (high >= left && v[high] >= pivot) // pivot보다 작으면 stop
			high++;

		if (low < high) // 둘이 만나지 않았는데 멈춰있다면 둘의 값을 변경
			swap(v[low], v[high]);
	}

	swap(v[left], v[high]); // pivot의 값이였던 left와 high를 바꿔서 pivot이 중앙에온다.

	return high; // high의 위치가 현재 pivot이 있는자리.
}


void QuickSort(vector<int>& v, int left, int right)
{
	// left가 right를 넘을순 없음!
	if (left > right)
		return; 

	int pivot = Partition(v, left, right);
	// 피벗값을 받아와서 그 기점으로 왼쪽과 오른쪽을 다시 나눈다
	QuickSort(v, left, pivot - 1);
	QuickSort(v, pivot + 1, right);
}



int main()
{
	srand(time(0));
	//  정렬      버블 선택 삽입 힙  병합 퀵
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