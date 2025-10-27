#include <string>
#include <vector>
#include <stack>
#include <map>
#include <tuple>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;


//시작 시간(min), 소요 시간, 과제 이름 순으로 저장
//시작시간이 이른순으로 정렬됨
priority_queue<tuple<int, int, string>, vector<tuple<int, int, string>>, greater<tuple<int, int, string>>> PQ;

//중단된 과제 저장
//남은 시간(min) , 과제 이름 순으로 저장
stack<tuple<int, string>> Pause;


void ChangeToMin(vector<vector<string>> P)
{
    for (auto Info : P)
    {
        //min으로 변환
        string Hour = Info[1].substr(0, 2);
        string Min = Info[1].substr(3, 2);

        int TotalMin = stoi(Hour) * 60 + stoi(Min);
        int SpendTime = stoi(Info[2]);

        PQ.push({ TotalMin, SpendTime, Info[0] });
    }
}



using namespace std;

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;

    //과제를 시작할 시간이 되면 진행중이던 과제 중단하고 그 과제를 최우선위로 바로 시작

    //진행중이던 과제가 끝난 경우 새로 시작할 과제가 없을 때는 중단한 과제들 중 가장 최근에 중단한 과제 시작(stack 활용하면 좋을 듯)

    ChangeToMin(plans);


    //현재 진행중인 과제
    //남은 시간, 과제 정보
    tuple<int, string> ProceedSub = { -1, " " };

    //현재 시간
    int CurMin = 0;

    int StartTime, SpendTime;
    string Subject;

    while (CurMin <= 60 * 24)
    {
        if (!PQ.empty())
        {
            tuple<int, int, string> New = PQ.top();
            auto [A, B, C] = New;
            StartTime = A;
            SpendTime = B;
            Subject = C;
        }

        auto [LeftTime, Sub] = ProceedSub;

        //진행 중인 과제가 끝난 경우
        if (LeftTime == 0)
        {
            answer.push_back(Sub);
            get<0>(ProceedSub) = -1;

            //새롭게 시작할 과제가 없는 경우에는 중단된 과제 중에 최근에 중단된 과제를 진행
            if (PQ.empty() || StartTime > CurMin)
            {
                //중단된 과제가 있는 경우 다시 실행
                if (!Pause.empty())
                {
                    tuple<int, string> PauseSub = Pause.top();
                    Pause.pop();
                    auto [PauseLeftTime, PauseSubName] = PauseSub;
                    get<0>(ProceedSub) = PauseLeftTime;
                    get<1>(ProceedSub) = PauseSubName;
                }

            }
        }

        //새롭게 시작할 과제가 남아있을 경우에만 check
        if (!PQ.empty())
        {
            //새로운 과제를 시작할 시간에 도달
            if (StartTime == CurMin)
            {
                //진행중인 과제가 있는 경우
                if (get<0>(ProceedSub) > 0)
                {
                    //진행중인 과제를 중단 목록에 추가
                    Pause.push(ProceedSub);
                }
                ProceedSub = { SpendTime, Subject };
                PQ.pop();
            }
        }
        //시간 1분 증가
        CurMin++;
        //현재 진행중인 과제 LeftTime 1분 감소
        if (get<0>(ProceedSub) != -1)
            get<0>(ProceedSub)--;

    }


    return answer;
}

