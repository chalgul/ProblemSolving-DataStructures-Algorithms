#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <list>
#include <queue>
#include <numeric>
#include <unordered_map>

using namespace std;

int N, M;

vector<int> List[502];

int Dis[502];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> N >> M;

    int A = 0, B = 0;
    for (int i = 1; i <= M; ++i)
    {
        cin >> A >> B;
        List[A].push_back(B);
        List[B].push_back(A);
    }


    //거리가 최대 2인 노드까지 모두 포함하면 됨 : BFS
    int ResultVal = 0;
    queue<int> Q;
    Q.push(1);
    Dis[1] = 1;

    while (!Q.empty())
    {
        int Cur = Q.front();
        Q.pop();

        for (int Node : List[Cur])
        {
            if (Dis[Node] != 0)
                continue;

            if (Dis[Cur] >= 3)
            {
                cout << ResultVal;
                return 0;
            }

            Q.push(Node);
            Dis[Node] = Dis[Cur] + 1;
            ResultVal++;
        }
    }

    cout << ResultVal;
    return 0;
}


