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

    GList.resize(N + 1);
    InDegree.resize(N + 1, 0);

    int A, B;
    for (int i = 0; i < M; ++i)
    {
        cin >> A >> B;
        GList[A].push_back(B);
        InDegree[B]++;
    }

    //최소 힙 기반의 우선순위 큐
    priority_queue<int, vector<int>, greater<>> PQ;

    for (int i = 1; i <= N; ++i)
    {
        if (InDegree[i] == 0)
            PQ.push(i);
    }

    while (!PQ.empty())
    {
        int Cur = PQ.top();
        PQ.pop();
        Result.push_back(Cur);

        for (int Node : GList[Cur])
        {
            InDegree[Node]--;
            if (InDegree[Node] == 0)
                PQ.push(Node);
        }
    }


    for (int Node : Result)
    {
        cout << Node << " ";
    }
    return 0;
}
