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

	sort(a.begin(), a.end()); // first ���� �������� ������ ��.

	int time = a[0].first + a[0].second;

	for (int i = 1; i < a.size(); i++)
	{
		time = max(time, a[i].first); // time�� first���� �������� �� ū ���� ã�´�.
		time += a[i].second;
	}

	cout << time << "\n";
}