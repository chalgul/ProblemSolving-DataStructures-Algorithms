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

int ArrayNum[10];

vector<int> SelectNum;

void Recursion(int SelectNumCount)
{
    //M개의 숫자를 이미 선택한 경우 출력 후 return
    if (SelectNum.size() == M)
    {
        for (auto It = SelectNum.begin(); It != SelectNum.end(); It++)
        {
            cout << *It << " ";
        }
        cout << "\n";
        return;
    }


    //상태 공간 트리를 끝까지 타고 들어간 경우 return
    if (SelectNumCount == N)
    {
        return;
    }


    //해당 레벨에서 숫자를 선택한 경우
    SelectNum.push_back(ArrayNum[SelectNumCount]);
    Recursion(SelectNumCount + 1);
    SelectNum.pop_back();



    //해당 레벨에서 숫자를 선택하지 않은 경우
    Recursion(SelectNumCount + 1);

}


int main() {
   
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> ArrayNum[i];
    }


    sort(ArrayNum, ArrayNum + N);


    Recursion(0);




    return 0;
}

