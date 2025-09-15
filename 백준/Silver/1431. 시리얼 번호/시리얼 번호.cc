#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <utility>
#include <map>

using namespace std;

int N;

vector<string> ArraySerial;


bool cmp(const string& A, const string& B)
{
	//case1
	if (A.size() != B.size())
	{
		return A.size() < B.size();
	}

	int SumA = 0;
	int SumB = 0;

	for (char Number : A)
	{
		//알파벳이 아닌 숫자인 경우
		if (Number - '0' <= 9)
		{
			SumA += (Number - '0');
		}
	}

	for (char Number : B)
	{
		//알파벳이 아닌 숫자인 경우
		if (Number - '0' <= 9)
		{
			SumB += (Number - '0');
		}
	}

	if (SumA != SumB)
	{
		return SumA < SumB;
	}


	return A < B;
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	
	string Serial;
	for (int i = 0; i < N; i++)
	{
		cin >> Serial;
		ArraySerial.push_back(Serial);
	}

	sort(ArraySerial.begin(), ArraySerial.end(), cmp);


	for (vector<string>::iterator It = ArraySerial.begin(); It != ArraySerial.end(); It++)
	{
		cout << *It << "\n";
	}


	return 0;
}

