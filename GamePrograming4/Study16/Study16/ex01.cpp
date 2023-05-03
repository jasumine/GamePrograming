// ���� 2178
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

		if (ny < 0 || nx < 0 || ny >= M || nx >= N) // ������ ����ų�
			continue;
		if (!s[ny] || visited[ny]) // map�� 0�̰ų�, �̹� �湮�ߴٸ�
			continue;
		// map�� 1�̰�, �湮���� �ʾҴٸ�
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
	
	// N ���� , M ����
	for (int i = 0; i < M; i++)
	{
		cin >> s[i];

	}

	bfs(0,0);

	cout << "�ִܰ�δ�" << visited[M - 1][N - 1];
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
	q.push(make_pair(y, x)); // q�� y��x���� �ְ�
	
	while (!q.empty())
	{
		int y = q.front().first; // ó�� ���� ���� �ְ�
		int x = q.front().second;

		q.pop(); // ó�� ���� ���� ���ش�.

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i]; // 4������ �����鼭
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue; // ������ ����� continue;
			if (maze[ny][nx] == 0)
				continue;
			if (visited[ny][nx])
				continue; // �湮�ߴٸ� continue;

			visited[ny][nx] = visited[y][x] + 1; // ���� ������ �����ֱ����� +1
			q.push(make_pair(ny, nx)); // ���ο� ���� �־��ش�.
		}
	}

	cout << visited[n - 1][m - 1]; // [0][0]~[n-1][m-1]������ �Ÿ�
}

int main()
{
	// n ����, m����
	cin >> n >> m; // ũ�⸦ �Է¹ް�
	for (int i = 0; i < n; i++) // ���α��̸�ŭ
	{
		string row;
		cin >> row;

		for (int j = 0; j < m; j++)
			maze[i][j] = row[j] - '0'; // char�� int�� ��ȯ('0' or 48)
	}

	bfs(0, 0);
}
