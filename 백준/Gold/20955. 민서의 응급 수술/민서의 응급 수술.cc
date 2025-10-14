#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <set>
#include <sstream>
using namespace std;

int N, M;

vector<int> GList[100002];

//0 = 방문 X ,  1 = 방문
int Vis[100002];

int GroupCnt = 0;



void DFS(int Cur)
{
    Vis[Cur] = 1;

    for (int Nxt : GList[Cur])
    {
        if (Vis[Nxt] == 0)
        {
            DFS(Nxt);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    int A, B;
    for (int i = 0; i < M; ++i)
    {
        cin >> A >> B;

        GList[A].push_back(B);
        GList[B].push_back(A);
    }
    
    for (int i = 1; i <= N; ++i)
    {
        if (Vis[i] == 0)
        {
            DFS(i);
            GroupCnt++;
        }
    }

    cout << (GroupCnt - 1) + (M + GroupCnt - 1) - (N - 1);

    return 0;
}