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
using namespace std;

int N, K;

vector<long long> Drink;

long long ReturnVal = 0;

//한 번 호출할 때마다 1만번 연산 수행
long long Check(long long Candidate)
{
    if (Candidate == 0)
        return 9999999999;


    long long Temp = 0;
    for (auto D : Drink)
    {
        Temp += D / Candidate;
    }

    return Temp;
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    long long Input = 0;
    long long Total = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> Input;
        Drink.push_back(Input);
        Total += Input;
    }


    long long Low = 0;
    long long High = Total / K;
    long long Mid = 0;

    while (Low <= High)
    {
        Mid = (Low + High) / 2;

        long long Temp = Check(Mid);

        //막걸리를 나눠줄 수 있는 분배양임
        //그렇지만 정답 후보일 뿐 더 많이 나눠줄 가능성도 존재
        if (Temp >= K)
        {
            ReturnVal = Mid;
            Low = Mid + 1;
        }
        //이것보다는 적게 나눠줘야 분배 가능
        else
        {
            High = Mid - 1;
        }
    }

    cout << ReturnVal;
    return 0;
}