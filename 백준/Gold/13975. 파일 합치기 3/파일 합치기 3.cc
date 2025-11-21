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



//매번 가장 작은 2개의 값을 합쳐나가면 최소값이 나오는 듯?

int TestCase;

int Pages;

priority_queue<long long, vector<long long>, greater<long long>> PQ;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> TestCase;

    for (int i = 0; i < TestCase; ++i)
    {
        cin >> Pages;
        long long Input;
        long long Result = 0;
        for (int j = 0; j < Pages; ++j)
        {
            cin >> Input;
            PQ.push(Input);
        }

        while (PQ.size() != 1)
        {
            long long A = PQ.top();
            PQ.pop();
            long long B = PQ.top();
            PQ.pop();
            Result += A + B;
            PQ.push(A + B);
        }

        cout << Result << "\n";
        PQ.pop();
    }

    return 0;
}