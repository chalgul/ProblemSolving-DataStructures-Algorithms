#include <string>
#include <vector>

#include <set>

using namespace std;

set<int> unique_combinations; // 중복되지 않은 유저 조합을 저장할 셋
vector<bool> visited;

// 문자열이 매칭되는지 확인하는 함수
bool isMatch(const string& user, const string& ban) {
    if (user.size() != ban.size()) return false;
    for (int i = 0; i < user.size(); ++i) {
        if (ban[i] != '*' && ban[i] != user[i]) return false;
    }
    return true;
}

// DFS 백트래킹 함수
void dfs(int ban_index, int current_bit, const vector<string>& user_id, const vector<string>& banned_id) {
    // 모든 banned_id를 매칭시키는 데 성공했다면
    if (ban_index == banned_id.size()) {
        unique_combinations.insert(current_bit); // 비트 정보를 셋에 삽입 (자동 중복 제거)
        return;
    }

    for (int i = 0; i < user_id.size(); ++i) {
        // 이미 다른 ban_id에 매칭된 유저라면 패스
        if (visited[i]) continue;

        // 매칭이 가능하다면 선택하고 다음 단계로 진행
        if (isMatch(user_id[i], banned_id[ban_index])) {
            visited[i] = true;
            // i번째 유저를 포함시켰음을 비트로 표시 (ex: 3번째 유저면 1 << 3)
            dfs(ban_index + 1, current_bit | (1 << i), user_id, banned_id); 
            visited[i] = false; // 백트래킹 원래대로 복구
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    visited.resize(user_id.size(), false);
    
    // 0번째 ban_id부터 탐색 시작, 현재 선택된 유저 비트는 0
    dfs(0, 0, user_id, banned_id);
    
    return unique_combinations.size();
}