#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// 전역 배열의 이름을 매개변수와 다르게 선언 (최대 1000이므로 크기는 1005면 충분)
int weight_counts[1005];

long long solution(vector<int> weights) {
    long long answer = 0;
    set<int> UnitWeights_Set;
    
    // 1. 카운팅 및 중복 제거
    for(int w : weights) {
        UnitWeights_Set.insert(w);
        weight_counts[w]++; // 전역 배열에 개수 누적
    }
    
    // 2. set을 vector로 변환 (자동으로 오름차순 정렬됨)
    vector<int> UnitWeights(UnitWeights_Set.begin(), UnitWeights_Set.end());
    int size = UnitWeights.size();
    
    // 3. 서로 다른 몸무게 간의 짝꿍 계산 (i < j 관계 유지)
    for(int i = 0; i < size; ++i) {
        for(int j = i + 1; j < size; ++j) { // j는 i+1부터 시작하여 중복 방지
            int w1 = UnitWeights[i];
            int w2 = UnitWeights[j]; // 무조건 w1 < w2 인 상태
            
            // w1이 작고 w2가 크므로 가능한 비율은 2:3, 2:4(1:2), 3:4 뿐입니다.
            if(w1 * 3 == w2 * 2 || w1 * 4 == w2 * 2 || w1 * 4 == w2 * 3) {
                // 단순히 ++이 아니라 (w1의 개수 * w2의 개수)를 더해줌
                answer += (long long)weight_counts[w1] * weight_counts[w2];
            }
        }
    }
    
    // 4. 같은 몸무게를 가진 사람들끼리의 조합(nCr) 계산
    for(int i = 100; i <= 1000; ++i) {
        if(weight_counts[i] > 1) {
            long long cnt = weight_counts[i];
            answer += (cnt * (cnt - 1)) / 2;
        }
    }
    
    return answer;
}