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



int Table[1002][1002];


string S1, S2;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> S1 >> S2;

    int Size1 = (int)S1.size();
    int Size2 = (int)S2.size();


    for (int i = 0; i <= Size1; ++i)
    {
        Table[i][0] = 0;
    }
    for (int i = 0; i <= Size2; ++i)
    {
        Table[0][i] = 0;
    }


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

    cout << Table[Size1][Size2];


    //LCS 문자열 역추적하기
    //int x, y;
    //x = Size1;
    //y = Size2;
    //stack<char> LCS;
    //while (x > 0 && y > 0)
    //{
    //    if (S1[x - 1] == S2[y - 1])
    //    {
    //        LCS.push(S1[x - 1]);
    //        x--;
    //        y--;
    //    }
    //    else
    //    {
    //        if (Table[x - 1][y] > Table[x][y - 1])
    //        {
    //            x--;
    //        }
    //        else
    //        {
    //            y--;
    //        }
    //    }
    //}

    //while (!LCS.empty())
    //{
    //    cout << LCS.top();
    //    LCS.pop();
    //}




    return 0;
}