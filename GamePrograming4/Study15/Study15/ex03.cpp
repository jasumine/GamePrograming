#include <iostream>
using namespace std;
#include <vector>

int T, N, M, K;
int y, x, ny, nx;
int cnt;

int cabbage[50][50];
bool visited[50][50];

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };

void dfs(int y, int x)
{
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		ny = y + dy[i];
		nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= M)
			continue;
		if (cabbage[ny][nx] == 1 && !visited[ny][nx])
			dfs(ny, nx);
	}
}


int main()
{
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		fill(&cabbage[0][0], &cabbage[0][0] + 50 * 50, 0);
		fill(&visited[0][0], &visited[0][0] + 50 * 50, 0);

		cnt = 0;

		cin >> M >> N >> K;

		for (int i = 0; i < K; i++)
		{
			cin >> x >> y;
			cabbage[y][x] = 1;
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (cabbage[i][j] == 1 && !visited[i][j])
				{
					dfs(i, j);
					cnt++;
				}
			}
		}

		cout << cnt << "\n";
	}
}