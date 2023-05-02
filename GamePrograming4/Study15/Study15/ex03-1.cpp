// ���� 1012��
#include <iostream>
using namespace std;
#include <vector>

int T, N, M, K; // �׽�Ʈ����, ����, ����, ���߰���
int y, x, ny, nx; // ������ �����Է�
int cnt; // ������ ����

int cabbage[50][50]; // ������ ��ġ
int visited[50][50]; // ���� �湮üũ

const int dy[] = { -1, 0,1,0 };
const int dx[] = { 0,1,0,-1 };

void dfs(int x, int y)
{
	visited[x][y] = 1; // �湮������ 1�� ����
	for (int i = 0; i < 4; i++) // �����¿� üũ
	{
		nx = x + dx[i];
		ny = y + dy[i];

		if (ny < 0 || nx < 0 || ny >= M || nx >= N)
			continue; // ������ ��� �� continue;
		if (cabbage[nx][ny] == 1 && !visited[nx][ny])
			dfs(ny, nx); // ���߰� �ְ�, �湮���� �ʾҴٸ� ����Լ�
	}
}



int main()
{
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		fill(&cabbage[0][0], &cabbage[0][0] + 50 * 50, 0); // 0���� �ʱ�ȭ
		fill(&visited[0][0], &visited[0][0] + 50 * 50, 0);// 0���� �ʱ�ȭ

		cnt = 0;

		cin >> N >> M >> K; // ����, ����, ���߰���
		
		for (int i = 0; i < K; i++)
		{
			cin >> x >> y; // x,y��ǥ�Է� �޾Ƽ�
			cabbage[x][y] = 1; // ������ġ �Է�
		}

		for (int i = 0; i < N; i++) 
		{
			for (int j = 0; j < M; j++)
			{
				if (cabbage[i][j] == 1 && !visited[i][j])
				{
					// ���߰� �ְ�, �湮���� �ʾҴٸ� dfs�Լ�, ������ī��Ʈ+1
					dfs(i, j);
					cnt++;
				}
			}// ������ �ɾ��� ���߰� ���ٸ� ����Լ��� �������ͼ� �ٽ� �����ϰ� ������ī��Ʈ+1
		}

		cout << cnt << "\n"; 
	}
}
