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
#include <string>
using namespace std;

int N;
int M;
string S;

int ReturnVal = 0;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    cin >> S;

    int ICnt = 0;
    int OCnt = 0;
    char PrevWord = S[0];
    if (S[0] == 'I')
        ICnt++;

    int Size = (int)S.size();

    for (int i = 1; i < Size; ++i)
    {
        if (S[i] == 'I')
        {
            if (PrevWord == 'O')
                ICnt++;
            //II가 된 case기 때문에 I부터 다시 check 시작
            else
            {
                ICnt = 1;
                OCnt = 0;
            }

        }
        else if(S[i] == 'O')
        {
            if (PrevWord == 'I')
                OCnt++;
            //OO가 된 case기 때문에 맨 처음부터 다시 check
            else
            {
                ICnt = 0;
                OCnt = 0;
            }
        }

        PrevWord = S[i];

        if (ICnt == N + 1 && OCnt == N)
        {
            ReturnVal++;
            ICnt--;
            OCnt--;
        }
    }

    cout << ReturnVal;
    return 0;
}