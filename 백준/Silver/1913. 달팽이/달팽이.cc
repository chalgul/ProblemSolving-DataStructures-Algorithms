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
#include <cmath>
using namespace std;

int N , M;

int Board[1000][1000];

struct Coord
{
    int X = 0;
    int Y = 0;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    //1 ~ N*N까지 표현하면 됨.


    //n == 3일 때 중심 1,1
    //n == 5일 때 중심 2,2
    //n == 7일 때 중심 3,3
    //n == 9일 때 중심 4,4

    Coord CenterPos = { (N - 1) / 2, (N - 1) / 2 };

    Board[CenterPos.X][CenterPos.Y] = 1;

    //위 1 오른 1 아래 2 왼 2 위 2

    //위 1 오른 3 아래 4 왼 4 위 4

    Coord Target = CenterPos;
    for (int i = 0; i < (N-1)/2; ++i)
    {
        //위
        Board[Target.X-1][Target.Y] = Board[Target.X][Target.Y] + 1;
        Target.X--;

        //오른
        for (int j = 0; j < 1 + i * 2; ++j)
        {
            Board[Target.X][Target.Y+1] = Board[Target.X][Target.Y] + 1;
            Target.Y++;
        }

        //아래
        for (int j = 0; j < 2 + i * 2; ++j)
        {
            Board[Target.X + 1][Target.Y] = Board[Target.X][Target.Y] + 1;
            Target.X++;
        }

        //왼
        for (int j = 0; j < 2 + i * 2; ++j)
        {
            Board[Target.X][Target.Y-1] = Board[Target.X][Target.Y] + 1;
            Target.Y--;
        }

        //위
        for (int j = 0; j < 2 + i * 2; ++j)
        {
            Board[Target.X-1][Target.Y] = Board[Target.X][Target.Y] + 1;
            Target.X--;
        }
    }


    Coord Temp;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (Board[i][j] == M)
                Temp = { i,j };

            cout << Board[i][j] << " ";
        }
        cout << "\n";
    }

    cout << Temp.X+1 << " " << Temp.Y+1;



    return 0;
}