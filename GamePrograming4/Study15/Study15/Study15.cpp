#include <iostream>
using namespace std;
#include <vector>

// depth first searching (깊이 있는거 부터 서칭)
// dfs bfs 행렬, 리스트.
// 0~9번 10개의 노드가 존재           // 1-2  1-3  3-4 연결되어있다.

// 정점 ---간선---> 정점  (단방향)
// 정점 <---간선---> 정점  (양방향)

//const int V = 10;
//bool a[V][V], visited[V]; // a는 연결되어있는지

// 0번부터 방문안한 노드를 찾고, 해당노드부터 방문하여 연결된 노드를 이어서 방문해서 출력하는 재귀함수를 만들어보자

//void go(int from)
//{
//    visited[from] = 1;
//    cout << from << "\n";
//
//    for (int i = 0; i < V; i++)
//    {
//        if (visited[i])
//            continue; // 방문했다면
//        if (a[from][i])
//            go(i); // 안했다면 재귀
//    }
//}

// list ver
//const int V = 10;
//vector<int> adj[V];
//int visited[V];
//
//void go(int idx)
//{
//    cout << idx << '\n';
//    visited[idx] = 1;
//
//    for (int there : adj[idx])
//    {
//        if (visited[there])
//            continue;
//
//        go(there);
//    }    
//}

const int n = 6;
vector<int> adj[n];
int visited[n];

void dfs(int u)
{
    visited[u] = 1;
    cout << u << "\n";

    for (int v : adj[u]) // 연결되어있고 
    {
        if (visited[v] == 0) //방문하지 않았다면
            dfs(v);
    }
}


int main()
{
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[4].push_back(2);
    adj[2].push_back(5);

    dfs(1); // 대표문제 백준 2178번

    // 그래프가 밀집되어 있을 경우에 사용, 간선이 많다.
    // 행렬ver 공간복잡도 - V^2 // 시간 복잡도 - o(1)
    //a[1][2] = 1;    a[1][3] = 1;    a[3][4] = 1;
    //a[2][1] = 1;    a[3][1] = 1;    a[4][3] = 1;


    //for (int i = 0; i < V; i++)
    //{
    //    for (int j = 0; j < V; j++)
    //    {
    //        if (a[i][j] && visited[i] == 0) // 방문하지 않았다면
    //        {
    //            go(i); //간다.
    //        }
    //    }
    //}

    // 그래프가 조밀 할 경우에 사용 , 간선이 적다. (보통)
    // 리스트ver 공간복잡도 - V+@ // 시간 복잡도 - o(v)
    // 0-1,2,3
    // 1-0,2
    // 2-0,1
    // 3-0

    //adj[1].push_back(2);
    //adj[2].push_back(1);

    //adj[1].push_back(3);
    //adj[3].push_back(1);

    //adj[3].push_back(4);
    //adj[4].push_back(3);
    //
    //for (int i = 0; i < V; i++)
    //{
    //    if (adj[i].size() && visited[i] == 0)
    //        go(i);
    //}


    /* 출력함수
    for (int i = 0; i < 4; i++)
    {
        cout << i << "::";
        for (int there : adj[i])
            cout << there << " ";

        cout << '\n';
    }
    */

}

