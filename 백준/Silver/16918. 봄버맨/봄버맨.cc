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

int R, C, N;


//결국 폭탄의 설치 시점은 2개로 나뉜다.


//0 : 빈 공간 1 : 폭탄 그룹 1 2: 폭탄 그룹 2
int Board[202][202];

int TargetBomb = 2;


void Bomb(int X, int Y)
{
    Board[X][Y] = 0;

    if(X > 0 && Board[X-1][Y] != TargetBomb)
        Board[X - 1][Y] = 0;

    if(X < R-1 && Board[X + 1][Y] != TargetBomb)
        Board[X + 1][Y] = 0;

    if (Y > 0 && Board[X][Y - 1] != TargetBomb)
        Board[X][Y - 1] = 0;

    if (Y < C - 1 && Board[X][Y + 1] != TargetBomb)
        Board[X][Y + 1] = 0;
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> R >> C >> N;

    char Input;

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cin >> Input;

            if (Input == '.')
                Board[i][j] = 0;
            else
                Board[i][j] = 1;
        }
    }


    //i가 짝수면 새로운 폭탄 그룹 설치
    //i가 홀수면 과거에 설치한 폭탄 폭파

    if (N == 1)
    {
        for (int i = 0; i < R; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                if (Board[i][j] == 0)
                    cout << '.';
                else
                    cout << 'O';
            }

            cout << "\n";
        }

        return 0;
    }

    for (int i = 0; i < N-1; ++i)
    {
        //폭탄 설치
        if (i % 2 == 0)
        {
            for (int j = 0; j < R; ++j)
            {
                for (int k = 0; k < C; ++k)
                {
                    if (Board[j][k] == 0)
                        Board[j][k] = TargetBomb;
                }
            }

            if (TargetBomb == 2)
                TargetBomb = 1;
            else
                TargetBomb = 2;
        }
        //과거에 설치한 폭탄 폭파
        else
        {
            for (int j = 0; j < R; ++j)
            {
                for (int k = 0; k < C; ++k)
                {
                    if (Board[j][k] == TargetBomb)
                    {
                        Bomb(j, k);
                    }
                }
            }
        }
    }


    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            if (Board[i][j] == 0)
                cout << '.';
            else
                cout << 'O';
        }

        cout << "\n";
    }



    return 0;
    
}