#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <set>
#include <sstream>
#include <tuple>
#include <stack>
#include <algorithm>

using namespace std;

//3*N의 타일 수가 홀수인 경우에는 채울 수 있는 경우의 수가 0

int Table[31];




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Table[0] = 0;
    Table[1] = 0;
    Table[2] = 3;
    Table[4] = 11;

    for (int i = 6; i <= 30; i += 2)
    {
        Table[i] = Table[i - 2] * 4 - Table[i - 4];
    }

    int Input;

    cin >> Input;

    cout << Table[Input];



    return 0;
}