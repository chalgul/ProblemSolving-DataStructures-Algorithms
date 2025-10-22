#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <numeric>

using namespace std;

int V, E;
int St;

//first : 가중치 second : outdegree가 향하는 정점
vector<vector<pair<int, int>>> GList;


//first : PQ에 push할 당시에 해당 노드까지의 최단 거리  second : outdegree가 향하는 정점
//최소힙 활용
priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;


vector<int> Dis;

vector<int> Pre;



int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E;

    GList.resize(V + 1);
    Dis.resize(V + 1, 99999999);
    Pre.resize(V + 1, -1);

    //인접리스트 방식으로 방향 그래프 표현
    int u, v, w;
    for (int i = 0; i < E; ++i)
    {
        cin >> u >> v >> w;

        GList[u].push_back({w,v});
    }


    int Start, End;
    cin >> Start >> End;


    //St를 기준으로 다익스트라 알고리즘 수행
    PQ.push({ 0,Start });
    Dis[Start] = 0;
    Pre[Start] = Start;

    while (!PQ.empty())
    {
        auto Cur = PQ.top();
        PQ.pop();

        //우선순위 큐에서 나온 최단거리 정보가 실제 Dis 배열과 일치하지 않으면, 이미 이후에 갱신된 값이라는 의미이므로 무시
        if (Cur.first != Dis[Cur.second])
            continue;

        for (auto Info : GList[Cur.second])
        {
            //기존에 Dis 배열에 있는 최단거리보다 Cur.second까지의 최단거리 + Cur.second에서의 outdegree 비용이 더 작으면
            //즉 Cur.second를 경유해서 가는 경로가 더 가깝다면 갱신
            //갱신되었으면 우선순위 큐에 해당 정보 넣어주어야 함.
            if (Dis[Info.second] > Dis[Cur.second] + Info.first)
            {
                Dis[Info.second] = Dis[Cur.second] + Info.first;
                Pre[Info.second] = Cur.second;
                PQ.push({ Dis[Info.second],Info.second });
            }
        }
    }
     
    
    cout << Dis[End] << "\n";

    stack<int> S;

    int Temp = End;
    
    while(Pre[Temp] != Temp)
    {
        S.push(Temp);
        Temp = Pre[Temp];
    }
    S.push(Temp);

    cout << S.size() << "\n";

    while (!S.empty())
    {
        cout << S.top() << " ";
        S.pop();
    }



    return 0;
}

