#include<vector>
#include<queue>


using namespace std;

int dx[4] = {0, 1 , 0 ,-1};
int dy[4] = {-1, 0 , 1 ,0};

int CheckDis[102][102];


int solution(vector<vector<int> > maps)
{
    
    int rows = maps.size();
    int columns = maps[0].size();
    
    queue<pair<int,int>> q;
    
    q.push({0,0});
    
    CheckDis[0][0] = 1;
    
    while(!q.empty())
    {
        pair<int,int> p = q.front();
        q.pop();
        
        for(int i = 0; i < 4; ++i)
        {
            int x = p.first + dx[i];
            int y = p.second + dy[i];
            
            if(x < 0 || x >= rows || y < 0 || y >= columns)
                continue;
            
            if(CheckDis[x][y] != 0)
                continue;
            
            if(maps[x][y] == 0)
                continue;
            
            CheckDis[x][y] = CheckDis[p.first][p.second] + 1;
            q.push({x,y});
        }  
    }  
    
    if(CheckDis[rows-1][columns-1] == 0)
        return -1;
    else
        return CheckDis[rows-1][columns-1];
}