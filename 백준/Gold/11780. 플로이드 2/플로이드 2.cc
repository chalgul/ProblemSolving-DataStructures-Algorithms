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
vector<vector<int>> Next;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    cin >> M;

    Dis.resize(N);
    Next.resize(N);
    for (int i = 0; i < N; ++i)
    {
        Dis[i].resize(N,99999999);
        Next[i].resize(N,99999999);
    }

    int A, B, C;

    //경유 불가능할 때 최단거리 테이블
    for (int i = 0; i < M; ++i)
    {
        cin >> A >> B >> C;
        if (Dis[A-1][B-1] > C)
        {
            Dis[A-1][B-1] = C;
            Next[A - 1][B - 1] = B - 1;
        }
    }
   
    for (int i = 0; i < N; ++i)
        Dis[i][i] = 0;


    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < N; ++k)
            {
                if (Dis[j][k] > Dis[j][i] + Dis[i][k])
                {
                    Dis[j][k] = Dis[j][i] + Dis[i][k];
                    Next[j][k] = Next[j][i];
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
            else
                cout << Dis[i][j] << " ";


        }
        cout << "\n";
    }

    
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int cnt = 0;
            queue<int> Q;
            if (Next[i][j] == 99999999)
                cout << 0 << "\n";
            else
            {
                int Temp = Next[i][j];
                Q.push(i + 1);
                while (Temp != j)
                {
                    Q.push(Temp + 1);
                    Temp = Next[Temp][j];
                }
                Q.push(Temp + 1);
                cout << Q.size() << " ";
                while (!Q.empty())
                {
                    cout << Q.front() << " ";
                    Q.pop();
                }
                cout << "\n";
            }
        }
    }

    return 0;
}
