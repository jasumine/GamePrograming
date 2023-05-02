// 백준 1012번
#include <iostream>
using namespace std;
#include <vector>

int T, N, M, K; // 테스트개수, 가로, 세로, 배추개수
int y, x, ny, nx; // 배추의 개수입력
int cnt; // 지렁이 개수

int cabbage[50][50]; // 배추의 위치
int visited[50][50]; // 배추 방문체크

const int dy[] = { -1, 0,1,0 };
const int dx[] = { 0,1,0,-1 };

void dfs(int x, int y)
{
	visited[x][y] = 1; // 방문했으니 1로 변경
	for (int i = 0; i < 4; i++) // 상하좌우 체크
	{
		nx = x + dx[i];
		ny = y + dy[i];

		if (ny < 0 || nx < 0 || ny >= M || nx >= N)
			continue; // 범위를 벗어날 시 continue;
		if (cabbage[nx][ny] == 1 && !visited[nx][ny])
			dfs(ny, nx); // 배추가 있고, 방문하지 않았다면 재귀함수
	}
}



int main()
{
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		fill(&cabbage[0][0], &cabbage[0][0] + 50 * 50, 0); // 0으로 초기화
		fill(&visited[0][0], &visited[0][0] + 50 * 50, 0);// 0으로 초기화

		cnt = 0;

		cin >> N >> M >> K; // 가로, 세로, 배추개수
		
		for (int i = 0; i < K; i++)
		{
			cin >> x >> y; // x,y좌표입력 받아서
			cabbage[x][y] = 1; // 배추위치 입력
		}

		for (int i = 0; i < N; i++) 
		{
			for (int j = 0; j < M; j++)
			{
				if (cabbage[i][j] == 1 && !visited[i][j])
				{
					// 배추가 있고, 방문하지 않았다면 dfs함수, 지렁이카운트+1
					dfs(i, j);
					cnt++;
				}
			}// 주위에 심어진 배추가 없다면 재귀함수를 빠져나와서 다시 실행하고 지렁이카운트+1
		}

		cout << cnt << "\n"; 
	}
}
