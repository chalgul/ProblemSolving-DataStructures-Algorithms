#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <stack>
using namespace std;

multiset<int> NumList;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    stack<int> s;
    for (vector<int>::size_type i = 0; i < numbers.size(); i++) {
        int n = numbers[i];
        while (!s.empty() && numbers[s.top()] < n) {
            answer[s.top()] = n;
            s.pop();
        }
        s.push(i);        
    }
    return answer;
}