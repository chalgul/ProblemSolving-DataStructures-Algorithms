#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <list>
#include <queue>
#include <numeric>
#include <unordered_map>

using namespace std;

int TestCase;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> TestCase;


    int M = 0, N= 0, x = 0, y = 0;
    
    //M이 초기화된 횟수 : a  N이 초기화된 횟수 b

    //a*M + x = b*N + y
    //M으로 나눴을 때 나머지 x인 수들 중에서
    //N으로 나눴을 때 나머지 y인 수
    for (int i = 0; i < TestCase; ++i)
    {
        cin >> M >> N >> x >> y;

        int LCM = 0;
        bool IsFinding = false;
        if (M > N)
        {
            LCM = lcm(M, N);
        }
        else
        {
            LCM = lcm(N, M);
        }

        for (int j = x; j <= LCM; j += M)
        {
            //y값이 N과 동일하게 들어오는 경우도 고려해야 됨
            if (j % N  == y % N)
            {
                cout << j << "\n";
                IsFinding = true;
                break;
            }
        }
        if(!IsFinding)
            cout << -1 << "\n";
    }

    return 0;
}


