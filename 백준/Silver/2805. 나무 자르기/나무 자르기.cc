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

using namespace std;

int N;
long long M;

vector<long long> Trees;

long long ReturnVal = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    long long Length;
    for (int i = 0; i < N; ++i)
    {
        cin >> Length;
        Trees.push_back(Length);
    }

    sort(Trees.begin(), Trees.end());

    long long Low = 0;
    long long High = Trees[N - 1];
    long long Cut = 0;

    while (Low <= High)
    {
        Cut = ((Low + High) / 2);

        long long TotalLength = 0;
        
        for (int i = 0; i < N; ++i)
        {
            if(Trees[i] - Cut > 0)
                TotalLength += (Trees[i] - Cut);
        }

        //정답이 될 수 있는 후보
        if (TotalLength > M)
        {
            ReturnVal = Cut;
            Low = Cut + 1;
        }
        else if(TotalLength < M)
        {
            High = Cut - 1;
        }
        else
        {
            ReturnVal = Cut;
            break;
        }

    }


    cout << ReturnVal;

    return 0;
}