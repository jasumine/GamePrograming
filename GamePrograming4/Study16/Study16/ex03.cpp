#include <iostream>
using namespace std;
#include <vector>
#include <queue>

const int maxN = 104;

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

int n, m;
int maze[maxN][maxN], visited[maxN][maxN];
int y, x;

queue<pair<int, int>> q;

void bfs(int y, int x)
{
	visited[y][x] = 1;
	q.push(make_pair(y, x));

	while (q.empty() == false)
	{
		int y = q.front().first;
		int x = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m || maze[ny][nx] == 0)
				continue;

			if (visited[ny][nx])
				continue;

			visited[ny][nx] = visited[y][x] + 1;
			q.push(make_pair(ny, nx));
		}

	}


	cout << visited[n-1][m-1]  << endl;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string row;
		cin >> row;

		for (int j = 0; j < m; j++)
			maze[i][j] = row[j] - '0';
	}

	bfs(0, 0);

}
