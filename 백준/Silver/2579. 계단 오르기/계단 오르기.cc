#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <utility>
#include <unordered_map>
#include <map>

using namespace std;

//i번째 계단의 점수
int StairScore[302];

//i번째 계단까지 올라가는데 구할 수 있는 최댓값
int Table[302];

//점화식

//k 계단까지 올라가는데 걸리는 최댓값
//k-1 계단을 밟는 경우 : k-3계단의 최댓값 + k-1 + k
//k-2 계단을 밟는 경우 : k-2계단의 최댓값 + k

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int Stair = 0;
	cin >> Stair;


	for (int i = 1; i <= Stair; i++)
	{
		cin >> StairScore[i];
	}

	Table[1] = StairScore[1];
	Table[2] = Table[1] + StairScore[2];
	if (StairScore[1] > StairScore[2])
	{
		Table[3] = Table[1] + StairScore[3];
	}
	else
	{
		Table[3] = StairScore[2] + StairScore[3];
	}


	int TempA = 0, TempB = 0;
	for (int i = 4; i <= Stair; i++)
	{
		TempA = Table[i - 3] + StairScore[i - 1] + StairScore[i];

		TempB = Table[i - 2] + StairScore[i];

		Table[i] = max(TempA, TempB);
	}


	cout << Table[Stair];





	return 0;
}

