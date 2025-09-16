#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <utility>
#include <unordered_map>
#include <map>

using namespace std;

//좌석의 개수
int N;

//고정석 개수
int M;

int VIPArray[42];

//좌석의 수가 i개고 고정석이 없을 때 나올 수 있는 경우의 수
int Table[42];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	cin >> M;
	Table[0] = 1;

	Table[1] = 1;

	Table[2] = 2;


	for (int i = 3; i <= N; i++)
	{
		Table[i] = Table[i - 1] + Table[i - 2];
	}

	for (int i = 0; i < M; i++)
	{
		cin >> VIPArray[i];
	}

	int Result = 0;
	if (M != 0)
	{
		Result = Table[VIPArray[0] - 1];
		for (int i = 1; i < M; i++)
		{
			Result *= Table[VIPArray[i] - VIPArray[i - 1] - 1];
		}

		Result *= Table[N - VIPArray[M - 1]];

	}
	else
	{
		cout << Table[N];
		return 0;
	}
	cout << Result;


	return 0;
}

