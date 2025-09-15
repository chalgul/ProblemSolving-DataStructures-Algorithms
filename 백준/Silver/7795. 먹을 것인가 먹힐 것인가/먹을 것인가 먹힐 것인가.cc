#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <utility>
#include <unordered_map>
#include <map>

using namespace std;

int TestCase;

int A, B;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> TestCase;

	for (int i = 0; i < TestCase; i++)
	{
		cin >> A >> B;

		vector<pair<int, int>> JVec;


		int InputNum = 0;
		for (int i = 0; i < A; i++)
		{
			cin >> InputNum;
			JVec.push_back({ InputNum,0 });
		}


		for (int i = 0; i < B; i++)
		{
			cin >> InputNum;
			JVec.push_back({ InputNum,1 });
		}

		sort(JVec.begin(), JVec.end());

		int Result = 0;
		int Stm = 0;
		for (int i = 0; i < A + B; i++)
		{
			//A인 경우
			if (JVec[i].second == 0)
			{
				Result += Stm;
			}
			//B인 경우
			else if (JVec[i].second == 1)
			{
				Stm++;
			}
		}

		cout << Result << "\n";
	}




	return 0;
}

