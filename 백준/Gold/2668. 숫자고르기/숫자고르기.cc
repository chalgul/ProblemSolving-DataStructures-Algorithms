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
#include <tuple>
#include <sstream>
#include <numeric>
#include <map>
#include <cmath>
using namespace std;

int N;

int Cnt = 0;
vector<int> Selects;

vector<vector<int>> GList;

//-1 : 방문 X , 1 : 현재 스택 프레임에서 방문이 누적된 상태
vector<int> Check;

vector<int> Store;

set<int> Answer;

void DFS(int Target, int Start)
{
    Check[Target] = 1;
    Store.push_back(Target);

    for (auto Node : GList[Target])
    {
        //사이클 발생
        if (Check[Node] == 1 && Node == Start)
        {
            for (auto Node : Store)
            {
                Answer.insert(Node);
            }
        }
        else if(Check[Node] == -1)
        {
            DFS(Node, Start);
        }
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int Input = 0;
    GList.resize(N + 1);
    Check.resize(N + 1, -1);

    for (int i = 0; i < N; ++i)
    {
        cin >> Input;
        GList[i + 1].push_back(Input);
    }
    
    for (int i = 1; i <= N; ++i)
    {
        Check.resize(N + 1, -1);
        DFS(i, i);
        Check.clear();
        Store.clear();
    }


    cout << Answer.size() << "\n";

    for (auto Val : Answer)
    {
        cout << Val << "\n";
    }

    return 0;
}


