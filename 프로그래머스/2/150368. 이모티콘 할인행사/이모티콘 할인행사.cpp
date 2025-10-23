#include <string>
#include <vector>

using namespace std;

int TotalSales = 0;
int Members = 0;

int SaledPercent[4] = {90,80,70,60};

int RealPercent[4] = {10,20,30,40};

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    
    //자유롭게 조절할 수 있는 것 : 각 이모티콘의 할인율
    //할인 경우의 수 4가지 : 10/20/30/40
    //이모티콘 최대 개수 7
    //사용자 최대 100명
    
    //7^4 = 약 2500
    //한 가지 할인율 케이스에 대해서 최종 구독자 수 + 판매 가격 도출 시간복잡도는 700번
    //2500 * 700  완전 탐색 가능할듯?
    
    //각각의 이모티콘은 할인율에 따라서 4가지 상태에 놓일 수 있음 4진수 (emoticons.size())자리로 계산하면 편리하지 않을까?    
    for(int i = 0; i < (1<<(emoticons.size()*2)); ++i)
    {
        int StateCase = i;
        
        int TempMembers = 0;
        int TempSales = 0;
        //first : 할인률 second : 할인된 가격의 이모티콘 저장 
        vector<pair<int,int>> Saled;
        Saled.resize(emoticons.size());
        
        for(int j = 0; j < emoticons.size(); ++j)
        {
            int Case = StateCase%4;
            StateCase = StateCase>>2;
            Saled[j] = {RealPercent[Case],(emoticons[j]/100 *  SaledPercent[Case])};
        }
         
        //특정 case에서 각 이모티콘에 대해 할인율이 적용된 상태의 가격이 저장된 배열 Saled 완성된 상태
        //모든 사용자에 대해서 해당 이모티콘에 따른 구매 여부 및 구독 가입 여부를 판단
        //구독이 가능하면 무조건 구독 아니라면 max 구매 비용 값
        for(int j = 0; j < users.size(); ++j)
        {
            int TotalPurchase = 0;
            bool Subs =  false;
            
            for(int k = 0; k < Saled.size(); ++k)
            {
                //유저가 구매 의향이 생기는 할인률인지 판단
                if(Saled[k].first >= users[j][0])
                {
                    //구매 가능
                    TotalPurchase += Saled[k].second;
                    //구독권 구매 기준 확인
                    if(TotalPurchase >= users[j][1])
                    {
                        //구독권 구매로 선회
                        TempMembers++;
                        Subs = true;
                        break;
                    }
                }
            }
            
            //구독을 안했다면 최종 매출에 추가
            if(!Subs)
            {
                TempSales += TotalPurchase;
            }
        }
        
        //해당 할인율 케이스가 최선의 성과를 내는 결과물인지 확인
        if(TempMembers > Members)
        {
            Members = TempMembers;
            TotalSales = TempSales;
        }
        else if(TempMembers == Members)
        {
            TotalSales = max(TempSales, TotalSales);
        }    
    }
    
    answer.push_back(Members);
    answer.push_back(TotalSales);
    
    
    
    return answer;
}