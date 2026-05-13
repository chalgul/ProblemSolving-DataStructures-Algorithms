#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int Size = 0;

bool IsUsed[10];

vector<int> Index_List;
vector<vector<int>> dup_Dungeon;

int Tired = 0;
int mx = 0;

void Recursion(int k)
{
    if(k == Size)
    {
        int T = Tired;
        int Cnt = 0;
        for(int Index : Index_List)
        {
            if(T >= dup_Dungeon[Index][0])
            {
                T -= dup_Dungeon[Index][1];
                Cnt++;
            }
            else
            {
                if(Cnt > mx)
                    mx = Cnt;
                return;
            }     
        }
        if(Cnt > mx)
            mx = Cnt;
        return;      
    }
    
    
    for(int i = 0; i < Size; ++i)
    {  
        if(!IsUsed[i])
        {
            IsUsed[i] = true;
            Index_List.push_back(i);
            Recursion(k+1);
            IsUsed[i] = false;
            Index_List.pop_back();
            Recursion(k+1);
        }        
    }   
}






int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;

    
    Size = dungeons.size();
    dup_Dungeon = dungeons;
    Tired = k;
    
    Recursion(0);
    
    
  
    return mx;
}