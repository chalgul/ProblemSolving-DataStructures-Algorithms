#include <iostream>
#include<string>
#include<list>
#include<stack>


using namespace std;

int solution(string s)
{
    
    stack<char> StackString;
    
    for(char word : s)
    {
        if(StackString.empty())
        {
            StackString.push(word);
        }
        else if(StackString.top() == word)
        {
            StackString.pop();
        }
        else
        {
            StackString.push(word);
        }
    }
    
    
    if(StackString.empty())
    {
        return 1;
    }
    
    return 0;
}