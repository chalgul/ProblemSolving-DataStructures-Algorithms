#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <set>
#include <sstream>
#include <tuple>

using namespace std;

int N, M;

vector<vector<int>> Dis;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    cin >> M;

    Dis.resize(N);
    for (int i = 0; i < N; ++i)
    {
        Dis[i].resize(N,99999999);
    }

    int A, B, C;

    //경유 불가능할 때 최단거리 테이블
    for (int i = 0; i < M; ++i)
    {
        cin >> A >> B >> C;
        if (Dis[A-1][B-1] > C)
        {
            Dis[A-1][B-1] = C;
        }
    }
   

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < N; ++k)
            {
                if (Dis[j][k] > Dis[j][i] + Dis[i][k])
                {
                    Dis[j][k] = Dis[j][i] + Dis[i][k];
                }
            }
        }
    }


    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (Dis[i][j] == 99999999)
                cout << 0 << " ";
            else if (i == j)
                cout << 0 << " ";
            else
                cout << Dis[i][j] << " ";


        }
        cout << "\n";
    }





    return 0;
}
