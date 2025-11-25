#include <string>
#include <vector>
#include <set>
#include <sstream>



using namespace std;


multiset<int> MS;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    char A;
    int B;
    
    for(string OP : operations)
    {
        stringstream SST(OP);
        SST >> A >> B;
        
        if(A == 'I')
        {
          MS.insert(B);  
        }
        else if(!MS.empty())
        {
            if(B == 1)
            {
                MS.erase(--MS.end());
            }
            else if(B == -1)
            {
                MS.erase(MS.begin());
            }
        }
    }
    
    
    if(MS.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(*(--MS.end()));
        answer.push_back(*(MS.begin()));
        
    }
    
    
    return answer;
}