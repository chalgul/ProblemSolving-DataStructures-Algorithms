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

int N, M;

int Board[102][102];

int DistanceBoard[102][102];

//위 오른 아래 왼 순서로 너비우선 계산 편하게 하기 위한 배열
int dx[4] = {-1,0,1,0};
int dy[4] = { 0,1,0,-1 };

queue<pair<int, int>> Q;


int main() {
   
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    //cin 과 getline을 혼용해서 사용할 때는, cin 사용이후 입력 버퍼에 남아있는 개행 문자를 비워준다.
    //getline은 \n 개행문자를 입력받는 순간 문자열 입력을 종료하기 때문
    cin.ignore();
    string S;
    for (int i = 0; i < N; i++)
    {
        getline(std::cin, S);

        for (int j = 0; j < M; j++)
        {
            //아스키 코드 정수로 변환하는 방법
            Board[i][j] = S[j] - '0';
        }
    }


    //시작 지점은 (0,0)으로 고정

    Q.push({ 0,0 });
    //시작 지점부터 거리 1 check
    DistanceBoard[0][0] = 1;

    while (!Q.empty())
    {
        pair<int,int> Coord = Q.front(); 
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int IndexX = Coord.first;
            int IndexY = Coord.second;

            IndexX += dx[i];
            IndexY += dy[i];


            //보드 범위를 벗어나지는 않았는지 계산
            if (IndexX < 0 || IndexX >= N || IndexY < 0 || IndexY >= M)
            {
                continue;
            }
            //벽이거나 이미 지나간 길이면 확장 X
            if (Board[IndexX][IndexY] == 0 || DistanceBoard[IndexX][IndexY] != 0)
            {
                continue;
            }

            //너비 우선 확장
            Q.push({ IndexX,IndexY });
            //거리 1 증가
            DistanceBoard[IndexX][IndexY] = DistanceBoard[Coord.first][Coord.second] + 1;
        }
    }


    cout << DistanceBoard[N - 1][M - 1];
    return 0;
}

