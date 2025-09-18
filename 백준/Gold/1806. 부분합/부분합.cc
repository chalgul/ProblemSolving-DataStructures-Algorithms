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

int N, S;

int ArrayInput[100002];


int main() {
   
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    cin >> N >> S;


    for (int i = 0; i < N; i++)
    {
        cin >> ArrayInput[i];
    }

    int Start = 0, End = -1;

    int Sum = 0;

    int MinLength = 100002;
    
    
    for (Start; Start < N; Start++)
    {

        while (Sum < S)
        {
            if (End < N)
            {
                End++;
                Sum += ArrayInput[End];
            }
            else
            {
                break;
            }
        }
        if (Sum >= S)
        {
            MinLength = min(MinLength, End - Start + 1);
        }
        Sum -= ArrayInput[Start];
    }


    if (MinLength == 100002)
    {
        cout << 0;
        return 0;
    }

    cout << MinLength;


    return 0;
}

