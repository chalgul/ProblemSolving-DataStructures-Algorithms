#include <string>
#include <vector>

using namespace std;

vector<vector<int>> Result;
int Tries = 0;
void Recursion(int Count, int Current ,int Towards)
{
   //base condition
   if(Count == 1)
   {
       vector<int> Temp;
       Temp.push_back(Current);
       Temp.push_back(Towards);
       Result.push_back(Temp);
       return;
   }
    
    
    if(Current == 1 && Towards == 3)
    {
        Recursion(Count-1,1,2);
        vector<int> Temp;
        Temp.push_back(Current);
        Temp.push_back(Towards);
        Result.push_back(Temp);
        Recursion(Count-1,2,3);
    }
    else if(Current == 1 && Towards == 2)
    {
        Recursion(Count-1,1,3);
        vector<int> Temp;
        Temp.push_back(Current);
        Temp.push_back(Towards);
        Result.push_back(Temp);
        Recursion(Count-1,3,2);
    }
    else if(Current == 2 && Towards == 3)
    {
        Recursion(Count-1,2,1);
        vector<int> Temp;
        Temp.push_back(Current);
        Temp.push_back(Towards);
        Result.push_back(Temp);
        Recursion(Count-1,1,3);
    }
    else if(Current == 2 && Towards == 1)
    {
        Recursion(Count-1,2,3);
        vector<int> Temp;
        Temp.push_back(Current);
        Temp.push_back(Towards);
        Result.push_back(Temp);
        Recursion(Count-1,3,1);
    }
    else if(Current == 3 && Towards == 1)
    {
        Recursion(Count-1,3,2);
        vector<int> Temp;
        Temp.push_back(Current);
        Temp.push_back(Towards);
        Result.push_back(Temp);
        Recursion(Count-1,2,1);
    }
    else if(Current == 3 && Towards == 2)
    {
        Recursion(Count-1,3,1);
        vector<int> Temp;
        Temp.push_back(Current);
        Temp.push_back(Towards);
        Result.push_back(Temp);
        Recursion(Count-1,1,2);
    }
}




vector<vector<int>> solution(int n) {
        
    Recursion(n, 1, 3);
    
    return Result;
}