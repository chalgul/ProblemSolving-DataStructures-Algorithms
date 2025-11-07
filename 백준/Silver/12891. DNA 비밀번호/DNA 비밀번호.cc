#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <set>
#include <sstream>
#include <tuple>
#include <stack>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <cmath>
using namespace std;

int S, P;

string DNA;

vector<int> PW;

int ReturnVal = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> S >> P;

    cin >> DNA;

    int Input = 0;
    for (int i = 0; i < 4; ++i)
    {
        cin >> Input;
        PW.push_back(Input);
    }

    int St = 0;
    int End = P-1;

    int A = 0, C = 0, G = 0, T = 0;
    int StValue = DNA[St] - 'A';
    int EndValue = DNA[End] - 'A';
    for (int i = St; i <= End; ++i)
    {
        if (DNA[i] == 'A')
            A++;
        else if (DNA[i] == 'C')
            C++;
        else if (DNA[i] == 'G')
            G++;
        else if (DNA[i] == 'T')
            T++;
    }

    if (A >= PW[0] && C >= PW[1] && G >= PW[2] && T >= PW[3])
    {
        ReturnVal++;
    }

    while (End != (S-1))
    {
        
        if (StValue == 0)
            A--;
        else if (StValue == 'C' - 'A')
            C--;
        else if (StValue == 'G' - 'A')
            G--;
        else if (StValue == 'T' - 'A')
            T--;

        St++;
        End++;

        StValue = DNA[St] - 'A';

        if (DNA[End] == 'A')
            A++;
        else if (DNA[End] == 'C')
            C++;
        else if (DNA[End] == 'G')
            G++;
        else if (DNA[End] == 'T')
            T++;


        if (A >= PW[0] && C >= PW[1] && G >= PW[2] && T >= PW[3])
        {
            ReturnVal++;
        }

    }

    cout << ReturnVal;

    return 0;
}