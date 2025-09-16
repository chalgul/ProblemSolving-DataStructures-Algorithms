#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <utility>
#include <unordered_map>
#include <map>

using namespace std;

int N;

int RopeLength[100002];

bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> RopeLength[i];
	}


	sort(RopeLength, RopeLength + N, cmp);

	int Max = 0;
	for (int i = 0; i < N; i++)
	{
		Max = max(Max, RopeLength[i] * (i + 1));
	}


	cout << Max;


	return 0;
}

