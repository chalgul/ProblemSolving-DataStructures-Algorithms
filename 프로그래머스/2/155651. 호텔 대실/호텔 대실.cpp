#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;


vector<pair<int,int>> Time;

//각 룸의 퇴실 시간 저장
vector<int> CheckRoom;

void SaveTime(const vector<string>& TimeInfo)
{
    pair<int,int> TempTime = {0,0};
    
    TempTime.first = stoi(TimeInfo[0].substr(0,2)) * 60 + stoi(TimeInfo[0].substr(3,2));
    TempTime.second = stoi(TimeInfo[1].substr(0,2)) * 60 + stoi(TimeInfo[1].substr(3,2));
    
    Time.push_back(TempTime);
}

//입실 시간 기준으로 오름차순 정렬
bool cmp(const pair<int,int>& A, const pair<int,int>& B)
{
    if(A.first < B.first)
    {
        return true;
    }
    else
    {
        return false;
    }
}





int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    for(vector<string>& S : book_time)
    {
        SaveTime(S);
    }
    
    sort(Time.begin(), Time.end(), cmp);
    
    
    CheckRoom.push_back(Time[0].second + 10);
    answer++;
    
    size_t Size = Time.size();
    
    
    for(size_t i = 1; i < Size; ++i)
    {
        bool NewRoom = true;
        
        for(size_t j = 0; j < CheckRoom.size(); ++j)
        {
            //해당 room 사용 가능
            if(CheckRoom[j] <= Time[i].first)
            {
                CheckRoom[j] = Time[i].second + 10;
                NewRoom = false;
                break;
            }
        }
        
        if(NewRoom)
        {
            CheckRoom.push_back(Time[i].second + 10);
            answer++;
        } 
        
    }
    
    
    
    
    
    return answer;
}