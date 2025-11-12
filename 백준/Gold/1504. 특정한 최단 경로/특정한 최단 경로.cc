#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <cmath>
#include <string>
#include <array>
using namespace std;

int N, E;


//first : 간선이 가는 노드 정보 second : 가중치
vector<vector<pair<int, int>>> GList;

//정해진 시작 지점으로부터 x까지 가는데 걸리는 최단 거리
vector<int> DisTable;
vector<int> DisTableU;
vector<int> DisTableV;

//first : PQ에 들어온 순간에 최단 경로를 의미하는 값  second : 목표지점
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;

int ResultVal = 0;

void Dijkstra(vector<int>& Table, int Start)
{
    PQ.push({ 0,Start });
    Table[Start] = 0;

    while (!PQ.empty())
    {
        auto Cur = PQ.top();
        PQ.pop();

        if (Cur.first != Table[Cur.second])
            continue;

        for (auto Node : GList[Cur.second])
        {

            if (Table[Node.first] > Node.second + Cur.first)
            {
                PQ.push({ Node.second + Cur.first, Node.first });
                Table[Node.first] = Node.second + Cur.first;
            }
        }
    }
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> N >> E;

    GList.resize(N + 1);

    DisTable.resize(N + 1,99999999);
    DisTableU.resize(N + 1,99999999);
    DisTableV.resize(N + 1,99999999);


    int A, B, C;
    for (int i = 0; i < E; ++i)
    {
        cin >> A >> B >> C;
        GList[A].push_back({B,C});
        GList[B].push_back({A,C});
    }

    int U, V;
    cin >> U >> V;

    Dijkstra(DisTable,1);
    Dijkstra(DisTableU,U);
    Dijkstra(DisTableV,V);

    if (DisTable[U] + DisTableU[V] + DisTableV[N] >= 99999999 &&
        DisTable[V] + DisTableV[U] + DisTableU[N] >= 99999999)
    {
        cout << -1;
        return 0;
    }


    ResultVal = DisTable[U] + DisTableU[V] + DisTableV[N];
    ResultVal =  min(ResultVal, DisTable[V] + DisTableV[U] + DisTableU[N]);

    cout << ResultVal;

    return 0;
}