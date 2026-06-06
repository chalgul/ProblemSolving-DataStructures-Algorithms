#include <string>
#include <vector>
#include <queue>

using namespace std;



int DisWords[52];




int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    
    queue<int> Q;
    
    for(int k = 0; k < words.size(); ++k)
    {
        int count  = 0;
        for(int i = 0; i < words[k].size(); ++i)
        {
            if(words[k][i] != begin[i])
            {
                count++;
            }
        }
        if(count == 1)
        {
            Q.push(k);
            DisWords[k] = 1;
            if(words[k] == target)
                return 1;
        }
    }
    
    
    while(!Q.empty())
    {
        int W = Q.front();
        Q.pop();
        
        for(int k = 0; k < words.size(); ++k)
        {
            int count  = 0;
            for(int i = 0; i < words[k].size(); ++i)
            {
                if(words[k][i] != words[W][i])
                {
                    count++;
                }
            }
            if(count == 1 && DisWords[k] == 0)
            {
                Q.push(k);
                DisWords[k] = DisWords[W] + 1;
                if(words[k] == target)
                    return DisWords[k];
            }
        }
    
    }
    
    return 0;
}