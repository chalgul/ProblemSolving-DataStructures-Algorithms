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



string S1, S2, S3;

// 각 문자열의 x,y,z번째까지 존재한다고 가정했을 때 LCS 길이
int Table[102][102][102];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> S1 >> S2 >> S3;

    int Size1 = (int)S1.size();
    int Size2 = (int)S2.size();
    int Size3 = (int)S3.size();
  
    for (int i = 1; i <= Size1; ++i)
    {
        for (int j = 1; j <= Size2; ++j)
        {
            for (int k = 1; k <= Size3; ++k)
            {
                if (S1[i - 1] == S2[j - 1] && S2[j - 1] == S3[k - 1])
                {
                    Table[i][j][k] = Table[i - 1][j - 1][k - 1] + 1;
                }
                else
                {
                    Table[i][j][k] = max(Table[i - 1][j][k], Table[i][j - 1][k]);
                    Table[i][j][k] = max(Table[i][j][k], Table[i][j][k-1]);
                }
            }
        }
    }

    cout << Table[Size1][Size2][Size3];
   
    return 0;
}