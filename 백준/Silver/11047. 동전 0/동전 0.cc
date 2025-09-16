#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <utility>
#include <unordered_map>
#include <map>

using namespace std;

int N, K;

int Coin[12];

int Result;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> Coin[i];
	}

	for (int i = N - 1; i >= 0; i--)
	{
		Result += K / Coin[i];	
		K %= Coin[i];
	}


	cout << Result;



	return 0;
}

