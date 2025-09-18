#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>


using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
bool IsOutdoor(const vector<string>& Copy, int a, int b)
{
    int Vis[52][52] = {0};
    
    queue<pair<int,int>> Q;
    Q.push({a,b});
    Vis[a][b] = 1;
    while(!Q.empty())
    {
        pair<int,int> Cur = Q.front();
        Q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int X = Cur.first + dx[i];
            int Y = Cur.second + dy[i];
            
            if(X < 0 || X >= Copy.size() || Y < 0 || Y >= Copy[0].size())
            {
                return true;
            }
            //이미 방문
            if(Vis[X][Y] == 1)
                continue;
            //공백이 아니면 방문 불가
            if(Copy[X][Y] != ' ')
                continue;
            
            Q.push({X,Y});
            Vis[X][Y] = 1;
        }
    }
    return false;
    
    
}


int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    
    
    //가장자리에 있느냐를 확인하는 방법은 행 또는 열 방향으로 +1/-1했을 때, 해당 지점이 바깥 혹은 빈 문자열이면 가장자리임을 알 수 있음
    
    //크레인의 경우에는 그냥 전체 스트링 중 그녀석 있으면 다 꺼내기
    
    //한 번 꺼냈으면 해당 지점을 공백 문자열을 넣어줄것임.
    for(string Request : requests)
    {
        //지게차
        if(Request.size() == 1)
        {
            char RequestChar = Request[0];
            vector<string> CopyCat = storage;
            //컨테이너 전체 순회
            for(int i = 0; i < storage.size(); i++)
            {
                for(int j = 0; j < storage[i].size(); j++)
                {
                    if(storage[i][j] == RequestChar)
                    {
                        /*
                        //가장자리인지 check!
                        //위로 벗어남
                        if(i - 1 < 0)
                        {
                            storage[i][j] = ' ';
                            continue;
                        }
                        //아래로 벗어남
                        if(i + 1 == storage.size())
                        {
                            storage[i][j] = ' ';
                            continue;
                        }
                        //좌로 벗어남
                        if(j - 1 < 0)
                        {
                            storage[i][j] = ' ';
                            continue;
                        }
                        //우로 벗어남
                        if(j + 1 == storage[i].size())
                        {
                            storage[i][j] = ' ';
                            continue;
                        }
                        */
                        //바깥과 연결되었는지 판단
                        if(IsOutdoor(CopyCat,i,j))
                        {
                            storage[i][j] = ' ';
                            continue;
                        }
                        
                        
                        /*
                        bool Empty = true;
                        //위로 쭉 밀기
                        for(int k = i; k >= 0; k--)
                        {
                            if(CopyCat[k][j] != ' ')
                            {
                                Empty = false;
                                break;
                            }
                        }
                        if(Empty)
                        {
                            storage[i][j] = ' ';
                            continue; 
                        }
                        else
                            Empty = true;
                        
                        //아래로 쭉 밀기
                        for(int k = i; k < storage.size(); k++)
                        {
                             if(CopyCat[k][j] != ' ')
                            {
                                Empty = false;
                                break;
                            }
                        }
                        if(Empty)
                        {
                            storage[i][j] = ' ';
                            continue; 
                        }
                        else
                            Empty = true;
                        
                        //좌로 쭉 밀기
                        for(int k = j; j >=0; k--)
                        {
                            if(CopyCat[i][k] != ' ')
                            {
                                Empty = false;
                                break;
                            }
                        }
                        if(Empty)
                        {
                            storage[i][j] = ' ';
                            continue; 
                        }
                        else
                            Empty = true;
                        //우로 쭉 밀기
                        for(int k = j; k < storage[i].size(); k++)
                        {
                             if(CopyCat[i][k] != ' ')
                            {
                                Empty = false;
                                break;
                            }
                        }
                        if(Empty)
                        {
                            storage[i][j] = ' ';
                            continue; 
                        }
                        else
                            Empty = true;
                        
                        */
                        
                    }
                }
            }
        }
        //크레인
        else if(Request.size() == 2)
        {
            for(int i = 0; i < storage.size(); i++)
            {
                for(int j = 0; j < storage[i].size(); j++)
                {
                    if(storage[i][j] == Request[0])
                    {
                         storage[i][j] = ' ';
                    }
                }
            }
        }
    }
    
    
    
       for(int i = 0; i < storage.size(); i++)
       {
                for(int j = 0; j < storage[i].size(); j++)
                {
                    if(storage[i][j] != ' ')
                    {
                        answer++;
                    }
                }
       }
    
    
    
    return answer;
}