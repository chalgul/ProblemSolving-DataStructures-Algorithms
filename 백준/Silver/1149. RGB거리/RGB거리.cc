#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <utility>
#include <unordered_map>
#include <map>

using namespace std;

int N;

//i번째 집의 j색깔을 칠하는 데 드는 비용
int PaintCost[1002][3];

//i번째 집의 j 색깔을 칠했을 때의 최솟값
int Table[1002][3];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> PaintCost[i][0] >> PaintCost[i][1] >> PaintCost[i][2];
	}

	Table[1][0] = PaintCost[1][0];
	Table[1][1] = PaintCost[1][1];
	Table[1][2] = PaintCost[1][2];

	int ResultMin = 0;

	for (int i = 2; i <= N; i++)
	{
		Table[i][0] = Table[i - 1][1] + PaintCost[i][0];
		Table[i][1] = Table[i-1][0] + PaintCost[i][1];
		Table[i][2] = Table[i-1][0] + PaintCost[i][2];
		
		
		Table[i][0] = min(Table[i][0],Table[i-1][2] + PaintCost[i][0]);
		Table[i][1] = min(Table[i][1],Table[i-1][2] + PaintCost[i][1]);
		Table[i][2] = min(Table[i][2],Table[i-1][1] + PaintCost[i][2]);
	}


	ResultMin = min(Table[N][0], Table[N][1]);
	cout << min(ResultMin,Table[N][2]);



	return 0;
}

