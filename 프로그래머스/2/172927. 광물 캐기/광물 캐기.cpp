#include <string>
#include <vector>

using namespace std;

vector<int> CanUse;
int ResultVal = 100000000;
int TempVal = 0;
int Durability = 0;

//상태공간트리 돌/철/다이아 곡 사용 여부
void Recursion(const vector<string>& Minerals, int Level, int Picks)
{   
    //모든 곡괭이 소모
    if(CanUse[0] == 0 && CanUse[1] == 0 && CanUse[2] == 0 && Durability == 0)
    {
        ResultVal = min(ResultVal,TempVal);
        return;
    }
    
    
    //모든 광물 다 캤으면 return
    if(Level == Minerals.size())
    {
        ResultVal = min(ResultVal,TempVal);
        return;
    }
    
    if(Durability == 0)
    {
     for(int i = 0; i < 3; i++)
     {
         Durability = 5;
         if(CanUse[i] != 0)
         {
             CanUse[i]--;
             //광물 5개 캐기
             //다이아 곡
             if(i == 0)
             {
                 TempVal++;
                 Durability--;
                 Recursion(Minerals, Level + 1,0);
                 TempVal--;
             }
             else if(i == 1)
             {
                 if(Minerals[Level] == "diamond")
                 {
                    TempVal += 5;
                    Durability--;
                    Recursion(Minerals, Level + 1,1);
                    TempVal -= 5;
                 }
                 else
                 { 
                    TempVal++;
                    Durability--;
                    Recursion(Minerals, Level + 1,1);
                    TempVal--;
                 }
             }
             else
             {
                 if(Minerals[Level] == "diamond")
                 {
                     TempVal += 25;
                     Durability--;
                     Recursion(Minerals,Level+1,2);
                     TempVal -= 25;
                 }
                 else if(Minerals[Level] == "iron")
                 {
                     TempVal += 5;
                     Durability--;
                     Recursion(Minerals,Level+1,2);
                     TempVal -= 5;
                 }
                 else
                 {
                     TempVal++;
                     Durability--;
                     Recursion(Minerals, Level + 1,2);
                     TempVal--;
                 }
                     
             }
             CanUse[i]++;
         }
     }
    }
    else
    {
        if(Picks == 0)
        {
            TempVal++;
                 Durability--;
                 Recursion(Minerals, Level + 1,0);
                 TempVal--;
        }
        else if(Picks == 1)
        {
             if(Minerals[Level] == "diamond")
                 {
                    TempVal += 5;
                    Durability--;
                    Recursion(Minerals, Level + 1,1);
                    TempVal -= 5;
                 }
                 else
                 { 
                    TempVal++;
                    Durability--;
                    Recursion(Minerals, Level + 1,1);
                    TempVal--;
                 }
        }
        else
        {
            if(Minerals[Level] == "diamond")
                 {
                     TempVal += 25;
                     Durability--;
                     Recursion(Minerals,Level+1,2);
                     TempVal -= 25;
                 }
                 else if(Minerals[Level] == "iron")
                 {
                     TempVal += 5;
                     Durability--;
                     Recursion(Minerals,Level+1,2);
                     TempVal -= 5;
                 }
                 else
                 {
                     TempVal++;
                     Durability--;
                     Recursion(Minerals, Level + 1,2);
                     TempVal--;
                 }
        }
    }
}




int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    
    //일단 그리디는 안될 듯 -> 한번 꺼낸 곡괭이는 내구도 끝날 때까지 써야한다는 조건 때문에
    //DP인가?
    //백트래킹인가? -> mineral 길이가 50이하면 한 번 곡 꺼내면 5개씩 캐니까 사실 범위 1~10인거랑 같은데
    
    CanUse = picks;
    Recursion(minerals,0,-1);

    answer = ResultVal;
    return answer;
}