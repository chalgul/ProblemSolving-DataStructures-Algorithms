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
string TargetString;

int main() {
   
    ios::sync_with_stdio(0);
    cin.tie(0);

    getline(cin, InputString);
    getline(cin, TargetString);

    int FocusIndex = 0;
    int ResultCount = 0;
    while (true)
    {

        FocusIndex = InputString.find(TargetString, FocusIndex);

        if (FocusIndex != string::npos)
        {
            ResultCount++;
            FocusIndex += TargetString.size();
        }
        else
        {
            break;
        }



    }


    cout << ResultCount;


    return 0;
}

