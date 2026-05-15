#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<tuple<int, int, int>> BridgeInfo;

vector<int> Parent;


int Find(int Node)
{
    if(Parent[Node] < 0)
        return Node;
    
    return Parent[Node] = Find(Parent[Node]);
}

bool Uni(int A, int B)
{
    A = Find(A);
    B = Find(B);
    
    if(A == B)
        return false; 
    
    if(Parent[A] < Parent[B])
        swap(A,B);
    
    if(Parent[A] == Parent[B])
        Parent[B]--;
    
    Parent[A] = B;
    return true;
}


int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int cnt = 0;
    
    for(vector<int> Info : costs)
    {
        BridgeInfo.push_back({Info[2],Info[0],Info[1]});
    }
    
    //튜플 오름차순 정렬
    sort(BridgeInfo.begin(), BridgeInfo.end());
    
    Parent.resize(n+1, -1);
    
    for(int i = 0; i < costs.size(); ++i)
    {
        auto [weight, st, end] = BridgeInfo[i];
        
        if(Uni(st,end))
        {
            answer += weight;
            cnt++;
            if(cnt == n-1)
                return answer;
        }
        else
        {
            continue;
        }    
    }
        
    return answer;
}