#include <iostream>
#include <queue>
#include <functional>
#include <vector>

using namespace std;

//카드 뭉치가 주어질 때, 가장 개수가 적은 카드 뭉치 2개씩 합쳐 나가면 제일 비교 횟수가 적다
//최소힙 쓰자..

int N;
priority_queue<int, vector<int>, greater<int>> PQ;
int ResultVal = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;


    int Input = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> Input;
        PQ.push(Input);
    }

    while (PQ.size() != 1)
    {
        int MinA = 0, MinB = 0;

        MinA = PQ.top();
        PQ.pop();
        MinB = PQ.top();
        PQ.pop();
        int Temp = MinA + MinB;
        PQ.push(Temp);
        ResultVal += Temp;
    }

    cout << ResultVal;

    return 0;
}