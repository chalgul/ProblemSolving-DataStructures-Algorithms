#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <list>
#include <queue>
#include <unordered_map>

using namespace std;

int N , M;

int DefaultArray[10];
int SelectArray[10];

void Recursion(int Level)
{
    if (Level == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << SelectArray[i] << " ";
        }
        cout << "\n";
        return;
    }

    int st = 0;
    if (Level != 0)
    {
        st = SelectArray[Level - 1];
    }
    for (int i = 0; i < N; i++)
    {
        if (DefaultArray[i] >= st)
        {
            SelectArray[Level] = DefaultArray[i];
            Recursion(Level + 1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> DefaultArray[i];
    }

    sort(DefaultArray, DefaultArray + N);

    Recursion(0);


    return 0;
}
