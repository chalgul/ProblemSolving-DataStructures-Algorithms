#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ArrayCnt[100002];

int solution(int k, vector<int> tangerine) {
    int answer = 0;

    //우선 귤을 크기 순으로 정렬 수행   O(NlogN)

    //정렬된 귤 배열을 한 번 순회하면서 동일한 크기를 가진 귤의 개수를 담은 배열 만들기  O(N)

    //새로 만든 배열 정렬 후, 뒤에서부터 확인하면 끝? O(N)

    //2N + NlogN

    sort(tangerine.begin(), tangerine.end());

    int Temp = tangerine[0];
    int Cnt = 0;
    int Index = 0;
    for (int Size : tangerine)
    {
        if (Temp != Size)
        {
            ArrayCnt[Index++] = Cnt;
            Cnt = 1;
            Temp = Size;
        }
        else
        {
            Cnt++;
        }
    }
    ArrayCnt[Index] = Cnt;

    sort(ArrayCnt, ArrayCnt + Index + 1);

    int Comp = k;
    for (int i = Index; i >= 0; --i)
    {
        if (ArrayCnt[i] >= Comp)
        {
            answer++;
            break;
        }
        else
        {
            answer++;
            Comp -= ArrayCnt[i];
        }

    }

    return answer;
}