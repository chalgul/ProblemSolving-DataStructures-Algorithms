#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <list>
#include <queue>
#include <unordered_map>

using namespace std;

int N, M;


//2부터 ~ N까지의 수들 중 소수를 반환
vector<int> PrimeList(int n, int m)
{
    vector<int> Prime;
    vector<bool> State(m+1,true);
    State[1] = false;

    //m의 제곱근 보다 큰 수부터는 이미 m의 제곱근 이하의 수는 전부 소수 check가
    //마무리 되었으므로 반복문 중단
    for (int i = 2; i*i <= m; i++)
    {
        for (int j = i * i; j <= m; j += i)
        {
            State[j] = false;
        }
    }

    for (int i = n; i <= m; i++)
    {
        if (State[i] == true)
            Prime.push_back(i);
    }

    return Prime;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    vector<int> Result;

    Result = PrimeList(N,M);

    for (auto P : Result)
    {
        cout << P << "\n";
    }

    return 0;
}


