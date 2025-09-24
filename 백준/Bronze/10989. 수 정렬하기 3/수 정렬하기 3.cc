#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <list>
#include <queue>
#include <unordered_map>

using namespace std;


int N;
int Arr[10002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int Num;
    for (int i = 0; i < N; ++i)
    {
        cin >> Num;
        Arr[Num]++;
    }


    for (int i = 1; i <= 10000; i++)
    {
        while (Arr[i])
        {
            cout << i << "\n";
            Arr[i]--;
        }
    }

    return 0;
}
