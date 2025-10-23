#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;


bool cmp(const string& A, const string& B)
{
    if(A.size() < B.size())
        return true;
    else if(A.size() == B.size())
    {
        return A < B;        
    }
    else
    {
        return false;
    }
}



string CalString(long long n)
{
    //만약 아무런 문자열도 지우지 않았을 때, n이 속한 주문의 문자열 길이가 얼마인지 확인
    long long St = 26;
    long long AddSum = 26;
    int Length = 1;
    long long PrevSt = 0;
    while(n > St)
    {
        PrevSt = St;
        AddSum *= 26;
        St += AddSum;
        Length++;
    }
    
    long long Temp = 0;
    long long num = n - (PrevSt) - 1;
    string TempS;

    //만약 아무런 문자열도 지우지 않았을 때, n이 나타내는 문자열 확인
    for(int i = Length; i > 0; --i)
    {
        if(num != 0)
        {
            Temp = num%26;
            num = num/26;
    
            char C = 'z' - (25-Temp);
           
            if(TempS.empty())
            {
                TempS = C;
            }
            else
                TempS = C + TempS;   
        }
        else
        {
            TempS = 'a' + TempS;
        }
    }
    
    
    return TempS;
    
    
}




string solution(long long n, vector<string> bans) {
    string answer = "";
    
    
    
    //a~z 26개
    
    //aa~zz 26^2개
    
    //aaa~zzz 26^3개
    
    //26 + 26^2 + 26^3 + 26^4 .... + 26^11  공비가 26인 등비수열

    //지워진 문자열을 순서대로 정렬
    sort(bans.begin(),bans.end(),cmp);
    
    string TempS = CalString(n);
    
    int EraseCnt = 0;
    
    //n이랑 같거나 이전에 있는 문자열들 중 지워진 문자열이 몇개인지 카운팅
    for(string Spell : bans)
    {
        if(Spell.size() < TempS.size())
        {
           n += 1;
           TempS = CalString(n);
           
        }
        else if(Spell.size() == TempS.size() && Spell <= TempS)
        {
           n += 1;
           TempS = CalString(n);
        }
    }
    
    
    
    answer = TempS;
    
    
    
    return answer;
}