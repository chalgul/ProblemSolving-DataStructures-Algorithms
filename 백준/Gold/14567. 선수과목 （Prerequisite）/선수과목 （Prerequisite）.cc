#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <set>
#include <sstream>
#include <tuple>
#include <stack>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using namespace std;

int N, M;

//타겟 노드 indegrees, 학기 회차 
vector<pair<int,int>> InDegree;

vector<vector<int>> GList;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    InDegree.resize(N + 1, { 0,1 });
    GList.resize(N+1);


    int A, B;
    for (int i = 0; i < M; ++i)
    {
        cin >> A >> B;

        GList[A].push_back(B);

        auto& Temp = InDegree[B];
        Temp.first++;
    }

    queue<int> Q;
    
    int Size = (int)InDegree.size();


    for (int i = 1; i < Size; ++i)
    {
        if (InDegree[i].first == 0)
        {
            Q.push(i);
        }
    }

    while (!Q.empty())
    {
        int Cur = Q.front();
        Q.pop();


        for (auto Node : GList[Cur])
        {
            auto& Temp = InDegree[Node];
            Temp.first--;

            //Indegree가 0이 되는 순간에 해당 노드는 위상 정렬 되므로
            //그 순간을 되게 만든 마지막 Indegree와 연결되어 있던 전 노드의 학기에 +1을 해주면 된다고 판단
            if (Temp.first == 0)
            {
                Q.push(Node);
                Temp.second = InDegree[Cur].second + 1;
            }
        }
    }



    for (int i = 1; i <= N; ++i)
    {
        cout << InDegree[i].second << " ";
    }

    return 0;
}