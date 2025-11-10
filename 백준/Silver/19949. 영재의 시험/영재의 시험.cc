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

int ReturnVal;

vector<int> Solution;

int Mark[11];

void Recursion(int Depth)
{
    if (Depth == 11)
    {
        int Cor = 0;
        //답과 일치하는지 check
        for (int i = 1; i <= 10; ++i)
        {
            if (Mark[i] == Solution[i - 1])
            {
                Cor++;
            }
        }
        if (Cor >= 5)
            ReturnVal++;
        return;
    }


    for (int i = 1; i <= 5; ++i)
    {
        if (Depth > 2)
        {
            if (Mark[Depth - 2] == Mark[Depth - 1] && Mark[Depth - 1] == i)
                continue;
        }

        Mark[Depth] = i;
        Recursion(Depth + 1);
        Mark[Depth] = -1;
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int Sol;
    for (int i = 0; i < 10; ++i)
    {
        cin >> Sol;
        Solution.push_back(Sol);
    }

    Recursion(1);
    cout << ReturnVal;

    return 0;
}