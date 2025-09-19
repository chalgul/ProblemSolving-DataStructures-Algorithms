#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> ListNode[1000002];

//first indegree, second outdegree
pair<int,int> DegreeInfo[1000002] = {{0,0}};

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    

    //edges 벡터 안에는 a,b 형태로 이루어진 길이가 2인 벡터들이 들어가 있음.
    
    
    //이미 존재하던 그래프 종류를 N개라고 가정
    //결국 간선의 개수는 본래 존재하던 간선 개수 + 임의의 새로 생성된 정점과 연결된 간선 N개
    
    //임의로 생성된 정점으로부터 빠져나온 간선은 반대로 원래 있던 그래프들의 정점에서는 건너갈 수 없음.
    
    //모든 주어진 번호에 대해서 DFS를 돌리면 어떻게 되지?
    
    //1. 뻣어나갈 수 있는 길이 1개면서 다시 자기 자신으로 돌아온다. -> 도넛
    
    
    //2. 뻣어나갈 수 있는 길이 2개면서 두 경로 다 다시 자기 자신으로 돌아온다 -> 8자 그래프에서 겹치는 곳 
    
    
    //3. 뻣어나갈 공간이 1개인데, 다시 자기 자신으로 돌아오지 못하고 탐색 종료 -> 막대 그래프
    
    
    //4. 뻣어나갈 수 있는 공간이 여러 개인데, 다시 자기 자신으로 돌아오지 못함. -> 임의의 추가 된 정점
    
    
    //뻣어나갈 경로가 2개면 임의의 생성된 정점이거나 8자 모양 그래프네요
    //뻣어나갈 경로가 3개 이상이면 그냥 확정임.
    
    int MaxNum = 0;
    
    
    
    
    //그래프 인접 리스트 형식으로 표현
    for(int i = 0; i < edges.size(); i++)
    {
        ListNode[edges[i][0]].push_back(edges[i][1]);
        MaxNum = max(MaxNum, edges[i][0]);
        DegreeInfo[edges[i][0]].second++;
        DegreeInfo[edges[i][1]].first++;
    }
    
    int Candidate = 0;
    int NewNode = 0;
    
    for(int i = 1; i <= MaxNum; i++)
    {
        //임의로 생성된 정점 후보지
        if(ListNode[i].size() == 2)
        {
            //임의로 생성된 정점임
            if(DegreeInfo[i].first == 0)
            {
                NewNode = i;
                break;
            }
           /* else
            {
                 c++;
            }*/
            /*
            Candidate = i;
            bool IsNewNode = true;
            //자기 자신으로 돌아오는 간선이 있는지 check
            for(int j = 0; j < edges.size(); j++)
            {
                if(edges[j][1] == Candidate)
                {
                    IsNewNode = false;
                    break;
                }
            }
            if(IsNewNode)
            {
                NewNode = i;
                break;
            }
            */
        }
        //임의로 생성된 정점 확정
        else if(ListNode[i].size() > 2)
        {
            NewNode = i;
            break;
        }
        
    }
    
    answer.push_back(NewNode);

    int TotalGraph = NewNode;
    /*
     for(int Node : ListNode[NewNode])
     {
         //막대임
         if(DegreeInfo[Node].first-1 == 0)
         {
             b++;
         }
     }
    
    */
    
    
    
    
    int a=0,b=0,c=0;
    
    
    for(int Node : ListNode[NewNode])
    {
     
        if(DegreeInfo[Node].second == 2)
        {
            c++;
            continue;
        }
        
        
        bool Vis[1000002] = {false};
        //임의의 정점과 연결되어 있는 다른 정점들로부터 BFS 수행하여 그래프 모양 유추하기
        //방문한 정점의 개수와 간선의 개수를 counting 하면 알 수 있을 듯.
        
        queue<int> Q;
        
        Q.push(Node);
        
        int VisitNodeCount = 0;
        int VisitRoadCount = 0;
        
        VisitNodeCount++;
        Vis[Node] = true;
        bool IsFindC = false;
        while(!Q.empty())
        {
            int Cur = Q.front();
            Q.pop();
            for(int OtherNode : ListNode[Cur])
            {
                VisitRoadCount++;
                if(Vis[OtherNode] == true)
                    continue;
                if(DegreeInfo[OtherNode].second == 2)
                {
                    c++;
                    IsFindC = true;
                    break;
                }
                Q.push(OtherNode);
                VisitNodeCount++;
            }
            if(IsFindC)
                break;
        }
        
        //도넛
        if(VisitNodeCount == VisitRoadCount && !IsFindC)
        {
            a++;
        }
        //막대
        else if(VisitNodeCount -1 == VisitRoadCount&& !IsFindC)
        {
            b++;
        }
        //8자
       // else
        //{
          //  c++;
        //}
        
        
        
    }
    
    
    answer.push_back(a);
    answer.push_back(b);
    answer.push_back(c);
    
    
    
    
    return answer;
}