#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <set>
#include <sstream>
#include <tuple>
#include <stack>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <cmath>
#include <string>
using namespace std;

//비용, 시작, 끝
vector<tuple<long long, int, int>> TP;

int N;

//인덱스 x가 속한 그룹 정보를 가진다.
//값이 0보다 작을 경우는 해당 인덱스가 그룹의 root
int Parent[1002];

long long ReturnVal = 0;
int FlowCnt = 0;


//경로압축
int Find(int Node)
{
    if (Parent[Node] < 0)
    {
        return Node;
    }

    return Parent[Node] = Find(Parent[Node]);
}


bool Uni(int A, int B)
{
    A = Find(A);
    B = Find(B);

    //이미 같은 그룹인 경우
    if (A == B)
    {
        return false;
    }

    //무조건 B가 A의 자식으로 들어오도록 하기
    //그룹의 depth가 늘어나지 않도록 하는 조치
    if (Parent[A] > Parent[B])
    {
        swap(A, B);
    }
    else if (Parent[A] == Parent[B])
    {
        Parent[A]--;
    }
    
    Parent[B] = A;
    return true;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int Input = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> Input;

            if (Input != 0)
            {
                TP.push_back({ Input,i,j });
            }
        }
    }

    if (N == 1)
    {
        cout << 0;
        return 0;
    }

    sort(TP.begin(), TP.end());
    
    fill(Parent, Parent + N, -1);

    for (auto Node : TP)
    {
        auto [W, St, End] = Node;

        if (Uni(St, End))
        {
            FlowCnt++;
            ReturnVal += W;

            if (FlowCnt == N - 1)
            {
                cout << ReturnVal;
                break;
            }
        }
    }

    return 0;
}