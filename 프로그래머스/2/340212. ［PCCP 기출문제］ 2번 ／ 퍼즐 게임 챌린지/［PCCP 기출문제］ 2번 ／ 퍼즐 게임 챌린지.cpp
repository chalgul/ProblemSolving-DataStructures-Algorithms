#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;

    // 1. 이분 탐색 범위 설정
    int Start = 1;
    int End = *max_element(diffs.begin(), diffs.end());
    int Mid = (Start + End)/2;
    
    
    while(End >= Start)
    {
        long long TotalSpendingTime = 0;
        
        int PuzzleSize = (int)diffs.size();
        
        for(int i = 0; i < PuzzleSize; ++i)
        {
            TotalSpendingTime += times[i];
            
            //퍼즐의 레벨이 더 높은 경우
            if(diffs[i] > Mid)
            {
                //첫번째 퍼즐의 레벨은 1 고정이라서 -1인덱스 접근 예외처리 필요X 
                TotalSpendingTime += (diffs[i] - Mid)*(times[i-1]+times[i]);
            }
            
            
            if(TotalSpendingTime > limit)
            {
                Start = Mid + 1;
                break;
            }
        }
        
        if(TotalSpendingTime <= limit)
        {
            answer = Mid;
            End = Mid - 1;
        }
        
        Mid = (Start + End) / 2 ;
    }
    

    return answer;
}