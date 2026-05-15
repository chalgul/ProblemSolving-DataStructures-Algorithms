#include <string>
#include <vector>

using namespace std;

vector<int> Numbers;
int Size = 0;

vector<bool> Cal;
int Target = 0;
int Count = 0;


void Recursion(int k)
{
    if(k == Size)
    {
        int Sum = 0;
        for(int i = 0; i < Size; ++i)
        {
            if(Cal[i])
            {
                Sum += Numbers[i];
            }
            else
            {
                Sum -= Numbers[i];
            }
        }
        
        if(Sum == Target)
            Count++;
        
        return;
    }
    
    Cal.push_back(true);
    Recursion(k+1);
    Cal.pop_back();
    
    
    Cal.push_back(false);
    Recursion(k+1);
    Cal.pop_back();
}


int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    
    Numbers = numbers;
    Size = numbers.size();
    Target = target;
    
    Recursion(0);
    
    return Count;
}