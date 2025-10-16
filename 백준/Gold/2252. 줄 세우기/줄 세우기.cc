#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <set>
#include <sstream>
using namespace std;

int N, M;

vector<vector<int>> GList;
vector<int> InDegree;
vector<int> Result;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    int A, B;

    GList.resize(N + 1);
    InDegree.resize(N + 1, 0);

    for (int i = 0; i < M; ++i)
    {
        cin >> A >> B;
        GList[A].push_back(B);
        InDegree[B]++;
    }

    queue<int> Q;

    for (int i = 1; i <= N; ++i)
    {
        if (InDegree[i] == 0)
        {
            Q.push(i);
        }
    }


    while (!Q.empty())
    {
        int Cur = Q.front();
        Q.pop();
        Result.push_back(Cur);

        for (int Node : GList[Cur])
        {
            InDegree[Node]--;
            if (InDegree[Node] == 0)
                Q.push(Node);
        }
    }


    for (auto Node : Result)
    {
        cout << Node << " ";
    }
    return 0;
}