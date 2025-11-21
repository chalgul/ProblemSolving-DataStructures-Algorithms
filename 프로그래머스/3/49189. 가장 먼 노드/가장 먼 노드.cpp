#include <string>
#include <vector>
#include <queue>

using namespace std;

int MaxDis = 0;

vector<vector<int>> GList;

vector<int> Check;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    GList.resize(n+1);
    Check.resize(n+1,0);
    
    //양방향 그래프 표현
    for(auto Info : edge)
    {
        GList[Info[0]].push_back(Info[1]);
        GList[Info[1]].push_back(Info[0]);
    }
    
    
    queue<int> Q;
    Q.push(1);
    Check[1] = 1;
    
    while(!Q.empty())
    {
        int Cur = Q.front();
        Q.pop();
        
        
        for(auto Node : GList[Cur])
        {
            if(Check[Node] != 0)
                continue;
            
            Check[Node] = Check[Cur] + 1;
            
            if(Check[Node] > MaxDis)
            {
                answer = 1;
                MaxDis = Check[Node];
            }
            else if(Check[Node] == MaxDis)
            {
                answer++;
            }
            
            Q.push(Node);
        }
    }
    
    
    
    
    return answer;
}