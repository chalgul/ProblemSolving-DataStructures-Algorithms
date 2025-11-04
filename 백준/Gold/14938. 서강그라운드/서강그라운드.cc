#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <set>
#include <sstream>
#include <tuple>
#include <stack>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using namespace std;



int N, M, R;

int Distance[101][101];

vector<int> Items;

const int INF = 999999;

int ReturnVal = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> R;

    for (int i = 0; i < N; ++i)
    {
        fill(Distance[i], Distance[i] + N, INF);
    }
    for (int i = 0; i < N; ++i)
    {
        Distance[i][i] = 0;
    }

    int ItemCnt;
    for (int i = 0; i < N; ++i)
    {
        cin >> ItemCnt;
        Items.push_back(ItemCnt);
    }

    int a, b, c;
    for (int i = 0; i < R; ++i)
    {
        cin >> a >> b >> c;
        Distance[a-1][b-1] = c;
        Distance[b-1][a-1] = c;
    }

    //i구역을 경유 가능하게 변경
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < N; ++k)
            {
                if (Distance[j][k] > Distance[j][i] + Distance[i][k])
                {
                    Distance[j][k] = Distance[j][i] + Distance[i][k];
                }
            }
        }
    }


    for (int i = 0; i < N; ++i)
    {
        int TempItemCounts = 0;
        for (int j = 0; j < N; ++j)
        {
            //i에 낙하산을 피고 내린다음 j 구역에 도달하는 것이 수색범위 내에 있는 경우
            if (Distance[i][j] <= M)
            {
                TempItemCounts += Items[j];
            }
        }
        ReturnVal = max(ReturnVal, TempItemCounts);
    }

    cout << ReturnVal;

    return 0;
}