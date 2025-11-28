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


//1~10^7의 범위 내에 모든 소수를 구한 다음
//각 소수들의 N제곱 연산


//에라토스테네스의 체

vector<int> PN;

bool Arr[10000002];


long long St, End;

long long Result = 0;


const long long LLMax = numeric_limits<long long>::max();

void PrimeNum()
{
    int Target = 2;
    while (Target * Target <= 10000000)
    {
        for (int i = Target * Target; i <= 10000000; i += Target)
        {
            Arr[i] = true;
        }
        Target++;
    }

    for (int i = 2; i <= 10000000; ++i)
    {
        if (Arr[i] == false)
        {
            PN.push_back(i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> St >> End;

    PrimeNum();
 

    long long Temp = 0;
    for (auto PrimeNumber : PN)
    {
        Temp = PrimeNumber;

        while (Temp <= End)
        {
            if ((LLMax / PrimeNumber) < Temp)
                break;

            Temp *= (long long)PrimeNumber;

            if (Temp >= St && Temp <= End)
                Result++;
        }
    }

    cout << Result;

    return 0;
}


