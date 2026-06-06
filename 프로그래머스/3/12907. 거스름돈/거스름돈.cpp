#include <string>
#include <vector>

using namespace std;


//x원 만드는데 가능한 경우의 수
int DP[100002];




int solution(int n, vector<int> money) {
    int answer = 0;
    
    DP[0] = 1;
    for(int i = 0; i < money.size(); ++i)
    {
        
        //money[i]원을 추가해서 j원을 만드는 경우
        for(int j = money[i]; j <= n; ++j)
        {
            //결국 money[i]원을 써서 j원이 완성되는 경우는 j-money[i]를 완성하는 경우의 수와 동일하다.
            //다만 DP[j] 자체는 j원이 완성되는 모든 경우의 수를 내포하므로, 누적하는 형식으로 구현해야 한다.
            DP[j] += DP[j - money[i]];            
            DP[j] %= 1000000007;
        }       
    }
    
    
    
    return DP[n];
}