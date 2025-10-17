#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N, M;

vector<int> Parent;

int find(int Node)
{
    if(Parent[Node] < 0)
    {
        return Node;
    }
    return Parent[Node] = find(Parent[Node]);
}
bool uni(int A, int B)
{
    //부모 그룹 정보
    int PA = find(A);
    int PB = find(B);
    
    if(PA == PB)
        return false; 
    
    //B가 rank가 더 깊은 경우  
    if(Parent[PA] > Parent[PB])
    {
        swap(PA,PB);
    }
    
    if(Parent[PA] == Parent[PB])
    {
        Parent[PA]--;
    }
    Parent[PB] = PA;
    return true;
}




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    
    Parent.resize(N+1,-1);
    
    int A,B,C;
    
    for(int i = 0; i < M; ++i)
    {
        cin >> A >> B >> C;
        
        //union
        if(A == 0)
        {
            uni(B,C);
        }
        //find
        else if(A == 1)
        {
            if(find(B) == find(C))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        
        
    }
    
    return 0;
}