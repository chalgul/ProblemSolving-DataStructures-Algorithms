#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <functional>

using namespace std;

#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용

string board[1002] = {}; // 1이 익은 토마토 0이 덜 익은 토마토 -1이 빈 공간

int dis[1002][1002] = {}; // 시작 지점으로부터 각 칸에 대한 거리를 지정
//벽을 -1 , 불이 지나간 자리를 -2, 움직일 수 있는 공간이 0 , 플레이어의 dis를 계산

int n = 7, m = 10; // n = 행의 수, m = 열의 수

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // 상하좌우 네 방향을 의미
int Day = 2147483647;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    cin.ignore();


    queue<pair<int, int>> PlayerQ;
    queue<pair<int, int>> FireQ;
    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
    }
    //벽을 -1 , 불이 지나간 자리를 -2, 움직일 수 있는 공간이 0 , 플레이어의 dis를 계산
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == '#')
            {
                dis[i][j] = -1;
            }
            if (board[i][j] == 'J')
            {
                PlayerQ.push({ i,j });
                dis[i][j] = 1;
            }
            if (board[i][j] == 'F')
            {
                FireQ.push({ i,j });
                dis[i][j] = -2;
            }

        }
    }


    //벽을 -1 , 불이 지나간 자리를 -2, 움직일 수 있는 공간이 0 , 플레이어의 dis를 계산
    while (!FireQ.empty() || !PlayerQ.empty())
    {
        //불은 여러 지점에서 시작할 수 있다.
        if (!FireQ.empty()) {
            int SizeF = (int)FireQ.size();
            for (int i = 0; i < SizeF; i++) {
                pair<int, int> Fcur = FireQ.front(); FireQ.pop();
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = Fcur.X + dx[dir];
                    int ny = Fcur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue; // 범위 밖일 경우 넘어감
                    if (dis[nx][ny] != 0) //이미 불orPlayer가 지나갔던 자리이거나, 벽면인 경우에 대해서 continue 
                        continue;
                    dis[nx][ny] = -2;  //불이 지나간 자리에 대해서는 -2 할당
                    FireQ.push({ nx,ny });
                }
            }
        }
        if (!PlayerQ.empty()) {
            int SizeP = (int)PlayerQ.size();
            for (int j = 0; j < SizeP; j++) {
                pair<int, int> Pcur = PlayerQ.front(); PlayerQ.pop();
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = Pcur.X + dx[dir];
                    int ny = Pcur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue; // 범위 밖일 경우 넘어감
                    if (dis[nx][ny] != 0) //이미 불orPlayer가 지나갔던 자리이거나, 벽면인 경우에 대해서 continue 
                        continue;
                    dis[nx][ny] = dis[Pcur.X][Pcur.Y] + 1;  //상하좌우에 해당하는 노드의 경우 시작지점으로부터 큐에서 빠져나온 노드보다 +1 더 멀리 있을 것임.
                    PlayerQ.push({ nx,ny });
                }
            }
        }
    }
    
    
    //가장자리에 대한 체크

    for (int i = 0; i < m; i++)
    {

        if (Day > dis[0][i] && dis[0][i] > 0)
            Day = dis[0][i];

        if (Day > dis[n-1][i] && dis[n-1][i] > 0)
            Day = dis[n-1][i];

    }

    for (int i = 0; i < n; i++)
    {

        if (Day > dis[i][0] && dis[i][0] > 0)
            Day = dis[i][0];


        if (Day > dis[i][m-1] && dis[i][m-1] > 0)
            Day = dis[i][m-1];
    }

    if (Day == 2147483647) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << Day;  
    
    return 0;
}