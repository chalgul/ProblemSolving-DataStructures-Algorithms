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



//7이라는 숫자를 4개의 수로 표현해야되면

//(6이라는 숫자를 3개의 수로 표현 + 1) + (5라는 숫자를 3개의 수로 표현 + 2) + (4라는 숫자를 3개의 수로 표현 + 3)


int TestCase;

long long Table[1001][1001];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> TestCase;


    Table[1][1] = 1;
    Table[2][1] = 1;
    Table[2][2] = 1;
    Table[3][1] = 1;
    Table[3][2] = 2;
    Table[3][3] = 1;


    for (int i = 4; i <= 1000; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            Table[i][j] = ((Table[i - 1][j - 1] + Table[i - 2][j - 1] + Table[i - 3][j - 1]) % 1000000009);
        }
    }


    int A, B;
    for (int i = 0; i < TestCase; ++i)
    {
        cin >> A >> B;
        cout << Table[A][B];
        cout << "\n";
    }

    return 0;
}