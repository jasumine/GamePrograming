#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main()
{
	int n;
	cin >> n;

	vector<pair<int, int>> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;

	sort(a.begin(), a.end()); // first 값을 기준으로 정렬이 됨.

	int time = a[0].first + a[0].second;

	for (int i = 1; i < a.size(); i++)
	{
		time = max(time, a[i].first); // time과 first값을 비교했을때 더 큰 값을 찾는다.
		time += a[i].second;
	}

	cout << time << "\n";
}