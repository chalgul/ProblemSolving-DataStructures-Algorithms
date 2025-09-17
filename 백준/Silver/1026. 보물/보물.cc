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
#include <set>
using namespace std;


int N;

int ArrayA[52];
int ArrayB[52];


//내림차순 정렬
bool cmp(int a, int b)
{
    return a > b;
}




int main() {
   
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> ArrayA[i];
    }

    for (int i = 0; i < N; i++)
    {
        cin >> ArrayB[i];
    }

    //오름차순 정렬
    sort(ArrayA, ArrayA + N);

    //내림차순 정렬
    sort(ArrayB, ArrayB + N, cmp);

    int ResultSum = 0;

    for (int i = 0; i < N; i++)
    {
        ResultSum += ArrayA[i] * ArrayB[i];

    }



    cout << ResultSum;

    return 0;
}

