#include <string>
#include <vector>
#include <stack>
#include <queue>


using namespace std;

//최대힙 기반 우선순위 큐
priority_queue<int , vector<int>, less<int>> pq;

queue<pair<int,int>> q;


int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    int Index = 0;
    for(int V : priorities)
    {
        pq.push(V);
        q.push({V,Index});
        Index++;
    }
    
    while(!q.empty())
    {
        auto PValue = q.front();
        q.pop();
        //최우선순위에 해당하는 경우
        if(PValue.first == pq.top())
        {
            pq.pop();
            answer++;
            
            if(PValue.second == location)
            {
                break;
            }   
        }
        //먼저 처리되어야 하는 프로세스가 큐에 남아있는 경우
        else
        {
            q.push(PValue);
        }
    
    }
    
    return answer;
}