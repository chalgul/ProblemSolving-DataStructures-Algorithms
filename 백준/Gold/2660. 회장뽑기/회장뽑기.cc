#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits> // 무한대 값 사용을 위해 추가
using namespace std;

// N 최대 50, 배열 크기 51x51 (1-based index 사용)
int Distance[51][51];
int N;
const int INF = 1e9; // 충분히 큰 값으로 무한대 설정

int main()
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    // 1. 초기화
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (i == j)
                Distance[i][j] = 0;
            else
                Distance[i][j] = INF;
        }
    }

    // 2. 간선 입력
    int A, B;
    while (true)
    {
        cin >> A >> B;

        if (A == -1 && B == -1) // 문제 조건에 따라 A가 -1이면 종료
            break;

        Distance[A][B] = 1;
        Distance[B][A] = 1; // 무방향 그래프
    }

    // 3. 플로이드-워셜 알고리즘 (모든 쌍 최단 경로)
    // k: 경유지, i: 출발지, j: 도착지
    for (int k = 1; k <= N; ++k)
    {
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                // INF 값의 합이 int 범위를 초과하는 것을 방지하기 위해 (i,k) 또는 (k,j)가 INF인 경우 체크 생략
                if (Distance[i][k] != INF && Distance[k][j] != INF)
                {
                    Distance[i][j] = min(Distance[i][j], Distance[i][k] + Distance[k][j]);
                }
            }
        }
    }

    // 4. 회원 점수 계산 및 회장 후보 찾기
    int ResultMinDis = N + 1; // 가능한 최대 점수(N-1)보다 큰 값으로 초기화
    vector<int> Candi;

    for (int i = 1; i <= N; ++i) // i번 회원
    {
        int MaxDis = 0; // i번 회원의 점수
        
        for (int j = 1; j <= N; ++j)
        {
            // 도달할 수 없는 경우가 있다고 가정한다면 (INF라면) 처리 필요
            // 하지만 이 문제에서는 친구 관계는 연결된 하나의 그래프를 형성한다고 가정하는 것이 일반적
            MaxDis = max(Distance[i][j], MaxDis);
        }

        // 도달 불가능한 회원(MaxDis == INF)은 점수 계산에서 제외되므로 
        // 문제 조건상 모든 회원이 연결되어 있다고 가정함.

        if (MaxDis < ResultMinDis)
        {
            Candi.clear();
            Candi.push_back(i);
            ResultMinDis = MaxDis;
        }
        else if (MaxDis == ResultMinDis)
        {
            Candi.push_back(i);
        }
    }

    // 5. 결과 출력 (정렬은 필요 없음. 이미 순서대로 탐색하며 넣었으므로)
    cout << ResultMinDis << " " << Candi.size() << "\n";
    for (int C : Candi)
    {
        cout << C << " ";
    }
    cout << "\n";

    return 0;
}