#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <set>
#include <sstream>
#include <tuple>
#include <stack>
#include <algorithm>

using namespace std;


int N;

vector<pair<int, int>> Meetings;

//끝나는 시간
vector<int> Room;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int St, End;
    for (int i = 0; i < N; ++i)
    {
        cin >> St >> End;
        Meetings.push_back({ St,End });
    }

    //회의 일정을 시작 시간 기준으로 오름차순 정렬
    sort(Meetings.begin(), Meetings.end());
    
    Room.resize(1, 0);

    for (auto Meet : Meetings)
    {
        bool NeedNewRoom = true;
        for (auto& RoomState : Room)
        {
            //빈 회의실 존재
            if (RoomState <= Meet.first)
            {
                RoomState = Meet.second;
                NeedNewRoom = false;
                break;
            }
        }
        //새로운 회의실 필요한 경우
        if (NeedNewRoom)
        {
            Room.push_back(Meet.second);
        }
    }

    cout << Room.size();

    return 0;
}