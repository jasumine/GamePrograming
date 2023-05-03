// 백준 2178
/*
#include <iostream>
using namespace std;
#include <queue>
#include <vector>

int N, M;
string s[100];
string visited[100];
const int dy[]{ -1,-1,-1,0,1,1,1,0 };
const int dx[]{ -1,0,1,1,1,0,-1,-1 };

void bfs(int y, int x)
{

	for (int i = 0; i < 8; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= M || nx >= N) // 범위를 벗어나거나
			continue;
		if (!s[ny] || visited[ny]) // map이 0이거나, 이미 방문했다면
			continue;
		// map이 1이고, 방문하지 않았다면
		if (s[ny] && !visited[ny])
		{
			visited[ny][nx] = visited[y][x] + 1;
			bfs(ny, nx);
			break;
		}
	}
}


int main()
{
	cin >> M >> N;
	
	// N 가로 , M 세로
	for (int i = 0; i < M; i++)
	{
		cin >> s[i];

	}

	bfs(0,0);

	cout << "최단경로는" << visited[M - 1][N - 1];
}
*/

#include <iostream>
using namespace std;
#include <vector>
#include <queue>

const int maxN = 101;

const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

int n, m;
int maze[maxN][maxN], visited[maxN][maxN];
int y, x;

queue<pair<int, int>>q;

void bfs(int y, int x)
{
	visited[y][x] = 1;
	q.push(make_pair(y, x)); // q에 y와x값을 넣고
	
	while (!q.empty())
	{
		int y = q.front().first; // 처음 들어온 값을 넣고
		int x = q.front().second;

		q.pop(); // 처음 들어온 값을 빼준다.

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i]; // 4방향을 따지면서
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue; // 범위를 벗어나면 continue;
			if (maze[ny][nx] == 0)
				continue;
			if (visited[ny][nx])
				continue; // 방문했다면 continue;

			visited[ny][nx] = visited[y][x] + 1; // 블럭의 개수를 구해주기위해 +1
			q.push(make_pair(ny, nx)); // 새로운 값을 넣어준다.
		}
	}

	cout << visited[n - 1][m - 1]; // [0][0]~[n-1][m-1]사이의 거리
}

int main()
{
	// n 세로, m가로
	cin >> n >> m; // 크기를 입력받고
	for (int i = 0; i < n; i++) // 세로길이만큼
	{
		string row;
		cin >> row;

		for (int j = 0; j < m; j++)
			maze[i][j] = row[j] - '0'; // char를 int로 변환('0' or 48)
	}

	bfs(0, 0);
}
