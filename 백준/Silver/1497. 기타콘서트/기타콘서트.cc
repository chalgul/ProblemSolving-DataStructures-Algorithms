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

int N, M;

vector<long long> Guitar;

int Result = 0;
int ReturnVal = 10000;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    string Name;
    string State;
    for (int i = 0; i < N; ++i)
    {
        cin >> Name >> State;

        long long Size = (int)State.size();

        long long Masking = 0;

        for (long long i = Size - 1; i >= 0; --i)
        {
            if (State[i] == 'Y')
            {
                Masking += ((long long)1 << i);
            }
        }
        Guitar.push_back(Masking);
    }

    //기타 사용 경우의 수
    for (int i = 0; i < (1 << N); ++i)
    {
        //악기 연주 여부
        long long PlayingState = 0;

        //구매할 기타 개수
        int GCount = 0;
        for (int j = 0; j < N; ++j)
        {
            //j번째 인덱스에 있는 기타 사용
            if (i & (1 << j))
            {
                PlayingState |= Guitar[j];
                GCount++;
            }
        }

        //연주에 성공한 음악 개수
        int Count = 0;
        for (int j = 0; j < M; ++j)
        {
            if (PlayingState & ((long long)1 << j))
            {
                Count++;
            }
        }
        
        //연주할 수 있는 음악의 개수가 더 늘어난 경우
        if (Count > Result)
        {
            ReturnVal = GCount;
            Result = Count;
        }
        else if (Count == Result)
        {
            ReturnVal = min(GCount, ReturnVal);
        }
    }

    if (ReturnVal == 0)
        cout << -1;
    else
        cout << ReturnVal;

    return 0;
}