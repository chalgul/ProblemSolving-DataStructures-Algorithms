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

//N : 도시 크기 NxN
//M : 폐업시키지 않을 치킨집 수
int N, M;

//도시 구성 보드판
int Board[51][51];

int DefaultChickenPlace = 0;
int DefaultHousePlace = 0;

//치킨 거리를 따지기 위한 BFS를 수행할 보드
int CheckBoard[51][51];

//치킨집 위치 저장
vector<pair<pair<int,int>,bool>> ChickenPlace;
//집 위치 저장
vector<pair<int,int>> HousePlace;


//BFS 수행을 위한 큐
queue<pair<int, int>> Q;

//도시의 최소 치킨 거리
int ResultMinChickenDis = 100000;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };




//도시의 치킨 거리를 구하는 아이디어
//도시에 존재하는 모든 집들이 각각 치킨집을 만날 때까지 BFS 수행
//각 집마다 도출되는 치킨 거리를 총합하면 해당 도시 상태에서의 치킨 거리 도출 가능


//도시의 치킨 거리 최솟값을 구하는 아이디어
//현재 도시에 존재하는 치킨 집 수 - M 을 계산하여 나오는 숫자가 폐업해야 하는 치킨집 수
//모든 치킨집의 위치를 별도의 Vector에 담아놓고 특정 치킨 집을 폐업시킬 것이냐 아니냐를 기반으로 하는 상태 공간 트리 구성
//BaseCondition에 도달하는 순간의 도시 상태를 기준으로 BFS 혹은 별도의 거리 계산 로직을 수행하여 치킨 거리 도출
//상태 공간 트리를 통해 따져본 모든 경우의 수에 도출된 치킨 거리 중 최솟값 출력


//
//int BFS()
//{
//    //도시 내에 존재하는 모든 집들의 치킨 거리를 구해야 함.
//    int TotalChickenDis = 0;
//
//
//    for(int i = 0; i < DefaultHousePlace; i++)
//    {
//        Q.push({ HousePlace[i].first,HousePlace[i].second });
//        CheckBoard[HousePlace[i].first][HousePlace[i].second] = 1;
//
//        while (!Q.empty())
//        {
//            pair<int,int> Pos = Q.front();
//            Q.pop();
//
//            int X, Y = 0;
//            for (int j = 0; j < 4; j++)
//            {
//                X = Pos.first + dx[j];
//
//                Y = Pos.second + dy[j];
//
//                //도시 범위를 벗어나는 경우
//                if (X < 0 || X >= N || Y < 0 || Y >= N)
//                {
//                    continue;
//                }
//                //확장하려는 위치가 치킨집도 아니면서 이미 탐색한 위치일 경우
//                if (CheckBoard[X][Y] != 0 && Board[X][Y] != 2)
//                {
//                    continue;
//                }
//                //치킨집인 경우 해당 집 기준으로의 치킨 거리 합산후 해당 BFS 탐색 종료
//                if (Board[X][Y] == 2)
//                {
//                    TotalChickenDis += (CheckBoard[Pos.first][Pos.second]);
//                    while (!Q.empty()) {
//                        Q.pop();
//                    }
//                    break;
//                }
//
//                Q.push({ X,Y });
//                CheckBoard[X][Y] = CheckBoard[Pos.first][Pos.second] + 1;
//
//
//            }
//
//        }
//
//        //checkBoard 초기화
//        for (int i = 0; i < N; i++)
//        {
//            for (int j = 0; j < N; j++)
//            {
//                CheckBoard[i][j] = 0;
//            }
//        }
//    }
//
//    return TotalChickenDis;
//}

int CalDistance()
{
    //도시 내에 존재하는 모든 집들의 치킨 거리를 구해야 함.
    int TotalChickenDis = 0;

    //모든 집들에 대해서..
    for (int i = 0; i < DefaultHousePlace; i++)
    {
        int HouseMinChickenDis = 10000;
        for (int j = 0; j < DefaultChickenPlace; j++)
        {
            //폐업하지 않은 치킨집이라면
            if (ChickenPlace[j].second == false)
            {

                int ChickenDis = abs(HousePlace[i].first - ChickenPlace[j].first.first)+
                abs(HousePlace[i].second - ChickenPlace[j].first.second);

                HouseMinChickenDis = min(ChickenDis, HouseMinChickenDis);
            }
        }
        TotalChickenDis += HouseMinChickenDis;
    }

    return TotalChickenDis;
}





int DischargeChickenPlace = 0;


void Recursion(int SelectChickenPlace)
{
    //최소한으로 남겨할 치킨집 수와 이미 존재하는 치킨집 수가 같은 경우
    if (DefaultChickenPlace - M == 0)
    {
        //그냥 바로 BFS 수행 후 리턴
        ResultMinChickenDis = CalDistance();
        return;
    }
   
    //치킨집 폐업 후 M개의 치킨집만 남은 경우
    if (DefaultChickenPlace - DischargeChickenPlace == M)
    {
        //BFS 수행 하여 도시의 치킨 거리 도출
        ResultMinChickenDis = min(ResultMinChickenDis, CalDistance());
        return;
    }

    //N개의 치킨집에 대한 모든 폐업 여부를 결정한 경우
    if (SelectChickenPlace == DefaultChickenPlace)
    {
        return;
    }


    //해당 치킨 집 폐업
    Board[ChickenPlace[SelectChickenPlace].first.first][ChickenPlace[SelectChickenPlace].first.second] = 0;
    ChickenPlace[SelectChickenPlace].second = true;
    DischargeChickenPlace++;
    Recursion(SelectChickenPlace + 1);
    DischargeChickenPlace--;
    ChickenPlace[SelectChickenPlace].second = false;
    Board[ChickenPlace[SelectChickenPlace].first.first][ChickenPlace[SelectChickenPlace].first.second] = 2;


    //해당 치킨 집 폐업 X
    Recursion(SelectChickenPlace + 1);
}









int main() {
   
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;


    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> Board[i][j];

            if (Board[i][j] == 1)
            {
                DefaultHousePlace++;
                HousePlace.push_back({ i,j });
            }
            else if (Board[i][j] == 2)
            {
                DefaultChickenPlace++;
                ChickenPlace.push_back({ { i,j },false });
            }
        }
    }


    Recursion(0);

    cout << ResultMinChickenDis;

    return 0;
}

