#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <list>
#include <queue>
#include <unordered_map>

using namespace std;

int N, M;

vector<vector<int>> Line;

bool Vis[102];

int ResultVal = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    Line.resize(N+1);

    int St = 0, En = 0;
    //인접리스트 방식으로 무방향 그래프 표현
    for (int i = 0; i < M; ++i)
    {
        cin >> St >> En;
        Line[St].push_back(En);
        Line[En].push_back(St);
    }


    queue<int> Q;
    Q.push(1);
    Vis[1] = true;

    while (!Q.empty())
    {
        int Cur = Q.front();
        Q.pop();


        for (int i = 0; i < Line[Cur].size(); ++i)
        {
            if (Vis[Line[Cur][i]] == true)
                continue;
            Vis[Line[Cur][i]] = true;
            Q.push(Line[Cur][i]);
            ++ResultVal;
        }
    }

    cout << ResultVal;

    return 0;
}
