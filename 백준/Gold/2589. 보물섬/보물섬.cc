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

//모든 육지 지점에서 거리 계산 BFS 수행 후 제일 멀리 떨어진 지점까지의 시간 따져보기
int N, M;

vector<vector<int>> Board;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int ReturnVal = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    Board.resize(N);

    string SB;
    for (int i = 0; i < N; ++i)
    {
        cin >> SB;
        for (char Check : SB)
        {
            //바다
            if (Check == 'W')
            {
                Board[i].push_back(1);
            }
            //육지
            else if (Check == 'L')
            {
                Board[i].push_back(0);
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            int Dis = 0;

            //육지인 경우, BFS 수행을 통해 제일 멀리 떨어진 거리 계산
            if (Board[i][j] == 0)
            {
                int Check[51][51] = { 0 };
                queue<pair<int,int>> Q;
                Q.push({ i,j });
                Check[i][j] = 1;

                while (!Q.empty())
                {
                    auto Cur = Q.front();
                    Q.pop();

                    for (int k = 0; k < 4; ++k)
                    {
                        int X = Cur.first + dx[k];
                        int Y = Cur.second + dy[k];

                        //범위를 벗어난 탐색
                        if (X < 0 || X >= N || Y < 0 || Y >= M)
                            continue;
                        //바다인 경우 탐색 불가
                        if (Board[X][Y] == 1)
                            continue;
                        //이미 탐색한 경우 탐색 불가
                        if (Check[X][Y] != 0)
                            continue;

                        Q.push({ X,Y });
                        Check[X][Y] = Check[Cur.first][Cur.second] + 1;
                        Dis = max(Check[X][Y]-1, Dis);
                    }
                }
            }
            ReturnVal = max(ReturnVal, Dis);
        }
    }

    cout << ReturnVal;
    return 0;
}