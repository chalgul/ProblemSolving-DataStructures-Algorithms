#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <set>
#include <sstream>
#include <tuple>
#include <stack>
#include <algorithm>

using namespace std;


int N;

vector<int> NumList;

vector<int> C;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    C.resize(N + 1, 10000);
    C[0] = -1;

    int Input = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> Input;
        NumList.push_back(Input);
    }

    C[1] = NumList[0];

    int LastIndex = 1;

    int Size = (int)NumList.size();
    for (int i = 0; i < Size; ++i)
    {
        //LIS 길이 1 증가
        if (NumList[i] > C[LastIndex])
        {
            C[LastIndex + 1] = NumList[i];
            LastIndex++;
        }
        //특정 길이 LIS의 최소값 갱신
        else 
        {
            vector<int>::iterator Iter = lower_bound(C.begin(), C.end(), NumList[i]);
            *Iter = NumList[i];
        }
    }


    cout << LastIndex;

    return 0;
}