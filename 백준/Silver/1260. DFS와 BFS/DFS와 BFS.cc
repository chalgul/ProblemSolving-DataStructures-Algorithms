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

int N,M,V;

bool BFSVis[1002];
bool DFSVis[1002];
vector<int> ListNode[1002];

vector<int> DFSVisitedHis;
vector<int> BFSVisitedHis;

//Visit : 가장 처음 방문하는 정점
void DFS(int Visit)
{
    //해당 정점 방문
    DFSVis[Visit] = true;
    DFSVisitedHis.push_back(Visit);
    for (int Number : ListNode[Visit])
    {
        if (DFSVis[Number] == true)
            continue;
        DFS(Number);
    }
}




int main() {
   
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> V;

    //인접리스트 방식으로 그래프 표현
    int A = 0, B = 0;
    for (int i = 0; i < M; i++)
    {
        cin >> A >> B;
        ListNode[A].push_back(B);
        ListNode[B].push_back(A);
    }

    for (int i = 1; i <= N; i++)
    {
        sort(ListNode[i].begin(), ListNode[i].end());
    }

     
    DFS(V);
    for (int VisitNum : DFSVisitedHis)
    {
        cout << VisitNum << " ";
    }
    cout << "\n";

    queue<int> Q;
    Q.push(V);
    BFSVis[V] = true;
    

    BFSVisitedHis.push_back(V);
    while (!Q.empty())
    {
        int Cur = Q.front();
        Q.pop();

        for (int Node : ListNode[Cur])
        {
            if (BFSVis[Node] == true)
                continue;

            Q.push(Node);
            BFSVis[Node] = true;
            BFSVisitedHis.push_back(Node);
        }
    }

    for (int VisitNum : BFSVisitedHis)
    {
        cout << VisitNum << " ";
    }

    return 0;
}

