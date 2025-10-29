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
#include <unordered_set>
#include <set>
#include <numeric>
#include <tuple>
#include <sstream>
#include <map>
#include <cmath>
using namespace std;

int N;


vector<int> MS(int Num)
{
    vector<int> List;

    int Target = 2;

    //Target의 제곱이 Num보다 커지게 되면 Num은 무조건 소수
    //합성수의 1이 아닌 가장 작은 약수는 합성수의 제곱근보다 무조건 작은 수
    //Target보다 작은 수들은 이미 나눠질 때까지 나눴으므로 해당 없고 Target의 제곱이 이미 Num보다
    //커버리면 Num은 소수라는 것이 자명하다.
    while (Target * Target <= Num)
    {
        if (Num % Target == 0)
        {
            List.push_back(Target);
            Num = Num / Target;
        }
        else
        {
            Target++;
        }

    }

    List.push_back(Num);

    return List;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    if (N == 1)
    {
        return 0;
    }

    vector<int> Temp = MS(N);

    for (auto Number : Temp)
    {
        cout << Number << "\n";
    }

    return 0;
}

