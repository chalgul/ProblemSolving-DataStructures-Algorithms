#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <set>
#include <sstream>
using namespace std;

int N;

vector<vector<int>> GList;

int Parent[100002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int A, B;

    GList.resize(N+1);

    for (int i = 0; i < N-1; ++i)
    {
        cin >> A >> B;
        GList[A].push_back(B);
        GList[B].push_back(A);
    }


    queue<int> Q;
    Q.push(1);
    Parent[1] = 0;

    while (!Q.empty())
    {
        int Cur = Q.front();
        Q.pop();

        for (auto Node : GList[Cur])
        {
            if (Node == Parent[Cur])
                continue;
            Q.push(Node);
            Parent[Node] = Cur;
        }
    }


    for (int i = 2; i <= N; ++i)
    {
        cout << Parent[i] << "\n";
    }

    return 0;
}