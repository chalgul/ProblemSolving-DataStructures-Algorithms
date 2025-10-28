#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <set>
#include <sstream>
#include <tuple>
#include <stack>
#include <algorithm>

using namespace std;

int N;

vector<vector<pair<int, int>>> GList;


vector<bool> Check;

int Result = 0;
int ResultNode = 0;

int Weight = 0;

void DFS(int Cur, int W)
{
    Check[Cur] = true;
    Weight += W;

    bool IsLeaf = true;

    for (auto Node : GList[Cur])
    {
        if (Check[Node.second] == false)
        {
            IsLeaf = false;
            DFS(Node.second, Node.first);
        }
    }

    if (Result < Weight)
    {
        Result = Weight;
        ResultNode = Cur;
    }
    Weight -= W;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    GList.resize(N + 1);
    Check.resize(N + 1, false);

    int A, B, W;
    for (int i = 0; i < N - 1; ++i)
    {
        cin >> A >> B >> W;

        GList[A].push_back({W,B});
        GList[B].push_back({W,A});
    
    }

    DFS(1, 0);
    int Temp = Result;
    Result = 0;
    Weight = 0;
    fill(Check.begin(), Check.end(), false);
    DFS(ResultNode, 0);


    cout << Result;

    return 0;
}