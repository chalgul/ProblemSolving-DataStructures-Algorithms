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


int TestCase;

int N;

vector<int> Arr;

//n번째 숫자까지의 누적합
vector<int> Prefix_Sum;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> TestCase;

    for (int i = 0; i < TestCase; ++i)
    {
        cin >> N;
        int Input;
        int MaxVal = -99999999;
        Prefix_Sum.clear();
        Prefix_Sum.resize(N+1,0);
        for (int i = 0; i < N; ++i)
        {
            cin >> Input;
            Arr.push_back(Input);
            Prefix_Sum[i+1] = Prefix_Sum[i] + Input;
        }

        //구간의 수
        for (int i = 1; i <= N; ++i)
        {
            //시작 지점
            for (int j = 1; j <= N - i + 1; j++)
            {
                MaxVal = max(MaxVal, Prefix_Sum[j + i - 1] - Prefix_Sum[j - 1]);
            }
        }

        cout << MaxVal << "\n";
    }


    

    return 0;
}