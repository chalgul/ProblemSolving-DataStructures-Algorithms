#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <list>
#include <queue>
#include <numeric>
#include <unordered_map>
#include <set>
#include <sstream>

using namespace std;

int TestCase = 0;

multiset<int> MSet;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> TestCase;

    int InputCount = 0;
    for (int i = 0; i < TestCase; ++i)
    {
        cin >> InputCount;
        string Dummy;
        getline(cin, Dummy);
        string Command;
        for (int j = 0; j < InputCount; ++j)
        {
            getline(cin, Command);
            stringstream SS(Command);

            string CommandString;
            int Number = 0;
            SS >> CommandString >> Number;

            if (CommandString == "I")
            {
                MSet.insert(Number);
            }
            else if (CommandString == "D")
            {
                if (MSet.empty())
                {
                    continue;
                }

                if (Number == 1)
                {
                    MSet.erase(--MSet.end());
                }
                else if(Number == -1)
                {
                    
                    MSet.erase(MSet.begin());
                }
            }
        }

        if (MSet.empty())
        {
            cout << "EMPTY" << "\n";
        }
        else
        {
            cout << *(--MSet.end()) << " " << *MSet.begin() << "\n";
            MSet.clear();
        }

    }
    return 0;
}


