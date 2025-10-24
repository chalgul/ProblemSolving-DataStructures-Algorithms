#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>
#include <utility>
#include <functional>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, less<int>> PQ1;
priority_queue<int, vector<int>, greater<int>> PQ2;

string solution(string s) {
    string answer = "";
    
    stringstream ST(s);
    
    int Input;
    
     int Num = 0;
    while(ST >> Input)
    {
        PQ1.push(Input);
        PQ2.push(Input);
    }
    
    int MaxNum = PQ1.top();
    int MinNum = PQ2.top();
  
    answer += to_string(MinNum);
    
    answer += " ";
    
    answer += to_string(MaxNum);
    
    return answer;
}