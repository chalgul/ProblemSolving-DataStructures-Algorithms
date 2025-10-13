#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <set>
#include <sstream>
using namespace std;

int N, M;


//어느 벽을 부술 지 결정하는 것이 핵심
//모든 벽을 하나씩 다 부셔보면서 완전탐색하는건 시간초과다.


//우선 상하좌우 벽으로 둘러 쌓인 벽은 부술 필요 X
//특정 벽을 부셨을 때, 해당 벽을 기점으로 나아갈 길이 없는 벽도 부술 필요 X


int Board[1002][1002];

int MinDistance = 99999999;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

//x : 행 y : 열 z : 벽 부쉈는지 여부
int Distance[1002][1002][2];
int BFS()
{
    queue<pair<pair<int,int>,int>> Q;
    Q.push({ { 0,0 },0 });


    Distance[0][0][0] = 1;

    while (!Q.empty())
    {
        auto Cur = Q.front();
        
        Q.pop();
        

        int Wall = Cur.second;

        if (Cur.first.first == N-1 && Cur.first.second == M-1)
            return Distance[N - 1][M - 1][Cur.second];


        for (int i = 0; i < 4; i++)
        {
            int X = Cur.first.first + dx[i];
            int Y = Cur.first.second + dy[i];

            //벗어난 범위는 check X
            if (X < 0 || X >= N || Y < 0 || Y >= M)
                continue;

            //벽이 아닌 활로가 있는 경우
            if (Board[X][Y] == 0 && Distance[X][Y][Wall] == 0)
            {
                Distance[X][Y][Wall] = Distance[Cur.first.first][Cur.first.second][Cur.second] + 1;
                Q.push({ {X,Y},Wall });
            }
            //벽이 있고 아직 벽을 부수지 않은 경우
            else if (Board[X][Y] == 1 && Wall == 0)
            {
                Distance[X][Y][Wall+1] = Distance[Cur.first.first][Cur.first.second][Cur.second] + 1;
                Q.push({ {X,Y},Wall+1});
            }
        }
    }

    return -1;
}





int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    string Input;
    for (int i = 0; i < N; ++i)
    {
        cin >> Input;
        for (int j = 0; j < Input.size(); ++j)
        {
            Board[i][j] = Input[j] - '0';
        }   
    }


    cout << BFS();


    return 0;
}