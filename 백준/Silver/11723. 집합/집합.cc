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

int M;

int State = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M;


    string CMD;
    int Num;

    for (int i = 0; i < M; ++i)
    {
        cin >> CMD;

        if (CMD == "add")
        {
            cin >> Num;
            State |= (1 << (Num - 1));
        }
        else if (CMD == "remove")
        {
            cin >> Num;
            State &= ~(1 << (Num - 1));
        }
        else if (CMD == "check")
        {
            cin >> Num;
            cout << ((State & (1 << (Num - 1))) > 0) << "\n";
        }
        else if (CMD == "toggle")
        {
            cin >> Num;
            State ^= (1 << (Num - 1));
        }
        else if (CMD == "all")
        {
            State = 0xFFFFFFFF;
        }
        else if (CMD == "empty")
        {
            State = 0;
        }
    }


    return 0;
}