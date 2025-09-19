#include <string>
#include <vector>
#include <queue>

using namespace std;

int FirstBoard[102][102] = {0};
int SecondBoard[102][102] = {0};

int DisFirst[102][102] = {0};
int DisSecond[102][102] = {0};


int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int solution(vector<string> maps) {
    int answer = 0;
    
    
    pair<int,int> StartPos;

    for(int i = 0; i < maps.size(); i++)
    {
        if(maps[i].find("S") != string::npos)
        {
            StartPos = {i,maps[i].find("S")};
        }
    }
    

    
    queue<pair<int,int>> Q;
    Q.push({StartPos.first,StartPos.second});
    DisFirst[StartPos.first][StartPos.second] += 1;
    
    int LeverTime = 0;
    pair<int,int> LeverPos;
    bool IsLeverFound = false;
    
    while(!Q.empty())
    {
        pair<int,int> Cur = Q.front();
        Q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int X = Cur.first + dx[i];
            int Y = Cur.second + dy[i];
            
            if(X < 0 || X >= maps.size() || Y <0 || Y >= maps[0].size())
                continue;
            if(DisFirst[X][Y] != 0 || maps[X][Y] == 'X')
                continue;
            if(maps[X][Y] == 'L')
            {
                LeverTime = DisFirst[Cur.first][Cur.second];
                LeverPos = {X,Y};
                IsLeverFound = true;
                break;
            }
            Q.push({X,Y});
            DisFirst[X][Y] = DisFirst[Cur.first][Cur.second] + 1;
        }
        
        if(IsLeverFound)
            break;
    }
    
    if(!IsLeverFound)
    {
        return -1;
    }
    
    
    
    queue<pair<int,int>> SQ;
    SQ.push({LeverPos.first,LeverPos.second});
    DisSecond[LeverPos.first][LeverPos.second] += 1;
    
    
    int ExitTime = 0;
    
    while(!SQ.empty())
    {
        pair<int,int> Cur = SQ.front();
        SQ.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int X = Cur.first + dx[i];
            int Y = Cur.second + dy[i];
            
            if(X < 0 || X >= maps.size() || Y <0 || Y >= maps[0].size())
                continue;
            if(DisSecond[X][Y] != 0 || maps[X][Y] == 'X')
                continue;
            if(maps[X][Y] == 'E')
            {
                return DisSecond[Cur.first][Cur.second] + LeverTime;
            }
            SQ.push({X,Y});
            DisSecond[X][Y] = DisSecond[Cur.first][Cur.second] +1;
        }
    }
    
    
    
    return -1;
}