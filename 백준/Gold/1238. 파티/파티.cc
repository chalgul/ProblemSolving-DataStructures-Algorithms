#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <set>
#include <sstream>
#include <tuple>
#include <stack>

using namespace std;


//모든 노드에서 특정 마을 지점까지 가는데 걸리는 최단거리 정보
//특정 마을 지점에 모든 노드로 돌아가는데 걸리는 최단거리 정보
//2번 다익스트라 수행하면 해결 가능

//모든 노드에서 특정 마을지점까지 가는데 걸리는 최단거리 정보를 다익스트라로 구하기 위해서는
//그래프 방향성을 거꾸로 뒤집고 특정 마을지점에서부터 모든 노드로 돌아가는 최단거리를 구하면 될 것이다.

int N, M, X;

//first : 간선 비용 second : 향하는 노드
vector<vector<pair<int, int>>> GList;
vector<vector<pair<int, int>>> XGList;

//first : 입력 시점에 최단 거리 비용 second: 향하는 노드
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> XPQ;

//최단거리 배열
vector<int> Dis;
vector<int> XDis;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> X;

    Dis.resize(1001, 9999999);
    XDis.resize(1001, 9999999);

    GList.resize(10001);
    XGList.resize(10001);



    int A, B, W;
    for (int i = 0; i < M; ++i)
    {
        cin >> A >> B >> W;
        GList[A].push_back({W,B});
        XGList[B].push_back({W,A});
    }


    PQ.push({ 0,X });
    Dis[X] = 0;

    while (!PQ.empty())
    {
        auto Info = PQ.top();
        PQ.pop();

        if (Info.first != Dis[Info.second])
            continue;

        for (auto Node : GList[Info.second])
        {
            if (Dis[Node.second] > Dis[Info.second] + Node.first)
            {
                Dis[Node.second] = Dis[Info.second] + Node.first;
                PQ.push({ Dis[Node.second],Node.second});
            }
        }
    }

    XPQ.push({ 0,X });
    XDis[X] = 0;

    while (!XPQ.empty())
    {
        auto Info = XPQ.top();
        XPQ.pop();

        if (Info.first != XDis[Info.second])
            continue;

        for (auto Node : XGList[Info.second])
        {
            if (XDis[Node.second] > XDis[Info.second] + Node.first)
            {
                XDis[Node.second] = XDis[Info.second] + Node.first;
                XPQ.push({ XDis[Node.second],Node.second });
            }
        }
    }


    int Result = 0;
    for (int i = 1; i <= N; ++i)
    {
        int Temp = 0;
        Temp += Dis[i];
        Temp += XDis[i];
        Result = max(Result, Temp);
    }


    cout << Result;

    return 0;
}