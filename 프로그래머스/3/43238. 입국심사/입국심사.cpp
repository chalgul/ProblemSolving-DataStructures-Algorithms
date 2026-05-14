#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    
    unsigned long long St = 0;
    //이론상 가장 오래걸릴 수 있는 시간
    unsigned long long End = times[times.size()-1]*n;
    
    unsigned long long Mid = 0;    
    
    while(St <= End)
    {
        Mid = (St+End)/2;
        unsigned long long Count = 0;
        
        for(unsigned long long CheckTime : times)
        {
            //Mid 값 기준으로 각 심사관이 최대로 심사할 수 있는 인원 계산하여 누적
            Count += Mid/CheckTime;
        }
        
        //해당 시간은 모든 사람을 심사하기에 충분한 시간
        //Count == n 이더라도, 더 적은 시간에 심사할 수 있는 방안 존재할 수 있음.
        if(Count >= n)
        {
            answer = Mid;
            End = Mid-1;
        }
        //Count < n인 경우에는 모든 사람이 입국심사를 끝내기 위해서는 더 많은 시간이 필요
        else
        {
            St = Mid+1;
        }
    }
    
     
    return answer;
}