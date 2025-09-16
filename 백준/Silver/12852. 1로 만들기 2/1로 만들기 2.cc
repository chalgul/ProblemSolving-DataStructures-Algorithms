#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <utility>
#include <unordered_map>
#include <map>

using namespace std;

int X;


int Table[1000002];

int RecoverTable[1000002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> X;

	Table[1] = 0;

	for (int i = 2; i <= X; i++)
	{
		Table[i] = Table[i - 1] + 1;
		RecoverTable[i] = i - 1;

		if (i % 3 == 0)
		{
			if (Table[i] > Table[i / 3] + 1)
			{
				Table[i] = Table[i / 3] + 1;
				RecoverTable[i] = i / 3;
			}
		}

		if (i % 2 == 0)
		{
			if (Table[i] > Table[i / 2] + 1)
			{
				Table[i] = Table[i / 2] + 1;
				RecoverTable[i] = i / 2;
			}
		}


	}

	cout << Table[X] << "\n";

	int Number = X;
	while(X != 1)
	{
		cout << X << " ";
		X = RecoverTable[X];

	}

	cout << 1;


	return 0;
}

