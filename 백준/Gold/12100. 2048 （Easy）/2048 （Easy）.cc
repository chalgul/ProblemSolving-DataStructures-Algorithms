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

//블럭의 상태를 나타냄
struct BlockNode
{
    bool IsCombined = false;

    int Number = 0;
};



//board의 가로 세로 길이
int N;

//실제로 움직여볼 보드
BlockNode Board[21][21];

//고정 case
BlockNode DefaultBoard[21][21];

int MaxNum = 0;

//초기 블록은 2~1024에 속한 2의 제곱근

//블록은 추가되지 않는다.

//한번의 이동에서 블록 한번만 합쳐질 수 있다.

//이동 방향은 위 아래 좌 우 4가지

//총 5번의 이동 = 4^5 경우의 수


void MoveBlock(int Dir)
{

    //행 또는 열 끼리 이동 구분

    //행 끼리 이동
    if (Dir % 2 == 1)
    {
        //0행 ~ N-1행에 대한 한 줄 이동
        for (int i = 0; i < N; i++)
        {
            //왼쪽으로 슬라이드
            if (Dir == 3)
            {
                //맨 왼쪽에 있는 블럭부터 왼쪽으로 이동 시작
                for (int j = 0; j < N; j++)
                {
                    //0이 아닌 숫자 블록을 만나면
                    //한칸씩 왼쪽으로 이동 시도
                    if (Board[i][j].Number != 0)
                    {   
                        //i행 j열 블럭이면 k=j-1열부터 이동 시도
                        for (int k = j-1; k >= 0; k--)
                        {
                            //왼쪽 칸이 비어있는 경우
                            if (Board[i][k].Number == 0)
                            {
                                //블럭 옮기기
                                Board[i][k] = Board[i][k+1];

                                //옮기기 전 자리는 빈공간으로 초기화
                                Board[i][k+1].Number = 0;
                                Board[i][k+1].IsCombined = false;
                            }
                            //왼쪽 칸에 블럭이 있는 경우
                            else if (Board[i][k].Number != 0)
                            {
                                //두 블럭의 숫자가 같은지 확인하고 왼쪽 칸에 있는 블럭이 이미 합쳐진 블럭은 아닌지 확인
                                if (Board[i][k].Number == Board[i][k+1].Number && !Board[i][k].IsCombined && !Board[i][k + 1].IsCombined)
                                {
                                    //블럭 합체
                                    Board[i][k].Number *= 2;
                                    Board[i][k].IsCombined = true;

                                    //합체 전에 오른쪽에 있던 블럭은 빈공간으로 초기화
                                    Board[i][k+1].Number = 0;
                                    Board[i][k+1].IsCombined = false;

                                }
                                //숫자라 서로 다르거나 같아도 이미 합쳐진 블록의 경우
                                else
                                {
                                    //블럭을 이동하거나 합치치 않는다. 제자리 유지
                                }
                            }
                        }


                    }
                }
            }
            //오른쪽으로 슬라이드
            else if (Dir == 1)
            {
                //맨 오른쪽에 있는 블럭부터 오른쪽으로 이동 시작
                for (int j = N-1; j >= 0; j--)
                {
                    //0이 아닌 숫자 블록을 만나면
                    //한칸씩 오른쪽으로 이동 시도
                    if (Board[i][j].Number != 0)
                    {
                        //i행 j열 블럭이면 k=j+1열 방향으로 이동 시도
                        for (int k = j + 1; k < N; k++)
                        {
                            //오른쪽 칸이 비어있는 경우
                            if (Board[i][k].Number == 0)
                            {
                                //블럭 옮기기
                                Board[i][k] = Board[i][k-1];

                                //옮기기 전 자리는 빈공간으로 초기화
                                Board[i][k-1].Number = 0;
                                Board[i][k-1].IsCombined = false;
                            }
                            //오른쪽 칸에 블럭이 있는 경우
                            else if (Board[i][k].Number != 0)
                            {
                                //두 블럭의 숫자가 같은지 확인하고 왼쪽 칸에 있는 블럭이 이미 합쳐진 블럭은 아닌지 확인
                                if (Board[i][k].Number == Board[i][k-1].Number && !Board[i][k].IsCombined && !Board[i][k-1].IsCombined)
                                {
                                    //블럭 합체
                                    Board[i][k].Number *= 2;
                                    Board[i][k].IsCombined = true;

                                    //합체 전에 왼쪽에 있던 블럭은 빈공간으로 초기화
                                    Board[i][k-1].Number = 0;
                                    Board[i][k-1].IsCombined = false;

                                }
                                //숫자라 서로 다르거나 같아도 이미 합쳐진 블록의 경우
                                else
                                {
                                    //블럭을 이동하거나 합치치 않는다. 제자리 유지
                                }
                            }
                        }


                    }
                }
            }
        }
    }
    //열 끼리 이동
    else if (Dir % 2 == 0)
    {
        //0열 ~ N-1열에 대한 한 줄 이동
        for (int i = 0; i < N; i++)
        {
            //위쪽으로 슬라이드
            if (Dir == 0)
            {
                //0열 부터 모든 행 값에 대해서 순서대로 check
                for (int j = 0; j < N; j++)
                {
                    //0이 아닌 숫자 블록을 만나면
                    //한칸씩 위쪽으로 이동 시도
                    if (Board[j][i].Number != 0)
                    {
                        //j행 i열 블럭이면 k=j-1행부터 이동 시도
                        for (int k = j - 1; k >= 0; k--)
                        {
                            //위쪽 칸이 비어있는 경우
                            if (Board[k][i].Number == 0)
                            {
                                //블럭 옮기기
                                Board[k][i] = Board[k+1][i];

                                //옮기기 전 자리는 빈공간으로 초기화
                                Board[k + 1][i].Number = 0;
                                Board[k + 1][i].IsCombined = false;
                            }
                            //위쪽 칸에 블럭이 있는 경우
                            else if (Board[k][i].Number != 0)
                            {
                                //두 블럭의 숫자가 같은지 확인하고 위쪽 칸에 있는 블럭이 이미 합쳐진 블럭은 아닌지 확인
                                if (Board[k][i].Number == Board[k + 1][i].Number && !Board[k][i].IsCombined && !Board[k + 1][i].IsCombined)
                                {
                                    //블럭 합체
                                    Board[k][i].Number *= 2;
                                    Board[k][i].IsCombined = true;

                                    //합체 전에 아래쪽에 있던 블럭은 빈공간으로 초기화
                                    Board[k + 1][i].Number = 0;
                                    Board[k + 1][i].IsCombined = false;

                                }
                                //숫자라 서로 다르거나 같아도 이미 합쳐진 블록의 경우
                                else
                                {
                                    //블럭을 이동하거나 합치치 않는다. 제자리 유지
                                }
                            }
                        }
                    }
                }
            }
            //아래쪽으로 슬라이드
            else if (Dir == 2)
            {
                //맨 아래쪽에 있는 블럭부터 아래쪽으로 이동 시작
                for (int j = N - 1; j >= 0; j--)
                {
                    //0이 아닌 숫자 블록을 만나면
                    //한칸씩 아래쪽으로 이동 시도
                    if (Board[j][i].Number != 0)
                    {
                        //j행 i열 블럭이면 k=j+1행 방향으로 이동 시도
                        for (int k = j + 1; k < N; k++)
                        {
                            //아래쪽 칸이 비어있는 경우
                            if (Board[k][i].Number == 0)
                            {
                                //블럭 옮기기
                                //Board[k][i] = Board[j][i];
                                Board[k][i] = Board[k-1][i];

                                //옮기기 전 자리는 빈공간으로 초기화
                                Board[k-1][i].Number = 0;
                                Board[k-1][i].IsCombined = false;
                            }
                            //아래쪽 칸에 블럭이 있는 경우
                            else if (Board[k][i].Number != 0)
                            {
                                //두 블럭의 숫자가 같은지 확인하고 아래쪽 칸에 있는 블럭이 이미 합쳐진 블럭은 아닌지 확인
                                if (Board[k][i].Number == Board[k-1][i].Number && !Board[k][i].IsCombined && !Board[k - 1][i].IsCombined)
                                {
                                    //블럭 합체
                                    Board[k][i].Number *= 2;
                                    Board[k][i].IsCombined = true;

                                    //합체 전에 위쪽에 있던 블럭은 빈공간으로 초기화
                                    Board[k-1][i].Number = 0;
                                    Board[k-1][i].IsCombined = false;

                                }
                                //숫자라 서로 다르거나 혹은 같아도 이미 합쳐진 블록의 경우
                                else
                                {
                                    //블럭을 이동하거나 합치치 않는다. 제자리 유지
                                }
                            }
                        }


                    }
                }
            }
        }
    }



    //특정 방향으로의 이동 마친 뒤, 다음 이동을 위해서 combined 변수 초기화

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (Board[i][j].IsCombined == true)
            {
                Board[i][j].IsCombined = false;
            }
        }
    }
}




int main() {
   
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;


    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int Number;
            cin >> Number;

            BlockNode Node;
            Node.IsCombined = false;
            Node.Number = Number;
            DefaultBoard[i][j] = Node;
            Board[i][j] = Node;
        }
    }

 
    for (int i = 0; i < (1 << 10); i++)
    {
        int Case = i;

        for (int j = 0; j < 5; j++)
        {
            int Dir = Case % 4;

            Case = Case / 4;

            MoveBlock(Dir);
        }

 

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                MaxNum = max(MaxNum, Board[i][j].Number);
            }
        }



        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                Board[i][j].IsCombined = DefaultBoard[i][j].IsCombined;
                Board[i][j].Number = DefaultBoard[i][j].Number;
            }
        }
    }

    cout << MaxNum;


    return 0;
}

