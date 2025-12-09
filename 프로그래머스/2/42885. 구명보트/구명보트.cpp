#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


int solution(vector<int> people, int limit) {
    int answer = 0;  

    sort(people.begin(), people.end());
    
    
    int Start = 0;
    int End = people.size()-1;
    
    
    while(Start <= End)
    {
        if(Start == End)
        {
            answer++;
            break;
        }        
        
        if(people[Start] + people[End] <= limit)
        {
            Start++;
            End--;
        }
        else
        {
            End--;
        }
        
        answer++;      
    }
    
    
    
    return answer;
}