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
#include <set>
using namespace std;

int N, M;

int ArrayN[100002];

int main() {
   
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    cin >> N >> M;
   

    for (int i = 0; i < N; i++)
    {
        cin >> ArrayN[i];
    }


    sort(ArrayN, ArrayN + N);


    int Start = 0, End = 0;
    int Min = 2000000002;

    for (Start; Start < N; Start++)
    {
        while (End < N && ArrayN[End] - ArrayN[Start] < M)
        {
            End++;
        }
        if (End == N)
            break;
        Min = min(Min, ArrayN[End] - ArrayN[Start]);
    }



    cout << Min;




    return 0;
}

