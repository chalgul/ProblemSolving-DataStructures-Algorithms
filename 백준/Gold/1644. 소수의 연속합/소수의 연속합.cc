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



vector<int> InterPrime(int N, int M)
{
    vector<int> PrimeList;
    vector<bool> PrimeCheck(M+1, true);

    for (int i = 2; i * i <= M; ++i)
    {
        for (int j = i * i; j <= M; j += i)
        {
            PrimeCheck[j] = false;
        }
    }

    for (int i = N; i <= M; ++i)
    {
        if (PrimeCheck[i] == true)
        {
            PrimeList.push_back(i);
        }
    }

    return PrimeList;
}


int N;
int Result = 0;
vector<int> Primes;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //소수 얻어오기
    Primes = InterPrime(2, 4000000);

    cin >> N;

    int St = 0;
    int End = 0;
    int Sum = 2;

    int Size = (int)Primes.size();


    while (End <= Size-1)
    {

        if (Primes[End] > N)
            break;

        if (Sum == N)
        {
            Result++;

            if (St < End)
            {
                Sum -= Primes[St];
                St++;
            }
            else
                break;
        }
        else if (Sum < N)
        {
            End++;
            Sum += Primes[End];
        }
        else
        {
            if (St < End)
            {
                Sum -= Primes[St];
                St++;
            }
        }
    }


    cout << Result;
    return 0;
}

