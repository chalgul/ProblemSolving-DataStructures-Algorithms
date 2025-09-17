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

int N;

vector<int> ArrayInput;

unordered_map<int, pair<int,int>> TwoSumMap;



int main() {
   
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    cin >> N;
   
    ArrayInput.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> ArrayInput[i];
    }

    //오름차순 정렬
    sort(ArrayInput.begin(), ArrayInput.end());

    //가장 원시적인건  N의 숫자가 나올수 있는 모든 N-1개의 숫자조합(2^(N-1))을 check  -> 너무 오래걸림
    //해시맵 활용하여 N^2으로 해결 시도

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            pair<int, int> Temp = { ArrayInput[i],ArrayInput[j] };
            TwoSumMap.emplace(ArrayInput[i] + ArrayInput[j], Temp);
        }
    }

    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (TwoSumMap.find(ArrayInput[i] - ArrayInput[j]) != TwoSumMap.end())
            {
               /* if (TwoSumMap.find(ArrayInput[i] - ArrayInput[j])->second.first != ArrayInput[j] &&
                    TwoSumMap.find(ArrayInput[i] - ArrayInput[j])->second.second != ArrayInput[j])
                {*/
                    cout << ArrayInput[i];
                    return 0;
                //}
            }
        }
    }


    return 0;
}

