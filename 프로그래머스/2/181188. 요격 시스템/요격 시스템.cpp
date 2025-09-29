#include <string>
#include <vector>
#include <algorithm>

using namespace std;


bool cmp(const vector<int>& a, const vector<int>& b)
{    
    return a[1] < b[1];
}



int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(),targets.end(),cmp);
    
    pair<int,int> Range;
    Range.first = 0;
    Range.second = 0;
    
    for(vector<int> Coord : targets)
    {
        if(Coord[0] >= Range.second)
        {
            answer++;
            Range.first = Coord[0];
            Range.second = Coord[1];
            continue;
        }
              
    }
    
    return answer;
}



















