#include <iostream>
using namespace std;

// 3*3 맵받아서 이맵은 1,0 으로 {0,0} 무조건 1 이고, 

const int n = 3;
int a[n][n], visited[n][n];
const int dy[] = { -1,0,1,0 }; 
const int dx[] = { 0,1,0,-1 };


void go(int y, int x)
{
	visited[y][x] = 1;
	cout << y << " : " << x << '\n';
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 00 || ny >= n || nx >= n)
			continue;
		if (a[ny][nx] == 0)
			continue;
		if (visited[ny][nx])
			continue;
		go(ny, nx);
	}
}


int main()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	
}