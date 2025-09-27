#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
//#include <string>
//#include <stack>
//#include <queue>
//#include <deque>
//#include <list>
//#include <functional>
//#include <unordered_map>
//#include <unordered_set>
//#include <set>
//#include <numeric>

using namespace std;

int N, K;


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    vector<int> Comb(N, 0);
    int Result = 1;

    for (int i = N-1; i >= N - K; i--)
    {
        Comb[i] = 1;
    }

    while (next_permutation(Comb.begin(), Comb.end()))
    {
        Result++;
    }

    cout << Result;

    return 0;
}

