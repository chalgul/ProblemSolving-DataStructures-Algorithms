#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <utility>
#include <unordered_map>
#include <map>

using namespace std;

int N;

//first : 카드의 개수 , second : 카드 안의 숫자

map<long long, int> CardSet;

bool cmp(const pair<long long, int>& A, const pair<long long, int>& B)
{
	if (A.second == B.second)
	{
		return A.first < B.first;
	}

	return A.second > B.second;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> N;

	long long Number;
	for (int i = 0; i < N; i++)
	{
		cin >> Number;
		CardSet[Number]++;
	}

	vector<pair<long long, int>> CardVec(CardSet.begin(), CardSet.end());


	sort(CardVec.begin(), CardVec.end(), cmp);


	cout << CardVec[0].first;

	return 0;
}

