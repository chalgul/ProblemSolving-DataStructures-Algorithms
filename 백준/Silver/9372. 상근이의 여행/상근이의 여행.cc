#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <set>
#include <sstream>
#include <tuple>

using namespace std;

int TestCase;
int N, M;


/*
문제 풀이 아이디어
모든 나라를 여행하기 위한 가장 적은 비행기를 타는 경우를 구하는 문제
문제 조건에서 A에서 B나라를 갈 때 다른 나라를 경유해도 상관 없다는 조건을 따져보면
결국 모든 간선에 대해서 가중치 값이 1인 최소 스패닝 트리를 구하는 문제임을 알 수 있음.
트리는 노드-1개의 간선이 존재하므로 답은 노드-1 x 1 로 고정
*/

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> TestCase;

    for (int i = 0; i < TestCase; ++i)
    {
        cin >> N >> M;

        int A, B;
        for (int j = 1; j <= M; ++j)
        {
            cin >> A >> B;
        }
      
     
        cout << N - 1 << "\n";

    }


    return 0;
}
