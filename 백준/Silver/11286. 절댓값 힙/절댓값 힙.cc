#include <iostream>
#include <queue>
#include <functional>
#include <vector>

using namespace std;

struct cmp
{
    bool operator()(const int& a, const int& b)
    {

        if (abs(a) != abs(b))
        {
            if (abs(a) > abs(b))
                return true;
            else
                return false;
        }
        else
        {
            if (a > b)
                return true;
            else
                return false;
        }
    }
};

int N;
priority_queue<int, vector<int>, cmp> PQ;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int Input = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> Input;

        if (Input == 0)
        {
            if (!PQ.empty())
            {
                cout << PQ.top() << "\n";
                PQ.pop();
            }
            else
            {
                cout << 0 << "\n";
            }
        }
        else
        {
            PQ.push(Input);
        }
    }


    return 0;
}