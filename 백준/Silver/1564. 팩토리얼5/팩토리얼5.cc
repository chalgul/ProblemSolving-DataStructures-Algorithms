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

long long N;

long long ReturnVal;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    long long Result = 1;

    long long Temp = 1;

    long long Cnt2 = 0;
    long long Cnt5 = 0;

    while (Temp != N+1)
    {
        Result *= Temp;

        while (Result % 2 == 0)
        {
            Result /= 2;
            Cnt2++;
        }

        while (Result % 5 == 0)
        {
            Result /= 5;
            Cnt5++;
        }

        Result %= 100000;
      
        Temp++;
    }

    for (long long i = 0; i < Cnt2 - Cnt5; ++i)
    {
        Result *= 2;
        Result %= 100000;
        
    }


    string A  = to_string(Result);

    if (A.size() > 5)
    {
       unsigned int Temp = A.size() - 5;
       A = A.substr(Temp, 5);
       cout << A;
    }
    else
    {
        long long Temp = 5 - A.size();
        for (int i = 0; i < Temp; ++i)
        {
            cout << 0;
        }
        cout << A;
    }
    

    return 0;
}