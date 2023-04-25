#include <iostream>
#include <vector>
using namespace std;
#include <time.h>

// MergeSort 병합 정렬
// [27] [10] [12] [20]			[25] [13] [15] [22]
//		left			mid			right
// [27] [10]   [12] [20]		[25] [13]   [15] [22]
// [27]   [10]   [12]   [20]	[25]   [13]   [15]   [22]	log N
// 
// [10][27]  [12][20]				[13][25]  [15][22]
// [10][12][20][27]		[13][15][22][25]
//	[10][12][13][15][20][22][25][27]	logN = Nlogn


// [10][12][20][27]			[15][15][22][25]
// left ++			mid		right ++
void MergeResult(vector<int>& v, int left, int mid, int right)
{
	int leftIdx = left;
	int rightIdx = mid + 1;

	vector<int> temp;

	while (leftIdx <= mid && rightIdx <= right) // leftidx는 mid보다 작고, rightidx는 right보다 작아야함
	{
		if (v[leftIdx] <= v[rightIdx]) // 작은 값을
		{
			temp.push_back(v[leftIdx]); // 넣어준다.
			leftIdx++;
		}
		else
		{
			temp.push_back(v[rightIdx]);
			rightIdx++;
		}
	}

	// 왼쪽이 먼저 끝났다면 오른쪽에는 큰 나머지만 남아있어서
	if (leftIdx > mid)
	{
		while (rightIdx <= right)
		{
			temp.push_back(v[rightIdx]); // 이미 정렬되어있어서 넣어주기만 하면된다.
			rightIdx++;
		}
	}
	else
	{
		while (leftIdx <= mid)
		{
			temp.push_back(v[leftIdx]);
			leftIdx++;
		}
	}

	for (int i = 0; i < temp.size(); i++)
	{
		v[left + i] = temp[i]; // 왼쪽값부터 차례대로 넣어준다!
	}
}

void MergeSort(vector<int>& v, int left, int right) // Nlogn
{
	// 재귀함수를 이용해서 반복실행
	if (left >= right)
	{
		return; // 데이터가 한개일 경우
	}

	// 분할하는 과정
	int mid = (left + right) / 2; /// 각 값의 중간을 나눈다.
	MergeSort(v, left, mid);
	MergeSort(v, mid + 1, right);
	
	// 합치는 과정
	MergeResult(v, left, mid, right);
}

// 퀵 정렬
// 0번째를 pivot으로 두고 1번째를 low, vector의 size를 high로 둔다.
// low는 pivot보다 큰 값을 만나면 멈추고,
// high는 pivot보다 작은 값을 만나면 멈춘다.
// 둘다 멈췄을경우 교환해주어서 다시 작동한다.
// low와 high가 같은 위치이거나, 서로 바뀌어서 low > high가 된경우 
// high의 위치와 pivot의 위치를 바꾸어서 pivot을 중앙에 오게하고
//									pivot을 기준으로 
// 왼쪽은 0 번째를 다시 pivot으로두고 퀵정렬 / 오른쪽은 pivot +1의 위치를 다시 pivot으로 두고 퀵정렬

int Partition(vector<int>& v, int left, int right)
{
	int pivot = v[left];
	int low = left + 1;
	int high = right;

	while (low <= high) // 만날때까지
	{
		while (low <= right && v[low] <= pivot) // low는 pivot보다 큰값을 만나면 멈춘다
			low++;

		while (high >= left + 1 && v[high] >= pivot) // high는 pivot보다 작은값을 만나면 멈춘다
			high--;

		if (low < high) // low와 high가 while문을 나왔을 때 교체를 해주어야 다시 while문을 반복하기때문에
			swap(v[low], v[high]); // swap을 해준다.
	}

	swap(v[left], v[high]); // pivot과 high의 값을 바꿔 pivot이 중앙에오게한다!

	return high;
}



void QuickSort(vector<int>& v, int left, int right)
{
	// 재귀함수를 이용

	if (left > right)
		return;

	int pivot = Partition(v, left, right);
	QuickSort(v, left, pivot - 1);
	QuickSort(v, pivot + 1, right);
}



int main()
{
	srand(time(0));
	clock_t start, end;
	start = clock();

	vector<int>v;
	for (int i = 0; i < 1000; i++)
	{
		int randValue = rand() % 10000;
		v.push_back(randValue);
	}

	QuickSort(v,0,v.size()-1);

	end = clock();
	double result = (double)(end - start);

	cout << result << endl;

	// 정수 6만개(평균초)
	// 버블													22.8
	// 선택													10.8
	// 삽입													7.4
	// 힙정렬		NlogN									0.034 <-실전에서 많이 쓴다. 나머지는 사고력개발!!!
	// 병합정렬		NlogN (힙보다 조금더빠르다)				0.026
	// 퀵정렬		NlogN	 최악의 케이스 N^2(제일느림)		0.014
}
