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

int N;


int main() {
   
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    cin >> N;
   

    vector<int> ArrayInput;
    int InputNum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> InputNum;
        ArrayInput.push_back(InputNum);
    }
    vector<int> CopyInput = ArrayInput;

    sort(CopyInput.begin(), CopyInput.end());

    vector<int> NewArray;
    int TempNum  = 0;
    for (int i = 0; i < N; i++)
    {
        if (TempNum != CopyInput[i])
        {
            NewArray.push_back(CopyInput[i]);

            TempNum = CopyInput[i];
        }
    }


    
    for (int i = 0; i < N; i++)
    {
        cout << lower_bound(NewArray.begin(), NewArray.end(), ArrayInput[i]) - NewArray.begin() << " ";
    }

    return 0;
}

