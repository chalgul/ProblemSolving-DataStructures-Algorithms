#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

//효율을 따지려면 이미 한 번 BFS 돌린 영역은 다시 안돌리고 재활용 해야 함.

//key : 시추 고유 ID, value : 너비 값
map<int,int> BFSResult;



int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int ID = 1;


int solution(vector<vector<int>> land) {
    int answer = 0;
    
    int row = land.size();
    int col = land[0].size();
    
     int Vis[502][502] = {0};
    //가로 길이
    for(int i = 0; i < col; ++i)
    {
        int TotalVal = 0;
        int Val = 0;
        set<int> IsAlreadySearch;
        //세로 길이
        for(int j = 0; j < row; ++j)
        {
            Val = 0;
            
            //석유 시추 가능
            if(land[j][i] == 1 && Vis[j][i] == 0)
            {
                queue<pair<int,int>> Q;
                Q.push({j,i});
                Vis[j][i] = ID;
                ++Val;
                
                while(!Q.empty())
                {
                    pair<int,int> Cur = Q.front();
                    Q.pop();
                    
                    for(int i = 0; i < 4; i++)
                    {
                        int X = Cur.first + dx[i];
                        int Y = Cur.second+ dy[i];
                        
                        if(X < 0 || X >= row || Y < 0 || Y >= col)
                            continue;
                        if(land[X][Y] != 1 || Vis[X][Y] != 0)
                            continue;
                        
                        ++Val;
                        Vis[X][Y] = ID;
                        Q.push({X,Y});
                    }
                }
                IsAlreadySearch.insert(ID);
                BFSResult[ID] = Val;
                ID++;
            }
            //이미 시추했던 석유
            else if(land[j][i] == 1 && Vis[j][i] != 0)
            {
                if(IsAlreadySearch.find(Vis[j][i]) != IsAlreadySearch.end())
                {
                    continue;
                }
                
                Val = BFSResult.find(Vis[j][i])->second;
                IsAlreadySearch.insert(Vis[j][i]);
            }
            TotalVal += Val;
        }
        
        answer = max(answer, TotalVal);    
    }
    
    
    return answer;
}