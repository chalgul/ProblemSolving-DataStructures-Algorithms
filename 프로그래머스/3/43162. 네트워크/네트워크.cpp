#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> GList;

vector<bool> Check;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    GList.resize(n);
    Check.resize(n,false);
    
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < computers[i].size(); ++j)
        {
            if(i != j && computers[i][j] == 1)
            {
                GList[i].push_back(j);
            }
        }
    }

  
    
    for(int i = 0; i < n; ++i)
    {
        if(Check[i] == true)
            continue;
        answer++;
        queue<int> Q;
    Q.push(i);
    Check[i] = true;
        
    while(!Q.empty())
    {
        int Cur = Q.front();
        Q.pop();
        
        for(auto Node : GList[Cur])
        {
            if(Check[Node] == true)
                continue;
            
            Q.push(Node);
            Check[Node] = true;
        }
    }
    }
    
    return answer;
}