#include <iostream>
using namespace std;
#include <vector>
#include <queue>
// 벡터, 내접, 외접, 삼각함수, 역삼각함수, 행렬
// 그래픽스
// 언어 c++, 자료구조, 알고리즘 (기본)
    // 게임수학 - 그래픽스
    // 규모가 클수록 클라와 서버를 잘 알아야한다
    // 인디게임 -포톤 / 언리얼 - 데디서버
    // 서버(멀티스레드)

vector<int> adj[100];
int visited[100];
int nodeList[] = { 10,12,14,16,18,20,22,24 };

// first in first out FIFO queue
void bfs(int here)
{
    queue<int>q;
    visited[here] = 1;
    q.push(here);

    while (q.size())
    {
        int here = q.front();
        q.pop();
        
        for (int there : adj[here])
        {
            if (visited[there])
                continue;
            
            visited[there] = visited[here] + 1; // 방문했다면 +1 해줘서 몇번 방문했는지 체크가능
            q.push(there);
        }
    }
}


int main()
{
    // dfs     bfs(breath first searching) - 최단경로

    adj[10].push_back(12);
    adj[10].push_back(14);
    adj[10].push_back(16);

    adj[12].push_back(18);
    adj[12].push_back(20);

    adj[20].push_back(22);
    adj[20].push_back(24);

    bfs(10);
    
    for (int i : nodeList)
        cout << i << ":" << visited[i] << '\n';

    //cout << "최단경로는" << visited[n-1] << '\n';


}

