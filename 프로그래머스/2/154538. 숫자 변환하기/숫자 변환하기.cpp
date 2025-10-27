#include <string>
#include <vector>
#include <queue>

int Dis[1000002];

int dx[3] = {2,3,-1};

using namespace std;

int solution(int x, int y, int n) {
    int answer = -1;
    
    //1차원 BFS로 풀이 가능할 듯
    //최소 연산 횟수 = 최단 거리
    //n,2,3 곱하기 = 확장 규칙
    
    
    queue<int> Q;
    Q.push(x);
    Dis[x] = 0;
    if(x == y)
    {
        return 0;
    }
    
    while(!Q.empty())
    {
        int Cur = Q.front();
        Q.pop();
        
        for(int i = 0; i < 3; i++)
        {
            int X = 0;                  
            
            if(i != 2)
            {
                X = dx[i]*Cur;
            }
            else
            {
                X = n+Cur;
            }
            
            if(X > y)
                continue;
            
            if(X == y)
            {
                return Dis[Cur] + 1;
            }
            
            Q.push(X);
            if(Dis[X] != 0)
                Dis[X] = min(Dis[X],Dis[Cur] + 1);
            else
                Dis[X] = Dis[Cur] + 1;
        }
    }
    
    return answer;
}