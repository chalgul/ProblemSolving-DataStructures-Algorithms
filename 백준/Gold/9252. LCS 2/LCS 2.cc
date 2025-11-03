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



string S1, S2;

int Table[1002][1002];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> S1 >> S2;

    int Size1 = (int)S1.size();
    int Size2 = (int)S2.size();
  
    //DP를 통해 LCS 최장 길이 구하기
    for (int i = 1; i <= Size1; ++i)
    {
        for (int j = 1; j <= Size2; ++j)
        {
            if (S1[i - 1] == S2[j - 1])
            {
                Table[i][j] = Table[i - 1][j - 1] + 1;
            }
            else
            {
                Table[i][j] = max(Table[i - 1][j], Table[i][j - 1]);
            }
        }
    }

    cout << Table[Size1][Size2] <<"\n";


    int X = Size1;
    int Y = Size2;

    string LCS = "";

    //역추적
    while (X > 0 && Y > 0)
    {
        if (S1[X-1] == S2[Y-1])
        {
            LCS = S1[X-1] + LCS;
            X--;
            Y--;
        }
        else
        {
            if (Table[X - 1][Y] > Table[X][Y - 1])
            {
                X--;
            }
            else
            {
                Y--;
            }
        }
    }

    if(!LCS.empty())
        cout << LCS;


    return 0;
}