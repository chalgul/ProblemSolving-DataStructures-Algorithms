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

using namespace std;

int N, M;

int Board[50][50];

int dx[4] = {-1,0,1,0};
int dy[4] = { 0,1,0,-1 };

bool Check[50][50] = { false };

struct Coord
{
    int x = 0;
    int y = 0;
};

Coord Start;

bool Cycle = false;

//depth가 4보다 큰 상태에서 시작 지점 위치를 만나게 되면 사이클이 성립하지 않을까..
void DFS(Coord Target,int Depth, int RoadInfo)
{

    Check[Target.x][Target.y] = true;

    for (int i = 0; i < 4; ++i)
    {
        Coord NewNode;

        NewNode.x = Target.x + dx[i];
        NewNode.y = Target.y + dy[i];

        //범위 벗어남
        if (NewNode.x < 0 || NewNode.x >= N || NewNode.y < 0 || NewNode.y >= M)
            continue;
        
        //진행 불가
        if (Board[NewNode.x][NewNode.y] != RoadInfo)
            continue;

        //사이클 존재
        if (Check[NewNode.x][NewNode.y] == true && NewNode.x == Start.x && NewNode.y == Start.y && Depth >= 3)
        {
            Cycle = true;
        }

        //이미 방문했으면 continue
        if (Check[NewNode.x][NewNode.y] == true)
            continue;

        DFS(NewNode, Depth + 1, RoadInfo);
    }

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    char Input;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> Input;
            Board[i][j] = Input - 'A';
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            memset(Check, 0, sizeof(Check));
            Start.x = i;
            Start.y = j;
            DFS(Start, 1, Board[i][j]);

            if (Cycle == true)
            {
                cout << "Yes";
                return 0;
            }
        }
    }

    cout << "No";

    return 0;
}