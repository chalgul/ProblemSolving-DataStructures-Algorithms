#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <utility>
#include <unordered_map>
#include <map>

using namespace std;

int TestCase = 0;

int N;

//그래프 정보
int Table[100002][3];

//x행, y열에 도달하는데 걸리는 최소 비용 값
long DisTable[100002][4];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (true)
	{
		cin >> N;
		if (N == 0)
			break;
		TestCase++;


		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= 3; j++)
			{
				cin >> Table[i][j];
			}
		}

		//초기값
		DisTable[1][1] = 10000;
		DisTable[1][2] = Table[1][2];
		DisTable[1][3] = Table[1][3] + Table[1][2];


		//N번째 행까지의 최소값 구하기
		for (int i = 2; i <= N; i++)
		{
			for (int j = 1; j <= 3; j++)
			{
				if (j == 1)
				{
					DisTable[i][j] = min(DisTable[i - 1][j] + Table[i][j], DisTable[i - 1][j + 1] + Table[i][j]);
				}
				else if (j == 2)
				{
					DisTable[i][j] = min(DisTable[i - 1][j - 1] + Table[i][j], DisTable[i - 1][j] + Table[i][j]);
					DisTable[i][j] = min(DisTable[i][j], DisTable[i - 1][j + 1] + Table[i][j]);
					DisTable[i][j] = min(DisTable[i][j], DisTable[i][j - 1] + Table[i][j]);
				}
				else if (j == 3)
				{
					DisTable[i][j] = min(DisTable[i - 1][j - 1] + Table[i][j], DisTable[i - 1][j] + Table[i][j]);
					DisTable[i][j] = min(DisTable[i][j], DisTable[i][j - 1] + Table[i][j]);
				}

			}
		}

		cout <<TestCase<<". " << DisTable[N][2] << "\n";
	}




	return 0;
}

