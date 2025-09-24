#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <list>
#include <queue>
#include <unordered_map>

using namespace std;

int N;


struct StudentScore
{
    string Name;
    int Korean;
    int English;
    int Math;

    StudentScore(string name, int korea, int english, int math) :
        Name(name), Korean(korea), English(english), Math(math)
    {

    }

};

vector<StudentScore> ArrayStudent;

bool cmp(const StudentScore& a, const StudentScore& b)
{
    if (a.Korean == b.Korean && a.Math == b.Math && a.English == b.English)
    {
        return a.Name < b.Name;
    }
    else if (a.Korean == b.Korean && a.English == b.English)
    {
        return a.Math > b.Math;
    }
    else if (a.Korean == b.Korean)
    {
        return a.English < b.English;
    }
    else
    {
        return a.Korean > b.Korean;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    string Name;
    int Korean = 0, English = 0, Math = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> Name >> Korean >> English >> Math;
        StudentScore Info(Name, Korean, English, Math);
        ArrayStudent.push_back(Info);
    }
   
    sort(ArrayStudent.begin(), ArrayStudent.end(), cmp);


    for (auto A : ArrayStudent)
    {
        cout << A.Name << "\n";
    }

    return 0;
}
