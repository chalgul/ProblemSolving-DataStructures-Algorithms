#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <set>
#include <sstream>
#include <tuple>

using namespace std;

int parent[304];
//가중치,노드1,노드2
vector<tuple<int, int, int>> TEdge;

int N, M;
long long ResultVal = 0;


/*
풀이 아이디어
결국 모든 논에 물을 대기 위해서는 최소 하나의 논 이상에는 직접 우물을 파내야 한다.
모든 논이 우물을 파는데 필요한 비용을 입력에서 제시해주고 있기 때문에
모든 논 + 우물을 정점이라고 가정하고, 최소 신장 트리를 탐색하면 풀린다고 판단
*/


int find(int Node)
{
    if (parent[Node] < 0)
        return Node;

    return parent[Node] = find(parent[Node]);
}

bool uni(int A, int B)
{
    A = find(A);
    B = find(B);

    if (A == B)
        return false;

    if (parent[A] > parent[B])
    {
        swap(A, B);
    }

    if (parent[A] == parent[B])
    {
        parent[A]--;
    }

    parent[B] = A;

    return true;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> N;

    //논의 개수 + 우물 1개
    fill(parent, parent + N + 1, -1);

    //0~n-1 : 논 n : 우물
    int WI;
    for (int i = 0; i < N; ++i)
    {
        cin >> WI;
        TEdge.push_back({WI, i, N});
    }

    for (int i = 0; i < N; ++i)
    {

        for (int j = 0; j < N; ++j)
        {
            cin >> WI;
            if (WI != 0)
            {
                TEdge.push_back({ WI,i,j });
            }
        }
    }

    sort(TEdge.begin(), TEdge.end());

    int Cnt = 0;

    size_t T = TEdge.size();
    for (size_t i = 0; i < T; ++i)
    {
        auto [W, A, B] = TEdge[i];

        if (uni(A, B) == false)
            continue;

        ResultVal += W;
        Cnt++;

        if (Cnt == N)
            break;
    }

    cout << ResultVal;
    return 0;
}
