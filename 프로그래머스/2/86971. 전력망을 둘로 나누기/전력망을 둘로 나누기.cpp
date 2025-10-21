#include <string>
#include <vector>
#include <algorithm>

using namespace std;

    //트리 형태로 연결되어 있기 때문에 간선의 개수는 n-1개로 고정
    //그래프 전체 완탐 할 때마다 O(n + n-1) 걸리니까
    //그냥 전선 하나씩 끊어보면서 절대값 제일 작은거 찾으면 되겠는데?
    //재귀 DFS로 전체 개수 카운팅 하자.

int Cnt = 0;

vector<vector<int>> GList;

bool Visit[102];

//A정점과 B정점을 연결하는 간선을 무시하고 DFS 수행
void DFS(int Node,int A, int B)
{
    Visit[Node] = true;
    Cnt++;
    
    for(int Link : GList[Node])
    {
        if(Node == A && Link == B)
            continue;
        if(Node == B && Link == A)
            continue;
        
        if(Visit[Link] == false)
            DFS(Link,A,B);
    }
}    
    



int solution(int n, vector<vector<int>> wires) {
    int answer = 10000;
    
    
    GList.resize(n+1);
    
    for(vector<int> Edge : wires)
    {
        GList[Edge[0]].push_back(Edge[1]);
        GList[Edge[1]].push_back(Edge[0]);
    }
    
    for(vector<int> Edge : wires)
    {
        fill(Visit,Visit+n+1,false);
        Cnt = 0;
        DFS(1,Edge[0],Edge[1]);
        answer = min(answer,abs((n-Cnt)-Cnt));
    }

    
    
    
    
    
    
    
    return answer;
}