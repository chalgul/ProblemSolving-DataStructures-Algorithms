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
#include <unordered_map>
#include <set>
using namespace std;


string InputString;
string Dictionary[8] = {"c=","c-","dz=","d-","lj","nj","s=","z="};

int main() {
   
    ios::sync_with_stdio(0);
    cin.tie(0);

    int Count = 0;
    int FocusingIndex = 0;
    int PrevFocusingIndex = 0;
    cin >> InputString;

    bool IsFindInDic = false;

    while (FocusingIndex < InputString.size())
    {
        for (int i = 0; i < 8; i++)
        {
            int FindingIndex = InputString.find(Dictionary[i], FocusingIndex);
            if (FindingIndex == FocusingIndex)
            {
                FocusingIndex += Dictionary[i].size();
                IsFindInDic = true;
                Count++;
            }
        }

        if (!IsFindInDic)
        {
            FocusingIndex += 1;
            Count++;
        }


        IsFindInDic = false;
    }




    cout << Count;





    return 0;
}

