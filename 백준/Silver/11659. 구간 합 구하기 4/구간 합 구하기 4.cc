#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <utility>
#include <unordered_map>
#include <map>

using namespace std;

int N, M;

vector<int> Sum;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	int InputNum = 0;
	int Total = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> InputNum;
		Total += InputNum;
		Sum.push_back(Total);
	}


	int Start = 0, End = 0;
	for (int i = 0; i < M; i++)
	{
		cin >> Start >> End;

		if (Start == 1)
		{
			cout << Sum[End - 1] << "\n";
			continue;
		}

		cout << Sum[End - 1] - Sum[Start - 2] << "\n";
	}

	return 0;
}
