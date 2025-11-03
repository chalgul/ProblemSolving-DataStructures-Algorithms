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

using namespace std;

//수열 최대 길이가 10만
//수열의 최대 길이 N이라면, 1~N의 양수 등장
//일반적인 DP로 풀면 시간초과

//하나의 수열 i번째 Index 값을 다른 수열의 동일한 숫자가 몇번째에 있는지로 바꾸면 LIS 풀이가 가능할까?
//결국 LCS는 순서가 보장된 공통 부분 수열을 알아야 하기 떄문에 위 같은 아이디어를 통해서 LIS적인 접근을 해보면
//LIS로 도출된 값이 순서가 보장된 LCS라는 것을 알 수 있다.

const int INF = 10000000;

int N;

unordered_map<int, int> PosTable;

vector<int> Arr;

vector<int> CTable;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    
    int InputNum;
    for (int i = 0; i < N; ++i)
    {
        cin >> InputNum;
        
        //InputNum이라는 숫자가 Arr1 배열의 i번째 index에 있음을 의미
        PosTable[InputNum] = i;
    }
    for (int i = 0; i < N; ++i)
    {
        cin >> InputNum;
        Arr.push_back(InputNum);
    }


    for (int i = 0; i < N; ++i)
    {
        Arr[i] = PosTable.find(Arr[i])->second;
    }


    //Arr에 대한 LIS 수행

    //CTable은 Arr배열에 대해서 i번째 인덱스까지만 배열이 
    //존재한다고 가정했을 때, LIS의 마지막 원소를 넣는다.
    CTable.resize(N + 1, INF);
    CTable[0] = -1;
    CTable[1] = Arr[0];

    int LastIndex = 1;

    for (int i = 2; i <= N; ++i)
    {
        if (Arr[i - 1] > CTable[LastIndex])
        {
            LastIndex++;
            CTable[LastIndex] = Arr[i - 1];
        }
        else
        {
            auto Iter = lower_bound(CTable.begin(), CTable.end(), Arr[i - 1]);
            *Iter = Arr[i - 1];
        }
    }

    //LIS 길이 결과 값이 곧 LCS의 길이가 된다.
    cout << LastIndex;

    return 0;
}