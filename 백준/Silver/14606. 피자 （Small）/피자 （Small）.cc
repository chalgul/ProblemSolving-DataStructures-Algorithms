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

int N;

int ReturnVal;

//분할정복에서 분할만 하면 끝나는 문제

void Recursion(int Height)
{
    //분할 끝
    if (Height == 1)
    {
        return;
    }

    int Temp = Height / 2;
    int Temp2 = Height - Temp;
    ReturnVal += Temp * Temp2;
    Recursion(Temp);
    Recursion(Temp2);
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    Recursion(N);

    cout << ReturnVal;


    return 0;
}