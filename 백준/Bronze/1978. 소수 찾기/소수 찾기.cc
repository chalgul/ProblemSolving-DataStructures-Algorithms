#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <list>
#include <queue>
#include <unordered_map>

using namespace std;

int N;


bool IsPrimeNumber(int n)
{
    //n이 1이면 소수가 아니다.
    if (n == 1)
        return false;
    
    //합성수일 경우 존재하는 가장 작은 약수는 n의 제곱근보다 작거나 같다.
    //따라서 n의 제곱근보다 작을 때 어떠한 약수도 찾지 못한다면
    //해당 수는 소수라는 것이 자명하다.
    for (int i = 2; i*i <= n; ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int ResultVal = 0;
    int Input = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> Input;
        if (IsPrimeNumber(Input))
            ++ResultVal;
    }

    cout << ResultVal;

    return 0;
}


