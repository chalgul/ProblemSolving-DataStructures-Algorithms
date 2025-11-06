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
#define X first
#define Y second
using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int people_num;
    cin >> people_num;

    stack<pair<int, int>> st;
    int now, cnt_same_height = 0;
    long long  cnt_pair = 0;

    for (int i = 0; i < people_num; ++i) {
        cin >> now;

        //같은 키의 사람 수 1로 초기화
        cnt_same_height = 1;

        //스택이 비어있지 않고, 다음 사람의 키가 stack의 top보다 크다면
        //stack에 들어있는 값들은 now 너머의 사람들을 절대 볼 수가 없다.
        while (!st.empty() && st.top().first < now) {
            //now 짝 지어지는 경우의 수 추가
            cnt_pair += st.top().second;
            st.pop();
        }

        if (!st.empty()) 
        {
            //stack top first와 동일한 키를 가지는 사람이 들어온 경우
            if (st.top().first == now) {
                //앞서 같은 키를 가진 사람들과 모두 짝을 이룰 수 있음
                cnt_pair += st.top().second;
                //새로들어온 사람까지 합쳐서 같은 키를 가지는 사람의 수가 1 늘어남
                cnt_same_height = (st.top().second + 1);

                //stack 사이즈가 1개 이상이면 그 전에 더 큰 사람들이 있다는 것
                //더 큰 사람 중 가장 가까이 있는 사람과도 짝을 이룰 수 있다.
                //그 너머는 보이지 않는다.
                if (st.size() > 1)
                    ++cnt_pair;

                //같은 키를 가지는 사람이 들어온 정보로 새롭게 갱신하기 전에 기존의 정보 pop
                st.pop();
            }
            //stack top first 값보다 now가 작은 경우에만 들어온다.
            //이전에 while 문에서 now가 큰 경우에 대해서 모든 짝 계산을 마치고 stack에서 꺼냈기 때문
            else {
                //stack의 top이 now보다 크기 때문에 이뤄질 수 있는 짝은 1개가 유일
                ++cnt_pair;
            }
        }

        //현재 키와 push하는 시점에 스택에 쌓여있는 같은 키의 사람 수를 저장
        st.push(make_pair(now, cnt_same_height));
    }

    cout << cnt_pair << '\n';

    return 0;
}