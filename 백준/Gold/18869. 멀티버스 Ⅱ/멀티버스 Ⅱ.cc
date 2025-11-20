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
#include <tuple>
#include <sstream>
#include <numeric>
#include <map>
#include <cmath>
using namespace std;


int M, N;

vector<vector<int>> Universe;

int ReturnVal = 0;



bool Check[102];

vector<int> Candidate;

void Recursion(int Depth, int K)
{
    if (Depth == 2)
    {
        //2개 선택완
        bool IsPair = true;
        for (int k = 0; k < N; ++k)
        {
            if (Universe[Candidate[0]][k] != Universe[Candidate[1]][k])
            {
                IsPair = false;
                break;
            }
        }

        if (IsPair)
        {
            ReturnVal++;
        }


        return;
    }


    for (int i = K; i < M; ++i)
    {
        Candidate.push_back(i);
        Check[i] = true;
        Recursion(Depth + 1,i + 1);
        Candidate.pop_back();
        Check[i] = false;
    }
}




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    

    cin >> M >> N;

    int Input = 0;

    Universe.resize(M);

    for (int i = 0; i < M; ++i)
    {
        vector<int> Temp;


        for (int j = 0; j < N; ++j)
        {
            cin >> Input;
            Universe[i].push_back(Input);
            Temp.push_back(Input);
        }


        sort(Temp.begin(), Temp.end());
        vector<int> Temp2;
        for(auto P : Universe[i])
        {
            int Temp3 = (int)(lower_bound(Temp.begin(), Temp.end(), P) - Temp.begin());
            Temp2.push_back(Temp3);
        }

        Universe[i] = Temp2;
    }


   
    Recursion(0,0);

    cout << ReturnVal;




    return 0;
    
}