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
#include <set>
using namespace std;


int N, M;

int ArrayN[1000002];
int ArrayM[1000002];



int main() {
   
    ios::sync_with_stdio(0);
    cin.tie(0);

   
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> ArrayN[i];
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> ArrayM[i];
    }

    sort(ArrayN, ArrayN + N);
    

    for (int i = 0; i < M; i++)
    {
        cout << upper_bound(ArrayN, ArrayN + N, ArrayM[i]) - lower_bound(ArrayN, ArrayN + N, ArrayM[i]) << " ";
    }

    return 0;
}

