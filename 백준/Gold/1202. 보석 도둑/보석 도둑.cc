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
#include <map>

using namespace std;

int N, K;

//key : 가치, value : 무게
multimap<int, int> Jewel;

//key : 가방 무게 정보
multiset<int> Bag;

long long ResultVal = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    int M = 0, V = 0;
    //보석 입력
    for (int i = 0; i < N; ++i)
    {
        cin >> M >> V;
        Jewel.insert({ V, M });
    }

    int C = 0;
    //가방 입력
    for (int j = 0; j < K; ++j)
    {
        cin >> C;
        Bag.insert(C);
    }
    

    for (multimap<int,int>::reverse_iterator RIter = Jewel.rbegin(); RIter != Jewel.rend(); ++RIter)
    {
        //해당 보석을 담을 수 있는 가방들 중 가장 작은 용량을 가진 가방을 탐색
        multiset<int>::iterator Iter = Bag.lower_bound(RIter->second);
        
        //해당 보석을 넣을 수 있는 가방이 실제로 존재하는지 check
        if (Iter != Bag.end())
        {
            //가방에 담은 총 보석 가치 증가 및 해당 가방을 사용 완료했으므로 set에서 제거
            ResultVal += RIter->first;
            Bag.erase(Iter);
        }
    }


    cout << ResultVal;

    return 0;
}


