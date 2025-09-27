#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
//#include <string>
//#include <stack>
//#include <queue>
//#include <deque>
//#include <list>
//#include <functional>
//#include <unordered_map>
//#include <unordered_set>
//#include <set>
//#include <numeric>

using namespace std;

int N, K;

//icj 를 10007로 나눈 값 저장
int Table[1002][1002];


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;


    Table[1][0] = 1;
    Table[1][1] = 1;

    //Table[i][j] = Table[i-1][j] + Table[i-1][j-1]
    for (int i = 2; i <= N; i++)
    {
        Table[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            Table[i][j] = Table[i - 1][j] + Table[i - 1][j - 1];
            Table[i][j] %= 10007;
        }
    }

    cout << Table[N][K];

    return 0;
}

