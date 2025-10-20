#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

int parent[500002];

int find(int Node)
{
    if(parent[Node] < 0)
        return Node;
    
    return parent[Node] = find(parent[Node]);
}

bool uni(int A, int B)
{
    A = find(A);
    B = find(B);
    
    if(A == B)
        return false;
    
    if(parent[A] > parent[B])
    {
        swap(A,B);
    }
    
    if(parent[A] == parent[B])
    {
        parent[A]--;
    }
    
    parent[B] = A;
    
    return true;
}


int N,M;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> N >> M;
    
    fill(parent, parent + N, -1);
    
    int A,B;
    for(int i = 1; i <= M; ++i)
    {
        cin >> A >> B;
        if(uni(A,B) == false)
        {
            cout << i;
            return 0;
        }
    }
    
    cout << 0;
    return 0;
}

