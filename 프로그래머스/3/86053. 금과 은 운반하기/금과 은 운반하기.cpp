#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;


//각 도시마다 자원을 얼만큼 씩 할당할지 고려하지 않고
//주어진 시간이 t일 때, 할당할 수 있는 최대 자원을 고려하는 방식으로 역발상하여 이분탐색으로 풀이
long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {  
    long long answer = -1;
    
    long long Start = 0;
    //모든 도시의 광물 운송시간이 10e5
    //한 번에 운송 가능한 광물 용량이 1
    //필요한 광물이 골드 10e9 실버 10e9인 경우 필요한 시간
    long long End = 10e14*4 + 10e5;
    
    long long Gold = a;
    long long Silver = b;
    
    int Size = (int)t.size();
    
    while(End >= Start)
    {
        
        long long Mid = (Start + End)/2;
        
        
        long long Greedy_Gold = 0;
        long long Greedy_Silver = 0;
        long long TotalMine = 0;
        
        for(int i = 0; i < Size; ++i)
        {
            long long Cnt = Mid/(t[i]*2);
            long long Temp = Mid%(t[i]*2);
            if(Temp >= t[i])
                Cnt++;
            
            //mid 값 기준으로 해당 도시에서 가져갈 수 있는 자원의 총량
            long long Take = Cnt*w[i];
            
            //무조건 모든 골드 가져가기
            Greedy_Gold += min(Take, (long long)g[i]);
            //무조건 모든 실버 가져가기
            Greedy_Silver += min(Take, (long long)s[i]);
            //골드든 실버든 가져갈 수 있는 최대용량을 가져가기
            TotalMine += min(Take, (long long)(g[i] + s[i]));            
        }
        
        //시간 Mid에서 가져갈 수 있는 골드의 양은 도시를 건설하기에 충분함을 의미
        //시간 Mid에서 가져갈 수 있는 실버의 양은 도시를 건설하기에 충분함을 의미
        //시간 Mid에서 가져갈 수 있는 총 용량은 필요한 골드와 실버의 양을 충분히 감당할 수 있음을 의미
        //즉, 골드 실버가 모두 충분히 존재하고 가져갈 수 있는 용량 자체도 더 크기 때문에 해당 시간에서는 도시 건설 가능
        if(Greedy_Gold >= (long long)a && Greedy_Silver >= (long long)b && TotalMine >= (long long)(a+b))
        {
            answer = Mid;     
            End = Mid - 1;
        }
        else
        {
            Start = Mid + 1;
        }       
    }

    
    return answer;
}