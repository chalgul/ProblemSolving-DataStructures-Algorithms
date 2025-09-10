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

//중복 선택 가능
int ArrayNum[8];


int SelectArray[8];

void Recursion(int SelectNum)
{
    //M개 만큼 수를 선택하여 수열 완성 시 반환
    if (SelectNum == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << SelectArray[i] << " ";


        }

        cout << "\n";
        return;
    }

    //SelectArray 어차피 덮어씌워질거라서 백트래킹시 별도의 배열 초기화 작업 필요 X
    for (int i = 0; i < N; i++)
    {
        SelectArray[SelectNum] = ArrayNum[i];
        Recursion(SelectNum + 1);
    }
}


int main() {
   
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> ArrayNum[i];
    }

    sort(ArrayNum, ArrayNum+N);

    Recursion(0);

    return 0;
}

