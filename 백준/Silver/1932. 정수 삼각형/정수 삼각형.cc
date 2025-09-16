#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <utility>
#include <unordered_map>
#include <map>

using namespace std;


int N;
int MaxResult = 0;
int Triangle[200002];

//x번째 위치에서의 최댓값
int Table[200002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	
	for (int i = 1; i <= (N*(1+N))/2; i++)
	{
		cin >> Triangle[i];
	}

	Table[1] = Triangle[1];
	MaxResult = Table[1];
	for (int i = 2; i <= N; i++)
	{


		//여기 부터 새로운 줄 인덱스
		int IndexX = (((i-1) * (1 + (i-1))) / 2) + 1;

		//가장 왼쪽
		Table[IndexX] = Table[IndexX - (i - 1)] + Triangle[IndexX];
		MaxResult = max(Table[IndexX], MaxResult);


		//3번째 줄부터는 중간 원소가 등장
		if (i >= 3)
		{
			int MiddleCount = i - 2;


			//중간 원소들
			while (MiddleCount != 0)
			{
				Table[IndexX + MiddleCount] = max(Table[IndexX + MiddleCount - i] + Triangle[IndexX+ MiddleCount], Table[IndexX + MiddleCount - i + 1] + Triangle[IndexX+ MiddleCount]);
				MaxResult = max(Table[IndexX + MiddleCount], MaxResult);
				MiddleCount--;
			}
		}
		//가장 오른쪽
		Table[IndexX + i - 1] = Table[IndexX - 1] + Triangle[IndexX + i - 1];
		MaxResult = max(Table[IndexX + i - 1], MaxResult);
	}

	cout << MaxResult;

	return 0;
}

