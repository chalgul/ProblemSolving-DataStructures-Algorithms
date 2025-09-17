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
        int Start = 0, End = N - 1, Middle = (Start + End) / 2;

        while (End >= Start)
        {
            if (ArrayN[Middle] == ArrayM[i])
            {
                cout << 1 << "\n";
                break;
            }
            else if (ArrayN[Middle] > ArrayM[i])
            {
                End = Middle - 1;
            }
            else if (ArrayN[Middle] < ArrayM[i])
            {
                Start = Middle + 1;
            }

            Middle = (Start + End) / 2;
        }

        if (End < Start)
        {
            cout << 0 << "\n";
        }
    }

    return 0;
}

