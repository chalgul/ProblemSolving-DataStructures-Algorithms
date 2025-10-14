#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <set>
#include <sstream>
using namespace std;

int N;

int LC[28];
int RC[28];

void PreOrder(int Cur)
{
    char Temp;
    Temp = Cur + 'A';
    cout << Temp;
    if(LC[Cur] != '.' - 'A')
        PreOrder(LC[Cur]);
    if(RC[Cur] != '.' - 'A')
        PreOrder(RC[Cur]);
}

void InOrder(char Cur)
{
    if(LC[Cur] != '.' - 'A')
        InOrder(LC[Cur]);
    char Temp;
    Temp = Cur + 'A';
    cout << Temp;
    if(RC[Cur] != '.' - 'A')
        InOrder(RC[Cur]);
}

void PostOrder(int Cur)
{
    if(LC[Cur] != '.' - 'A')
        PostOrder(LC[Cur]);
    if(RC[Cur] != '.' - 'A')
        PostOrder(RC[Cur]);
    char Temp;
    Temp = Cur + 'A';
    cout << Temp;
}




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    char Node, L, R;

    for (int i = 0; i < N; ++i)
    {
        cin >> Node >> L >> R;

        LC[Node - 'A'] = L - 'A';
        RC[Node - 'A'] = R - 'A';
    }

    PreOrder(0);
    cout << "\n";
    InOrder(0);
    cout << "\n";
    PostOrder(0);

    return 0;
}