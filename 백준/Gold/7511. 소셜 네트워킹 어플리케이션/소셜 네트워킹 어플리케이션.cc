#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

int N, M;
int TestCase;
vector<int> Parent;

int find(int Node)
{
    if (Parent[Node] < 0)
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

    if (PA == PB)
        return false;

    //B가 rank가 더 깊은 경우  
    if (Parent[PA] > Parent[PB])
    {
        swap(PA, PB);
    }

    if (Parent[PA] == Parent[PB])
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
    cin >> TestCase;

    Parent.resize(1000002,-1);
    int User, Relation;
    for (int t = 1; t <= TestCase; ++t)
    {
        cin >> User;
        fill(Parent.begin(), Parent.end(), -1);
        cin >> Relation;
        int A, B;
        for (int i = 0; i < Relation; ++i)
        {
            cin >> A >> B;
            uni(A, B);
        }
        int Pairs;
        cin >> Pairs;
        cout << "Scenario " << t << ":\n";
        for (int i = 0; i < Pairs; ++i)
        {
            cin >> A >> B;
            if (find(A) == find(B))
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        cout << "\n";
    }
    return 0;
}