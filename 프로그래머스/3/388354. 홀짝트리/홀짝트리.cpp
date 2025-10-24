#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

//노드의 번호가 인덱스 크기와 동일하게 매칭되지 않기 때문에, vector가 아닌 해시 활용
unordered_map<int,vector<int>> GList;

unordered_map<int,bool> Visit;


//트리 정보들을 저장
vector<vector<int>> Trees;

vector<int> TempTrees;

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    vector<int> answer(2,0);
    
    //정점이 최대 40만개 일일이 루트 지정해가면서 완탐은 절대 불가능
    
    //짝수 노드 따질 때 자식 개수 짝수라는게 바로 아래 자식들의 수만 얘기하는 거임.
    //자식 0개면 짝수로 침.
    
    //자식이었던 정점이 부모가 되면 간선 +1이 된다.
    //즉, 홀수노드였던 자식이 루트가 되면 역홀수노드가 되고
    //마찬가지로
    //짝수노드 -> 역짝수노드,   역홀짝노드 -> 홀짝노드로 바뀌게 된다.
       
    //홀짝 트리가 되기 위한 조건
    //기본적으로 어떤 주어진 트리가 홀짝 트리가 되기 위해서는 모든 정점이 자식 정점이라고 가정했을 때
    //자식 정점이면 현재 연결된 (간선의 개수 -1)을 기준으로 자식 노드 개수 판단
    //전부다 홀짝노드인데 딱 하나 정점에서 역홀짝노드면 해당 노드를 루트로 삼으면 홀짝트리가 된다.
    //2개 이상 노드가 역홀짝 노드가 되버리면 하나를 루트로 삼아도, 나머지 역홀짝노드가 여전히 유지되기 때문에 불가능
    
    //역홀짝 트리가 되기 위한 조건
    //모든 노드가 자식노드라고 가정했을 때
    //각 노드가 모두 역홀짝 노드여야 하고 딱 하나의 노드만 홀짝노드여야함.
    
    //역홀짝/홀짝 트리가 될 수 있는 경우의 수
    // 1. 노드의 개수가 1개인 트리
    // 2. 노드의 개수가 2개인 경우, 역홀짝 노드 1개와 홀짝 노드 1개로 이루어진 경우, 2가지 트리 다 가능함.
    // 3. 노드의 개수가 3개 이상일 때, 자식 노드 취급 기준 역홀짝 노드가 1개만 있는 경우 홀짝 트리 가능
    // 4. 노드의 개수가 3개 이상일 떄, 자식 노드 취급 기준 홀짝 노드가 1개만 있는 경우 역홀짝 트리 가능
    
    
    for(int N : nodes)
    {
        Visit[N] = false;
    }
    
    
    //인접리스트 방식으로 그래프 표현
    for(vector<int> E : edges)
    {
        GList[E[0]].push_back(E[1]);
        GList[E[1]].push_back(E[0]);
    }
    
    //트리 구분 작업
    for(auto Info : nodes)
    {
        if((Visit.find(Info))->second == true)
            continue;
        
        TempTrees.clear();
        
        Visit[Info] = true;
        queue<int> Q;
        Q.push(Info);
        TempTrees.push_back(Info);
        
        while(!Q.empty())
        {
            int Cur = Q.front();
            Q.pop();
            
            //간선이 존재하지 않는 정점에 대한 예외처리
            if(GList.find(Cur) == GList.end())
                continue;
            
            for(auto Node : GList.find(Cur)->second)
            {
                if((Visit.find(Node))->second == true)
                    continue;
                
                Visit[Node] = true;
                Q.push(Node);
                TempTrees.push_back(Node);
            }
        }
        Trees.push_back(TempTrees);
    }
    
    
    for(vector<int> T : Trees)
    {
        if(T.size() == 1)
        {
            if(T[0]%2 == 0)
                answer[0]++;
            else
                answer[1]++;
        }
        else if(T.size() == 2)
        {
            if((T[0]%2 == 0 && T[1]%2 == 1) || (T[0]%2 == 1 && T[1]%2 == 0))
            {
                answer[0]++;
                answer[1]++;
            }
        }
        else
        {
            //해당 트리의 각각의 정점에 대해서 역홀짝 노드, 홀짝 노드 구분 필요
            int DNode = 0;
            int IDNode = 0;
            
            for(int Node : T)
            {
                if(Node%2 == 0)
                {
                    if((GList.find(Node)->second.size()-1)%2 == 0)
                        DNode++;
                    else if((GList.find(Node)->second.size()-1)%2 == 1)
                        IDNode++;
                }
                else
                {
                    if((GList.find(Node)->second.size()-1)%2 == 0)
                        IDNode++;
                    else if((GList.find(Node)->second.size()-1)%2 == 1)
                        DNode++;
                }
            }
            if(DNode == 1)
                answer[1]++;
            else if(IDNode == 1)
                answer[0]++;
        }
    }
    
    
    return answer;
}