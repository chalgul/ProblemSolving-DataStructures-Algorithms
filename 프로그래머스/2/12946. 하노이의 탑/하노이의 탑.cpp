#include <string>
#include <vector>

using namespace std;

vector<vector<int>> Result;
int Tries = 0;
void Recursion(int Count, int Current ,int Towards, int Empty)
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
    
    
    
    Recursion(Count-1,Current,Empty, Towards);
    vector<int> Temp;
    Temp.push_back(Current);
    Temp.push_back(Towards);
    Result.push_back(Temp);
    Recursion(Count-1,Empty,Towards, Current);
    
   
}




vector<vector<int>> solution(int n) {
        
    Recursion(n, 1, 3, 2);
    
    return Result;
}