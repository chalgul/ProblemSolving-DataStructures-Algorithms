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

//스택에 빌딩에 대한 정보가 들어오는 순간 해당 빌딩을 벤치마킹할 수 있는 빌딩의 수는 기존의 스택의 size와 동일
//스택은 자연스레 내림차순으로 정렬된 상태로 유지될 것임

int N;
vector<int> Building;

stack<int> Check;

long long ReturnVal = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int Height;
    for (int i = 0; i < N; ++i)
    {
        cin >> Height;
        Building.push_back(Height);
    }

    for (auto H : Building)
    {
        //스택이 비어있는 경우 바로 추가
        if(Check.empty())
            Check.push(H);
        else
        {
            //스택의 Top보다 새로 확인한 빌딩의 높이가 낮은 경우
            if (Check.top() > H)
            {
                //스택에 쌓여있는 모든 빌딩들은 새로 확인한 빌딩을 벤치마킹 할 수 있음
                ReturnVal += (int)Check.size();
                Check.push(H);
            }
            else
            {
                //스택의 Top이 새로 확인한 빌딩보다 높이가 높을 때까지 무한반복
                while (true)
                {
                    Check.pop();
                    //아예 높은 빌딩이 스택에 없었음
                    if (Check.empty())
                    {
                        Check.push(H);
                        break;
                    }
                    else
                    {
                        //pop을 반복하던 도중 높이가 높은 빌딩이 stack의 top에 위치
                        if (Check.top() > H)
                        {
                            //스택에 남아있는 빌딩들은 새로 확인한 빌딩보다 높이가 높은 것이 보장됨
                            ReturnVal += (int)Check.size();
                            Check.push(H);
                            break;
                        }
                    }
                }
            }
        }
    }

    cout << ReturnVal;


    return 0;
}