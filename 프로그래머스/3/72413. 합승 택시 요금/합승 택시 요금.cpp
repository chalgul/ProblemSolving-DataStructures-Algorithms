#include <string>
#include <vector>

using namespace std;

vector<vector<int>> DisTable;

const int INF = 99999999;


int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    
    DisTable.resize(n+1);
    for(int i = 0; i <= n; ++i)
    {
        DisTable[i].resize(n+1,INF);
    }
    
    for(int i = 0; i <= n; ++i)
    {
        DisTable[i][i] = 0;
    }
    
    for(auto Info : fares)
    {
        DisTable[Info[0]][Info[1]] = Info[2];
        DisTable[Info[1]][Info[0]] = Info[2];
    }
    
    
    //k번째 노드까지 경유가능하다고 가정했을 때, 모든 노드 쌍 간의 최단 거리 값
    for(int k = 1; k <= n; ++k)
    {
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                if(DisTable[i][j] > DisTable[i][k] + DisTable[k][j])
                {
                    DisTable[i][j] = DisTable[i][k] + DisTable[k][j];
                }
            }
        }
    }
    
    
    //S에서 시작하여 특정 노드까지 같이 택시 타고 이동 + 이후에 각자 집으로 이동에 대한 브루트포스 수행
    
    for(int i = 1; i <= n; ++i)
    {
        answer = min(answer , DisTable[s][i] + DisTable[i][a] + DisTable[i][b]);
    }
      
    
    return answer;
}