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

vector<vector<int>> Board;

int N , M;

//1,1부터  x,y 까지의 전체 합
int Table[1025][1025];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    Board.resize(N);


    for (int i = 0; i < N; ++i)
    {
        int Input;
        for (int j = 0; j < N; ++j)
        {
            cin >> Input;
            Board[i].push_back(Input);
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            Table[i][j] = Table[i - 1][j] + Table[i][j - 1] - Table[i - 1][j - 1] + Board[i - 1][j - 1];
        }
    }

    int  x1, y1, x2, y2;
    for (int i = 0; i < M; ++i)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << Table[x2][y2] - Table[x2][y1-1] - Table[x1-1][y2] + Table[x1-1][y1-1] << "\n";
    }
 

    return 0;
}