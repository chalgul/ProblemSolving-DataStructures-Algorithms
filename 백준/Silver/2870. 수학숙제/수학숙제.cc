#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <set>
#include <sstream>
#include <tuple>
#include <stack>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <cmath>
#include <string>
using namespace std;

int N;
vector<string> Numbers;

//sort 비교 함수의 경우, A가 B보다 앞에 와야할 경우, true를 반환하도록 설계해야 한다.
bool cmp(string A, string B)
{
    if (A.size() < B.size())
    {
        return true;
    }
    else if (A.size() == B.size())
    {
        //사전순으로 판단
        return A < B;
    }
    else
        return false;
}




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    string Line;

    for (int i = 0; i < N; ++i)
    {
        cin >> Line;

        //해당 라인의 숫자들 판단

        int St = 0;
        int Size = (int)Line.size();

        for (int i = 0; i < Size; ++i)
        {
            if (isdigit(Line[i]))
            {
                St = i;
                for (St; St < Size; St++)
                {
                    if (!isdigit(Line[St]))
                    {
                        break;
                    }
                }
                St--;
                //i ~ St까지가 숫자
                string Temp = Line.substr(i, St - i + 1);
                
                int Point = 0;
                for (int i = 0; i < Temp.size(); ++i)
                {
                    if (Temp[i] == '0')
                    {
                        Point++;
                    }
                    else
                    {
                        break;
                    }
                }
                if (Point == Temp.size())
                    Temp = '0';
                else if(Point > 0)
                    Temp = Temp.substr(Point, Temp.size() - Point + 1);
                
                Numbers.push_back(Temp);
                i = St;
            }
        }
    }

    sort(Numbers.begin(), Numbers.end(), cmp);

    for (auto Num : Numbers)
    {
        cout << Num << "\n";
    }


    return 0;
}