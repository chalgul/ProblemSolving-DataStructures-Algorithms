#include <string>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

//x : 훔쳐야될 물건 개수 ,  y : B가 남길 수 있는 흔적 최대 개수,  v : A가 남긴 흔적(적을 수록 가치 good)
int Table[42][122];



int solution(vector<vector<int>> info, int n, int m) {
    //int answer = 0;    
    /*
    fill(&Table[0][0], &Table[0][0] + sizeof(Table) / sizeof(int), 1000000);
    
    //B가 남길 수 있는 흔적 최대 개수가 i개 라고 할 때..
    for(int i = 1; i <= m; i++)
    {
        
        //j번째까지의 물건을 훔쳤을 때 A가 남긴 흔적이 제일 적은 경우를 찾기
        for(int j = 1; j <= info.size(); j++)
        {
            //첫번째 물건까지만 훔치는 경우
            if(j == 1)
            {
                if(info[j-1][1] <= i)
                {
                    Table[j][i] = 0;
                }
                else
                {
                    Table[j][i] = info[j-1][0];
                }
            }         
            //B가 물건을 훔칠 수 없는 경우 무조건 A가 훔쳐야 함.
            else if(i - info[j-1][1] < 0)
            {
              Table[j][i] = Table[j-1][i] + info[j-1][0];  
            }
            //둘 다 훔칠 수 있는 경우에는 해당 물건을 A가 훔치는 경우와 B가 훔치는 경우 중 최선의 값 선택
            //A가 남길 흔적의 개수에 대해서는 딱히 제한을 두지 않고 있는데 최종적으로 따졌을 때
            //A가 남기는 흔적이 n 넘어서면 -1 반환하면 되기 때문
            else
            {
                Table[j][i] = min(Table[j-1][i-info[j-1][1]], Table[j-1][i] + info[j-1][0]); 
            }
        }
    }
    
    if(Table[info.size()][m] >= n)
    {
        return -1;
    }
    
   
    return Table[info.size()][m];*/
    
    ll items = info.size();
    
    vector<vector<ll>> dp(items, vector<ll>(m));
    
    for (ll i = 0; i < items; i++) {
        for (ll j = 0; j < m; j++) {
            
            if (i == 0) {
                if (info[i][1] <= j) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = info[i][0];
                }
            } else if (j - info[i][1] < 0) {
                dp[i][j] = dp[i - 1][j] + info[i][0];
            }
            else {
                 dp[i][j] = min(dp[i - 1][j] + info[i][0], dp[i - 1][j - info[i][1]]);
            }
        }
    }
    
    ll answer;
    
    if (dp[items - 1][m - 1] < n) {
        answer = dp[items - 1][m - 1];
    } else {
        answer = -1;
    }
      return answer;
}














