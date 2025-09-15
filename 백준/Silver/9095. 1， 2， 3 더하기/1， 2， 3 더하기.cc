#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <utility>
#include <unordered_map>
#include <map>

using namespace std;


int TestCase;
int N;

//index i가 1이되기 위한 연산 횟수 최소값 할당
int Table[12];


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> TestCase;


	//초기값 설정
	Table[1] = 1;
	Table[2] = 2;
	Table[3] = 4;
	for (int i = 4; i <= 10; i++)
	{
		Table[i] = Table[i - 1] + Table[i - 2] + Table[i - 3];
	}


	for (int i = 0; i < TestCase; i++)
	{

		cin >> N;

		cout << Table[N] << "\n";
	}
	return 0;
}

