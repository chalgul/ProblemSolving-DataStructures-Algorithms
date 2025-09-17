#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <functional>
#include <set>
using namespace std;


int N;
int K;

vector<pair<int, int>> ObjectList;

//x번째 물건까지 고려한다고 가정했을 때, y만큼 무게 제한이 있는 상황에서 넣을 수 있는 최대 가치 값.
int Table[102][100002];

int main() {
   
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    int Weight = 0, Value = 0;


    for (int i = 0; i < N; i++)
    {
        cin >> Weight >> Value;

        pair<int, int> ObjectInfo = { Weight,Value };

        ObjectList.push_back(ObjectInfo);
    }
    //무게 순으로 오름차순 정렬, 무게가 동일하면 가치가 낮은 것이 앞순번에 배치
    sort(ObjectList.begin(), ObjectList.end());

    //제한 무게 : 무게 순으로 정렬된 물건 리스트 중 가장 앞쪽에 있는 물건의 무게 기준부터 시작하기
    //그보다 낮은 경우에는 모두 가치 값이 0으로 고정
    for (int i = ObjectList[0].first; i <= K; i++)
    {
        //물품 개수
        for (int j = 1; j <= N; j++)
        {
            //현재 포커싱하는 물건 무게가 배낭 전체 무게보다 큰 경우
            if (i < ObjectList[j - 1].first)
            {
                //그냥 담지 않고 이전 물건까지 기준으로 최대 가치 값을 그대로 물려받음
                Table[j][i] = Table[j - 1][i];
            }
            //현재 포커싱하는 물건 무게보다는 제한 무게가 더 크거나 같은 경우
            else if(i >= ObjectList[j - 1].first)
            {
                //현재 포커싱 중인 물건을 담지 않는 경우와, 
                // 담는 경우 해당 무게를 제외하고 남은 베낭 무게 기준으로 담을 수 있는 최대값을 합한 것 중 더 높은 가치를 할당
                Table[j][i] = max(Table[j - 1][i], Table[j - 1][i - ObjectList[j - 1].first] + ObjectList[j - 1].second);
            }
        }
    }

    cout << Table[N][K];



    return 0;
}

