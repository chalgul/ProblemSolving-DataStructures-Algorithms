#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;

    // 1. 이분 탐색 범위 설정
    int start = 1;
    int end = *max_element(diffs.begin(), diffs.end());
    
    // 2. 이분 탐색 시작
    while (start <= end) {
        // 2-1. 매번 새로운 mid(테스트할 숙련도) 값을 계산
        int mid = start + (end - start) / 2;
        
        long long totalSpendingTime = 0;

        // 2-2. 'mid' 숙련도로 모든 퍼즐을 풀 때의 총 시간을 계산
        for (size_t i = 0; i < diffs.size(); ++i) {
            // 기본 소요 시간은 항상 추가됨
            totalSpendingTime += times[i];
            
            // 숙련도가 부족할 경우 추가 시간 계산
            if (diffs[i] > mid) {
                long long failures = diffs[i] - mid;
                long long penalty_per_failure = 0;

                penalty_per_failure = times[i] + times[i-1];
                
                totalSpendingTime += failures * penalty_per_failure;
            }
            
            // 최적화: 계산 중간에 이미 limit을 넘었다면 더 볼 필요 없이 중단
            if (totalSpendingTime > limit) {
                break;
            }
        }

        // 2-3. 계산된 총 시간과 limit을 비교하여 범위 조정
        if (totalSpendingTime <= limit) {
            // 성공: 이 레벨(mid)은 가능. 더 낮은 최소 레벨을 찾기 위해 범위를 아래로 좁힘
            answer = mid;
            end = mid - 1;
        } else {
            // 실패: 이 레벨(mid)은 불가능. 더 높은 레벨이 필요하므로 범위를 위로 좁힘
            start = mid + 1;
        }
    }

    return answer;
}