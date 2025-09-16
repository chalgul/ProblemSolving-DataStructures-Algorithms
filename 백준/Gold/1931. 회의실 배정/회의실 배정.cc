#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <utility>
#include <unordered_map>
#include <map>

using namespace std;

int N;

pair<int,int> ArraySch[1000002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;

	int X = 0;
	int Y = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> X >> Y;
		//끝나는 시간, 시작 시간 순으로 pair에 할당
		ArraySch[i] = { Y,X };
	}

	sort(ArraySch, ArraySch + N);

	int Count = 0;

	//가장 끝나는 시간이 빠른 회의 스케쥴 부터 배정하기
	int Finish = ArraySch[0].first;
	Count++;

	for (int i = 1; i < N; i++)
	{
		if (Finish <= ArraySch[i].first)
		{
			if (Finish <= ArraySch[i].second)
			{
				Finish = ArraySch[i].first;
				Count++;
			}
		}
	}

	cout << Count;


	return 0;
}

