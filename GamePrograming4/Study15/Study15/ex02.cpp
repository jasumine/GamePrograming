// 백준 1012번(이거) 2178번(말고)
#include <iostream>
using namespace std;
#include <vector>

int T, n, m, number;
int x, y;
int cabbage[50][50];
const int dy[] = { -1,0,1,0 }; 
const int dx[] = { 0,1,0,-1 };
// 상(0,-1)  우(1,0)  하(0,1),  좌(-1,0)

void go(int y, int x,int &count)
{
	count++;
	cabbage[y][x] = 1;
	for (int i = 1; i < n; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= y || nx >= x)
			continue;
		if (cabbage[ny][nx] == 0)
			continue;
		if (cabbage[ny][nx])
			continue;
		go(ny, nx, count);
	}

}

int main()
{

	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		cin >> n>> m>> number;
		fill(&cabbage[n][m], &cabbage[n][m] + 50 * 50, 0);
		for (int j = 0; j < number; j++)
		{
			cin >> x, y;
			cabbage[x][y] = 1;
			cin.ignore();
		}
		int count = 0;
		go(n, m,count);
		cout << count << endl;
	}
	return 0;
}