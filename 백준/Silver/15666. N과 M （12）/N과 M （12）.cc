#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <set>

using namespace std;


int N, M;

int Size = 0;

int Array[10];

int SelectArray[10];


void Recursion(int Level, int Start)
{
    if (Level == M)
    {
        for (int i = 0; i < M; ++i)
        {
            cout << SelectArray[i] << " ";
        }
        cout << "\n";
        return;
    }

    int St = 0;

    if (Level != 0)
    {
        St = Start;
    }


    for (St; St < Size; ++St)
    {
        if (Array[St] >= Array[Start])
        {
            SelectArray[Level] = Array[St];
            Recursion(Level + 1, St);
        }
    }
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    set<int> S;

    int Input = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> Input;

        S.insert(Input);
    }

    int Index = 0;
    for (int Num : S)
    {
        Array[Index] = Num;
        Index++;
        Size++;
    }

    
    Recursion(0, 0);

    return 0;
}