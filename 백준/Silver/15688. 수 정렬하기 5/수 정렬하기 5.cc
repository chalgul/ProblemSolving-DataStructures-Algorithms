#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <utility>
#include <map>

using namespace std;


int N;

//-1 ~ -1000000 -> index : 1000001 ~ 2000000
int CountNum[2000005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> N;

	int InputNum;
	for (int i = 0; i < N; i++)
	{
		cin >> InputNum;

		if (InputNum < 0)
		{
			InputNum = abs(InputNum);
			CountNum[InputNum + 1000000]++;
		}
		else
		{
			CountNum[InputNum]++;
		}


	}
	
	for (int i = 2000001; i >= 1000001; i--)
	{
		if (CountNum[i] != 0)
		{
			for (int j = 0; j < CountNum[i]; j++)
			{
				cout << -1*(i-1000000) << "\n";
			}
		}
	}


	for (int i = 0; i < 1000001; i++)
	{
		if (CountNum[i] != 0)
		{
			for (int j = 0; j < CountNum[i]; j++)
			{
				cout << i << "\n";
			}
		}
	}	








	return 0;
}

