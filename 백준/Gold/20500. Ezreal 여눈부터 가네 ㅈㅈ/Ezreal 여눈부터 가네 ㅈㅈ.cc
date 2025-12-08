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
#include <tuple>
#include <sstream>
#include <numeric>
#include <map>
#include <cmath>
using namespace std;

const int DIV = 1000000007;

int N;

//i자리 이내에 존재하는 1과 5로 구성된 숫자들 중, 3으로 나눴을 때 나머지가 j인 경우의 수
int DP[1516][3];

//15의 배수는 3의 배수이면서 5의 배수인 것과 동일

//5의 배수의 마지막 자리 숫자는 0 or 5
//1과 5로만 구성된 숫자 수열이기 때문에 마지막 자리의 수는 5가 확정


//3의 배수의 경우, 모든 자리의 숫자의 합이 3으로 나눠진다.


//맨 마지막 자리수가 5가 확정, 5를 3으로 나눌 때 나머지는 2
//앞에서 나머지 1이 나와주어야 함


//N자리수의 경우, N-1 자리수의 수에서 모든 자리의 숫자의 합을 3으로 나눈 나머지가 1인 경우를 구하면 된다.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    DP[1][1] = 1;
    DP[1][2] = 1;

    
    for (int i = 2; i <= 1515; ++i)
    {
        //추가되는 자릿수가 1인 경우와 5인 경우를 구분해서 생각
        DP[i][0] = (DP[i - 1][2] + DP[i - 1][1]) % DIV;
        DP[i][1] = (DP[i - 1][0] + DP[i - 1][2]) % DIV;
        DP[i][2] = (DP[i - 1][1] + DP[i - 1][0]) % DIV;
    }

    cin >> N;

    cout << DP[N-1][1];

   
    return 0;
}


