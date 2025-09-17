#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    answer.resize(2);
    
    //x인덱스까지 모든 수열 값을 합친 값
    vector<int> PrefixSum;
    int Sum = 0;
    for(int i = 0; i < sequence.size(); i++)
    {
        Sum += sequence[i];
        PrefixSum.push_back(Sum);
     
    }
    
    
    int Start = 0, End = 0;
    int MinLength = 1000002;
    int TotalSum = 0;
    for(Start; Start < sequence.size(); Start++)
    {        
        while(End < sequence.size() && TotalSum < k)
        {
            TotalSum += sequence[End];
            End++;
        }
        
        if(TotalSum == k)
        {
            if(End-1 - Start < MinLength)
            {
                MinLength = End-1 - Start;
                answer[0] = Start;
                answer[1] = End-1;
            }
        }
        
        TotalSum -= sequence[Start];
    }
    
    
    return answer;
}