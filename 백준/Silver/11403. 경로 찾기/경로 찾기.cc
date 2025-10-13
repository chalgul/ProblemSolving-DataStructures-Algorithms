#include <iostream>
#include <queue>
#include <functional>
#include <vector>

using namespace std;

//최대 정점의 개수가 100개
//인접행렬로 표현했을 때 bfs 1번 탐색마다 걸리는 시간복잡도 10000
//100번의 bfs -> 100 * 10000 = 백만회 연산 -> 여유있음


int N;
int GArray[102][102];


bool BFS(int X, int Y)
{
    queue<int> Q;

    bool Check[102] = { false };

    Q.push(X);


    while (!Q.empty())
    {
        int Cur = Q.front();
        Q.pop();
        for (int i = 0; i < N; ++i)
        {
            //지나가지 않은 길 존재
            if (GArray[Cur][i] == 1 && Check[i] == false)
            {
                Check[i] = true;
                Q.push(i);

                if (i == Y)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int Input = 0;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> Input;
            GArray[i][j] = Input;
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (BFS(i , j))
            {
                cout << 1 << " ";
            }
            else
            {
                cout << 0 << " ";
            }
        }
        cout << "\n";
    }





    return 0;
}