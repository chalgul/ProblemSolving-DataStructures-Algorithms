#include <string>
#include <vector>

using namespace std;

vector<int> Answer;
vector<vector<int>> Question;

vector<bool> IsUsed(32,false);
vector<int> SelectNum;

int ResultVal = 0;

//암호 후보가 될 수 있는지 판독
bool IsCanCode()
{
    int PairNum = 0;
    //모든 해독 시도 결과에 대해서 검증
    for(int i = 0; i < (int)Question.size(); ++i)
    {
        //i번째 해독 시도 결과에 대해서 검증
        for(auto Num : Question[i])
        {
            //어차피 무조건 5개임
            for(int i = 0; i < 5; i++)
            {
                //짝이 맞는 수가 있으면 +1
                if(SelectNum[i] == Num)
                {
                    PairNum++;
                }
            }
        }
        //i번째 해독 시도 결과와 암호 후보와 비교한 결과 pair이 맞지 않으면 암호 아님
        if(PairNum != Answer[i])
        {
            return false;
        }
        //다음 해독 시도 결과와의 비교를 위해서 초기화
        PairNum = 0;
    }
    
    return true;
}




void Recursion(int MaxNum, int Level, int Start)
{
    //임의의 숫자 5개 선택했으면 return
    if(Level == 5)
    {
        //암호 코드 후보가 될 수 있는지 check
        if(IsCanCode())
        {
            ++ResultVal;
        }
        return;
    }
    
    for(int st = Start; st <= MaxNum; st++)
    {
        IsUsed[st] = true;
        SelectNum.push_back(st);
        Recursion(MaxNum,Level+1, st+1);
        SelectNum.pop_back();
        IsUsed[st] = false;
    }
        
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    //n : 숫자 범위
    //q : m행 5열    암호 해독 시도한 숫자 리스트
    //해독 시도한 것에 대한 결과값 리스트 : 길이 m
    
    //30c5 로 나올 수 있는 모든 경우의 수에서 m개 숫자 리스트에 알맞는지 check 하는 방식? 
    
    //2.4만 * 10 * 25  괜찮겠는데?
    Answer = ans;
    Question = q;
    
    
    Recursion(n,0,1);
    
    answer = ResultVal;
    return answer;
}