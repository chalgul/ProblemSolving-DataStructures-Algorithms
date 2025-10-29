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
#include <unordered_set>
#include <set>
#include <numeric>
#include <tuple>
#include <sstream>
#include <map>
#include <cmath>
using namespace std;

int L,C;


vector<char> Candidates;
vector<int> Combination;

bool IsMJ(char Cord)
{   
    if (Cord == 'a' || Cord == 'e' || Cord == 'i' || Cord == 'o' || Cord == 'u')
    {

        return true;

    }
    else
        return false;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> L >> C;


    char Input;
    for (int i = 0; i < C; ++i)
    {
        cin >> Input;
        Candidates.push_back(Input);
    }

    Combination.resize(C, 1);
    for (int i = 0; i < L; ++i)
    {
        Combination[i] = 0;
    }


    sort(Candidates.begin(), Candidates.end());

    do
    {

        int M = 0;
        int J = 0;


        vector<char> Temp;

        for (int i = 0; i < C; ++i)
        {
            //암호 포함
            if (Combination[i] == 0)
            {
                Temp.push_back(Candidates[i]);
                
                if (IsMJ(Candidates[i]))
                    M++;
                else
                    J++;
            }
        }

        if (M >= 1 && J >= 2)
        {
            for (char Cord : Temp)
            {
                cout << Cord;
            }

            cout << "\n";
        }

    
    } while (next_permutation(Combination.begin(), Combination.end()));

    return 0;
}

