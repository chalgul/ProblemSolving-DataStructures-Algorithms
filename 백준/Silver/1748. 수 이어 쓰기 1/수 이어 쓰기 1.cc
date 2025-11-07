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
using namespace std;

long long N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    std::cin >> N;

    //총 자릿수 길이
    long long Digits = 0;

    //현재 포커스된 자릿수 길이
    long long Length = 1;

    //자릿수가 바뀌는 경계
    long long Boundary;

    long long Start = 1;


    while (true)
    {
        Boundary = Start * 10;

        //여기서 종료
        if (N < Boundary)
        {
            Digits += (N - (Boundary / 10) + 1) * (Length);
            break;
        }
        else
        {
            Digits += (Boundary - pow(10, Length-1)) * Length;
            Length++;
            Start = Boundary;
        }
    }


    cout << Digits;

    return 0;
}