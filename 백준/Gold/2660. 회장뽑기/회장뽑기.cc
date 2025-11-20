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

int Distance[52][52];

//모든 간선의 가중치가 1인 플로이드-워셜 알고리즘 

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;


    int A, B;

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; ++j)
        {
            Distance[i][j] = 99999;
        }
    }


    for (int i = 0; i <= N; ++i)
    {
        Distance[i][i] = 0;
    }

    while (true)
    {
        cin >> A >> B;

        if (A == -1)
            break;

        Distance[A][B] = 1;
        Distance[B][A] = 1;
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            for (int k = 1; k <= N; ++k)
            {
                if(Distance[j][i] != 99999 || Distance[i][k] != 99999)
                    Distance[j][k] = min(Distance[j][k],Distance[j][i] + Distance[i][k]);
            }
        }
    }

    int ResultMinDis = 60;
    vector<int> Candi;

    for (int i = 1; i <= N; ++i)
    {
        int MaxDis = 0;
        for (int j = 1; j <= N; ++j)
        {
            MaxDis = max(Distance[i][j], MaxDis);
        }


        if (MaxDis < ResultMinDis)
        {
            Candi.clear();
            Candi.push_back(i);
            ResultMinDis = MaxDis;
        }
        else if (MaxDis == ResultMinDis)
        {
            Candi.push_back(i);
        }

    }


    cout << ResultMinDis << " " << Candi.size() << "\n";
    for (auto C : Candi)
    {
        cout << C << " ";
    }
    cout << "\n";


    return 0;
    
}