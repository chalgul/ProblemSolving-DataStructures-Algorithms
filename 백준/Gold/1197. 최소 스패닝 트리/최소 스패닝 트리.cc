#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <set>
#include <sstream>
#include <tuple>

using namespace std;

int parent[10002];
tuple<int, int, int> TEdge[100002];

int N, M;
long long ResultVal = 0;

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


    cin >> N >> M;

    fill(parent, parent + N, -1);


    int A, B, W;
    for (int i = 0; i < M; ++i)
    {
        cin >> A >> B >> W;
        TEdge[i] = make_tuple(W, A, B);
    }
    
    //tuple은 앞의 값을 기준으로 정렬을 수행한다.
    sort(TEdge, TEdge + M);

    int EdgeCnt = 0;

    for (int i = 0; i < M; ++i)
    {
        //Tuple 값 얻어오는 방식 : c++17부터 적용
        auto [W, A, B] = TEdge[i];

        if (uni(A, B) == false)
            continue;
        else
        {
            ResultVal += W;
            EdgeCnt++;
        }

        if (EdgeCnt == N - 1)
            break;
    }

    cout << ResultVal;
    return 0;
}
