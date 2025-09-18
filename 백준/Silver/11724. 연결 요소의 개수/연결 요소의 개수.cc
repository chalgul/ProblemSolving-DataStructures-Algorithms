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
#include <set>
using namespace std;

int N, M;

bool Vis[1002];
vector<int> ListNode[1002];


int main() {
   
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;


    //무방향 그래프의 인접 리스트 표현 방식
    int A = 0, B = 0;
    for (int i = 0; i < M; i++)
    {
        cin >> A >> B;
        ListNode[A].push_back(B);
        ListNode[B].push_back(A);
    }


    queue<int> Q;
    int Count = 0;
    for (int i = 1; i <= N; i++)
    {
        if (Vis[i] == false)
        {
            Q.push(i);
            Vis[i] = true;
            Count++;
        }
        else
            continue;

        while (!Q.empty())
        {
            int Cur = Q.front();
            Q.pop();

            for (int Node : ListNode[Cur])
            {
                //이미 방문한 노드는 방문 X
                if (Vis[Node] == true)
                {
                    continue;
                }

                Q.push(Node);
                Vis[Node] = true;
            }
        }
    }

    cout << Count;

    return 0;
}

