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
#include <cmath>
#include <string>
using namespace std;

long long N, P, Q;

long long ReturnVal;

unordered_map<long long, long long> Memo;

//수가 1000억 이상 단위로 커져서 DP Table로 두는 것은 메모리가 부족할 듯
//재귀로 시도해보자.

//메모제이션이 필요한 듯
//어차피 1000억 단위의 모든 수열 값은 알 필요 없음
//P,Q에 의해 나눠지는 몫에 대한 값만 중복 계산하지 않게 하면 된다.

long long Recursion(long long Num)
{
    if (Num == 0)
        return 1;

    long long TempA = 0;
    long long TempB = 0;
    if (Memo.find(Num/P) != Memo.end())
    {
        TempA = Memo[Num / P];
    }
    else
    {
        Memo[Num / P] = Recursion(Num / P);
        TempA = Memo[Num / P];
    }
    if (Memo.find(Num/Q) != Memo.end())
    {
        TempB = Memo[Num / Q];
    }
    else
    {
        Memo[Num / Q] = Recursion(Num / Q);
        TempB = Memo[Num / Q];
    }

    return TempA + TempB;
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> N >> P >> Q;

    ReturnVal = Recursion(N);
    cout << ReturnVal;

    return 0;
}