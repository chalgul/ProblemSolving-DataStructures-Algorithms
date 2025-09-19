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

int N;




int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> N;

    unordered_map<string, string> OfficeLog;

    string Name;
    string PLog;

    for (int i = 0; i < N; i++)
    {
        cin >> Name >> PLog;
        OfficeLog[Name] = PLog;
    }

    vector<string> Officer;

    for (auto Log : OfficeLog)
    {
        if (Log.second == "enter")
        {
            Officer.push_back(Log.first);
        }

    }

    sort(Officer.begin(), Officer.end());

    for (vector<string>::iterator i = --Officer.end(); i != Officer.begin(); i--)
    {
        cout << *i << "\n";
    }
    cout << *Officer.begin();



    return 0;
}

