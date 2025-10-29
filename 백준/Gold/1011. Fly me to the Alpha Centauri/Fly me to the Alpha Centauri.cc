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
#include <numeric>
#include <tuple>
#include <sstream>
#include <map>
#include <cmath>
using namespace std;

int TestCase;


int Count(int Dis)
{
    int Result = 0;

    int Target = 1;

    while (Dis != 0)
    {
        if (Dis - (Target * 2) > 0)
        {
            Result += 2;
            Dis = Dis - (Target * 2);
            Target++;
        }
        else
        {
            if (Dis > Target)
            {
                Result += 2;
                return Result;
            }
            else
            {
                Result += 1;
                return Result;
            }
        }
    }
    return Result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> TestCase;

    int A, B;
    for (int i = 0; i < TestCase; ++i)
    {
        cin >> A >> B;

        int Dis = B - A;

        cout << Count(Dis) << "\n";
    }

    return 0;
}

