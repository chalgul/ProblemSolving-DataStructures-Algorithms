#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;


stack<int> S;

int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> N;

    int Input = 0;

    for (int i = 0; i < N; ++i)
    {
        cin >> Input;

        switch (Input)
        {
        case 1:
            int Temp;
            cin >> Temp;
            S.push(Temp);
            break;
        case 2:
            if (!S.empty())
            {
                cout << S.top();
                S.pop();
            }
            else
                cout << -1;
            cout << "\n";
            break;
        case 3:
            cout << S.size();
            cout << "\n";
            break;
        case 4:
            if (S.empty())
                cout << 1;
            else
                cout << 0;
            cout << "\n";
            break;
        case 5:
            if (!S.empty())
            {
                cout << S.top();
            }
            else
                cout << -1;
            cout << "\n";
            break;
        }
    }


   
    return 0;
}


